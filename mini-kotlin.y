%code requires{
    #include "ast.h"
}

%{
    #include <cstdio>
    extern int yylineno;
    int yylex();
    extern int line;
    extern int column;
    void yyerror(const char * message){
        fprintf(stderr, "Error: %s in line: %d and column %d\n", message, line, column);
    }
%}

%union{
        int int_t;
        char * string_t;
        float float_t;
        bool boolean_t;
        char char_t;
        Statement * statement_t;
        Expression * expr_t;
        VarDeclarationStatement * var_declaration_t;
}

%token TK_INCREMENT TK_DECREMENT TK_AND TK_OR TK_EQUAL TK_NOT_EQUAL
%token TK_LESS_EQUAL TK_GT_EQUAL TK_RANGE
%token KW_BREAK KW_DO KW_ELSE KW_FOR KW_FUN KW_IF KW_IN
%token KW_RETURN KW_VAR KW_CONTINUE KW_ARRAYOF KW_ARRAY KW_WHEN KW_IS KW_NULL KW_VAL
%token KW_WHILE KW_CONST KW_INT KW_FLOAT KW_CHAR KW_BOOLEAN KW_STRING KW_UNTIL
%token KW_PRINTLN KW_READLINE KW_PRINT KW_MAIN KW_ARGS

%token<string_t> TK_ID TK_LIT_STRING TK_LINE_COMMENT TK_BLOCK_COMMENT
%token<float_t> TK_LIT_FLOAT
%token<int_t> TK_LIT_INT
%token<char_t> TK_LIT_CHAR
%token<boolean_t> KW_TRUE KW_FALSE

%type<statement_t> stmt print_stmt if_stmt assignation_stmt comment_stmt loop_stmt returnORbreak_stmt methodcall_stmt incre_decre_stmt
%type<expr_t> expression
%type<var_declaration_t> variable_decl

%precedence TK_EQUAL TK_NOT_EQUAL
%precedence TK_AND
%precedence TK_OR

%%

program: functions
        ;

functions: func functions
        | /*eps*/
        ;

func: KW_FUN TK_ID '(' params ')' ':' func_type block
    | KW_FUN TK_ID '(' params ')' block
    | KW_FUN KW_MAIN '(' KW_ARGS ':' KW_ARRAY '<' KW_STRING '>' ')' block
    | KW_FUN KW_MAIN '(' ')' block
    ;

block: '{' decls_stmts '}' ;

decls_stmts: decls_or_stmts decls_stmts
            | /*epsilon*/
            ;

decls_or_stmts: decl
              | stmt
              ;

decl: KW_VAL decl_inline
    | KW_VAR decl_inline
    ;

decl_inline: variable_decl
        |   variable_decl ';'
        |   variable_decl '=' expression
        |   variable_decl '=' expression ';'
        |   variable_decl '=' array_decl
        |   variable_decl '=' TK_ID '(' paramsCall ')'
        ;

array_decl: KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}'
          | KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}' ';'
            ;

params: TK_ID ':' type ',' params
        | TK_ID ':' type
        | array_params params
        | /*epsilon*/
        ;

array_params: TK_ID ':' KW_ARRAY '<' type '>' ','
        | TK_ID ':' KW_ARRAY '<' type '>'
        ;

paramsCall: TK_ID ',' paramsCall
        | TK_ID
        | literal ',' paramsCall
        | literal
        | arrayFuncCall_params paramsCall
        ;

arrayFuncCall_params: KW_ARRAYOF '<' type '>' '(' func_CallLiterals ')' ','
        | KW_ARRAYOF '<' type '>' '(' func_CallLiterals ')' 
        ;

variable_decl: TK_ID ':' type { $$ = new VarDeclarationStatement($1,$3,line, column);}
            | TK_ID{ $$ = new VarDeclarationStatement($1,NULL,line, column);}
            ;

stmt: print_stmt { $$ = $1;}
    | if_stmt { $$ = $1;} 
    | assignation_stmt { $$ = $1;}
    | comment_stmt { $$ = $1;}
    | loop_stmt { $$ = $1;}
    | returnORbreak_stmt
    | methodcall_stmt
    | incre_decre_stmt
    ;

incre_decre_stmt: TK_ID TK_INCREMENT
                | TK_ID TK_INCREMENT ';'
                | TK_ID TK_DECREMENT 
                | TK_ID TK_DECREMENT ';'
                ;

assignation_stmt: TK_ID '=' expression { $$ = new AssignationStatement($1, $3, NULL, line, column);}
                | TK_ID '=' expression ';' { $$ = new AssignationStatement($1, $3, NULL, line, column);}
                | TK_ID '[' arithmetic_expression ']' '=' arithmetic_expression { $$ = new AssignationStatement($1, $6, $3, line, column);}
                | TK_ID '[' arithmetic_expression ']' '=' arithmetic_expression ';' { $$ = new AssignationStatement($1, $6, $3, line, column);}

if_stmt: KW_IF '(' expression ')' block { $$ = new IfStatement($3, $5, NULL, line, column);}
       | KW_IF '(' expression ')' stmt { $$ = new IfStatement($3, $5, NULL, line, column);}
       | KW_IF '(' expression ')' block KW_ELSE block { $$ = new IfStatement($3, $5, $7, line, column);}
        ;

print_stmt: KW_PRINT '(' expression ')' { $$ = new PrintStatement($3, line, column);}
          | KW_PRINTLN '(' expression ')' { $$ = new PrintStatement($3, line, column);}
          | KW_PRINT '(' expression ')' ';' { $$ = new PrintStatement($3, line, column);}
          | KW_PRINTLN '(' expression ')' ';' { $$ = new PrintStatement($3, line, column);}
         ;

loop_stmt: for_stmt { $$ = $1;}
         | while_stmt { $$ = $1;}
         | do_while_stmt { $$ = $1;}
        ;

while_stmt: KW_WHILE '(' expression ')' block 
          | KW_WHILE '(' expression ')' stmt 
;

do_while_stmt: KW_DO block KW_WHILE '(' expression ')' 
             | KW_DO stmt KW_WHILE '(' expression ')' 
             | KW_DO block KW_WHILE '(' expression ')' ';'
             | KW_DO stmt KW_WHILE '(' expression ')' ';'
             ;

for_stmt: KW_FOR '(' variable_decl KW_IN expression KW_UNTIL expression ')' block { $$ = new ForStatement($3,$5,$7,$9, line, column);}
    | KW_FOR '(' variable_decl KW_IN expression KW_UNTIL expression ')' stmt { $$ = new ForStatement($3,$5,$7,$9, line, column);}
    | KW_FOR '(' variable_decl KW_IN expression ')' block { $$ = new ForStatement($3,$5,NULL,$7, line, column);}
    | KW_FOR '(' variable_decl KW_IN expression ')' stmt { $$ = new ForStatement($3,$5,NULL,$7, line, column);}
    ; 
            
comment_stmt: TK_LINE_COMMENT { $$ = new CommentStatement($1,line, column);}
            | TK_BLOCK_COMMENT { $$ = new CommentStatement($1,line, column);}
            ;

returnORbreak_stmt: KW_RETURN expression ';'
            | KW_RETURN expression
            | KW_BREAK ';'
            | KW_BREAK
            ; 

methodcall_stmt: TK_ID '(' paramsCall ')'
                ;
                
//EXPRESSIONS

expression: expression TK_OR comparison_expression
        | expression TK_AND comparison_expression  
        | expression TK_EQUAL comparison_expression 
        | expression TK_NOT_EQUAL comparison_expression
        | comparison_expression
        ;

comparison_expression: comparison_expression '>' arithmetic_expression
        | comparison_expression '<' arithmetic_expression 
        | comparison_expression TK_LESS_EQUAL arithmetic_expression   
        | comparison_expression TK_GT_EQUAL arithmetic_expression 
        | arithmetic_expression
        ;

arithmetic_expression: arithmetic_expression '+' term
        | arithmetic_expression '-' term
        | arithmetic_expression TK_RANGE term
        | term
        ;

term: term '*' unary_expression
    | term '/' unary_expression
    | term '%' unary_expression
    | unary_expression
    ;

unary_expression: '!' factor
                | '-' factor
                | incre_decre_expression
                | factor 
                ;

incre_decre_expression: TK_INCREMENT factor
                | TK_DECREMENT factor
                | factor TK_INCREMENT
                | factor TK_DECREMENT

factor: '(' expression ')'
    | literal
    | TK_ID
    | TK_ID '[' expression ']' //array access
    ;

literal: TK_LIT_CHAR
       | TK_LIT_STRING
       | TK_LIT_INT
       | TK_LIT_FLOAT
       | KW_TRUE
       | KW_FALSE
       ;

func_CallLiterals: literal ',' func_CallLiterals
                | literal
                ;

type: KW_INT
    | KW_FLOAT
    | KW_BOOLEAN
    | KW_CHAR
    | KW_STRING
    ;

func_type: type 
    | KW_ARRAY '<' type '>'
    ;

%%