%option noyywrap
%{
  #include "tokens.h"

%}

LETTER [a-zA-Z]
DIGIT [0-9]

%%

{LETTER}({LETTER}|{DIGIT})* { return TK_ID; }
{DIGIT}+"."{DIGIT}+ { return TK_LIT_FLOAT; }
{DIGIT}+ { return TK_LIT_INT; }
"//"[^'']*[\n] { return TK_LINE_COMMENT; }
"/*"[^'']*"/*" { return TK_BLOCK_COMMENT; }
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"%" {return '%';}
"=" {return '=';}
"++" {return TK_INCREMENT;}
"--" {return TK_DECREMENT;}
"&&" {return TK_AND;}
"||" {return TK_OR;}
"!" {return '!';}
"==" {return TK_EQUAL;}
"!=" {return TK_NOT_EQUAL;}
">" {return '>';}
"<" {return '<';}
"<=" {return TK_LESS_EQUAL;}
">=" {return TK_GT_EQUAL;}
"[" {return '[';}
"]" {return ']';}
"(" {return '(';}
")" {return ')';}
"{" {return '{';}
"}" {return '}';}
".." {return TK_RANGE;}
";" {return ';';}
":" {return ':';}
[\t \n \r] {/*ignore*/}
"break" {return KW_BREAK;}/*Palabras reservadas*/
"do" {return KW_DO;}
"else" {return KW_ELSE;}
"false" {return KW_FALSE;}
"true" {return KW_TRUE;}
"for" {return KW_FOR;}
"fun" {return KW_FUN;}
"if" {return KW_IF;}
"in" {return KW_IN;}
"return" {return KW_RETURN;}
"var" {return KW_VAR;}
"continue" {return KW_CONTINUE;}
"Array" {return KW_ARRAY;}
"when" {return KW_WHEN;}
"is" {return KW_IS;}
"null" {return KW_NULL;}
"val" {return KW_VAL;}
"while" {return KW_WHILE;}
"const" {return KW_CONST;}
"Int" {return KW_INT;}
"Float" {return KW_FLOAT;}
"Char" {return KW_CHAR;}
"Boolean" {return KW_BOOLEAN;}
"String" {return KW_STRING;}

"readLine" {return KW_READLINE;}
"print" {return KW_PRINT;}
"\""[^']{0,1}"\"" {return TK_LIT_CHAR;}/*Char*/
"\""[^']*"\"" {return TK_LIT_STRING;}/*Cadena/string*/

. {printf("Caracter invalido %c en la linea %d\n",yytext[0],yylineno);return -1;}

%%