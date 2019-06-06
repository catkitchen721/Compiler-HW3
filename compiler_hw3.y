/*	Definition section */
%{
//#include "xxxx.h" // include header if needed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
void yyerror(char *s);
extern char *error_type;
char *error_target;

typedef struct _symbol_table_entry {
	char name[32];
	char entry_type[32];
	char data_type[16];
	int scope_level;
	char formal_para[16][16];
}symbol_table_entry;

symbol_table_entry *symbol_table = NULL;
int table_pointer = 0;
extern int curr_scope;
char curr_formal_para[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
int curr_formal_para_index = 0;
int dump_on = -1;
int isGlobal = 1;

FILE *file; // To generate .j file for Jasmin

/* symbol table functions */
/*
int lookup_symbol();
void create_symbol_table();
void free_symbol_table();
void insert_symbol();
void dump_symbol();
*/

int lookup_symbol(char name[32]);
void create_symbol();
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]);
void dump_symbol();

void free_symbol_table();

/* code generation functions, just an example! */
void gencode_function(char *cmd);

%}

%union {
	int i_val;
    double f_val;
    char* string;
    int bool_val;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token RET CONTINUE BREAK
%token C_COMMENT CPP_COMMENT NL

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <bool_val> TRUE_RESULT FALSE_RESULT
%token <string> INT FLOAT BOOL STRING VOID
%token <string> STR_CONST ID

/* Nonterminal with return, which need to sepcify type */
%type <string> type

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program global_decl_or_functions
    |
;

global_decl_or_functions
	: global_decl_or_functions global_decl_or_function
	| global_decl_or_function
	| new_line
;
	
global_decl_or_function
	: global_decl
	| function_define
;

new_line
	: NL { 
		if(strcmp(error_type, "") == 0)
			(strcmp(buf, "\n") == 0)?printf("%d:%s", yylineno, buf):printf("%d: %s", yylineno, buf); 
		else
			(strcmp(buf, "\n") == 0)?printf("%d:%s\n", yylineno, buf):printf("%d: %s\n", yylineno, buf);
		if(strcmp(error_type, "Redeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Redeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Redeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Redeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Undeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Undeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else;
		error_type = strdup("");
		error_target = strdup("");
		memset(buf, '\0', sizeof(buf)); 
		if(dump_on == 0){dump_symbol(); curr_scope--; dump_on = -1;}
	}
;

global_decl
    : var_decl
    | function_decl
;

var_decl
    : type ID ASGN initializer SEMICOLON {
    	if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function($2); 
					gencode_function(" I = 0\n");
				}
				else
				{
					
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function($2); 
					gencode_function(" I = 0\n");
				}
				else
				{
					
				}
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else
    	{
    		error_type = strdup("Redeclared variable");
			error_target = strdup($2);
    	}
    }
    | type ID SEMICOLON {
    	if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared variable");
				error_target = strdup($2);
    		}
    	}
    	else
    	{
    		// semantic error
    		error_type = strdup("Redeclared variable");
			error_target = strdup($2);
    	}
    }
;

function_decl
	: type ID para_area SEMICOLON {
		if(strcmp($1, "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared function");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared function");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared function");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared function");
				error_target = strdup($2);
    		}
    	}
    	else if(strcmp($1, "void") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol($2);
    		if(targetIndex == -1)
    		{
    			insert_symbol($2, "function", "void", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol($2, "function", "void", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				error_type = strdup("Redeclared function");
				error_target = strdup($2);
    		}
    	}
    	else
    	{
    		
    	}
	}
;

para_area
	: LB paras RB
	| LB RB
;

paras
	: paras COMMA para
	| para
;

para
	: type ID { 
		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
		int targetIndex = lookup_symbol($2);
		if(targetIndex == -1)
		{
			insert_symbol($2, "parameter", $1, curr_scope+1, temp);
		}
		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope+1)
		{
			insert_symbol($2, "parameter", $1, curr_scope+1, temp);
		}
		else
		{
			// semantic error
			error_type = strdup("Redeclared variable");
			error_target = strdup($2);
		}
	/*
		strcat(curr_formal_para[curr_formal_para_index], $1); 
		strcat(curr_formal_para[curr_formal_para_index], " "); 
		strcat(curr_formal_para[curr_formal_para_index], $2); 
		if(curr_formal_para_index <= 14) curr_formal_para_index++; 
	*/
	}
;

/* actions can be taken when meet the token or rule */
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;

initializer
	: logic_initializer
	| STR_CONST 
;

logic_initializer
	: number_initializer
	| tf_initializer
;

number_initializer
	: I_CONST 
	| F_CONST 
	| count_expr
	| ID { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| function_using
;

tf_initializer
	: TRUE_RESULT 
	| FALSE_RESULT 
	| ID { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| function_using
;

count_expr  //need to complete it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	: number_initializer two_term_op number_initializer
	| logic_initializer two_term_op_logic logic_initializer
	| LB count_expr RB
	| pre_one_term_op logic_initializer
	| both_one_term_op ID { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($2);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($2);
			}
			else
			{
				
			} 
		}
	| ID both_one_term_op { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
;

two_term_op
	: ADD
	| SUB
	| MUL
	| DIV
	| MOD
	| MT
	| LT
	| MTE
	| LTE
	| EQ
	| NE
	| two_term_op_logic
;

two_term_op_logic
	: AND
	| OR
;

/*one_term_op
	: pre_one_term_op
	| both_one_term_op
;*/

pre_one_term_op
	: NOT
;

both_one_term_op
	: INC
	| DEC
;

function_define
	: function_define_head function_combound { 
		fprintf(file, ".end method\n");
		isGlobal = 1;
	}
;

function_define_head
	: type ID para_area {
		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "def"};
		for(int i=0; i<30; i++)
		{
			if(strcmp(symbol_table[i].entry_type, "parameter") == 0)
			{
				strcpy(temp[i], symbol_table[i].data_type);
			}
		}
		int targetIndex = lookup_symbol($2);
		if(targetIndex == -1)
		{
			insert_symbol($2, "function", $1, curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function($2);
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
		{
			insert_symbol($2, "function", $1, curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function($2);
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else if(targetIndex != -1 && strcmp(symbol_table[targetIndex].formal_para[15], "decl") == 0)
		{
			insert_symbol($2, "function", $1, curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function($2);
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else
		{
			// semantic error
			error_type = strdup("Redeclared function");
			error_target = strdup($2);
		}
	}
;

function_combound
	: combound_area
	| new_line function_combound
;

combound_area
	: LCB combound_area_inner RCB { dump_on = 0; }
;

combound_area_inner
	: combound_area_inner stat
	|
;

stat
	: asgn_stat SEMICOLON
	| var_decl
	| print_stat SEMICOLON
	| function_using SEMICOLON
	| select_stat  
	| while_stat
	| return_stat SEMICOLON
	| SEMICOLON
	| combound_area
	| new_line
;

asgn_stat
	: ID ASGN initializer { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID ADDASGN number_initializer{ 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID SUBASGN number_initializer { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID MULASGN number_initializer { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID DIVASGN number_initializer { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID MODASGN number_initializer { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| ID both_one_term_op { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| both_one_term_op ID { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($2);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($2);
			}
			else
			{
				
			} 
		}
;

print_stat
	: PRINT LB print_target RB
;

print_target
	: ID { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared variable");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
	| STR_CONST
	| number_initializer
;

function_using
	: ID para_area_using { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol($1);
			if(targetIndex == -1)
			{
				// semantic error
				error_type = strdup("Undeclared function");
				error_target = strdup($1);
			}
			else
			{
				
			} 
		}
;

para_area_using
	: LB paras_using RB
	| LB RB
;

paras_using
	: paras_using COMMA initializer
	| initializer
;

select_stat
	: IF LB logic_initializer RB stat else_stat
	| IF LB logic_initializer RB stat
;

else_stat
	: ELSE stat
	| new_line else_stat
;

while_stat
	: WHILE LB logic_initializer RB stat
;

return_stat
	: RET initializer
	| RET { gencode_function("\treturn\n"); }
;

%%

/* C code section */

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    create_symbol();
    curr_scope = 0;
    int result = 0;
    error_type = strdup("");
    error_target = strdup("");

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    result = yyparse();
	if(result == 0) 
	{
		dump_symbol();
		printf("\nTotal lines: %d \n",yylineno);
	}
	
	if(symbol_table != NULL)
	{
		free(symbol_table);
	}

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
	if(strcmp(s, "syntax error") == 0)
	{
		(strcmp(buf, "\n") == 0)?printf("%d:%s\n", yylineno + 1, buf):printf("%d: %s\n", yylineno + 1, buf); 
		if(strcmp(error_type, "Redeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Redeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Redeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Redeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Undeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Undeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else;
		error_type = strdup("");
		error_target = strdup("");
		
		error_type = strdup("syntax error");
		printf("\n|-----------------------------------------------|\n");
    	printf("| Error found in line %d: %s\n", yylineno + 1, buf);
    	printf("| %s", s);
    	printf("\n|-----------------------------------------------|\n\n");
    	memset(buf, '\0', sizeof(buf)); 
	}
    /*printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");*/
}

/* stmbol table functions */
void create_symbol() {
	symbol_table = (symbol_table_entry *)malloc(sizeof(symbol_table_entry) * 30);
	for(int i=0; i<30; i++)
	{
		strcpy(symbol_table[i].name, "\0");
		strcpy(symbol_table[i].entry_type, "\0");
		strcpy(symbol_table[i].data_type, "\0");
		symbol_table[i].scope_level = -1;
		for(int j=0; j<16; j++)
			strcpy(symbol_table[i].formal_para[i], "\0");
	}
}
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]) {
	if(lookup_symbol(name) != -1 && scope_level == symbol_table[lookup_symbol(name)].scope_level)
	{
		//semantic error.
	}
	else
	{
		strcpy(symbol_table[table_pointer].name, name);
		strcpy(symbol_table[table_pointer].entry_type, entry_type);
		strcpy(symbol_table[table_pointer].data_type, data_type);
		symbol_table[table_pointer].scope_level = scope_level;
		for(int i=0; i<16; i++)
			strcpy(symbol_table[table_pointer].formal_para[i], formal_para[i]);
		
		if(table_pointer != 29) table_pointer++;
	}
}
int lookup_symbol(char name[32]) {
	for(int i=0; i<30; i++)
	{
		if(strcmp(symbol_table[i].name, name) == 0)
		{
			return i;  //used
		}
	}
	return -1;
}
void dump_symbol() {
	int myFlag = 0;
	for(int i=0; i<30; i++)
	{
		if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
		{
			myFlag = 1;
		}
	}
	if(myFlag)
	{
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
    int dump_index = 0;
    int isPrinted = -1;
           
    for(int i=0; i<30; i++)
    {
    	char *attribute;
    	attribute = strdup("\0");
    	char index_str[10] = "\0";
    	char scope_str[10] = "\0";
    	
    	if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
    	{
    		for(int j=0; j<15; j++)
    		{
    			strcat(attribute, symbol_table[i].formal_para[j]);
    			if(strcmp(attribute, "\0") != 0 && j != 14 && strcmp(symbol_table[i].formal_para[j+1], "\0") != 0 && strcmp(symbol_table[i].formal_para[j+1], "decl") != 0) strcat(attribute, ", ");
    		}
    		sprintf(index_str, "%d", dump_index);
    		sprintf(scope_str, "%d", symbol_table[i].scope_level);
    		isPrinted = 0;
    		if(strcmp(attribute, "\0") != 0)
    		{
    			printf("%-10s%-10s%-12s%-10s%-10s",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str);
           		for(int k=0; k<10; k++)
           		{
           			(attribute[k] == '\0')?:printf("%c", attribute[k]);
				}
				printf("\n");
           }
           else
           {
           		printf("%-10s%-10s%-12s%-10s%-10s\n",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str);
           }
           
           strcpy(symbol_table[i].name, "\0");
		   strcpy(symbol_table[i].entry_type, "\0");
		   strcpy(symbol_table[i].data_type, "\0");
		   symbol_table[i].scope_level = -1;
		   for(int j=0; j<16; j++)
			   strcpy(symbol_table[i].formal_para[i], "\0");
           
           dump_index++;
    	}
    }
    if(isPrinted == 0)
    {
    	printf("\n");
    }
}

/* code generation functions */
void gencode_function(char *cmd) 
{
	fprintf(file, "%s", cmd);
}
