%code requires{
    #include "ast.h"
}

%{
    #include <cstdio>
    #include "asm.h"
    #include <fstream>
    #include <iostream>
    extern int yylineno;
    int yylex();
    extern int line;
    extern int column;
    asmcode assemblyResult;
    void yyerror(const char * message){
        fprintf(stderr, "Error: %s in line: %d and column %d\n", message, line, column);
    }

    void writeFile(string name){
        ofstream file;
        file.open(name);
        file<<".data"<<endl
        <<"\t"<< assemblyResult.data<<endl
        <<"\t" << "nextline: .asciiz \"\\n\""<<endl
        <<".text"
        <<"\t"<< assemblyResult.text<<endl
        <<".globl main"<<endl
        <<"\t"<< assemblyResult.code<<endl;
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
        Declaration * decl_t;
        VarDeclarationStatement * var_declaration_t;
        list<Expression *> * expr_list_t;
        list<VarDeclarationStatement *> * var_declaration_list_t;
        list<Statement *> * stmt_list_t;
        ComplexType * type_t;
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

%type<statement_t> stmt print_stmt if_stmt assignation_stmt comment_stmt loop_stmt returnORbreak_stmt methodcall_stmt incre_decre_stmt for_stmt
%type<statement_t> program block func while_stmt do_while_stmt decls_or_stmts
%type<stmt_list_t> decls_stmts functions
%type<expr_t>  array_arg literal factor unary_expression incre_decre_expression term arithmetic_expression comparison_expression expression
%type<decl_t> decl decl_inline
%type<var_declaration_t> variable_decl array_param
%type<int_t> type_identifier
%type<expr_list_t> args func_CallLiterals
%type<type_t> func_type type
%type<var_declaration_list_t> params

%precedence TK_EQUAL TK_NOT_EQUAL
%precedence TK_AND
%precedence TK_OR

%%

program: functions 
        {
           $$ = new BlockFunctionStatement($1, line, column);
           //$$->evaluateSemantic();
           string code = $$->generateCode();
           assemblyResult.code += code;
           writeFile("result.asm");
        }
        ;

functions: func functions { $$ = $2; $$->push_back($1); }
        | /*eps*/ { $$ = new list<Statement*>; }
        ;

func: KW_FUN TK_ID '(' params ')' ':' func_type block { $$ = new FunctionStatement($2, $4, $7, $8, line, column); }
    | KW_FUN TK_ID '(' params ')' block { $$ = new FunctionStatement($2, $4, new ComplexType(VOID, false), $6, line, column); }
    | KW_FUN KW_MAIN '(' KW_ARGS ':' KW_ARRAY '<' KW_STRING '>' ')' block {}
    | KW_FUN KW_MAIN '(' ')' block { $$ = new FunctionStatement("main", new list<VarDeclarationStatement *>, new ComplexType(VOID, false), $5, line, column);  }
    ;

block: '{' decls_stmts '}' { $$ = new BlockStatement($2, line, column); }
        ;

decls_stmts: decls_or_stmts decls_stmts { $$ = $2; $$->push_back($1); }
            | /*epsilon*/ { $$ = new list<Statement *>; }
            ;

decls_or_stmts: decl { $$ = $1; }
              | stmt { $$ = $1; }
              ;

decl: KW_VAL decl_inline { $$ = $2; }
    | KW_VAR decl_inline { $$ = $2; }
    ;

decl_inline: variable_decl { $$ = $1; }
        |   variable_decl ';' { $$ = $1; }
        |   variable_decl '=' expression { $$ = new VarDeclAssignStatement($1, $3, line, column); }
        |   variable_decl '=' expression ';' { $$ = new VarDeclAssignStatement($1, $3, line, column); }
        |   TK_ID '=' KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}' { $$ = new ArrayVarDeclAssignStatement($1, $5, $8, $11, line, column); }
        |   TK_ID '=' KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}' ';' { $$ = new ArrayVarDeclAssignStatement($1, $5, $8, $11, line, column); }
        ;

variable_decl: TK_ID ':' func_type { $$ = new VarDeclarationStatement($1,$3,line, column);}
            ;

params: TK_ID ':' type ',' params { $$ = $5; $$->push_back(new VarDeclarationStatement($1, $3, line, column)); }
        | TK_ID ':' type { $$ = new list<VarDeclarationStatement *>; $$->push_back(new VarDeclarationStatement($1, $3, line, column));}
        | array_param params { $$ = $2; $$->push_back($1); }
        | /*epsilon*/ { $$ = new list<VarDeclarationStatement *>; }
        ;

array_param: TK_ID ':' KW_ARRAY '<' type_identifier '>' ',' { $$ = new VarDeclarationStatement($1, new ArrayType(1,(PrimitiveType)$5), line, column); }
        | TK_ID ':' KW_ARRAY '<' type_identifier '>' { $$ = new VarDeclarationStatement($1, new ArrayType(1,(PrimitiveType)$5), line, column); }
        ;

args: TK_ID ',' args { $$ = $3; $$->push_back(new IdExpression($1, line, column)); }
        | TK_ID { $$ = new list<Expression *>; $$->push_back(new IdExpression($1, line, column)); }
        | literal ',' args { $$ = $3; $$->push_back($1); }
        | literal { $$ = new list<Expression *>; $$->push_back($1); }
        | array_arg args { $$ = $2; $$->push_back($1); }
        ;

array_arg: KW_ARRAYOF '<' type_identifier '>' '(' func_CallLiterals ')' ',' { $$ = new ArrayArgExpression(new ArrayType(1,(PrimitiveType)$3), $6, line, column); }
        | KW_ARRAYOF '<' type_identifier '>' '(' func_CallLiterals ')' { $$ = new ArrayArgExpression(new ArrayType(1,(PrimitiveType)$3), $6, line, column); }
        ;

stmt: print_stmt { $$ = $1;}
    | if_stmt { $$ = $1;} 
    | assignation_stmt { $$ = $1;}
    | comment_stmt { $$ = $1;}
    | loop_stmt { $$ = $1;}
    | returnORbreak_stmt { $$ = $1;}
    | methodcall_stmt { $$ = $1;}
    | incre_decre_stmt { $$ = $1;} 
    ;

incre_decre_stmt: TK_ID TK_INCREMENT { $$ = new IncreDecreStatement(new IncreDecreExpression(INCRE, new IdExpression($1, line, column), line, column), line, column); }
                | TK_ID TK_INCREMENT ';' { $$ = new IncreDecreStatement(new IncreDecreExpression(INCRE, new IdExpression($1, line, column), line, column), line, column); }
                | TK_ID TK_DECREMENT { $$ = new IncreDecreStatement(new IncreDecreExpression(DECRE, new IdExpression($1, line, column), line, column), line, column); }
                | TK_ID TK_DECREMENT ';' { $$ = new IncreDecreStatement(new IncreDecreExpression(DECRE, new IdExpression($1, line, column), line, column), line, column); }
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

while_stmt: KW_WHILE '(' expression ')' block { $$ = new WhileStatement($3, $5, line, column); }
          | KW_WHILE '(' expression ')' stmt { $$ = new WhileStatement($3, $5, line, column); }
;

do_while_stmt: KW_DO block KW_WHILE '(' expression ')' { $$ = new WhileStatement($5, $2, line, column); }
             | KW_DO stmt KW_WHILE '(' expression ')' { $$ = new WhileStatement($5, $2, line, column); }
             | KW_DO block KW_WHILE '(' expression ')' ';' { $$ = new WhileStatement($5, $2, line, column); }
             | KW_DO stmt KW_WHILE '(' expression ')' ';' { $$ = new WhileStatement($5, $2, line, column); }
             ;

for_stmt: KW_FOR '(' TK_ID KW_IN expression KW_UNTIL expression ')' block { $$ = new ForStatement($3,$5,$7,$9, line, column);}
    | KW_FOR '(' TK_ID KW_IN expression KW_UNTIL expression ')' stmt { $$ = new ForStatement($3,$5,$7,$9, line, column);}
    ; 
            
comment_stmt: TK_LINE_COMMENT { $$ = new CommentStatement($1,line, column);}
            | TK_BLOCK_COMMENT { $$ = new CommentStatement($1,line, column);}
            ;

returnORbreak_stmt: KW_RETURN expression ';' { $$ = new ReturnStatement($2, line, column);}
            | KW_RETURN expression { $$ = new ReturnStatement($2, line, column);}
            | KW_BREAK ';' { $$ = new ReturnStatement(NULL, line, column);}
            | KW_BREAK { $$ = new ReturnStatement(NULL, line, column);}
            ; 

methodcall_stmt: TK_ID '(' args ')' { $$ = new ExpressionStatement(new MethodCallExpression(new IdExpression($1,line,column),$3, line,column),line,column);}
                ;
                
//EXPRESSIONS

expression: expression TK_OR comparison_expression { $$ = new OrExpression($1, $3, line, column); }
        | expression TK_AND comparison_expression  { $$ = new AndExpression($1, $3, line, column); }
        | expression TK_EQUAL comparison_expression { $$ = new EqExpression($1, $3, line, column); }
        | expression TK_NOT_EQUAL comparison_expression { $$ = new NeqExpression($1, $3, line, column); }
        | comparison_expression { $$ = $1; }
        ;

comparison_expression: comparison_expression '>' arithmetic_expression { $$ = new GtExpression($1, $3, line, column); }
        | comparison_expression '<' arithmetic_expression { $$ = new LtExpression($1, $3, line, column); }
        | comparison_expression TK_LESS_EQUAL arithmetic_expression  { $$ = new LteExpression($1, $3, line, column); }
        | comparison_expression TK_GT_EQUAL arithmetic_expression { $$ = new GteExpression($1, $3, line, column); } 
        | arithmetic_expression { $$ = $1; }
        ;

arithmetic_expression: arithmetic_expression '+' term { $$ = new AddExpression($1, $3, line, column); }
        | arithmetic_expression '-' term { $$ = new SubExpression($1, $3, line, column); }
        | arithmetic_expression TK_RANGE term { $$ = new RangeExpression($1, $3, line, column); }
        | term { $$ = $1; }
        ;

term: term '*' unary_expression { $$ = new MultExpression($1, $3, line, column); }
    | term '/' unary_expression { $$ = new DivExpression($1, $3, line, column); }
    | term '%' unary_expression { $$ = new ModExpression($1, $3, line, column); }
    | unary_expression { $$ = $1; }
    ;

unary_expression: '!' factor  { $$ = new UnaryExpression(NOT, $2, line, column); }
                | '-' factor { $$ = new UnaryExpression(NEG, $2, line, column); }
                | incre_decre_expression { $$ = $1; }
                | factor { $$ = $1; }
                ;

incre_decre_expression: TK_INCREMENT factor  { $$ = new IncreDecreExpression(INCRE, $2, line, column); }
                | TK_DECREMENT factor { $$ = new IncreDecreExpression(DECRE, $2, line, column); } 
                | factor TK_INCREMENT { $$ = new IncreDecreExpression(INCRE, $1, line, column); }
                | factor TK_DECREMENT { $$ = new IncreDecreExpression(DECRE, $1, line, column); }

factor: '(' expression ')' { $$ = $2; }
    | literal { $$ = $1; }
    | TK_ID { $$ = new IdExpression($1, line, column); }
    | TK_ID '[' expression ']' { $$ = new ArrayAccessExpression(new IdExpression($1, line, column), $3, line, column); } //array access
    | TK_ID '(' args ')' { $$ = new MethodCallExpression(new IdExpression($1,line,column),$3, line,column); }
    ;

literal: TK_LIT_CHAR { $$ = new CharExpression($1, line, column); }
       | TK_LIT_STRING { $$ = new StringExpression($1, line, column); }
       | TK_LIT_INT { $$ = new IntExpression($1, line, column); }
       | TK_LIT_FLOAT { $$ = new FloatExpression($1, line, column); }
       | KW_TRUE { $$ = new BooleanExpression(true, line, column); }
       | KW_FALSE { $$ = new BooleanExpression(false, line, column); }
       ;

func_CallLiterals: literal ',' func_CallLiterals { $$ = $3; $$->push_back($1); }
                | literal { $$ = new list<Expression *>; $$->push_back($1); }
                ;

type: type_identifier { $$ = new ComplexType((PrimitiveType)$1, false); /*solo Primitive Type (non Array)*/ }
     ;

func_type: type_identifier { $$ = new ComplexType((PrimitiveType)$1, false); }
    | KW_ARRAY '<' type_identifier '>' { $$ = new ArrayType(1,(PrimitiveType)$3); /*Si incluye Array*/}
    ;

type_identifier: KW_INT { $$ = INT; }
    | KW_FLOAT { $$ = FLOAT;}
    | KW_BOOLEAN { $$ = BOOLEAN;}
    | KW_CHAR { $$ = CHAR;}
    | KW_STRING { $$ = STRING;}
    ;

%%