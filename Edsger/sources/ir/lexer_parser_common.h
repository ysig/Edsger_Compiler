/*
 * 
 */
#ifndef __LEXER_PARSER_COMMON_H__
#define __LEXER_PARSER_COMMON_H__



#include <stdio.h>
#include "general.h"
#include "llv.h"
#include "error.h"
#include "symbol.h"



#define PINK "\x1b[47m"
#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA	"\x1b[35m"
#define RESET		"\x1b[0m"
#define MAX_INCLUDE_DEPTH 40
/*
 * Lexical Analyzer section
 */


struct dec_node{
	char name[256];
	int cells;
	Type type;
	int by_ref_idx;
	struct dec_node *next;
};

struct type_node{
	int rv;
	llvm::Value *val;
	llvm::Value *adr;
	Type type;
	struct type_node * next;
};

struct Variable{
	char name[256];
	Type type;
  };

extern FILE *yyin;
extern char *yytext;		/* Last matched input token */
extern int  include_stack_ptr;	
/* extern hashset_t set; f*****cking hashset */
extern char filename[256];	
extern char filename_stack[MAX_INCLUDE_DEPTH][256];
extern int countlines_stack[MAX_INCLUDE_DEPTH];	
extern int Number_of_Errors;
extern int Number_of_Warnings;
extern int countlines;
extern llvm::Module* Mod;
extern int yylex(void);
#endif
