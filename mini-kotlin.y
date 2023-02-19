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

%token TK_ID TK_LIT_FLOAT TK_LIT_INT
%token TK_LINE_COMMENT TK_BLOCK_COMMENT
%token TK_INCREMENT TK_DECREMENT TK_AND TK_OR TK_EQUAL TK_NOT_EQUAL
%token TK_LESS_EQUAL TK_GT_EQUAL TK_RANGE
%token KW_BREAK KW_DO KW_ELSE KW_FALSE KW_TRUE KW_FOR KW_FUN KW_IF KW_IN
%token KW_RETURN KW_VAR KW_CONTINUE KW_ARRAY KW_WHEN KW_IS KW_NULL KW_VAL
%token KW_WHILE KW_CONST KW_INT KW_FLOAT KW_CHAR KW_BOOLEAN KW_STRING KW_UNTIL
%token KW_PRINTLN KW_READLINE KW_PRINT TK_LIT_CHAR TK_LIT_STRING KW_MAIN KW_ARGS

%precedence TK_EQUAL TK_NOT_EQUAL
%precedence TK_AND
%precedence TK_OR

%%

program: function-main
        ;

function-main: KW_FUN KW_MAIN '(' KW_ARGS ':' KW_ARRAY '<' KW_STRING '>' ')' block
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

variable_decl: TK_ID ':' type 
            | TK_ID
            ;

stmt: print_stmt
    | if_stmt
    | assignation_stmt
    | comment_stmt
    | loop_stmt
    ;

assignation_stmt: TK_ID '=' expression
                | TK_ID '=' if_stmt
;

if_stmt: KW_IF '(' expression ')' block
       | KW_IF '(' expression ')' decls_or_stmts
       | KW_IF '(' expression ')' block KW_ELSE block
;

print_stmt: KW_PRINT '(' expression ')'
          | KW_PRINTLN '(' expression ')'
          | KW_PRINT '(' expression ')' ';'
          | KW_PRINTLN '(' expression ')' ';'
         ;

loop_stmt: for_stmt
        ;

for_stmt: KW_FOR '(' variable_decl KW_IN expression KW_UNTIL expression ')' block 
    | KW_FOR '(' variable_decl KW_IN expression KW_UNTIL expression ')' stmt
    | KW_FOR '(' variable_decl KW_IN expression ')' block 
    | KW_FOR '(' variable_decl KW_IN expression ')' stmt 
    ; 
            
comment_stmt: TK_LINE_COMMENT | TK_BLOCK_COMMENT;

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

type: KW_INT
    | KW_FLOAT
    | KW_BOOLEAN
    | KW_CHAR
    | KW_STRING
    ;

%%