%{
#include "function.h"
#include "MyMap.h"
#include <malloc.h>
#include <string.h>      // strcpy

//#include "lex.h"
#include "SyntaxNode.h"
#include "SyntaxTree.h"
//#include "inherit.h"
//#include <afxtempl.h>
CMAP g_StructNameMap;

//类的层次关系
//typedef CArray<Inherit,Inherit> ClassHier;//这行代码相当于定义了一个数组，数组中的每个元素都是一个Inherit对象
//ClassHier classarray;//定义一个数组用来保存Tempura程序中类定义的继承关系

//******************  用来存储程序语法树以及性质树 *******************************/
/***************************************************************************/
//程序语法树节点指针
CSyntaxNode *g_syntaxTree = NULL;  
//性质语法树节点指针
CSyntaxNode *g_propositionTree=NULL; 

CSyntaxNode *function_tree=NULL, *propositionDefineTree=NULL;

CSyntaxNode *struct_tree=NULL;//存储结构体的定义

CSyntaxTree *g_tree=NULL, *g_proptree=NULL;     

map<string, string> structName; //存储定义的结构体的名字

//g_tree=new CSyntaxTree(g_syntaxTree);  
//g_proptree=new CSyntaxTree(g_propositionTree); 

int g_nErrors=0;

extern void yyerror(const char *msg );

extern int yylex(void);

#define YYDEBUG 1	          // Generate debug code; needed for YYERROR_VERBOSE
#define YYERROR_VERBOSE       // Give a more specific parse error message

%}

%union{
   char     * cString;   /* A character string */
   int       nInteger;   /* An intliteral value */
   float floatval;	/* A float value added by Jane 2012-06-06 */
   char character;	/* A character added by Jane 2012-06-06*/
   CSyntaxNode *tnode;    /* Node in the syntax tree */
   enum NODETYPE  nodetype;
   enum RETURNTYPE  returntype;
} 

%token SWITCH CASE BREAK DEFAULT//add by yubin 2015-3-23
%token IF ELSE EMPTY AWAIT PROJECTION  PBEGIN PEND POINTERNULL ARRAY STRUCT DOT UNION FILEDECLARATION
%token MORE DEFINE MY_TRUE MY_FALSE EXIST FRAME FOR WHILE DO 
%token TRUE FALSE
%token REPEAT UNTIL DISPLAY SKIP THEN COMMA COLON 
%token INTDECLARATION STRDECLARATION POINTERDECLARATION CHARDECLARATION VOIDDECLARATION
%token FLOATDECLARATION LISTDECLARATION           
%token OPEN_PAR CLOSE_PAR TIMES OPEN_BPAR CLOSE_BPAR OPEN_MPAR CLOSE_MPAR FUNCTION
%token OVER CYLINDER
%token OVEREP
%token INTER_OR NON_DETERMINED 
%token SEND RECEIVE PROCESS CHANNEL PUT GET ERROR_TOKEN

%token EXTERN
%token UNSIGNED SIGNED
%left COMMA 
%left CHOP
%left OR PARALLEL CYLINDER
%left AND 
%right ASS_P ASS_N 
%left BOOL_OR
%left INTER_OR	//按位异或	
%left OVEREP	
%left CON   //按位异或
%left ADDRESS //按位与
%left BOOL_AND
%left IMPLY IFF PROPIMPLY
%left NE EQ  
%left GE LE  GT LT 
%left LST RST  //左移右移
%left ADD SUB 
%left MUL DIV MOD 
%left BNE  //按位取反




%nonassoc CHOPSTAR NEXT NEGATION LENGTH REQUEST FINAL KEEP ALWAYS HALT W_NEXT PREFIX /*ADDRESS*/ SOMETIMES 

%token<cString> ID STRLITERAL STRUCT_TYPE
%token<nInteger> INTLITERAL
%token<floatval> FLOATLITERAL 
%token<character> CHARLITERAL 

//-----------%type<cString> idstatement       //Annotation-Class 
//%type<tnode> cylinder_statement over_statement rep_statement fomer_rep_statement
//%type<tnode> option_fomer_rep_statement option_rep_statement

//added for cylinder computing  
//2015-3-7 %type<tnode> CYLINDER_STATEMENT OVER_STATEMENT INTERVAL_STATEMENT
//2015-3-7 %type<tnode> SIG_INTERVAL
 


%type<tnode> type_cast  /*--------cdstatement mdstatement new atrbstatement-----*/ //Annotation-Class   
%type<tnode> statement identifier strliteral intliteral ass_statement  option_exp_else_statement leftaddrshift rightaddrshift
%type<tnode> if_statement option_else_statement while_statement extend_for_statement ass_left imply_pre for_sta_init for_sta_condition for_sta_control
%type<tnode> ari_exp for_statement option_frame_identifier option_projection type_cast_alg_exp
%type<tnode> option_function_parameter_list inner_option_define_identifier
%type<tnode> option_function_identifier inner_option_function_identifier empty_statement
%type<tnode> option_list_value inner_option_list_value option_ari_exp ass_right array_exp array_cast_exp

%type<tnode> declaration option_identifier_array_declaration inner_option_identifier_array_declaration point_exp array option_struct_declaration
%type<tnode> address_exp//added by Jane
%type<tnode> option_array_declaration inner_option_array_declaration//added by Jane

%type<tnode> statement_bpar bool_par option_output option_input output_statement input_statement function//add by yubin 2015/4/15    
%type<tnode> simple_ari_exp  
%type<tnode> charliteral floatliteral 
%type<tnode> struct_define_statement struct_identifier
%type<tnode> option_struct_list_value //结构体的初始化列表{{1,"hello"},{2,"hi"}}
%type<tnode> sign_declaration//带有unsigned的定义语句

//%type<tnode>array_exp option_array_exp 

%type<tnode> casted_element 

//结构体串联
%type<tnode> struct_member_exp  option_struct_member_exp


%type<nodetype>		assign_operator
%type<returntype>  type_define sign_type_define
%type<returntype> all_type_define
%type<tnode> program gComplexProposition complexProposition poptional_projection 
%type<tnode> switch_statement case_par init_case_par //add by yubin 2015-3-23


//%expect 1  /* shift/reduce conflict: dangling ELSE declaration */

%%
program      //Annotation-Class   
       :gComplexProposition /*---cdstatement---*/ statement 
	   {
			
			//验证需要的语句
			g_propositionTree=$1;
			g_proptree=new CSyntaxTree(g_propositionTree);    
			
			
			
			//$2是类中定义的方法，将其加入function_tree中，实质是合并两个链
			//Annotation-Class   2013-5-6 add by YY[fixed]
			/*---------------------------------------------------------------------
			SyntaxTree  temp;
			temp = $2;
			if (temp!=NULL)
			{
					while(temp->GetChild2()!=NULL){ temp=temp->GetChild2(); };
					temp->SetChild2(function_tree);
					function_tree = $2;
			}
			---------------------------------------------------------------------*/

			
			//执行的基本语句
			g_syntaxTree=$2;
			g_tree=new CSyntaxTree(g_syntaxTree);          //2013-5-3 add by YY[fixed]
          
		}
	   ;
//下面是验证条件的语句的语法
gComplexProposition
	   :PBEGIN complexProposition PEND  {$$=$2;}
	   |								{$$=NULL;}
	   ;

complexProposition
	   :complexProposition AND complexProposition   {$$=new CSyntaxNode(AND_EXP, $1, $3, VOIDTYPE);}   
	   |complexProposition OR complexProposition    {$$=new CSyntaxNode(OR_EXP, $1, $3, VOIDTYPE);}    
	   |complexProposition IFF complexProposition   {$$=new CSyntaxNode(IFF_STA, $1, $3, BOOLTYPE);}    
	   |complexProposition PROPIMPLY complexProposition {$$=new CSyntaxNode(IMPLY_STA, $1, $3, VOIDTYPE);}    
	   |complexProposition CHOP complexProposition  
	   {
			if($1==NULL)                            $$=$3;
			else                                    $$=new CSyntaxNode(CHOP_STA, $1, $3, VOIDTYPE);       
	   }
	   |ALWAYS complexProposition					{$$=new CSyntaxNode(ALWAYS_STA, $2, VOIDTYPE);}    
	   |KEEP complexProposition					    {$$=new CSyntaxNode(KEEP_STA, $2, VOIDTYPE);}     
	   |SOMETIMES complexProposition				{$$=new CSyntaxNode(SOMETIMES_STA, $2, VOIDTYPE);}
	   |W_NEXT complexProposition					{$$=new CSyntaxNode(W_NEXT_STA, $2, VOIDTYPE);}    
	   |NEXT complexProposition			            {$$=new CSyntaxNode(NEXT_STA, $2, VOIDTYPE);}     
	   |SKIP										{$$=new CSyntaxNode(SKIP_STA, VOIDTYPE);}         
	   |MY_TRUE										{$$=new CSyntaxNode(TRUE_EXP, VOIDTYPE);}       
	   |MY_FALSE									{$$=new CSyntaxNode(FALSE_EXP, VOIDTYPE);}         
	   |LENGTH ari_exp								{$$=new CSyntaxNode(LENGTH_STA, $2, VOIDTYPE);}   
	   
	   
	   
//2015-3-9	   |LENGTH intliteral							    {$$=new CSyntaxNode(LENGTH_STA, $2, VOIDTYPE);}   
	   |EMPTY										{$$=new CSyntaxNode(EMPTY_EXP, VOIDTYPE);}      
	   |MORE										{$$=new CSyntaxNode(MORE_STA, VOIDTYPE);}        
	   |HALT complexProposition                     {$$=new CSyntaxNode(HALT_STA, $2, VOIDTYPE);}  
	   |FINAL complexProposition                    {$$=new CSyntaxNode(FINAL_STA, $2, VOIDTYPE);}   
	   |NEGATION complexProposition                 {$$=new CSyntaxNode(NEGATION_EXP, $2, VOIDTYPE);}  
	   |OPEN_BPAR complexProposition poptional_projection CLOSE_BPAR PROJECTION OPEN_BPAR complexProposition CLOSE_BPAR
	   {
			$$=new CSyntaxNode(PROJECTION_STA, $2, $3, $7, VOIDTYPE);                         
	   }
	   |ID 											{$$=new CSyntaxNode(IDENT_EXP, $1, NULL, VOIDTYPE)}     //{$$=new CSyntaxNode(IDENT_EXP, $1, 0);}  
	   |DEFINE ID COLON ari_exp             
	   {
			$$=NULL;
			propositionDefineTree=new CSyntaxNode(FUNCTION_DEFINE_STA, $2, $4, propositionDefineTree, NULL, VOIDTYPE);			
	   }
       |complexProposition  CHOPSTAR  {$$=new CSyntaxNode(CHOPSTAR_STA, $1, VOIDTYPE);}   //{$$=new CSyntaxNode(CHOPSTAR_STA, "", 0, $1);}
	   |OPEN_PAR complexProposition CLOSE_PAR       {$$=$2;}
	   ;

poptional_projection
	   :COMMA complexProposition poptional_projection               
	   {
			$$ = new CSyntaxNode(PROJECTION_STA, $2, $3, VOIDTYPE);                      //$$ = new CSyntaxNode(PROJECTION_STA, "", 0, $2, $3);
	   }
	   |								{$$=NULL;}
	   ;

//下面是可执行基本语句的语法
statement
	   :statement  AND statement        {$$=new CSyntaxNode(AND_EXP, $1, $3, VOIDTYPE);}

	   |statement  OR  statement        {$$=new CSyntaxNode(OR_EXP, $1, $3, VOIDTYPE);}
	   
	   //**********************************************************************************
	   //   把函数声明语句放到function_tree中进行存储  
	   //   按照原始的定义，函数的声明确实要在最开始进行 
	   //   我添加了下面一块代码 使得的函数可以在任何地方声明
	   //**********************************************************************************
	   |statement CHOP statement        
	   {
			//结构体(struct)定义 暂时规定struct只能在最开始定义
			
			// 两个都是struct定义语句
			if(NULL!=$1 && $1->GetNType()==STRUCT_DEFINE_STA && NULL!=$3 && $3->GetNType()==STRUCT_DEFINE_STA)
			{
			    if($1->FindSameName($3->GetNName()) )
					{  yyerror("Structs have the same name");
					   $$=$1;
					}
				else 
				    {
					  $3->SetChild1($1);
					  $$=$3;
					}
			}
			// 第一个是struct定义语句，第二个是执行语句
			if(NULL!=$1 && $1->GetNType()==STRUCT_DEFINE_STA && NULL!=$3 && $3->GetNType()!=STRUCT_DEFINE_STA )
			{
				struct_tree=$1;
				$$=$3;
			}
			// 第一个是执行语句，第二个是struct定义语句
			if( NULL!=$1 && $1->GetNType()!=STRUCT_DEFINE_STA  && $1->GetNType()!=FUNCTION_DEFINE_STA &&  
			    NULL!=$3 && $3->GetNType()==STRUCT_DEFINE_STA)
			{
				        if(NULL==struct_tree) 
						{
							struct_tree=$3;
						}
					    else 
						{
							if(struct_tree->FindSameName($3->GetNName()))
							{  
									yyerror("Structs have the same name"); 
								    $$=$1;  
							}
							else
							{
								$3->SetChild1(struct_tree);
								struct_tree=$3;
																
								/*CSyntaxNode* p = struct_tree;
								while(p->GetChild1()!=NULL)
								p=p->GetChild1();
								p->SetChild1($3);
								$$=$1;*/
							}
						}					
			}
			
			//两个都是函数声明语句
			if(NULL!=$1 && $1->GetNType()==FUNCTION_DEFINE_STA && NULL!=$3 && $3->GetNType()==FUNCTION_DEFINE_STA )
			{
				if($1->FindSameName($3->GetNName()) )
					{  yyerror("Functions or predicates have the same name");
					   $$=$1;
					}
				else 
				    {
					  $3->SetChild2($1);
					  $$=$3;
					}
			}
			//第一个是函数声明语句，第二个是执行语句
			if(NULL!=$1 && $1->GetNType()==FUNCTION_DEFINE_STA && NULL!=$3 && $3->GetNType()!=FUNCTION_DEFINE_STA)
			{
				function_tree=$1;
                $$=$3;
			}

			//两个都是执行语句
			if( NULL!=$1 && $1->GetNType()!=FUNCTION_DEFINE_STA &&  $1->GetNType()!=STRUCT_DEFINE_STA && 
			    NULL!=$3 && $3->GetNType()!=FUNCTION_DEFINE_STA &&  $3->GetNType()!=STRUCT_DEFINE_STA)
			{
				$$=new CSyntaxNode(CHOP_STA, $1, $3, VOIDTYPE);
			}

			//第一个是执行语句，第二个是声明语句  
			//problem: 整个程序的第一句必须是声明语句才可以    
			if( NULL!=$1 && $1->GetNType()!=FUNCTION_DEFINE_STA   &&  $1->GetNType()!=STRUCT_DEFINE_STA &&
			    NULL!=$3 && $3->GetNType()==FUNCTION_DEFINE_STA)
				{
				        if(NULL==function_tree) 
						{
							function_tree=$3;
						}
					    else 
						{
							if(function_tree->FindSameName($3->GetNName()))
							{  
									yyerror("Functions or predicates have the same name"); 
								    $$=$1;  
							}
							else
							{
								CSyntaxNode* p = function_tree;
								while(p->GetChild2()!=NULL)
								p=p->GetChild2();
								p->SetChild2($3);
								$$=$1;
							}
						}
					
				}								
	   }
	   
	  // |PREFIX OPEN_PAR statement CLOSE_PAR   {$$=new CSyntaxNode(PREFIX_STA, $3, VOIDTYPE);}
       |ass_statement                   {$$=$1;}
	   |sign_declaration                    {$$=$1;}
	   
	   |switch_statement              {$$=$1;}   //add 2015-3-18
	   |if_statement                    {$$=$1;}
	   |while_statement                 {$$=$1;}
	   |for_statement                   {$$=$1;}
	   |extend_for_statement            {$$=$1;}//类似于C语言中的for语句
	   |NEXT OPEN_PAR statement CLOSE_PAR    {$$=new CSyntaxNode(NEXT_STA, $3, VOIDTYPE);}
//2015-3-7	   |W_NEXT OPEN_PAR statement CLOSE_PAR    {$$=new CSyntaxNode(W_NEXT_STA, $3, VOIDTYPE);}
	   |KEEP OPEN_PAR statement CLOSE_PAR       {$$=new CSyntaxNode(KEEP_STA, $3, VOIDTYPE);}
	   |ALWAYS OPEN_PAR statement CLOSE_PAR      {$$=new CSyntaxNode(ALWAYS_STA, $3, VOIDTYPE);}
//2015-3-7	   |HALT OPEN_PAR ari_exp CLOSE_PAR   {$$=new CSyntaxNode(HALT_STA, $3, VOIDTYPE);}
	   |AWAIT OPEN_PAR ari_exp CLOSE_PAR  {$$=new CSyntaxNode(AWAIT_STA, $3, VOIDTYPE);}
	   |REPEAT OPEN_BPAR statement CLOSE_BPAR UNTIL OPEN_PAR ari_exp CLOSE_PAR  {$$=new CSyntaxNode(REPEAT_UNTIL_STA, $3, $7, VOIDTYPE);}
	   |SKIP                            {$$=new CSyntaxNode(SKIP_STA, VOIDTYPE);}
       |EMPTY                           {$$=new CSyntaxNode(EMPTY_EXP, VOIDTYPE);}
	   |MORE                            {$$=new CSyntaxNode(MORE_STA, VOIDTYPE);}
	   |LENGTH OPEN_PAR ari_exp CLOSE_PAR   {$$=new CSyntaxNode(LENGTH_STA, $3, VOIDTYPE);}
//2013-5-7 
//	   
//	   |LENGTH OPEN_PAR intliteral CLOSE_PAR  {$$=new CSyntaxNode(LENGTH_STA, $3, VOIDTYPE);}
//annotated by YY 2013/06/17 16:20
///	   |REQUEST OPEN_PAR identifier CLOSE_PAR             {$$=new CSyntaxNode(REQUEST_STA, $3, VOIDTYPE);}
	   |input_statement               {$$=$1;}
	   |output_statement               {$$=$1;}
	   |TRUE                         {$$=new CSyntaxNode(TRUE_EXP, VOIDTYPE);}         //2015-3-7
	   |FALSE                        {$$=new CSyntaxNode(FALSE_EXP, VOIDTYPE);}        //2015-3-7
	   |FINAL OPEN_PAR statement CLOSE_PAR   {$$=new CSyntaxNode(FINAL_STA, $3, VOIDTYPE);}
	   | statement PARALLEL  statement  	{$$=new CSyntaxNode(PARALLEL_STA, $1, $3, VOIDTYPE);}

	   |OPEN_PAR imply_pre CLOSE_PAR IMPLY OPEN_MPAR statement CLOSE_MPAR       
			{$$=new CSyntaxNode(IMPLY_STA, $2, $6, VOIDTYPE);}     	   	   
	   
	   |FRAME OPEN_PAR identifier option_frame_identifier CLOSE_PAR AND OPEN_PAR statement CLOSE_PAR
	   {
			$$=new CSyntaxNode(FRAME_STA, $3, $4, $8, VOIDTYPE);
	   }

//prj 
	   |OPEN_BPAR statement option_projection CLOSE_BPAR PROJECTION statement_bpar
	   {
			$$=new CSyntaxNode(PROJECTION_STA, $2, $3, $6,VOIDTYPE);
	   }
	   |OPEN_BPAR statement CLOSE_BPAR PROJECTION statement_bpar
	   {
			$$=new CSyntaxNode(PROJECTION_STA, $2, NULL, $5, VOIDTYPE);
	   }

	   	   
	  |FUNCTION ID OPEN_PAR option_function_parameter_list CLOSE_PAR  OPEN_BPAR statement CLOSE_BPAR//2015-4-13,于斌修改
	   {
			$$=new CSyntaxNode(FUNCTION_DEFINE_STA, $2, $4, $7, NULL, VOIDTYPE);
	   }

	   //***********************************************************************
	      //无返回值的函数调用      过程！！！！！  
	   //***********************************************************************
	   |DEFINE ID OPEN_PAR option_function_parameter_list CLOSE_PAR ASS_P OPEN_BPAR empty_statement CLOSE_BPAR 
	   { 
			$$=new CSyntaxNode(FUNCTION_DEFINE_STA , $2, $4, $8, NULL, VOIDTYPE);
	   }
	   
	   //*******************************************************************************************
	       //有返回值的函数调用function, 函数体为可以赋值的算术式
		      
	   //*******************************************************************************************
	    
       |struct_define_statement//结构体定义语句
	   
	   |function                         {$$=$1;}
//	   |new                              {$$=$1;}    //Annotation-Class   
	   |EXIST identifier inner_option_define_identifier COLON OPEN_BPAR statement CLOSE_BPAR
	   {
			CSyntaxNode * p;
//			$6->par_change($2->m_NodeName, LOCAL_IDENT_EXP);
			p=$3;

			while(p!=NULL)
			{
//				$6->par_change(p->GetChild0()->GetNName(), LOCAL_IDENT_EXP);
				p=p->GetChild0();
			}

			$$=new CSyntaxNode(EXIST_STA, $2, $3, $6,VOIDTYPE);
	   }
	   |OPEN_PAR statement CLOSE_PAR    {$$=$2;}
//2015-3-7	   |CYLINDER_STATEMENT				{$$=$1;} 
	   ;
option_struct_declaration
       :sign_declaration 
	   {
	      $$=$1;
		}
      |sign_declaration AND option_struct_declaration
		{
		   $$=new CSyntaxNode(AND_EXP,$1,$3,VOIDTYPE);
		}
        ;

empty_statement
	   :statement                       {$$=$1;}
	   |                                {$$=NULL;}
	   ;

//调用谓词和函数时的语法
function
       :ID OPEN_PAR option_function_identifier CLOSE_PAR
	   {
	        // 暂时不考虑带成员函数 .的函数调用
			$$=new CSyntaxNode(FUNCTION_STA, $1, $3, NULL, NULL, VOIDTYPE);//构造调用函数的程序语法树子树          
	   }
	   |EXTERN ID OPEN_PAR option_function_identifier CLOSE_PAR
	   {
	        // 暂时不考虑带成员函数 .的函数调用
			$$=new CSyntaxNode(EXT_FUNCTION_STA, $2, $4, NULL, NULL, VOIDTYPE);//构造调用函数的程序语法树子树          
	   }
	   |array OPEN_PAR option_function_identifier CLOSE_PAR
	   {
	        //Annotate by YY 2013/11/20 暂时不考虑带成员函数 .的函数调用
			$$=new CSyntaxNode(FUNCTION_STA, $1, $3, NULL, FUNCPTYPE);//通过函数指针数组调用函数
	   }
	   ;


struct_define_statement
       :struct_identifier OPEN_BPAR option_struct_declaration CLOSE_BPAR 
	   {
           CSyntaxNode* temp=$1;
		   string structName=temp->GetNName();
           $$=new CSyntaxNode(STRUCT_DEFINE_STA, structName, $3, VOIDTYPE);
	   }
       ;
struct_identifier
       :STRUCT ID 
	   {
			if(!g_StructNameMap.insert($2))
			{
			    yyerror("Redefinition of struct");
			}
			else
			{
			    $$=new CSyntaxNode(STRUCT_NAME, $2, STRUCT_NAME_TYPE);
			}
	   }
       |UNION  ID 
	   {
	       if(!g_StructNameMap.insert($2))
			{
			    yyerror("Redefinition of union");
			}
			else
			{
			    $$=new CSyntaxNode(STRUCT_NAME, $2, STRUCT_NAME_TYPE);
			}
	   }
	   ;
//处理unsigned和signed的问题，最终的定义语句
sign_declaration
	   :SIGNED declaration   {$$=$2;} //默认为signed
	   |UNSIGNED declaration {$$=new CSyntaxNode(UNSIGN_DECLARATION_STA, $2, VOIDTYPE); }
	   |declaration          {$$=$1;}
	   ;

declaration
	   :type_define  option_identifier_array_declaration	
	   {
	      $$=new CSyntaxNode(DECLARE_STA, $2, $1);
		}
       |STRUCT_TYPE option_identifier_array_declaration 	 
	   {
	     $$=new CSyntaxNode(DECLARE_STA,$1,$2,STRUCTTYPE);
		} //结构体声明 yangkai
	   |STRUCT ID option_identifier_array_declaration
	   {
	     $$=new CSyntaxNode(DECLARE_STA,$2,$3,STRUCTTYPE);
	   }//结构体声明
       |UNION ID option_identifier_array_declaration
	   {
	     $$=new CSyntaxNode(DECLARE_STA,$2,$3,STRUCTTYPE);
	   }//联合体声明
	   |STRUCT STRUCT_TYPE option_identifier_array_declaration
	   {
	     $$=new CSyntaxNode(DECLARE_STA,$2,$3,STRUCTTYPE);
	   }//结构体声明
       |UNION STRUCT_TYPE option_identifier_array_declaration
	   {
	     $$=new CSyntaxNode(DECLARE_STA,$2,$3,STRUCTTYPE);
	   }//联合体声明
	//2015-3-20    |POINTERDECLARATION   option_function_parameter_list {$$=new CSyntaxNode(DECLARE_STA, $2, POINTERTYPE);}  
	  //2015-3-20 |LISTDECLARATION   option_array_declaration		{$$=new CSyntaxNode(DECLARE_STA, $2, LISTTYPE);}
	    // 函数指针 
	   |OPEN_PAR MUL identifier CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR	{$$=new CSyntaxNode(DECLARE_STA, $3, FUNCPTYPE);}
	   //函数指针的指针
	   |OPEN_PAR MUL MUL identifier CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR {$$=new CSyntaxNode(DECLARE_STA, $4, FUNCPPTYPE);}
	   	//函数指针数组 
	   |OPEN_PAR MUL ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR	
	   {
	       CSyntaxNode *pChild0=new CSyntaxNode(PARAMETER_EXP,new CSyntaxNode(ARRAY_DECLARE_STA, $3, $5, $6, NULL, LISTTYPE), VOIDTYPE);
	       $$=new CSyntaxNode(DECLARE_STA, pChild0, FUNCPTYPE);
	   }
       |OPEN_PAR MUL ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR ASS_P array_exp
	   {
	       CSyntaxNode *pChild0_Child0=new CSyntaxNode(ARRAY_DECLARE_STA, $3, $5, $6, NULL, LISTTYPE);
		   CSyntaxNode *pChild0=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, pChild0_Child0, $13, VOIDTYPE), VOIDTYPE);
		   $$=new CSyntaxNode(DECLARE_STA, pChild0, FUNCPTYPE);
		   pChild0=NULL;
		   pChild0_Child0=NULL;
	   }
	   ;


type_define
		:INTDECLARATION					{$$=INTTYPE;}
		|FLOATDECLARATION				{$$=FLOATTYPE;}
		|CHARDECLARATION				{$$=CHARTYPE;}
//		|UNSIGNED INTDECLARATION        {$$=UINTTYPE;}
//	    |UNSIGNED CHARDECLARATION       {$$=UCHARTYPE;}
		|STRDECLARATION					{$$=STRTYPE;}
		|VOIDDECLARATION                {$$=VOIDTYPE;}
		|FILEDECLARATION    			{$$=FILETYPE;} 
		;



//将option_declaration改为option_identifier_array_declaration      
option_identifier_array_declaration
		:identifier inner_option_identifier_array_declaration
		{
		   $$=new CSyntaxNode(PARAMETER_EXP, $1, $2, VOIDTYPE);
		}
	    |ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR inner_option_identifier_array_declaration
		{
	       $$=new CSyntaxNode(PARAMETER_EXP,new CSyntaxNode(ARRAY_DECLARE_STA, $1, $3, $4, NULL, LISTTYPE), $6, VOIDTYPE);
		}
	    |identifier ASS_P ass_right inner_option_identifier_array_declaration
		{
		   $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, $1, $3, VOIDTYPE), $4, VOIDTYPE);
		}
		// int a[]<==[1,2,3]
		|ID ARRAY ASS_P array_exp inner_option_identifier_array_declaration
		{
		   $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, new CSyntaxNode(ARRAY_DECLARE_NULL_STA, $1, NULL, NULL, NULL, LISTTYPE), $4, VOIDTYPE), $5, VOIDTYPE);
		}
		
		// char a[]<=="hallo"
		|ID ARRAY ASS_P strliteral inner_option_identifier_array_declaration
		{
		   $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, new CSyntaxNode(ARRAY_DECLARE_NULL_STA, $1, NULL, NULL, NULL, LISTTYPE), $4, VOIDTYPE), $5, VOIDTYPE);
		}
		// int a[3]<==[1,2,3]   char a[2,6]<==["he","she"]
	    |ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR ASS_P array_exp inner_option_identifier_array_declaration
		{
	       CSyntaxNode *pChild0=new CSyntaxNode(ARRAY_DECLARE_STA, $1, $3, $4, NULL, LISTTYPE);
		   $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, pChild0, $7, VOIDTYPE), $8, VOIDTYPE);
		   pChild0=NULL;
	    } 
	   // a[3]<=="ni";
	   |ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR ASS_P strliteral inner_option_identifier_array_declaration
	   {
	       CSyntaxNode *pChild0=new CSyntaxNode(ARRAY_DECLARE_STA, $1, $3, $4, NULL, LISTTYPE);
		   $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(ASS_EQU_EXP, pChild0, $7, VOIDTYPE), $8, VOIDTYPE);
		   pChild0=NULL;
	   }
	   |MUL option_identifier_array_declaration
	   {
	      CSyntaxNode* pChild0=new CSyntaxNode(ADDRESS_DECLARE_STA,$2->GetChild0(),VOIDTYPE);
          $$=$2;
		  $2->SetChild0(pChild0);
		  pChild0=NULL;
	   }
	   ;


inner_option_identifier_array_declaration
	   :COMMA option_identifier_array_declaration
	                  {$$=$2;}
	   |COMMA error   {$$=NULL;}
	   |{$$=NULL;}
	   ;
//将list_option_declaration修改为option_array_declaration 
option_array_declaration
	   :ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR inner_option_array_declaration
	   {
	        $$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(LIST_DECLARE_STA, $1, $3, $4, NULL, LISTTYPE), $6, VOIDTYPE);
	   }
	   ;
//将list_inner_option_declaration修改为inner_option_array_declaration
inner_option_array_declaration
	   :COMMA ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR inner_option_array_declaration
	   {
			$$=new CSyntaxNode(PARAMETER_EXP, new CSyntaxNode(LIST_DECLARE_STA, $2, $4, $5, NULL, LISTTYPE), $7, VOIDTYPE);
	   }
	   | /* empty */                    {$$=NULL;}
	   |COMMA error                     {$$=NULL;}
	   ;

//变量类型声明 end Jane

//变赋值语句  

ass_statement
       :ass_left assign_operator ass_right       
									{$$=new CSyntaxNode($2, $1, $3, VOIDTYPE);}	
	   ;
ass_left
       :identifier                      {$$=$1;}
	   |struct_member_exp               {$$=$1;}	   
       |array                            {$$=$1;}   //a[2,3,4]  
	   |point_exp                       {$$=$1;}
	   |OPEN_PAR ass_left CLOSE_PAR    {$$=$2;}
	   |NEXT ass_left                  {$$=new CSyntaxNode(NEXT_STA, $2, UNKNOWNTYPE);} 
	   |leftaddrshift                   {$$=$1;}  
	   ;
leftaddrshift
	   :OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $6, $9, $10, NULL, CHARTYPE);}   //((char*)0x01)[2]=5
	   |OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $7, $10, $11, NULL, UCHARTYPE);}   //((unsigned char*)0x01)[2]=5
	   |OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $6, $9, $10, NULL, INTTYPE);}   //((int*)0x01)[2]=5
	   |OPEN_PAR OPEN_PAR FLOATDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $6, $9, $10, NULL, FLOATTYPE);}   //((float*)0x01)[2]=5
	   |OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $11, $15, $16, NULL, CHARTYPE);}   //((char*)((char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $12, $16, $17, NULL, CHARTYPE);}   //((char*)((unsigned char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $11, $15, $16, NULL, CHARTYPE);}   // ((char*)((int*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $12, $16, $17, NULL, UCHARTYPE);}   //((unsigned char*)((char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $13, $17, $18, NULL, UCHARTYPE);}   //((unsigned char*)((unsigned char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $12, $16, $17, NULL, UCHARTYPE);}   //((unsigned char*)((int*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $11, $15, $16, NULL, INTTYPE);}   //((int*)((char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $12, $16, $17, NULL, INTTYPE);}   // ((int*)((unsigned char*)0x01))[2]=5
	   |OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR INTLITERAL CLOSE_PAR CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR		
	  								{$$=new CSyntaxNode(ADDR_VAR_LIST, $11, $15, $16, NULL, INTTYPE);}   // ((int*)((int*)0x01))[2]=5
		;

assign_operator
	   :ASS_P                         {$$=ASS_EQU_EXP;}    // <==
	   |ASS_N      {$$=UNITASSIGN_EXP;}   // :=
	   ;                
ass_right
	   :ari_exp                         {$$=$1;}
	   |array_exp                        {$$=$1;}   // [2,3,5,9] 或者[1,3]^[2,4]
	   |OPEN_PAR strliteral CLOSE_PAR OPEN_PAR type_define CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR function {$$=new CSyntaxNode(DLL_CALL_STA, $2, $10, $5);}
	   |OPEN_PAR ass_right CLOSE_PAR      {$$=$2;} 
	   |rightaddrshift                  {$$=$1;}
	   ;
rightaddrshift
       :MUL OPEN_PAR leftaddrshift CLOSE_PAR {$$=$3;}
	   ;

array  
       :ID OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR  {$$=new CSyntaxNode(LIST_SYMBOL_STA, $1, $3, $4, NULL, VOIDTYPE);}
	   | OPEN_PAR array CLOSE_PAR   {$$=$2;}
	   ;
array_cast_exp
       // 增加((unsigned char*)a)[2]='b',可作为左值或者右值
       :OPEN_PAR OPEN_PAR INTDECLARATION MUL CLOSE_PAR identifier CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR 
	   {
		   CSyntaxNode* child0=new CSyntaxNode(TYPE_CAST_STA, $6, INTPTYPE);
		   $$=new CSyntaxNode(ARRAY_CAST_EXP, child0, $9, $10, VOIDTYPE);
	   }  
	   | OPEN_PAR OPEN_PAR UNSIGNED INTDECLARATION MUL CLOSE_PAR identifier CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR 
	   {
		   CSyntaxNode* child0=new CSyntaxNode(TYPE_CAST_STA, $7, UINTPTYPE);
		   $$=new CSyntaxNode(ARRAY_CAST_EXP, child0, $10, $11, VOIDTYPE);
	   }  
	   | OPEN_PAR OPEN_PAR FLOATDECLARATION MUL CLOSE_PAR identifier CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR  
	   {
		   CSyntaxNode* child0=new CSyntaxNode(TYPE_CAST_STA, $6,FLOATPTYPE);
		   $$=new CSyntaxNode(ARRAY_CAST_EXP, child0, $9, $10, VOIDTYPE);
	   }  
	   | OPEN_PAR OPEN_PAR CHARDECLARATION MUL CLOSE_PAR identifier CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR 
	   {
		   CSyntaxNode* child0=new CSyntaxNode(TYPE_CAST_STA, $6,CHARPTYPE);
		   $$=new CSyntaxNode(ARRAY_CAST_EXP, child0, $9, $10, VOIDTYPE);
	   } 
	   | OPEN_PAR OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR identifier CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR 
	   {
		   CSyntaxNode* child0=new CSyntaxNode(TYPE_CAST_STA, $7, UCHARPTYPE);
		   $$=new CSyntaxNode(ARRAY_CAST_EXP, child0, $10, $11, VOIDTYPE);
	   }
	   | OPEN_PAR array_cast_exp CLOSE_PAR
	   { 
	      $$=$2
	   } 

option_ari_exp
	   :COMMA ari_exp option_ari_exp
	                                    {$$=new CSyntaxNode(LIST_SUBSCRIPT_EXP, $2, $3, VOIDTYPE);}
	   |COMMA error                     {$$=NULL;}
	   | /* empty */                    {$$=NULL;}
	   ;


//实际上是指针（*p）
point_exp
	   :MUL identifier                  {$$=new CSyntaxNode(VALUE_EXP, $2, UNKNOWNTYPE);}    //*x
	   |MUL point_exp 					{$$=new CSyntaxNode(VALUE_EXP, $2, UNKNOWNTYPE);}    //**x
	   |MUL array                              //*a[2]
									    {$$=new CSyntaxNode(VALUE_EXP, $2,  UNKNOWNTYPE);} //add by wm 2013/10/28
	   |OPEN_PAR point_exp CLOSE_PAR OPEN_MPAR ari_exp option_ari_exp CLOSE_MPAR                     //(*a)[2]
									    {$$=new CSyntaxNode(VALUE_LIST_EXP, $2, $5, $6, UNKNOWNTYPE);}
	   |MUL OPEN_PAR all_type_define MUL CLOSE_PAR ari_exp
	   		{$$=new CSyntaxNode(ADDR_VAR, $6, $3);} //  *(char*)0x01=5
	   |MUL OPEN_PAR ari_exp CLOSE_PAR	                                    
	        {$$=new CSyntaxNode(VALUE_EXP, $3, UNKNOWNTYPE);}
	   |OPEN_PAR point_exp CLOSE_PAR    {$$=$2;}   // 使得a<==(*p)+
	   //|MUL error                       {$$=NULL;}
       ;

//算术表达式
ari_exp     
	   :simple_ari_exp  {$$=$1;}
	   ///算术表达式
	   |ari_exp ADD ari_exp  {$$=new CSyntaxNode(ADD_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp SUB ari_exp  {$$=new CSyntaxNode(SUB_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp MUL ari_exp  {$$=new CSyntaxNode(MUL_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp DIV ari_exp  {$$=new CSyntaxNode(DIV_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp MOD ari_exp  {$$=new CSyntaxNode(MOD_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp LST ari_exp  {$$=new CSyntaxNode(LST_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp RST ari_exp  {$$=new CSyntaxNode(RST_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp ADDRESS ari_exp  {$$=new CSyntaxNode(BAN_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp INTER_OR ari_exp  {$$=new CSyntaxNode(BOR_EXP, $1, $3, ARITHMETICTYPE);}
	   |ari_exp CON ari_exp  {$$=new CSyntaxNode(XOR_EXP, $1, $3, ARITHMETICTYPE);}
	   |IF ari_exp THEN  ari_exp option_exp_else_statement { $$ = new CSyntaxNode(IF_ELSE_EXP, $2, $4, $5, ARITHMETICTYPE);}   
	   ///bool 表达式
	   |ari_exp GT ari_exp     { $$=new CSyntaxNode(GT_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp GE ari_exp     { $$=new CSyntaxNode(GE_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp LE ari_exp     { $$=new CSyntaxNode(LE_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp NE ari_exp     { $$=new CSyntaxNode(NE_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp LT ari_exp     { $$=new CSyntaxNode(LT_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp EQ ari_exp     { $$=new CSyntaxNode(EQU_EXP, $1, $3, BOOLTYPE);}
	   |ari_exp BOOL_AND ari_exp{ $$=new CSyntaxNode(AND_EXP, $1, $3, BOOLTYPE);   }
	   |ari_exp BOOL_OR ari_exp {$$=new CSyntaxNode(OR_EXP, $1, $3, BOOLTYPE);}
	   |NEGATION ari_exp {$$=new CSyntaxNode(NEGATION_EXP, $2, BOOLTYPE);} 	   	  
	   ;

type_cast_alg_exp
       :simple_ari_exp                  {$$=$1;}	   
	   ;

option_exp_else_statement
       : ELSE ari_exp					                   {$$=$2;}
       | /* empty */                                       {$$=NULL;}
       ;


simple_ari_exp
       :intliteral                      {$$=$1;}
	   |charliteral						{$$=$1;}
	   |floatliteral					{$$=$1;} 
	   |strliteral                      {$$=$1;}
	   |identifier						{$$=$1;}
	   |array                           {$$=$1;}
	   |point_exp                       {$$=$1;}
	   |function                        {$$=$1;} 
	   |address_exp						{$$=$1;} // 初始化指针数组用到	   
	   |type_cast                       {$$=$1;} // 强制转换可以参与算数运算	  	   	   
	   |struct_member_exp               {$$=$1;} // 结构体串联
	   |array_cast_exp                  {$$=$1;}
	   |SUB simple_ari_exp				{$$=new CSyntaxNode(MINUS_EXP, $2, ARITHMETICTYPE);}
	   |BNE simple_ari_exp               {$$=new CSyntaxNode(BNE_EXP, $2, ARITHMETICTYPE);}
	   |POINTERNULL                     {$$=new CSyntaxNode(NULL_EXP, VOIDTYPE);} 
	   |MY_TRUE                         {$$=new CSyntaxNode(TRUE_EXP, BOOLTYPE);}
	   |MY_FALSE                        {$$=new CSyntaxNode(FALSE_EXP, BOOLTYPE);}
	   |OPEN_PAR ari_exp CLOSE_PAR      {$$=$2;}  	 
	   ;

	  

array_exp
	   :array_exp CON array_exp           {$$=new CSyntaxNode(CON_EXP, $1, $3, LISTTYPE);}
	   |option_list_value               {$$=$1;}   // [2,3,5,9]
	   |option_struct_list_value         {$$=$1;}   // {1,'C',"HELLO"}
	   |OPEN_PAR array_exp CLOSE_PAR     {$$=$2;}
	   ;


//可能是对于数组赋值[1,2,4]的形式  【int float str char array】 
option_list_value
	   :OPEN_MPAR ari_exp inner_option_list_value CLOSE_MPAR
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
		}	
	   |OPEN_MPAR strliteral inner_option_list_value CLOSE_MPAR
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
	   }
	   |OPEN_MPAR array_exp inner_option_list_value CLOSE_MPAR
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
	   }
	   ;     

// 结构体的初始化列表{{1,"hello"},{2,"hi"}}
option_struct_list_value
	   :OPEN_BPAR ari_exp inner_option_list_value CLOSE_BPAR
	   {
			$$ = new CSyntaxNode(STRUCT_LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
		}	
	   |OPEN_BPAR array_exp inner_option_list_value CLOSE_BPAR
	   {
			$$ = new CSyntaxNode(STRUCT_LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
	   }
	   /*|OPEN_BPAR CLOSE_BPAR / * empty * /				   
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, LISTTYPE);
   	   }*/
	   ;  

//此处含有STR_EXP,CHARLITERAL_EXP的不同含义定义 返回值类型为LISTTYPE 
inner_option_list_value
	   :COMMA ari_exp inner_option_list_value
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);//INTEGER_EXP Jane
	   }
	   |COMMA strliteral inner_option_list_value
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
	   }
	   |COMMA array_exp inner_option_list_value
	   {
			$$ = new CSyntaxNode(LIST_ASSVALUE_STA, $2, $3, LISTTYPE);
	   }
	   | /* emtpy */									   {$$=NULL;}
	   |COMMA error                                        {$$=NULL;}
	   ;
 
address_exp:	 
            ADDRESS identifier	
			{
			   $$=new CSyntaxNode(ADDRESS_EXP, $2, VOIDTYPE);
			}
            |ADDRESS array
			{
			   $$=new CSyntaxNode(ADDRESS_EXP, $2, VOIDTYPE);
			}
            |ADDRESS struct_member_exp
			{
			   $$=new CSyntaxNode(ADDRESS_EXP, $2, VOIDTYPE );
			}
			//add by YY 2013/11/28 多重地址引用暂时不考虑
		    |ADDRESS address_exp 
			{
			   $$=new CSyntaxNode(ADDRESS_EXP, $2, VOIDTYPE);
			}
			|OPEN_PAR address_exp CLOSE_PAR  {$$=$2;}   //add by YY 2014/01/17
			;

 


//加入强制类型转换语句 
type_cast:
			//add by YY 2014/01/07 10:57 强制转换 (int) (float) (char)		
		      OPEN_PAR INTDECLARATION CLOSE_PAR type_cast_alg_exp     {$$=new CSyntaxNode(TYPE_CAST_STA, $4, INTTYPE);}      //char->int   float->int   
			| OPEN_PAR FLOATDECLARATION CLOSE_PAR type_cast_alg_exp {$$=new CSyntaxNode(TYPE_CAST_STA, $4, FLOATTYPE);}    //int->float   //char->float  
			| OPEN_PAR CHARDECLARATION CLOSE_PAR type_cast_alg_exp   {$$=new CSyntaxNode(TYPE_CAST_STA, $4, CHARTYPE);}     //int->char float->char
			
			//add by YY 2014/01/07 10:57 强制转换 (signed int) (signed char)	
			| OPEN_PAR SIGNED INTDECLARATION CLOSE_PAR type_cast_alg_exp     {$$=new CSyntaxNode(TYPE_CAST_STA, $5, INTTYPE);}      //char->int   float->int   
			| OPEN_PAR SIGNED CHARDECLARATION CLOSE_PAR type_cast_alg_exp   {$$=new CSyntaxNode(TYPE_CAST_STA, $5, CHARTYPE);}     //int->char float->char
			
			//add by YY 2014/01/07 10:57 强制转换 (unsigned int) (unsigned char)		
			| OPEN_PAR UNSIGNED INTDECLARATION CLOSE_PAR type_cast_alg_exp     {$$=new CSyntaxNode(TYPE_CAST_STA, $5, UINTTYPE);}      //char->int   float->int  
			| OPEN_PAR UNSIGNED CHARDECLARATION CLOSE_PAR type_cast_alg_exp   {$$=new CSyntaxNode(TYPE_CAST_STA, $5, UCHARTYPE);}     //int->char float->char						
			
			//add by YY 2014/01/07 10:57 强制转换 (int*) (unsigned int*) (float*) (char*) (unsigned char*)			
			| OPEN_PAR INTDECLARATION MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $5, INTPTYPE);}  
			| OPEN_PAR UNSIGNED INTDECLARATION MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $6, UINTPTYPE);}  
			| OPEN_PAR FLOATDECLARATION MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $5, FLOATPTYPE);}  
			| OPEN_PAR CHARDECLARATION MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $5, CHARPTYPE);}  
			| OPEN_PAR UNSIGNED CHARDECLARATION MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $6, UCHARPTYPE);}   
			| OPEN_PAR VOIDDECLARATION MUL CLOSE_PAR casted_element {$$=new CSyntaxNode(TYPE_CAST_STA, $5, VOIDPTYPE);}

			//二重指针强制类型转换			
			| OPEN_PAR INTDECLARATION MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $6, DOUBLEINTPTYPE);}  
			| OPEN_PAR UNSIGNED INTDECLARATION MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $7, DOUBLEUINTPTYPE);}  
			| OPEN_PAR FLOATDECLARATION MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $6, DOUBLEFLOATPTYPE);}  
			| OPEN_PAR CHARDECLARATION MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $6, DOUBLECHARPTYPE);}  
			| OPEN_PAR UNSIGNED CHARDECLARATION MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $7, DOUBLEUCHARPTYPE);}   
			| OPEN_PAR VOIDDECLARATION MUL MUL CLOSE_PAR casted_element {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $6, VOIDPTYPE);}
			//yangkai malloc相关
			| OPEN_PAR STRUCT STRUCT_TYPE MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(TYPE_CAST_STA, $3, $6, STRUCTPTYPE);} 
			| OPEN_PAR STRUCT_TYPE MUL CLOSE_PAR casted_element  {$$=new CSyntaxNode(TYPE_CAST_STA, $2, $5, STRUCTPTYPE);} 
            //结构体类型二重指针转换
			| OPEN_PAR STRUCT STRUCT_TYPE MUL MUL CLOSE_PAR casted_element   {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $3, $7, DOUBLESTRUCTPTYPE);} 
			| OPEN_PAR STRUCT_TYPE MUL MUL CLOSE_PAR casted_element  {$$=new CSyntaxNode(DOUBLE_TYPE_CAST_STA, $2, $6, DOUBLESTRUCTPTYPE);} 
			;
casted_element:	type_cast_alg_exp	{$$=$1;}   // malloc相关			  
			  ;		
//加入强制类型转换语句 end Jane
 









//添加类型需要改动的地方 

 
sign_type_define:
	    UNSIGNED INTDECLARATION					{$$=UINTTYPE;} 
	   |UNSIGNED CHARDECLARATION				{$$=UCHARTYPE;}
	   ;
//  用于函数形参列表option_function_parameter_list，使得可以传递unsigned修饰参数
all_type_define:
		sign_type_define  {$$=$1;}
	   |type_define       {$$=$1;}
	   ;


//定义谓词和函数时使用的形参列表
option_function_parameter_list
	   :all_type_define identifier inner_option_define_identifier
	   {
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, $2, $3, $1);
	   }
	   |all_type_define inner_option_define_identifier //  函数指针的形参列表可以没有参数名字
	   {
			CSyntaxNode* pChild0=new CSyntaxNode(IDENT_EXP, "$$NoCare", NULL, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $2, $1);
	   }

	   
	   |STRUCT_TYPE identifier inner_option_define_identifier //结构体 S s	 
	   {
	        CSyntaxNode* pChild0=new CSyntaxNode(STRUCT_PARAMETER_EXP, $1, $2, VOIDTYPE);
			$$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $3, STRUCTTYPE);
			pChild0=NULL;
		}
       |STRUCT_TYPE MUL identifier inner_option_define_identifier//结构体指针类型的参数S *s
	   {
	        CSyntaxNode* pChild0= new CSyntaxNode(STRUCTP_PARAMETER_EXP, $1, $3, VOIDTYPE);
            $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, STRUCTPTYPE);
            pChild0=NULL;
	   }
       |STRUCT_TYPE MUL MUL identifier inner_option_define_identifier//结构体指针类型的参数S **s //二重结构体指针
	   {
	        CSyntaxNode* pChild0= new CSyntaxNode(DOUBLESTRUCTP_PARAMETER_EXP, $1, $4, VOIDTYPE);
            $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $5, STRUCTPTYPE);
            pChild0=NULL;
	   }
	   |STRUCT_TYPE identifier ARRAY inner_option_define_identifier //结构体数组 S a[]	 
	   {

			CSyntaxNode* pChild0=new CSyntaxNode(STRUCT_ARRAY_PARAMETER_EXP, $1, $2, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, STRUCTTYPE);
            pChild0=NULL;
		}
	   
		
		
	   |ID identifier inner_option_define_identifier //结构体 S s	 
	   {
	        CSyntaxNode* pChild0=new CSyntaxNode(STRUCT_PARAMETER_EXP, $1, $2, VOIDTYPE);
			$$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $3, STRUCTTYPE);
			pChild0=NULL;
		}
	   |ID MUL identifier inner_option_define_identifier//结构体指针类型的参数S *s
	   {
	        CSyntaxNode* pChild0= new CSyntaxNode(STRUCTP_PARAMETER_EXP, $1, $3, VOIDTYPE);
            $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, STRUCTPTYPE);
            pChild0=NULL;
	   }
       |ID MUL MUL identifier inner_option_define_identifier//结构体指针类型的参数S **s //二重结构体指针
	   {
	        CSyntaxNode* pChild0= new CSyntaxNode(DOUBLESTRUCTP_PARAMETER_EXP, $1, $4, VOIDTYPE);
            $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $5, STRUCTPTYPE);
            pChild0=NULL;
	   }
	   |ID identifier ARRAY inner_option_define_identifier //结构体数组 S a[]	 
	   {
			CSyntaxNode* pChild0=new CSyntaxNode(STRUCT_ARRAY_PARAMETER_EXP, $1, $2, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, STRUCTTYPE);
            pChild0=NULL;
		}

	   
	   |STRUCT_TYPE  inner_option_define_identifier //结构体 S s	 
	   {
	        $$=NULL;
		}
       |STRUCT_TYPE MUL  inner_option_define_identifier//结构体指针类型的参数S *s
	   {
	        $$=NULL;
	   }
       |STRUCT_TYPE MUL MUL  inner_option_define_identifier//结构体指针类型的参数S **s //二重结构体指针
	   {
			$$=NULL;
	   }
	  
       
	   |ID  inner_option_define_identifier //结构体 S s	 
	   {
	        $$=NULL;
		}
       |ID MUL  inner_option_define_identifier//结构体指针类型的参数S *s
	   {
	        $$=NULL;
	   }
       |ID MUL MUL  inner_option_define_identifier//结构体指针类型的参数S **s //二重结构体指针
	   {
			$$=NULL;
	   }

	   
	   |all_type_define identifier ARRAY inner_option_define_identifier//数组类型的参数int a[]
	   {
			CSyntaxNode* pChild0=new CSyntaxNode(ARRAY_PARAMETER_EXP, $2, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, $1);
            pChild0=NULL;
	   }
	   |all_type_define MUL identifier ARRAY inner_option_define_identifier //指针数组int *a[]
	   {
            CSyntaxNode* pChild0=new CSyntaxNode(POINTER_ARRAY_PARAMETER_EXP, $3, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $5, $1);
            pChild0=NULL;
	   }
	    //数组类型的参数a[][100]
	   |all_type_define identifier ARRAY OPEN_MPAR ari_exp CLOSE_MPAR inner_option_define_identifier
	   {
			CSyntaxNode* pChild0=new CSyntaxNode(DOUBLEARRAY_PARAMETER_EXP, $2, VOIDTYPE);
			$$ = new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $7, $1);
            pChild0=NULL;
	   }
	   |all_type_define MUL identifier inner_option_define_identifier//指针类型的参数*p
	   {
	      CSyntaxNode* pChild0= new CSyntaxNode(ADDRESS_DECLARE_STA, $3, VOIDTYPE);
          $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $4, $1);
          pChild0=NULL;
		}
	   |all_type_define MUL inner_option_define_identifier//指针类型的参数*p
	   {
	      $$=NULL;
		}
	   |all_type_define MUL MUL identifier inner_option_define_identifier//指针类型的参数**p
	   {
		  CSyntaxNode* pChild00=new CSyntaxNode(ADDRESS_DECLARE_STA, $4, VOIDTYPE);
		  CSyntaxNode* pChild0= new CSyntaxNode(ADDRESS_DECLARE_STA, pChild00, VOIDTYPE);
          $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $5, $1);
          pChild0=NULL;
		}
	   // 函数的参数可以是函数指针
	   |OPEN_PAR MUL ID CLOSE_PAR OPEN_PAR option_function_parameter_list CLOSE_PAR inner_option_define_identifier//函数指针类型的参数
	   {
	      CSyntaxNode* pChild0= new CSyntaxNode(FUNCP_PARAMETER_EXP, $3,$6, VOIDTYPE);
          $$=new CSyntaxNode(FORMAL_PARAMETER_EXP, pChild0, $8, FUNCPTYPE);
          pChild0=NULL;
		}
	   | /* empty */                                       {$$ = NULL;}
	   ;
inner_option_define_identifier
      : COMMA option_function_parameter_list {$$=$2}
	  |  {$$=NULL}
	  ;


//调用函数和谓词的实参列表，加入字符串  
option_function_identifier
       :ass_right inner_option_function_identifier           
	   {
			$$ = new CSyntaxNode(ACTUAL_PARAMETER_EXP, $1, $2, VOIDTYPE);
	   }
	   //函数参数可以是int, float, char等，这种情况用于sizeof函数
	   |all_type_define                            
	   {
	       $$ = new CSyntaxNode(ACTUAL_PARAMETER_EXP, $1);
	   }
	   |STRUCT_TYPE
	   {
	      $$ = new CSyntaxNode(ACTUAL_PARAMETER_EXP, $1, NULL, STRUCTTYPE);
	   }
	   | /* empty */                                       {$$=NULL;}
	   |ADDRESS error                                      {$$=NULL;}
	   ;

inner_option_function_identifier
       :COMMA ass_right inner_option_function_identifier
	   {
			$$ = new CSyntaxNode(ACTUAL_PARAMETER_EXP, $2, $3, VOIDTYPE);
	   }
	   | /* empty */                                       {$$=NULL;}
	   |COMMA error                                        {$$=NULL;}
	   ;

//调用函数和谓词的实参列表，加入字符串 end



statement_bpar
       :OPEN_BPAR statement CLOSE_BPAR					   {$$=$2;}
//	   |OPEN_BPAR statement				{yyerror("expecting '}'"); $$=NULL;}
	   |error CLOSE_BPAR                                   {$$=NULL;}
//	   |OPEN_BPAR CLOSE_BPAR            {yyerror("expecting statement"); $$=NULL;}
	   ;



bool_par
       :OPEN_PAR ari_exp CLOSE_PAR				   {$$=$2;}
//	   |OPEN_PAR ari_exp			{yyerror("expecting ')'"); $$=NULL;}
	   |error CLOSE_PAR									   {$$=NULL;}
//	   |OPEN_PAR CLOSE_PAR              {yyerror("expecting statement"); $$=NULL;}
	   ;


identifier
       :ID                              {$$=new CSyntaxNode(IDENT_EXP, $1, NULL, VOIDTYPE);}	   
	   |OPEN_PAR identifier CLOSE_PAR   {$$=$2;}
       ;

strliteral
       : STRLITERAL                            {$$=new CSyntaxNode(STR_EXP, $1, STRTYPE);}
       ;


intliteral
       : INTLITERAL                        {$$=new CSyntaxNode(INTEGER_EXP, $1, INTTYPE);}
       ;


charliteral
			:CHARLITERAL					{$$=new CSyntaxNode(CHARLITERAL_EXP, $1, CHARTYPE);}
			;


floatliteral
			:FLOATLITERAL					{$$=new CSyntaxNode(FLOATLITERAL_EXP, $1, FLOATTYPE);}
			;



option_frame_identifier
       : COMMA identifier option_frame_identifier        
	    {
			$$ = new CSyntaxNode( FRAME_STA, $2, $3, VOIDTYPE);
		}
	   | /* empty */                                       {$$ = NULL;}
	   |COMMA error                                        {$$=NULL;}
	   ;



option_projection
	   :                                                   {$$=NULL;}
	   |COMMA statement option_projection               
	   {
			$$ = new CSyntaxNode( PROJECTION_STA, $2, $3, VOIDTYPE);
	   }							
	   ;





imply_pre
	   :
	    
	   /*
	   ass_statement                   
	   {
			if($1->GetNType()==ASS_EQU_EXP)
				$1->SetRType(BOOLTYPE);
			$$=$1;
	   }
	   */
	   |NEGATION imply_pre              {$$=new CSyntaxNode(NEGATION_EXP, $2, BOOLTYPE);}
	   |imply_pre AND imply_pre
	                                    {$$=new CSyntaxNode(AND_EXP, $1, $3, BOOLTYPE);}
	   |imply_pre OR imply_pre
	                                    {$$=new CSyntaxNode(OR_EXP, $1, $3, BOOLTYPE);}
	   |OPEN_PAR imply_pre CLOSE_PAR    {$$=$2;}
	   ;


				 
while_statement
       :WHILE bool_par statement_bpar			{$$=new CSyntaxNode(WHILE_DO_STA, $2, $3, VOIDTYPE);}
	   ;



for_statement
       :FOR ari_exp TIMES DO statement_bpar
	                                    {$$=new CSyntaxNode(FOR_TIMES_STA, $2, $5, VOIDTYPE);}
//	   |FOR ari_exp DO statement_bpar          {yyerror("expecting TIMES"); $$=NULL;}
//	   |FOR ari_exp TIMES statement_bpar       {yyerror("expecting DO"); $$=NULL;}
//	   |FOR ari_exp statement_bpar             {yyerror("expecting TIMES DO"); $$=NULL;}
	   ;

extend_for_statement
       :FOR OPEN_PAR for_sta_init COMMA for_sta_condition COMMA for_sta_control  CLOSE_PAR  statement_bpar
	   {
	     CSyntaxNode* pchild0=new CSyntaxNode(FOR_STA_CON, $3, $5, $7, VOIDTYPE); 
		 $$=new CSyntaxNode(FOR_STA, pchild0, $9, VOIDTYPE);
		 pchild0=NULL;
	   }
       ;
for_sta_init//for语句括号中的初始化语句,可以是赋值语句，也可以是声明语句,也可以不写
       :ass_statement 
	   {
	      $$=$1;
	   }
	   |declaration
	   {
	      $$=$1;
	   }
	   |/*empty*/
	   {
	      $$=NULL;
	   }
       ;
for_sta_condition//for语句括号中的条件语句，是一个布尔表达式也可以不写
      :ari_exp
	  {
	      $$=$1;
	  }
	  |/*empty*/
	  {
	      $$=NULL;
	  }
	  ;
for_sta_control//for语句括号中的控制语句，是一个赋值语句也可以不写
      :ass_statement
	  {
	     $$=$1;
	  }
	  |/*empty*/
	  {
	      $$=NULL;
	  }
	  ;
//add by yubin 2015-3-23
switch_statement
       :SWITCH OPEN_PAR simple_ari_exp CLOSE_PAR OPEN_BPAR case_par CLOSE_BPAR 
	   {$$=new CSyntaxNode(SWITCH_STA, $3, $6,VOIDTYPE);}
	   ;   
case_par
       :CASE simple_ari_exp COLON OPEN_PAR statement CLOSE_PAR init_case_par 
	   {
	     $$=new CSyntaxNode(CASE_STA, $2, $5, $7, VOIDTYPE);
	   }
	   |DEFAULT COLON OPEN_PAR statement CLOSE_PAR //default语句只能写在最后一条,且后面不能加break语句
	   {
	     $$=new CSyntaxNode(DEFAULT_STA, $4, VOIDTYPE);
	   }
	   //|  {$$=NULL;}
       ;
init_case_par
       :BREAK case_par
	   {
			$$=new CSyntaxNode(INIT_CASE_STA, $2, BREAKTYPE);
		}
	   |case_par  //modified by yubin  
	   {
			$$=new CSyntaxNode(INIT_CASE_STA, $1, VOIDTYPE);
	    }
	   |{$$=NULL;}
	   ;

if_statement
       : IF ari_exp THEN  statement_bpar option_else_statement
        {
            $$ = new CSyntaxNode( IF_ELSE_STA, $2, $4, $5, VOIDTYPE);
        }
//	   | IF bool_par sma_par option_else_statement  {yyerror("Expecting THEN");$$=NULL;}
	   ;



option_else_statement
       : ELSE statement_bpar					                   {$$=$2;}
       | /* empty */                                       {$$=NULL;}
       ;



output_statement
       :DISPLAY OPEN_PAR ass_right CLOSE_PAR   {$$=new CSyntaxNode(DISPLAY_STA, $3, UNKNOWNTYPE);}
	   |DISPLAY OPEN_PAR ass_right option_output CLOSE_PAR   {$$=new CSyntaxNode(DISPLAY_STA, $3, $4, UNKNOWNTYPE);}
	   ;

option_output
       :								{$$=NULL;}
	   |COMMA ass_right option_output     {$$=new CSyntaxNode(DISPLAY_STA, $2, $3, UNKNOWNTYPE);}
	   ;

 
input_statement 
		:REQUEST OPEN_PAR identifier CLOSE_PAR {$$=new CSyntaxNode(REQUEST_STA, $3, UNKNOWNTYPE);}
		|REQUEST OPEN_PAR identifier option_input CLOSE_PAR 	{$$=new CSyntaxNode(REQUEST_STA, $3, $4, UNKNOWNTYPE);}
		|REQUEST OPEN_PAR array CLOSE_PAR  {$$=new CSyntaxNode(REQUEST_STA, $3, UNKNOWNTYPE);}
		|REQUEST OPEN_PAR array option_input CLOSE_PAR  {$$=new CSyntaxNode(REQUEST_STA, $3, $4, UNKNOWNTYPE);}
	    |REQUEST OPEN_PAR struct_member_exp CLOSE_PAR  {$$=new CSyntaxNode(REQUEST_STA, $3, UNKNOWNTYPE);}
		;
option_input
		:								{$$=NULL;}
	    |COMMA identifier option_input{$$=new CSyntaxNode(REQUEST_STA, $2, $3, UNKNOWNTYPE);}
	    |COMMA array option_input		{$$=new CSyntaxNode(REQUEST_STA, $2, $3, UNKNOWNTYPE);}
		;


// s.a->b[2].a   结构体串联
struct_member_exp 
		:identifier	 DOT identifier option_struct_member_exp						{$$=new CSyntaxNode(STRUCT_IDENT_EXP, $1, $3, $4, VOIDTYPE);}
		|array        DOT identifier option_struct_member_exp						{$$=new CSyntaxNode(STRUCT_IDENT_EXP, $1, $3, $4, VOIDTYPE);}
		|point_exp DOT identifier option_struct_member_exp                {$$=new CSyntaxNode(STRUCT_IDENT_EXP, $1, $3, $4, VOIDTYPE);}

		|identifier	 DOT array option_struct_member_exp						{$$=new CSyntaxNode(STRUCT_LIST_EXP, $1, $3, $4, VOIDTYPE);}
		|array        DOT array option_struct_member_exp						{$$=new CSyntaxNode(STRUCT_LIST_EXP, $1, $3, $4, VOIDTYPE);}
		|point_exp DOT array option_struct_member_exp                {$$=new CSyntaxNode(STRUCT_LIST_EXP, $1, $3, $4, VOIDTYPE);}

		|identifier	 IMPLY identifier option_struct_member_exp						{$$=new CSyntaxNode(STRUCTP_IDENT_EXP, $1, $3, $4, VOIDTYPE);}
		|array        IMPLY identifier option_struct_member_exp						{$$=new CSyntaxNode(STRUCTP_IDENT_EXP, $1, $3, $4, VOIDTYPE);}
		|OPEN_PAR address_exp CLOSE_PAR IMPLY identifier option_struct_member_exp                {$$=new CSyntaxNode(STRUCTP_IDENT_EXP, $2, $5, $6, VOIDTYPE);}
		|point_exp IMPLY identifier option_struct_member_exp                {$$=new CSyntaxNode(STRUCTP_IDENT_EXP, $1, $3, $4, VOIDTYPE);}

		|identifier	 IMPLY array option_struct_member_exp						{$$=new CSyntaxNode(STRUCTP_LIST_EXP, $1, $3, $4, VOIDTYPE);}
		|array        IMPLY array option_struct_member_exp						{$$=new CSyntaxNode(STRUCTP_LIST_EXP, $1, $3, $4, VOIDTYPE);}
		|OPEN_PAR address_exp CLOSE_PAR  IMPLY array option_struct_member_exp     {$$=new CSyntaxNode(STRUCTP_LIST_EXP, $2, $5, $6, VOIDTYPE);}
		|identifier DOT function {$$=new CSyntaxNode(STRUCT_FUNC_EXP, $1, $3, VOIDTYPE);} //结构体成员是函数指针
		|identifier IMPLY function {$$=new CSyntaxNode(STRUCTP_FUNC_EXP, $1, $3, VOIDTYPE);} //结构体成员是函数指针
		|point_exp   IMPLY array option_struct_member_exp                {$$=new CSyntaxNode(STRUCTP_LIST_EXP, $1, $3, $4, VOIDTYPE);}
		|OPEN_PAR struct_member_exp CLOSE_PAR {$$=$2;}
		;
		
option_struct_member_exp
		:	{$$=NULL;}
		|DOT identifier		option_struct_member_exp      {$$=new CSyntaxNode(STRUCT_IDENT_EXP, $2, $3, VOIDTYPE);}
		|DOT array			option_struct_member_exp            {$$=new CSyntaxNode(STRUCT_LIST_EXP, $2, $3, VOIDTYPE);}
		|IMPLY identifier   option_struct_member_exp    {$$=new CSyntaxNode(STRUCTP_IDENT_EXP, $2, $3, VOIDTYPE);}
		|IMPLY array			option_struct_member_exp		  {$$=new CSyntaxNode(STRUCTP_LIST_EXP, $2, $3, VOIDTYPE);}
		|DOT function {$$=new CSyntaxNode(STRUCT_FUNC_EXP, $2, NULL, VOIDTYPE);}    //结构体成员是函数指针
		|IMPLY function {$$=new CSyntaxNode(STRUCTP_FUNC_EXP, $2, NULL, VOIDTYPE);}  //结构体成员是函数指针
		;
