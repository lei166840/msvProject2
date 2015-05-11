#include "IR.h"
#include <iostream>

IRStruct::IRStruct(Module *module,IR *Ir, string name, CSyntaxNode *pTree)
{
	s_module = module;
	s_name = name;
	isDef = true;
	this->Ir = Ir;

	///a loop to define the variable of struct
	CSyntaxNode* visit = pTree;
	while (isDef && visit != NULL)
	{
		switch (visit->GetNType())
		{
			case AND_EXP:{
				if (visit->GetChild0()->GetNType() == UNSIGN_DECLARATION_STA)
					__Init(visit->GetChild0()->GetChild0(), false);
				else
					__Init(visit->GetChild0(), true);
				visit = visit->GetChild1();
				break;
			}

			case DECLARE_STA:{
				__Init(visit, true);
				visit = NULL;
				break;
			}

			case UNSIGN_DECLARATION_STA:{
				__Init( visit->GetChild0(), false);
				visit = NULL;
				break;
			}

			default: {
				cout << "IRStruct : invalid case " << endl;
				isDef = false;
				break;
			}
		}
	}

	s_type = StructType::create(module->getContext(),types,s_name);

}

IRStruct::~IRStruct()
{
	//for (vector<Type*>::iterator it = types.begin(); it != types.end(); it++)
		 //delete (*it);
}

/*
*Init the struct
*@param module(which the struct be defined)  pTree(the defination of struct)
*/
///add by shiyifang 2015-4-16
void IRStruct::__Init(CSyntaxNode *pTree, bool sign)
{
	Type* type = IR::GetType(s_module, pTree);

	if (type == NULL)
	{
		cout << "__Init : struct define failed";
		isDef = false;
		return;
	}

	CSyntaxNode* visit = pTree->GetChild0();
	while (isDef && visit != NULL)
	{
		
		switch (visit->GetChild0()->GetNType())
		{
		case IDENT_EXP:{
			__DeclrIdent(type, visit->GetChild0()->GetNName(), sign);
			break;
		}

		case ADDRESS_DECLARE_STA:{
			__DeclrPtr(type, visit->GetChild0(), sign);
			break;
		}

		case ARRAY_DECLARE_STA:{
			__DeclrArray(type, visit->GetChild0(), sign);
			break;
		}

		default: {
			cout << "__Init : Type " << visit->GetChild0()->GetNType() << "has not considered " << endl;
			isDef = false;
			break;
		}

		}

		visit = visit->GetChild1();
	}

}

/*
*Declare a pure Identify
*@param type(its type)  name(its name)
*/
///add by shiyifang 2015-4-16
void IRStruct::__DeclrIdent(Type *type, string name, bool sign)
{
	types.push_back(type);
	IsSign.push_back(sign);
	if (position.insert(make_pair(name, types.size())).second == false)
	{
		cout << "__Init : variable " << name << "has already defined" << endl;
		isDef = false;
	}
}

/*
*Declare a pointer variable
*@param type(its type)  pTree(declaration)
*/
///add by shiyifang 2015-4-16
void IRStruct::__DeclrPtr(Type *type, CSyntaxNode *pTree, bool sign)
{
	while (pTree != NULL)
	{
		if (pTree->GetNType() == ADDRESS_DECLARE_STA)
			type = PointerType::get(type, 0);//ADDRESS_SAPCE_GENERIC ??

		else if (pTree->GetNType() == ARRAY_DECLARE_STA)
		{
			__DeclrArray(type, pTree, sign);
			return;
		}

		else if (pTree->GetNType() == IDENT_EXP)
		{
			__DeclrIdent(type, pTree->GetNName(), sign);
			return;
		}

		pTree = pTree->GetChild0();
	}
}

/*
*Declare a array variable
*@param type(its type)  pTree(declaration)
*/
///add by shiyifang 2015-4-16
void IRStruct::__DeclrArray(Type *type, CSyntaxNode *pTree, bool sign)
{
	string name = pTree->GetNName();

	vector<int> subscript;
	while (pTree != NULL)
	{
		if (pTree->GetChild0()->GetNType() == INTEGER_EXP)
			subscript.push_back(pTree->GetChild0()->GetiValue());
		else if (pTree->GetChild0()->GetChild0() != NULL)
		{
			//算术表达式的情况暂时不考虑
			//Value *value = Ir->__Expr2IR(pTree->GetChild0()->GetChild0());
		}
		else
		{
			cout << "__DeclrArray: invalid array subscript " << endl;
			isDef = false;
		}

		pTree = pTree->GetChild1();
	}

	for (int i = subscript.size() - 1; i >= 0; i--)
		type = ArrayType::get(type,subscript.at(i));

	__DeclrIdent(type, name, sign);
}

/*
*Get the element's type by its name
*@param EleName(the element's name)
*return false if it's unsigned ,else return true
*if we cannot find it return false
*/
///add by shiyifang 2015-4-21
bool IRStruct::GetIsSigned(string EleName)
{
	int pos = GetElementPos(EleName);
	if (pos == -1)
		return false;
	else
		return IsSign.at(pos);
}

/*
*Get the element's type by its name
*@param EleName(the element's name)
*return its Type* if we find it , else return NULL
*/
///add by shiyifang 2015-4-21
llvm::Type* IRStruct::GetElementType(string EleName)
{
	int pos = GetElementPos(EleName);
	if (pos == -1)
		return NULL;
	else
		return types.at(pos);
}

/*
*Get the element's position by its name
*@param EleName(the element's name)
*return its poision if we find it , else return -1
*/
///add by shiyifang 2015-4-21
int IRStruct::GetElementPos(string EleName)
{
	map<string, int>::iterator it = position.find(EleName);
	if (it == position.end())
		return -1;
	else
		return it->second;
}
