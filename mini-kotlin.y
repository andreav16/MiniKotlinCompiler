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
%token KW_PRINTLN KW_READLINE KW_PRINT TK_LIT_CHAR TK_LIT_STRING KW_MAIN KW_ARGS

%%

function-main: KW_FUN KW_MAIN '(' KW_ARGS ':' KW_ARRAY '<' KW_STRING '>' ')' block
                ;

block: '{' decls_stmts '}' ;

decls_stmts: decls_or_stmts decls_stmts
            | /*epsilon*/
            ;

decls_or_stmts: decl
              | stmt
              ;


decl: KW_VAL TK_ID '=' expression
    | KW_VAR TK_ID '=' expression
    | KW_VAL TK_ID ':' type '=' expression 
    | KW_VAR TK_ID ':' type '=' expression
    | KW_VAL TK_ID
    | KW_VAR TK_ID
    | KW_VAL TK_ID '=' expression ';'
    | KW_VAR TK_ID '=' expression ';'
    | KW_VAL TK_ID ':' type '=' expression ';'
    | KW_VAR TK_ID ':' type '=' expression ';'
    | KW_VAL TK_ID ';'
    | KW_VAR TK_ID ';'
    ;

stmt: print_stmt
    ;

print_stmt: KW_PRINT '(' expression ')'
          | KW_PRINTLN '(' expression ')'
          | KW_PRINT '(' expression ')' ';'
          | KW_PRINTLN '(' expression ')' ';'
         ;

expression: expression '>' arithmetic_expression
        | expression '<' arithmetic_expression 
        | expression TK_LESS_EQUAL arithmetic_expression   
        | expression TK_GT_EQUAL arithmetic_expression   
        | expression TK_NOT_EQUAL arithmetic_expression   
        | expression TK_EQUAL arithmetic_expression 
        | arithmetic_expression
        ;

arithmetic_expression: arithmetic_expression '+' term
        | arithmetic_expression '-' term
        | term
        ;

term: term '*' factor
    | term '/' factor
    | term '%' factor
    | factor
    ;

factor: '(' expression ')'
    | literal
    | TK_ID
    ;

literal: TK_LIT_CHAR
       | TK_LIT_STRING
       | TK_LIT_INT
       | TK_LIT_FLOAT
       | KW_TRUE
       | KW_FALSE
       ;

type: KW_INT
    | KW_FLOAT
    | KW_BOOLEAN
    | KW_CHAR
    | KW_STRING
    ;

%%