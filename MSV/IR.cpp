#include"IR.h"
#include<iostream>

#include<map>

using namespace llvm;
using namespace std;

extern CSyntaxNode *struct_tree;

IRSymbol::IRSymbol()
{
}
IRSymbol::IRSymbol(AllocaInst* InstVar, bool sign)
{
	AllocaInstVar = InstVar;
	IsSigned = sign;
}

IRSymbol::~IRSymbol()
{
}

bool IR::InstIRSymbol(string name, AllocaInst* InstVar, bool sign)
{
	return m_IRSTable.insert(make_pair(name, new IRSymbol(InstVar, sign))).second;
}

IR::IR()
{

	m_IRStruct = map<string, IRStruct*>();
	m_SVtable = map<string, string>();
}
IR::~IR()
{
	delete m_module;
	delete m_builder;
}
void IR::Trslt2IR(CSyntaxTree* m_GlbVarTree,CSyntaxNode *function_tree, CSyntaxTree *IRTree)
{
	if (IRTree == NULL)
	{
		cout << "In function Trslt2IR, IRTree is NULL" << endl;
		return;
	}

	LLVMContext Context;
	std::unique_ptr<Module> Owner = make_unique<Module>("test", Context);
	m_module = Owner.get();

	m_builder = new llvm::IRBuilder<>(m_module->getContext());

	FunctionType *FuncTypeOfMain = FunctionType::get(IntegerType::get(m_module->getContext(), 32), false);
	Function *MainFunc = Function::Create(FuncTypeOfMain, Function::ExternalLinkage, "main", m_module);

	BasicBlock *entrymain = BasicBlock::Create(m_module->getContext(), "entry", MainFunc, 0);

	m_builder->SetInsertPoint(entrymain);

	m_StNum = m_builder->CreateAlloca(IntegerType::get(m_module->getContext(), 32), NULL, "$state_num");

	m_StNum = m_builder->CreateAlloca(IntegerType::get(m_module->getContext(), 32), NULL, "$$state_num");
	m_StNum->setAlignment(4);

	StoreInst *store = m_builder->CreateStore(m_builder->getInt32(0), m_StNum, false);
	store->setAlignment(4);

	//结构体定义
	CSyntaxNode *visit = struct_tree;
	vector<CSyntaxNode*> tree;
	vector<string> name;
	//逆置语法树
	while (visit != NULL){
		name.push_back(visit->GetNName());
		tree.push_back(visit->GetChild0());
		visit = visit->GetChild1();
	}
	//生成定义
	for (int i = tree.size() - 1; i >= 0; i--)
	{
		IRStruct* s = new IRStruct(m_module,this,name.at(i), tree.at(i));
		if (!s->IsDefined() || m_IRStruct.insert(make_pair(s->GetStructName(), s)).second == false)
		{
			cout << "failed to define struct " << endl;
			break;
		}
		//m_builder->CreateAlloca(s->GetStructType());
	}

	frame2IR(m_GlbVarTree->GetRoot());

	func2IR(function_tree);

	Stmt2IR(IRTree->GetRoot());

	m_builder->CreateRetVoid();

	ExecutionEngine* EE = EngineBuilder(std::move(Owner)).create();

	outs() << *m_module;
	outs() << "\n\nResult: \n";
	outs().flush();

	//m_module->dump();


	std::vector<GenericValue> noargs;
	//EE->runFunction(FooF, noargs);
	GenericValue gv = EE->runFunction(MainFunc, noargs);

	//outs() << "Result: " << gv.IntVal << "\n";

	outs().flush();
	delete EE;
	llvm_shutdown();

}

/**
* 处理全局变量
* @param pTrlee(全局变量树) 
*/
///add by daichunchun 2015-5-5
void IR::frame2IR(CSyntaxNode *pTrlee)
{
	if (pTrlee == NULL)
	{
		return;
	}
	switch (pTrlee->GetNType())
	{
		case DECLARE_STA:
		{
			__Declr2IR(pTrlee, true);//处理signed类型的声明语句
			break;
		}
		case UNSIGN_DECLARATION_STA:
		{
			__Declr2IR(pTrlee->GetChild0(), false);//处理unsigned类型的声明语句
			break;
		}
		case CHOP_STA:
		{
			__Chop2IR(pTrlee);
			break;
		}
		default:
		{
			cout << "In function frame2IR,pTrlee have not-declare node" << endl;
			return;
		}
	}
}

void IR::Stmt2IR(CSyntaxNode *pTree)
{
	if (pTree == NULL)
	{
		cout << "In function Stmt2IR, IRTree is NULL" << endl;
		return;
	}
	
	switch (pTree->GetNType())
	{
	    case DECLARE_STA:
	    {

			__Declr2IR(pTree, true);//处理signed类型的声明语句
			break;
	    }
		case UNSIGN_DECLARATION_STA:
		{
			__Declr2IR(pTree->GetChild0(), false);//处理unsigned类型的声明语句
			break;
		}
	    case CHOP_STA:
    	{
		    __Chop2IR(pTree);
		    break;
	    }
	    case ASS_EQU_EXP:
		case EX_ASS_EXP:
	    {
		    __Ass2IR(pTree);
		    break;
	    }
		//2015/4/22 修改 daichunchun.原因：词法分析的IR树输出标识修改
		case STATE_OUTPUT_STA:
		{
			__Out2IR(pTree);
			break;
	    }
		case IF_ELSE_STA:
		{
			__If2IR(pTree);
			break;
		//函数调用语句
		case FUNCTION_STA:
		{
			__Call2IR(pTree);
			break;
		}
		//外部函数调用语句
		case EXT_FUNCTION_STA:
		{
			__Call2IR(pTree);
			break;
		}
		}
	}
}


/**add by yubin 2015-4-7
* 将声明转成对应的IR代码
* @param 传入待分析的语法树
* @return void
*/             
///changed by shiyifang 2015-04-17
void IR::__Declr2IR(CSyntaxNode *pTree, bool sign)
{
	//获得待声明的类型
	Type* type = IR::GetType(m_module, pTree);

	if (type == NULL)
	{
		cout << "__Declr2IR() error: Basic Type is not considered !" << pTree->GetRType() << endl;
		return;
	}

	//获取对齐方式
	int alignment = type->getPrimitiveSizeInBits() / 8;
	
	CSyntaxNode* visit = pTree->GetChild0();
	while (visit != NULL)
	{
		switch (visit->GetChild0()->GetNType())
		{
			case IDENT_EXP:
			{
				__DeclrIdent(type, visit->GetChild0(), alignment, sign);
				break;
			}

			case ADDRESS_DECLARE_STA:
			{
				alignment = 4;
				__DeclrPtr(type, visit->GetChild0(), alignment, sign);
				break;
			}

			case ARRAY_DECLARE_STA:
			{
				__DeclrArray(type, visit->GetChild0(), alignment, sign);
				break;
			}

			default: 
			{
				cout << "__Declr2IR() error: Combinational Type is not considered !" << visit->GetChild0()->GetNType() << endl;
				break;
			}
		}
		visit = visit->GetChild1();
	}

}

/**
* 声明一个基本类型变量
* @param type(基本类型)  pTree(传入待分析的语法树)  alignment(对齐方式) sign(是否有符号)
* @return 转换之后的结果
*/
///add by shiyifang 2015-04-17
void IR::__DeclrIdent(Type *type, CSyntaxNode *pTree, int alignment, bool sign)
{
	string name = pTree->GetNName();

	AllocaInst *allocDeclr = m_builder->CreateAlloca(type);
	allocDeclr->setName(name);
	if (alignment > 0)
		allocDeclr->setAlignment(alignment);

	IRSymbol *symbol = new IRSymbol(allocDeclr, sign);

	if (m_IRSTable.insert(map<string, IRSymbol *>::value_type(name, symbol)).second == false)
	{
		cout << "__DeclrIdent : variable " << name << "has already defined" << endl;
	}
}

/**
* 声明一个指针类型变量
* @param type(基本类型)  pTree(传入待分析的语法树)  alignment(对齐方式) sign(是否有符号)
* @return 转换之后的结果
*/
///add by shiyifang 2015-04-17
void IR::__DeclrPtr(Type *type, CSyntaxNode *pTree, int alignment, bool sign)
{     
	while (pTree != NULL)
	{
		if (pTree->GetNType() == ADDRESS_DECLARE_STA)
		{
			if (type->isVoidTy())
				type = Type::getInt8Ty(m_module->getContext());
			else
				type = PointerType::get(type, 0);//ADDRESS_SAPCE_GENERIC ??
		}
			
		else if (pTree->GetNType() == ARRAY_DECLARE_STA)
		{
			__DeclrArray(type, pTree, alignment, sign);
			return;
		}

		else if (pTree->GetNType() == IDENT_EXP)
		{
			__DeclrIdent(type, pTree, alignment, sign);
			return;
		}

		pTree = pTree->GetChild0();
	}
}

/**
* 声明一个数组类型变量
* @param type(基本类型)  pTree(传入待分析的语法树)  alignment(对齐方式) sign(是否有符号)
* @return 转换之后的结果
*/
///add by shiyifang 2015-04-17
///changed by daichunchun 2015-04-27 所做修改：添加数组下标表达式计算
void IR::__DeclrArray(Type *type, CSyntaxNode *pTree, int alignment, bool sign)
{
	vector<int> subscript;
	
	CSyntaxNode *TempNode=pTree;

	while (TempNode != NULL)
	{ 
		if (TempNode->GetChild0()->GetNType() == INTEGER_EXP)
			subscript.push_back(TempNode->GetChild0()->GetiValue());
		//若为表达式
		else if (TempNode->GetChild0() != NULL)
		{
			//计算表达式的值
			Value* integer_exp = __Expr2IR(TempNode->GetChild0());
			//判断表达式计算结果的值是否为i32类型
			if (integer_exp->getType() == IntegerType::get(m_module->getContext(), 32))
			{
				//将计算结果加入下标数组
				ConstantInt* tempInt = (ConstantInt*)integer_exp;
				subscript.push_back(tempInt->getSExtValue());
			}
			else
			{
				//下标非法报错
				cout << "__DeclrArray error: The array subscript is not int type" << endl;
				return;
			}
		}
		else
		{
			//无下标报错
			cout << "__DeclrArray error: Array Type has no subscript " << endl;
			return;
		}
		TempNode = TempNode->GetChild1();
	}

	for (int i = subscript.size() - 1; i >= 0; i--)
		type = ArrayType::get(type, subscript.at(i));


	__DeclrIdent(type, pTree, alignment, sign);

	}
	

///add by yubin 2015/4/7,处理chop类型的结点
void IR::__Chop2IR(CSyntaxNode *pTree)
{
	if (pTree == NULL)
	{
		cout << "In function __Chop2IR, IRTree is NULL" << endl;
		return;
	}
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "The left tree of chop node is null" << endl;
		return;
	}
	Stmt2IR(pTree->GetChild0());
	Stmt2IR(pTree->GetChild1());
}

/**
* 赋值语句转成对应的IR代码
* @param 传入待分析的语法树
* @return void
*/
///2015-4-7 add by wangmeng 
void IR::__Ass2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Ass2IR() syntax tree error!" << endl;
		return;
	}

	AllocaInst *LeftValue = m_IRSTable[pTree->GetChild0()->GetNName()]->GetAllocaInstVar();
	
	Type*LType = LeftValue->getAllocatedType();

	Value *tmpRtValue = __Expr2IR(pTree->GetChild1());
	if (tmpRtValue == NULL)
	{
		cout << "__Ass2IR() handle right error!" << endl;
		return;
	}

	Value *RightValue = __Cast2IR(tmpRtValue, LType, true);

	if (RightValue == NULL)
	{
		cout << "__Ass2IR() handle right error2!" << endl;
		return;
	}

	StoreInst *store = m_builder->CreateStore(RightValue, LeftValue, false);
	store->setAlignment(4);
}

/**
* 表达式转成对应的IR代码
* @param 传入待分析的语法树
* @return 转换之后的结果
*/
///2015-4-7 add by wangmeng
Value * IR::__Expr2IR(CSyntaxNode* pTree)
{
	if (pTree == NULL)
	{
		cout << "__Expr2IR error!" << endl;
		return NULL;
	}
	switch (pTree->GetNType())
	{
		///整数 例：3
		case INTEGER_EXP:
		{
			return ConstantInt::get(m_module->getContext(), APInt(32, pTree->GetiValue()));
			break;
			}
		//add by chengyu	2015-5-6
		//负数 
		case MINUS_EXP:
		{
			//int类型的负值	例：-3
			if (pTree->GetChild0()->GetNType() == INTEGER_EXP)
			{
				return ConstantInt::get(m_module->getContext(), APInt(32, -(pTree->GetChild0()->GetiValue())));
				break;
			}
			//float类型的负值	例：-3.1
			else if (pTree->GetChild0()->GetNType() == FLOATLITERAL_EXP)
			{
				return ConstantFP::get(m_module->getContext(), APFloat(-(pTree->GetChild0()->GetfValue())));
			}
			//变量取负值 例:-x
			/*
			else if (pTree->GetChild0()->GetNType() == IDENT_EXP)
			{
			Value *res = m_builder->CreateLoad(m_IRSTable[pTree->GetChild0()->GetNName()]->GetAllocaInstVar());
			}*/
		}
		///浮点数 例：3.1
		case FLOATLITERAL_EXP:
		{
			return ConstantFP::get(getGlobalContext(), APFloat(pTree->GetfValue()));
			break;
			}
		//字符 例：'c',add by daichunchun 2015/4/21
		case CHARLITERAL_EXP:
		{
			return ConstantInt::get(m_module->getContext(), APInt(8, pTree->GetcValue()));
			break;
			}
		//地址 例：&a ,add by daichunchun 2015/4/22
		case ADDRESS_EXP:
		{
			return m_IRSTable[pTree->GetChild0()->GetNName()]->GetAllocaInstVar();
			break;
			}
		case STR_EXP:
		{
			return m_builder->CreateGlobalStringPtr(pTree->GetsValue());
		}
		///变量 例：x
		case IDENT_EXP:
		{
			return m_builder->CreateLoad(m_IRSTable[pTree->GetNName()]->GetAllocaInstVar());
		}

		///加 例：x+y
		case ADD_EXP:
		{
			return __Add2IR(pTree);
		}

		///减 例：x-y
		case SUB_EXP:
		{
			return __Sub2IR(pTree);
		}
		///乘 例：x*y
		case MUL_EXP:
		{
			return __Mul2IR(pTree);
		}
		///除 例：x/y
		case DIV_EXP:
		{
			return __Div2IR(pTree);
		}

		///取余 例：x%y
		case MOD_EXP:
		{
			return __Mod2IR(pTree);
		}
		///函数调用表达式
		case FUNCTION_STA:
		{
			return __Call2IR(pTree);
			}
		//外部函数调用表达式
		case EXT_FUNCTION_STA:
		{
			return __Call2IR(pTree);
		}	
		
	}
}

//add by yubin 2015/4/9,调用printf输出变量的值
void IR::__Out2IR(CSyntaxNode *pTree)
{
	//先声明printf函数，然后根据不同的变量类型，进行调用
	std::vector<llvm::Type *> putsArgs;
	putsArgs.push_back(m_builder->getInt8PtrTy());
	llvm::ArrayRef<llvm::Type*>  argsRef(putsArgs);
	llvm::FunctionType *putsType = llvm::FunctionType::get(m_builder->getInt32Ty(), argsRef, true);
	llvm::Constant *putsFunc = m_module->getOrInsertFunction("printf", putsType);
	
	//每次输出变量的值之前，先输出是第几个状态,如state 0：
	m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr("State "));
	LoadInst *m_StNumVal = m_builder->CreateLoad(m_StNum);
	m_builder->CreateCall2(putsFunc, m_builder->CreateGlobalStringPtr("%d"), m_StNumVal);
	m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr(":\n"));
	
	
	if (pTree->GetST().size() != 0)//如果有变量的话，进行如下操作，否则什么也不做
	{
		vector<string> outPutSymTbl;//需要输出的变量，用vector存储
		outPutSymTbl = pTree->GetST();

		vector<string>::iterator iter;
		for (iter = outPutSymTbl.begin(); iter != outPutSymTbl.end(); iter++)
		{
			string a = *iter;
			int position = a.find("$$");
			if (position!=0)
			{
				//对于每一个变量，输出形式如下x=1
				m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr(*iter));
				m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr("="));

				AllocaInst *outPutVar = m_IRSTable[*iter]->GetAllocaInstVar();//通过变量的名字在m_IRSTable中找到对应的AllocaInst类型指针
				LoadInst *a = m_builder->CreateLoad(outPutVar);
				a->setAlignment(4);

				if (outPutVar->getAllocatedType() == IntegerType::get(m_module->getContext(), 32))//如果是int类型的话
				{
					Value *intFormat = m_builder->CreateGlobalStringPtr("%d");
					m_builder->CreateCall2(putsFunc, intFormat, a);
				}
				else if (outPutVar->getAllocatedType() == Type::getFloatTy(m_module->getContext()))//如果是float类型的话
				{
					//强制类型转换，将float类型转换成double类型，否则输出时会崩溃
					Value* floatTyToDoubleTy = m_builder->CreateFPExt(a, Type::getDoubleTy(m_module->getContext()));
					Value *floatFormat = m_builder->CreateGlobalStringPtr("%f");
					m_builder->CreateCall2(putsFunc, floatFormat, floatTyToDoubleTy);
				}
				//字符输出, add by daichunchun 2015/4/21
				else if (outPutVar->getAllocatedType() == Type::getInt8Ty(m_module->getContext()))//如果是char类型的话
				{
					Value *charFormat = m_builder->CreateGlobalStringPtr("%c");
					m_builder->CreateCall2(putsFunc, charFormat, a);
				}
				//指针输出, add by daichunchun 2015/4/22
				else if (outPutVar->getAllocatedType()->isPointerTy())
				{
					Value *intFormat = m_builder->CreateGlobalStringPtr("%d");
					//添加一次强制类型转换，直接输出指针类型为0，为了体现地址故添加强制类型转换（LLVM 3.7）
					m_builder->CreateCall2(putsFunc, intFormat, m_builder->CreatePtrToInt(a, IntegerType::get(m_module->getContext(),
						32)));
				}
				m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr("  "));//每个变量输出之后，输出两个空格，以便和下一个变量的输出隔开
			}
		}
		m_builder->CreateCall(putsFunc, m_builder->CreateGlobalStringPtr("\n"));//每个状态输出之后，换行

	}
	__AddOne2IR(m_StNum);//将状态数加1
}

/**
* 变量自加操作转成对应的IR代码
* @param 待处理的变量
* @return void
*/
///2015-4-8 add by wangmeng
void IR::__AddOne2IR(AllocaInst * alloc)
{
	LoadInst *load = m_builder->CreateLoad(alloc);
	Value *One = m_builder->getInt32(1);
	Value *result = m_builder->CreateNSWAdd(load, One, "inc");
	StoreInst *store = m_builder->CreateStore(result, alloc, false);

}


void IR::__If2IR(CSyntaxNode *pTree)
{
	Function *TheFunction = m_builder->GetInsertBlock()->getParent();

	BasicBlock *ThenBB = BasicBlock::Create(m_module->getContext(), "then", TheFunction);
	BasicBlock *ElseBB = BasicBlock::Create(m_module->getContext(), "else", TheFunction);
	BasicBlock *IfEnd = BasicBlock::Create(m_module->getContext(), "ifend", TheFunction);
	//m_builder->SetInsertPoint(entry);

	//条件跳转
	Value *v = m_builder->CreateCondBr(__Cond2IR(pTree->GetChild0()), ThenBB, ElseBB, 0);


	m_builder->SetInsertPoint(ThenBB);
	Stmt2IR(pTree->GetChild1());
	m_builder->CreateBr(IfEnd);


	m_builder->SetInsertPoint(ElseBB);
	Stmt2IR(pTree->GetChild2());
	m_builder->CreateBr(IfEnd);

	m_builder->SetInsertPoint(IfEnd);
}

//add by wanglei 2015-4-29
/**
* 条件语句转为IR代码
* @param 传入待分析的语法树
* @return 转换后的IR代码
*/
Value * IR::__Cond2IR(CSyntaxNode* pTree)
{
	if (pTree == NULL)
	{
		cout << "__Cond2IR error!" << endl;
		return NULL;
	}

	//获取当前结点类型 
	switch (pTree->GetNType())
	{
	case IDENT_EXP:   //标识符，如if(x)
	case INTEGER_EXP:   //整型，如if(3)
	case FLOATLITERAL_EXP:   //浮点型，如if(2.1)
	case ADD_EXP:    //加，如if(1+2)
	case SUB_EXP:    //减，如if(1-2) 
	case MUL_EXP:    //乘，如if(1*2)
	case DIV_EXP:    //除，如if(1/2)
	case MOD_EXP:    //取模，如if(1%2)
	{
		return __Expr2IR(pTree);
		break;
	}

	case EQU_EXP:    //等于，如if(x==y)
	{
		CSyntaxNode* LC = pTree->GetChild0();   //左孩子
		CSyntaxNode* RC = pTree->GetChild1();   //右孩子
		Value* LHS = __Cond2IR(LC);      //处理左孩子
		Value* RHS = __Cond2IR(RC);      //处理右孩子
		return __EQ2IR(LHS, RHS);
		break;
	}
	case NE_EXP:     //不等于，如if(x!=y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return __NE2IR(LHS, RHS);
		break;
	}
	case GT_EXP:     //大于，如if(x>y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return __GT2IR(LHS, RHS);
		break;
	}
	case LT_EXP:     //小于，如if(x<y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return __LT2IR(LHS, RHS);
		break;
	}
	case GE_EXP:     //大于等于，如if(x>=y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return __GE2IR(LHS, RHS);
		break;
	}
	case LE_EXP:     //小于等于，如if(x<=y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return __LE2IR(LHS, RHS);
		break;
	}
	case NEGATION_EXP:   //否定表达式，如if(!x)
	{
		CSyntaxNode* C = pTree->GetChild0();
		Value* value = __Cond2IR(C);   //处理子树
		Type* type = value->getType();    //获取value的类型
		if (type->isIntegerTy())
		{
			value = m_builder->CreateZExt(value, IntegerType::get(m_module->getContext(), 32));   //将返回值扩展为int32
			Value* zero_int32 = m_builder->getInt32(0);   //创建int32位整数0
			return m_builder->CreateICmpEQ(value, zero_int32);    //返回和0比较的结果
		}
		else if (type->isFloatTy())
		{
			Value* zero_int32 = m_builder->getInt32(0);   //创建int32位整数0
			Value* zero_float = m_builder->CreateSIToFP(zero_int32, Type::getFloatTy(m_module->getContext()));   //创建浮点型的0
			return m_builder->CreateFCmpOEQ(value, zero_float);    //返回和0比较的结果
		}
		break;
	}
	case AND_EXP:   //与，如if(x and y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return m_builder->CreateAnd(LHS, RHS, "AND");
		break;
	}
	case OR_EXP:    //或，如if(x or y)
	{
		CSyntaxNode* LC = pTree->GetChild0();
		CSyntaxNode* RC = pTree->GetChild1();
		Value* LHS = __Cond2IR(LC);
		Value* RHS = __Cond2IR(RC);
		return m_builder->CreateOr(LHS, RHS, "OR");
		break;
	}
	default:
		break;
	}
}

//等于
Value * IR::__EQ2IR(Value* LHS, Value* RHS)
{
	//二元关系运算
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())  //整型
	{
		Value* temp = m_builder->CreateICmpEQ(LHS, RHS);
		temp->print(llvm::outs());
		return m_builder->CreateICmpEQ(LHS, RHS, "ICmpEQ");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())   //浮点型
	{
		return m_builder->CreateFCmpOEQ(LHS, RHS, "FCmpOEQ");
	}
}

//不等于
Value * IR::__NE2IR(Value* LHS, Value* RHS)
{
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())
	{
		return m_builder->CreateICmpNE(LHS, RHS, "ICmpNE");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())
	{
		return m_builder->CreateFCmpONE(LHS, RHS, "FCmpONE");
	}
}

//大于
Value * IR::__GT2IR(Value* LHS, Value* RHS)
{
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())
	{
		return m_builder->CreateICmpSGT(LHS, RHS, "ICmpGT");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())
	{
		return m_builder->CreateFCmpOGT(LHS, RHS, "FCmpOGT");
	}
}

//小于
Value * IR::__LT2IR(Value* LHS, Value* RHS)
{
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())
	{
		return m_builder->CreateICmpSLT(LHS, RHS, "ICmpLT");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())
	{
		return m_builder->CreateFCmpOLT(LHS, RHS, "FCmpOLT");
	}
}

//大于等于
Value * IR::__GE2IR(Value* LHS, Value* RHS)
{
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())
	{
		return m_builder->CreateICmpSGE(LHS, RHS, "ICmpGE");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())
	{
		return m_builder->CreateFCmpOGE(LHS, RHS, "FCmpGE");
	}
}

//小于等于
Value * IR::__LE2IR(Value* LHS, Value* RHS)
{
	Type* LType = LHS->getType();
	Type* RType = RHS->getType();

	if (LType->isIntegerTy() && RType->isIntegerTy())
	{
		return m_builder->CreateICmpSLE(LHS, RHS, "ICmpLE");
	}
	else if (LType->isFloatTy() && RType->isFloatTy())
	{
		return m_builder->CreateFCmpOLE(LHS, RHS, "FCmpLE");
	}
}
/**
* 加法操作转成对应的IR代码
* @param 待处理的语法树
* @return 转之后的结果
*/
///2015-4-9 add by wangmeng
Value * IR::__Add2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Expr2IR add error!" << endl;
		return NULL;
	}
	Value *Left = __Expr2IR(pTree->GetChild0());

	if (Left == NULL)
	{
		cout << "__Add2IR() handle left error!" << endl;
		return NULL;
	}
	Value* Right = __Expr2IR(pTree->GetChild1());

	if (Right == NULL)
	{
		cout << "__Add2IR() handle right error!" << endl;
		return NULL;
	}

	Type* LType = Left->getType();
	Type* RType = Right->getType();

	///整数相加 3+4
	if (LType->isIntegerTy() &&
		RType->isIntegerTy())
	{
		return  m_builder->CreateAdd(Left, Right, "add", false, false);
	}

	///浮点数相加
	else if (LType->isFloatTy())
	{
		///浮点数与浮点数相加 3.1+4.2
		if (RType->isFloatTy()) 
		{
			return m_builder->CreateFAdd(Left, Right, "fadd", 0);
		}
		///浮点数与整数相加 3.6+5
		else if (RType->isIntegerTy())
		{
			Value* fRight = m_builder->CreateSIToFP(Right,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFAdd(Left, fRight, "fadd", 0);
		}
	}
	else if (RType->isFloatTy())
	{
		///整数与浮点数相加 4+3.6
		if (LType->isIntegerTy())
		{
			Value*fLeft = m_builder->CreateSIToFP(Left,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFAdd(fLeft, Right, "fadd", 0);
		}
	}
}

/**
* 减法操作转成对应的IR代码
* @param 待处理的语法树
* @return 转之后的结果
*/
///2015-4-9 add by wangmeng
Value * IR::__Sub2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Expr2IR add error!" << endl;
		return NULL;
	}
	Value *Left = __Expr2IR(pTree->GetChild0());

	if (Left == NULL)
	{
		cout << "__Sub2IR() handle left error!" << endl;
		return NULL;
	}

	Value* Right = __Expr2IR(pTree->GetChild1());

	if (Right == NULL)
	{
		cout << "__Sub2IR() handle right error!" << endl;
		return NULL;
	}

	Type* LType = Left->getType();
	Type* RType = Right->getType();

	///整数相减 4-2
	if (LType->isIntegerTy() &&
		RType->isIntegerTy())
	{
		return  m_builder->CreateSub(Left, Right, "sub", false, false);
	}

	///浮点数相减
	else if (LType->isFloatTy())
	{
		///浮点数与浮点数相减 4.3-3.5
		if (RType->isFloatTy())
		{
			return m_builder->CreateFSub(Left, Right, "fsub", 0);
		}
		///浮点数与整数相减 5-3.6
		else if (RType->isIntegerTy())
		{
			Value* fRight = m_builder->CreateSIToFP(Right,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFSub(Left, fRight, "fsub", 0);
		}
	}
	else if (RType->isFloatTy())
	{
		///整数与浮点数相减 4-3.6
		if (LType->isIntegerTy())
		{
			Value*fLeft = m_builder->CreateSIToFP(Left,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFSub(fLeft, Right, "fsub", 0);
		}

	}
}

/**
* 乘法操作转成对应的IR代码
* @param 待处理的语法树
* @return 转之后的结果
*/
///2015-4-9 add by wangmeng
Value * IR::__Mul2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Expr2IR add error!" << endl;
		return NULL;
	}
	Value *Left = __Expr2IR(pTree->GetChild0());

	if (Left == NULL)
	{
		cout << "__Mul2IR() handle left error!" << endl;
		return NULL;
	}

	Value* Right = __Expr2IR(pTree->GetChild1());

	if (Right == NULL)
	{
		cout << "__Mul2IR() handle right error!" << endl;
		return NULL;
	}

	Type* LType = Left->getType();
	Type* RType = Right->getType();

	///整数相乘 5*6
	if (LType->isIntegerTy() &&
		RType->isIntegerTy())
	{
		return  m_builder->CreateMul(Left, Right, "mul", false, false);
	}

	///浮点数相乘
	else if (LType->isFloatTy())
	{
		///浮点数与浮点数相乘 4.3*3.5
		if (RType->isFloatTy())
		{
			return m_builder->CreateFMul(Left, Right, "fmul", 0);
		}
		///浮点数与整数相乘 5*3.6
		else if (RType->isIntegerTy())
		{
			Value* fRight = m_builder->CreateSIToFP(Right,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFMul(Left, fRight, "fmul", 0);
		}
	}
	else if (RType->isFloatTy())
	{
		///整数与浮点数相乘 4*3.6
		if (LType->isIntegerTy())
		{
			Value*fLeft = m_builder->CreateSIToFP(Left,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFMul(fLeft, Right, "fmul", 0);
		}
	}
}


/**
* 除法操作转成对应的IR代码
* @param 待处理的语法树
* @return 转之后的结果
*/
///2015-4-9 add by wangmeng
Value * IR::__Div2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Expr2IR add error!" << endl;
		return NULL;
	}
	Value *Left = __Expr2IR(pTree->GetChild0());
	if (Left == NULL)
	{
		cout << "__Div2IR() handle left error!" << endl;
		return NULL;
	}
	Value* Right = __Expr2IR(pTree->GetChild1());

	if (Right == NULL)
	{
		cout << "__Div2IR() handle right error!" << endl;
		return NULL;
	}

	Type* LType = Left->getType();
	Type* RType = Right->getType();

	///整数相除 5/6
	if (LType->isIntegerTy() &&
		RType->isIntegerTy())
	{
		return  m_builder->CreateSDiv(Left, Right, "div", false);
	}

	///浮点数相除
	else if (LType->isFloatTy())
	{
		///浮点数与浮点数相除 4.3/3.5
		if (RType->isFloatTy())
		{
			return m_builder->CreateFDiv(Left, Right, "fdiv", 0);
		}
		///浮点数与整数相除 5/3.6
		else if (RType->isIntegerTy())
		{
			Value* fRight = m_builder->CreateSIToFP(Right,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFDiv(Left, fRight, "fdiv", 0);
		}
	}
	else if (RType->isFloatTy())
	{
		///整数与浮点数相除 4/3.6
		if (LType->isIntegerTy())
		{
			Value*fLeft = m_builder->CreateSIToFP(Left,
				Type::getFloatTy(m_module->getContext()));
			return m_builder->CreateFDiv(fLeft, Right, "fdiv", 0);
		}
	}
}

/**
* 取余操作转成对应的IR代码
* @param 待处理的语法树
* @return 转之后的结果
*/
///2015-4-9 add by wangmeng
Value * IR::__Mod2IR(CSyntaxNode* pTree)
{
	if (pTree->GetChild0() == NULL || pTree->GetChild1() == NULL)
	{
		cout << "__Expr2IR add error!" << endl;
		return NULL;
	}
	Value *Left = __Expr2IR(pTree->GetChild0());

	if (Left == NULL)
	{
		cout << "__Mod2IR() handle left error!" << endl;
		return NULL;
	}
	Value* Right = __Expr2IR(pTree->GetChild1());

	if (Right == NULL)
	{
		cout << "__Mod2IR() handle right error!" << endl;
		return NULL;
	}

	Type* LType = Left->getType();
	Type* RType = Right->getType();

	///整数取余
	if (LType->isIntegerTy() &&
		RType->isIntegerTy())
	{
		return  m_builder->CreateSRem(Left, Right, "rem");
	}
	else
	{
		cout << "__Mod2IR() error: cannot from float to float !" << endl;
		return NULL;
	}


}

/**
* 强制转换语句转为IR代码
* @param 传入待分析的语法树
* @return 转换后的IR代码
*/
///2015-4-9 add by wangmeng
///2015-5-6 modified by chengyu 
//2015-5-8 modified by wanglei，另添加sign变量，表示当前操作的数值的类型是否带符号
Value* IR::__Cast2IR(Value *value, Type *type, bool sign)
{
	Type *valType = value->getType();  //待转数据的类型
	if (valType == type)
	{
		return value;
	}
	else if (valType->isIntegerTy() && sign == true && type->isFloatTy())  //int -> float
	{
		return m_builder->CreateSIToFP(value, type);
	}
	else if (valType->isIntegerTy() && sign == false && type->isFloatTy())   //unsigned int -> float
	{
		return m_builder->CreateUIToFP(value, type);
	} 
	else if (valType->isFloatTy() && type->isIntegerTy())   //float -> int
	{
		return m_builder->CreateFPToSI(value, type);
	}
	else if (valType->isIntegerTy() && type->isPointerTy())   //int -> int*
	{
		return m_builder->CreateIntToPtr(value, type);
	}
	else if (valType->isPointerTy() && type->isIntegerTy())   //int* -> int
	{
		return m_builder->CreatePtrToInt(value, type);
	}
	//add by chengyu
	//int类型转char类型
	else if (type->isIntegerTy(8) && valType->isIntegerTy(32))
	{
		return m_builder->CreateTrunc(value, IntegerType::get(m_module->getContext(), 8));
	}
	//char类型转int类型
	else if (type->isIntegerTy(32) && valType->isIntegerTy(8))
	{
		return m_builder->CreateZExt(value, IntegerType::get(m_module->getContext(), 32));
	}

	else
	{
		cout << "cast error!" << endl;
		return NULL;
	}

}


/**
* 函数调用语句转为IR代码
* @param 传入待分析的语法树
* @return 转换后的IR代码
*/
///2015-4-14 add by daichunchun
Value* IR::__Call2IR(CSyntaxNode *pTree)
{
	//获取调用函数名
	std::string Callee = pTree->GetNName();
	//获取模块中函数定义
	Function *CalleeF = m_module->getFunction(Callee);
	//判断函数是否在该模块中存在
	if (CalleeF == 0)
	{
		cout << "__Call2IR Unknown function referenced" << endl;
		return NULL;
	}
	//获取参数列表
	std::vector<Value*> vecvalue;                                             
	CSyntaxNode *ParameterLeader = pTree->GetChild0();
	while (ParameterLeader != NULL)
	{
		CSyntaxNode *ParameterNode = ParameterLeader->GetChild0();
		if (ParameterNode->GetNName()!="")
		{
			AllocaInst* parameter = m_IRSTable[ParameterNode->GetNName()]->GetAllocaInstVar();
			LoadInst* parameter_load = m_builder->CreateLoad(parameter);
			vecvalue.push_back(parameter_load);
		}
		ParameterLeader = ParameterLeader->GetChild1();
	}

	if (CalleeF->getReturnType() != Type::getVoidTy(m_module->getContext()))
	{
		AllocaInst *ReturnValue = m_builder->CreateAlloca(CalleeF->getReturnType());
		ReturnValue->setName("RValue");
		int alignment = CalleeF->getReturnType()->getPrimitiveSizeInBits() / 8;
		ReturnValue->setAlignment(alignment);
		vecvalue.push_back(ReturnValue);
	}
	
	//判断传入的参数个数是否与调用函数的参数个数相符合
	if (CalleeF->arg_size() != vecvalue.size())
	{
		cout << "__Call2IR Incorrect arguments number" << endl;
		return NULL;
		}
	
	//构造函数调用
	llvm::ArrayRef<Value*>  Idx(vecvalue);
	return m_builder->CreateCall(CalleeF, Idx);
}

/**
*根据结构体定义的模块和declare树得到对应的llvm type
*@param module (声明结构体的模块) pTree(声明语句)
*@return 与声明对应的llvm type
*/
//add by shiyifang 2015-04-16
Type* IR::GetType(Module* m_module, CSyntaxNode *pTree)
{
	/*if (pTree->GetNType() != DECLARE_STA && pTree->GetNType() != UNSIG N_DECLARATION_STA)
	{
		cout << "In function GetType : pTree is not a DECLARE CSyntaxNode !"<<endl;
		return NULL;
	}
	if (pTree->GetNType() == UNSIGN_DECLARATION_STA)
	{
		cout << "In function GetType : Unsigned declaration is not considered !" << endl;
		return NULL;
	}
	*/

	RETURNTYPE type = pTree->GetRType();
	switch (type)
	{
		case INTTYPE:
		{
			return IntegerType::get(m_module->getContext(), 32);
		}
		case FLOATTYPE:
		{
			return Type::getFloatTy(m_module->getContext());
		}
		case CHARTYPE:
		{
			return Type::getInt8Ty(m_module->getContext());
		}
		/*
		case BOOLTYPE:
		{
		return Type::getInt8Ty(m_module->getContext());
		}
		*/
		case STRUCTTYPE:
		{
			map<string, IRStruct*>::iterator it = m_IRStruct.find(pTree->GetNName());
			if (it == m_IRStruct.end())
				return NULL;
			return ((*it).second)->GetStructType();
		}
		case VOIDTYPE:
		{
			return Type::getVoidTy(m_module->getContext());
		}
		default:
		{
			cout << "In function GetType() : Type is not considered !" << endl;
			return NULL;
		}

	}

}

/**
* 函数定义语句转为IR代码
* @param 传入待分析的语法树
* @return 转换后的IR代码
*/
///2015-4-27 add by daichunchun
void IR::func2IR(CSyntaxNode *pTree)
{
	if (pTree == NULL)
	{
		return;
	}
	//参数类型数组
	std::vector<Type*> vectype;
	//参数名数组
	std::vector<string> vecname;
	//返回值类型
	Type* rettype = Type::getVoidTy(m_module->getContext());
	//填补参数类型
	CSyntaxNode *ParameterLeader = pTree->GetChild0();
	while (ParameterLeader != NULL)
	{
		Type* temptype = IR::GetType(m_module, ParameterLeader);
		vectype.push_back(temptype);
		string parametername = ParameterLeader->GetChild0()->GetNName();
		vecname.push_back(parametername);
		if (parametername == "RValue")
			rettype = temptype;
		ParameterLeader = ParameterLeader->GetChild1();
	}
	//构造函数类型
	FunctionType* FT = FunctionType::get(rettype, vectype, false);
	//获取函数名字
	string functionname = pTree->GetNName();
	//函数定义
	Function* Func = Function::Create(FT, Function::ExternalLinkage, functionname, m_module);

	//函数符号表
	map<string, IRSymbol *> fun_STable;

	//存储全局状态
	BasicBlock *tempinsertpoint = m_builder->GetInsertBlock();
	map<string, IRSymbol *> temp_IRStable = m_IRSTable;

	//添加函数体
	if (pTree->GetChild1() != NULL)
	{
		BasicBlock *entry = BasicBlock::Create(m_module->getContext(), "entry", Func, 0);
		m_builder->SetInsertPoint(entry);
		Function::arg_iterator args = Func->arg_begin();
		vector<string>::iterator argsnames = vecname.begin();
		vector<Type*>::iterator types = vectype.begin();
		while (args != Func->arg_end())
		{
			string tempname = *(argsnames++);
			Type* temptype = *(types++);
			Value* temparg = args++;
			//参数列表加上变量名
			temparg->setName(tempname);
			//为参数列表分配内存
			AllocaInst *allocDeclr = m_builder->CreateAlloca(temptype);
			allocDeclr->setName(tempname + ".addr");
			int alignment = temptype->getPrimitiveSizeInBits() / 8;
			allocDeclr->setAlignment(alignment);
			//添加至符号表
			IRSymbol *symbol = new IRSymbol(allocDeclr,1);
			if (fun_STable.insert(map<string, IRSymbol *>::value_type(tempname, symbol)).second == false)
			{
				cout << "__DeclrIdent : variable " << tempname << "has already defined" << endl;
			}
			//存储参数
			StoreInst *store = m_builder->CreateStore(temparg, allocDeclr, false);
			}
		//修改符号表上下文
		m_IRSTable = fun_STable;
		Stmt2IR(pTree->GetChild1());
	}

	if (FT->getReturnType() != Type::getVoidTy(m_module->getContext()))
	{
		AllocaInst *ReturnValue = m_IRSTable["RValue"]->GetAllocaInstVar();
		LoadInst *LoadValue = m_builder->CreateLoad(ReturnValue);
		m_builder->CreateRet(LoadValue);
	}

	m_IRSTable = temp_IRStable;
	m_builder->SetInsertPoint(tempinsertpoint);

	return;
	}