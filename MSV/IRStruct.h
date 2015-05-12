
///create by shiyifang 2015-04-15

#ifndef IRSTRUCT_H_
#define IRSTRUCT_H_

#include <map>
#include <vector>
#include "SyntaxNode.h"
#include "SyntaxTree.h"

#include "llvm/ADT/SmallVector.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Type.h"

using namespace llvm;
using namespace std;

/*
 *Translate the struct tree！！pTree to two parts
 *one is vector<llvm::Type*> : store the struct member's types in order
 *the other is map<string,int> : store the map between member's name and member's position
 *then we can get the StructType* of this struct
 *that can help us handle the define 、declar and use of struct in llvm IR.
*/

class IR;

class IRStruct
{
public:
	/*
	 *更夛痕方
	 *@param module(the module you define the struct) name(struct name)  pTree(struct member tree)
	*/
	IRStruct(Module *module, IR *Ir, string name, CSyntaxNode *pTree);
	~IRStruct();

	inline string GetStructName()
	{
		return s_name;
	}

	inline void SetStructName(string name)
	{
		s_name = name;
	}

	inline bool IsDefined()
	{
		return isDef;
	}

	inline std::vector<llvm::Type*> GetAllTypes()
	{
		return types;
	}

	inline StructType* GetStructType()
	{
		return s_type;
	}

	/*
	*Get the element's type by its name
	*@param EleName(the element's name)
	*return false if it's unsigned ,else return true
	*if we cannot find it return false
	*/
	bool GetIsSigned(string EleName);

	/*
	*Get the element's type by its name
	*@param EleName(the element's name)
	*return its Type* if we find it , else return NULL
	*/
	llvm::Type* GetElementType(string EleName);

	/*
	 *Get the element's position by its name
	 *@param EleName(the element's name)
	 *return its poision if we find it , else return -1
	*/
	int GetElementPos(string EleName);

private:
	/*
	*Init the struct
	*@param module(which the struct be defined)  pTree(the defination of struct)
	*/
	void __Init(CSyntaxNode *pTree, bool sign);

	/*
	*Declare a pure Identify
	*@param type(its type)  name(its name)
	*/
	void __DeclrIdent(Type *type, string name, bool sign);

	/*
	*Declare a pointer variable
	*@param type(its type)  pTree(declaration)
	*/
	void __DeclrPtr(Type *type, CSyntaxNode *pTree, bool sign);

	/*
	*Declare a array variable
	*@param type(its type)  pTree(declaration)
	*/
	void __DeclrArray(Type *type, CSyntaxNode *pTree, bool sign);

	Module * s_module;

	string s_name;//the name of the struct

	bool isDef;//whether this struct has been defined successfully 

	map <string, int> position; //a map between struct member's name and member's position

	std::vector<llvm::Type*> types;//store struct member's type in order

	std::vector<bool> IsSign;//store whether the struct member is singed

	StructType* s_type;// type of the struct

	IR *Ir;
};


#endif // !IRSTRUCT_H_
