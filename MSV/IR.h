#ifndef IR_H_INCLUDED
#define IR_H_INCLUDED

#include "llvm/ADT/SmallVector.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/Value.h"
#include "llvm/IR/Type.h"

#include "IRStruct.h"
#include "SyntaxTree.h"


using namespace llvm;

static map<string, IRStruct*> m_IRStruct;///结构体名 到 IRStruct的映射



#include "SyntaxTree.h"

using namespace llvm;


class IRSymbol
{
public:
	///构造函数
	IRSymbol();
	IRSymbol(AllocaInst* InstVar, bool sign);
	~IRSymbol();
	inline void SetIsSigned(bool sign)
	{
		IsSigned = sign;
	}
	inline bool GetIsSigned()
	{
		return IsSigned;
	}
	inline void SetAllocaInstVar(AllocaInst* InstVar)
	{
		AllocaInstVar = InstVar;
	}
	inline AllocaInst* GetAllocaInstVar()
	{
		return AllocaInstVar;
	}


private:
	bool IsSigned;
	AllocaInst* AllocaInstVar;
};

class IR
{
public:
	///构造函数
	IR();
	~IR();

	/**add by yubin 2015-4-7
	* 遍历m_IRTree,遇到每个结点，调用Stmt2IR函数
	* @param 传入待分析的m_IRTree
	* @return void
	*/
	void Trslt2IR(CSyntaxTree* m_GlbVarTree,CSyntaxNode *function_tree, CSyntaxTree *IRTree);

	/**add by yubin 2015-4-7
	* 将每个结点转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	void Stmt2IR(CSyntaxNode* pTree); //


	/*
	*根据结构体定义的模块和declare树得到对应的llvm type
	*@param module (声明结构体的模块) pTree(声明语句)
	*@return 与声明对应的llvm type
	*/
	//add by shiyifang 2015-04-16
	static Type* GetType(Module *m_module, CSyntaxNode *pTree);

	/**add by yubin 2015-4-7
	* 将声明转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	///changed by shiyifang 2015-04-17
	void __Declr2IR(CSyntaxNode *pTree, bool sign);

	/*
	*声明一个单纯的变量
	*@param  type(变量类型)  name(变量名)  alignment(对齐方式)
	*/
	void __DeclrIdent(Type *type, CSyntaxNode *pTree, int alignment, bool sign);

	/*
	*声明一个指针类型变量
	*@param  type(变量类型)  name(变量名)  alignment(对齐方式)
	*/
	void __DeclrPtr(Type *type, CSyntaxNode *pTree, int alignment, bool sign);

	/*
	*声明一个数组类型变量
	*@param  type(变量类型)  name(变量名)  alignment(对齐方式)
	*/
	void __DeclrArray(Type *type, CSyntaxNode *pTree, int alignment, bool sign);

	/**
	* 赋值语句转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	void __Ass2IR(CSyntaxNode* pTree);

	/**add by yubin 2015-4-7
	* 顺序语句转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	void __Chop2IR(CSyntaxNode *pTree);

	/**
	* 表达式转成对应的IR代码
	* @param 传入待分析的语法树
	* @return 转换之后的结果
	*/
	///2015-4-7 add by wangmeng
	Value * __Expr2IR(CSyntaxNode* pTree);

	/**
	* 输出语句转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	void __Out2IR(CSyntaxNode *pTree);

	/**
	* 变量自加操作转成对应的IR代码
	* @param 待处理的变量
	* @return void
	*/
	void __AddOne2IR(AllocaInst * alloc);

	/**
	* 加法操作转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __Add2IR(CSyntaxNode* pTree);

	/**
	* 减法操作转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __Sub2IR(CSyntaxNode* pTree);

	/**
	* 乘法操作转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __Mul2IR(CSyntaxNode* pTree);

	/**
	* 除法操作转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __Div2IR(CSyntaxNode* pTree);

	/**
	* 取余操作转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __Mod2IR(CSyntaxNode* pTree);

	/**
	* if语句转成对应的IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	void __If2IR(CSyntaxNode* pTree);

	/**
	* 将if语句和while语句中的条件表达式转为IR代码
	* @param 传入待分析的语法树
	* @return void
	*/
	Value* __Cond2IR(CSyntaxNode* pTree);

	/**
	* 强制转换语句转为IR代码
	* @param 传入待分析的语法树
	* @return 转换后的IR代码
	*/

	/**
	* 等于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __EQ2IR(Value* LHS, Value* RHS);

	/**
	* 不等于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __NE2IR(Value* LHS, Value* RHS);

	/**
	* 大于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __GT2IR(Value* LHS, Value* RHS);

	/**
	* 小于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __LT2IR(Value* LHS, Value* RHS);

	/**
	* 大于等于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __GE2IR(Value* LHS, Value* RHS);

	/**
	* 小于等于转成对应的IR代码
	* @param 待处理的语法树
	* @return 转之后的结果
	*/
	Value * __LE2IR(Value* LHS, Value* RHS);


	Value* __Cast2IR(Value *value, Type *type, bool sign);

	/**
	* 函数调用语句转为IR代码
	* @param 传入待分析的语法树
	* @return 转换后的IR代码
	*/
	///2015-4-14 add by daichunchun
	Value* IR::__Call2IR(CSyntaxNode *pTree);
	
	/**
	* 函数定义语句转为IR代码
	* @param 传入待分析的语法树
	* @return 转换后的IR代码
	*/
	///2015-4-27 add by daichunchun
	void IR::func2IR(CSyntaxNode *pTree);
	
	/**
	* 处理全局变量
	* @param pTrlee(全局变量树)
	*/
	///add by daichunchun 2015-5-5
	void IR::frame2IR(CSyntaxNode *pTrlee);
		
	bool InstIRSymbol(string name, AllocaInst* InstVar, bool sign);

private:
	///
	llvm::IRBuilder<> *m_builder;

	///
	Module* m_module;

	///符号表
	//map<string, AllocaInst *> m_IRSTable;
	map<string, IRSymbol *> m_IRSTable;

	///add by syf 2015-04-16
	map<string, string> m_SVtable;//结构体变量名到结构体名的映射

	///状态数
	AllocaInst *m_StNum;

};

#endif