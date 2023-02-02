%{
    #include <cstdio>
    extern int yylineno;
    int yylex();
    void yyerror(const char * message){
        fprintf(stderr, "Error %s, in line: %d\n", message, yylineno);
    }
%}

%token TK_ID TK_LIT_FLOAT TK_LIT_INT
%token TK_LINE_COMMENT TK_BLOCK_COMMENT
%token TK_INCREMENT TK_DECREMENT TK_AND TK_OR TK_EQUAL TK_NOT_EQUAL
%token TK_LESS_EQUAL TK_GT_EQUAL TK_RANGE
%token KW_BREAK KW_DO KW_ELSE KW_FALSE KW_TRUE KW_FOR KW_FUN KW_IF KW_IN
%token KW_RETURN KW_VAR KW_CONTINUE KW_ARRAY KW_WHEN KW_IS KW_NULL KW_VAL
%token KW_WHILE KW_CONST KW_INT KW_FLOAT KW_CHAR KW_BOOLEAN KW_STRING
%token KW_PRINTLN KW_READLINE KW_PRINT TK_LIT_CHAR TK_LIT_STRING

%%

program: /* epsilon */

%%