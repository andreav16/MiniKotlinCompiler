#include "ast.h"
#include <map>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

//Maps
map<string, MethodInformation *> methods = {};

/*PRINTS*/

void CharExpression::print()
{
    cout << "char expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void StringExpression::print()
{
    cout << "string expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void IntExpression::print()
{
    cout << "int expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void FloatExpression::print()
{
    cout << "float expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void BooleanExpression::print()
{
    cout << "boolean expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void IdExpression::print()
{
    cout << "Id expr: " << this->id << " line: " << this->line << " column : " << this->column << endl;
}

void ArrayAccessExpression::print()
{
    cout << "Array access expr: " << this->id << " line: " << this->line << " column : " << this->column << endl;
}

void MethodCallExpression::print()
{
    cout << "Method call expression: " << this->id->id << " line:" << this->line << " column : " << this->column << endl;
}

void UnaryExpression::print()
{
    cout << "Unary expr operator: " << this->op << " expression: " << this->expr << " line: " << this->line << " column : " << this->column << endl;
}

void IncreDecreExpression::print()
{
    cout << "Incre/decre expr operator: " << this->op << " expression: " << this->expr << " line: " << this->line << " column : " << this->column << endl;
}

#define PRINT_BINARY_EXPRESSION(name) \
    void name##Expression::print()    \
    {                                 \
        cout << "" << endl;           \
    };

PRINT_BINARY_EXPRESSION(Mult);
PRINT_BINARY_EXPRESSION(Div);
PRINT_BINARY_EXPRESSION(Mod);
PRINT_BINARY_EXPRESSION(Add);
PRINT_BINARY_EXPRESSION(Sub);
PRINT_BINARY_EXPRESSION(Range);
PRINT_BINARY_EXPRESSION(Gt);
PRINT_BINARY_EXPRESSION(Lt);
PRINT_BINARY_EXPRESSION(Gte);
PRINT_BINARY_EXPRESSION(Lte);
PRINT_BINARY_EXPRESSION(Or);
PRINT_BINARY_EXPRESSION(And);
PRINT_BINARY_EXPRESSION(Eq);
PRINT_BINARY_EXPRESSION(Neq);

void ParamExpression::print(){
    cout << "Params expr of type " << this->type->primitiveType << " Line: " << this->line << " column : " << this->column << endl;
}

void ArrayParamExpression::print(){
    cout << "Arrat param expr of type " << this->type->primitiveType << " Line: " << this->line << " column : " << this->column << endl;
}

void ArrayArgExpression::print(){
    cout << "Array arg expr of type " << this->type->primitiveType << " Line: " << this->line << " column : " << this->column << endl;
}

void VarDeclarationStatement::print()
{
    cout << "Var Declaration Statement line: " << this->line << " column: " << this->column << endl;
}

void VarDeclAssignStatement::print()
{
    cout << "Var decl and assign Statement line: " << this->line << " column: " << this->column << endl;
}

void ArrayVarDeclAssignStatement::print()
{
    cout << "Array var decl Statement line: " << this->line << " column: " << this->column << endl;
}

void PrintStatement::print()
{
    cout << "Print Statement line: " << this->line << " column: " << this->column << endl;
}

void IfStatement::print()
{
    cout << "If Statement line: " << this->line << " column: " << this->column << endl;
    this->trueStatement->print();
    if (this->falseStatement != NULL)
    {
        this->falseStatement->print();
    }
}

void AssignationStatement::print()
{
    cout << "Assignation Statement id: " << this->id << " line: " << this->line << " column: " << this->column << endl;
}

void CommentStatement::print()
{
    cout << " Comment Statement line: " << this->line << " column: " << this->column << endl;
}

void ForStatement::print()
{
    cout << " For Statement line: " << this->line << " column: " << this->column << endl;
    this->stmt->print();
}

void ReturnStatement::print()
{
    cout << " Return Statement line: " << this->line << " column: " << this->column << endl;
}

void ExpressionStatement::print()
{
    cout << " Expression Statement line: " << this->line << " column: " << this->column << endl;
}

void IncreDecreStatement::print()
{
    cout << " Incre/decre Statement line: " << this->line << " column: " << this->column << endl;
}

void WhileStatement::print()
{
    cout << " While Statement line: " << this->line << " column: " << this->column << endl;
    this->stmt->print();
}

void BlockStatement::print(){
    cout << "Block Statement line: " << this->line << " column: " << this->column << endl;
    list<Statement *>::iterator itStmt = this->statements->begin();
    while(itStmt != this->statements->end()){
        (*itStmt)->print();
        itStmt++;
    }
}

void FunctionStatement::print(){
    cout << " Function " <<this->id<<" Statement line: " << this->line << " column: " << this->column << endl;
    this->block->print();
}

void BlockFunctionStatement::print(){
    cout << "Block Functions Statement line: " << this->line << " column: " << this->column << endl;
    list<Statement *>::iterator itStmt = this->statements->begin();
    while(itStmt != this->statements->end()){
        (*itStmt)->print();
        itStmt++;
    }
}

/* Expression Get Type*/

PrimitiveType CharExpression::getType(){
    return CHAR;
}

PrimitiveType StringExpression::getType(){
    return STRING;
}

PrimitiveType IntExpression::getType(){
    return INT;
}


PrimitiveType FloatExpression::getType(){
    return FLOAT;
}

PrimitiveType BooleanExpression::getType(){
    return BOOLEAN;
}


//Id
class Context{
    public:
        struct Context * prev;
        map<string, PrimitiveType> vars;
};

map<string, PrimitiveType> vars;
map<string, PrimitiveType> globalVars;
Context * currentContext = NULL;

void pushContext(){
    vars.clear();
    Context * context = new Context();
    context->vars = vars;
    context->prev = currentContext;
    currentContext = context;
}

void popContext(){
    if (currentContext != NULL)
    {
        Context * previous = currentContext->prev;
        free(currentContext);
        currentContext = previous;
    }
}

PrimitiveType getLocalVarType(string id){
    Context * context = currentContext;
    while (context  != NULL)
    {
        if (context->vars[id] != 0)
        {
            return context->vars[id];
        }
        context = context->prev;
    }
    return NONE;
}

PrimitiveType getVarType(string id){
    PrimitiveType resultType = NONE;
    if (currentContext != NULL)
    {
        resultType = getLocalVarType(id);
    }
    if (resultType != NONE)
    {
        return resultType;
    }
    return globalVars[id] != 0 ? globalVars[id] : NONE;
}

PrimitiveType IdExpression::getType(){
    PrimitiveType type = getVarType(this->id);
    if (type == NONE)
    {
        cerr<<this->id<<" no declarada linea: "<<this->line<<" column "<<this->column<<endl;
    }
    
    return type;
}

PrimitiveType ArrayAccessExpression::getType(){
    return this->id->getType();
}

PrimitiveType MethodCallExpression::getType()
{
    MethodInformation * method = methods[this->id->id];
    if (method == NULL)
    {
        cerr<<this->id->id<<" no declarado linea: "<<this->line<<" column "<<this->column<<endl;
        return NONE;
    }
  
    if (method->parameters->size() > this->args->size())
    {
        cerr<<"Muy pocos argumentos para el método: "<<this->id->id <<" linea: "<<this->line<<" column "<<this->column<<endl;
        return NONE;
    }
    
    if (method->parameters->size() < this->args->size())
    {
        cerr<<"Muchos argumentos para el método: "<<this->id->id <<" linea: "<<this->line<<" column "<<this->column<<endl;
        return NONE;
    }

    /*
    ComplexType * paramsType = method->parameters;
    list<Expression*>::iterator argsIt = this->args->begin();
    while (argsIt != this->args->end())
    {
        if ((*argsIt)->getType() != paramsType->primitiveType)
        {   
            cerr<<"Tipo de dato incorrecto en parámetros, se esperaba tipo: "<<getTypeAsString(paramsType->primitiveType)<<" se obtuvo: "<< getTypeAsString((*argsIt)->getType()) <<" linea: "<<this->line<<" column "<<this->column<<endl;
            return NONE;
        }
        argsIt++;
    }
    
    */

    return method->returnType;
}

PrimitiveType IncreDecreExpression::getType()
{
    return this->expr->getType();
}

PrimitiveType UnaryExpression::getType(){
    PrimitiveType type = this->expr->getType();
    if (this->op == NOT && type != BOOLEAN)
    {
        cerr<<"No se puede aplicar el operador NOT a una expresion no booleana"<<endl;
    }else if (this-> op == NEG && type != BOOLEAN)
    {
        cerr<<"No se puede aplicar el operador NEG a una expresion no booleana"<<endl;
    }
    return type;
}

PrimitiveType ParamExpression::getType(){
    return this->getType(); //no se 
}

PrimitiveType ArrayParamExpression::getType(){
    return this->getType(); //no se 
}

PrimitiveType ArrayArgExpression::getType(){
    return this->getType(); //no se 
}

map<string, PrimitiveType> exprResultTypes = {
    {"INT,INT", INT},
    {"INT,FLOAT", FLOAT},
    {"FLOAT,INT", FLOAT},
    {"FLOAT,FLOAT", FLOAT},
    {"STRING,STRING", STRING},
    {"STRING,CHAR", STRING},
    {"CHAR,STRING", STRING},
    {"CHAR,CHAR", CHAR},
    {"BOOLEAN,BOOLEAN", BOOLEAN}, 
};

string getTypeAsString(PrimitiveType type){
    if (type == STRING)
    {
        return "STRING";
    }else if(type == CHAR){
        return "CHAR";
    }else if(type == BOOLEAN){
        return "BOOLEAN";
    }else if(type == INT){
        return "INT";
    }
    return "NONE";
}

#define GET_TYPE_BINARY_EXPR(name)\
PrimitiveType name##Expression::getType(){\
    string leftType = getTypeAsString(this->left->getType());\
    string rightType = getTypeAsString(this->right->getType());\
    PrimitiveType type = exprResultTypes[leftType+","+rightType];\
    if(type == 0){\
        cerr<<"El tipo de dato "<<leftType<<" no puede ser operado con el tipo de dato "<<rightType<<" linea: "<<this->line<<" columna: "<<this->column<<endl;\
    }\
    return type;\
}\

#define GET_TYPE_BINARY_EXPR_BOOL(name)\
PrimitiveType name##Expression::getType(){\
    string leftType = getTypeAsString(this->left->getType());\
    string rightType = getTypeAsString(this->right->getType());\
    if(leftType != rightType){\
        cerr<<"El tipo de dato "<<leftType<<" no puede ser operado con el tipo de dato "<<rightType<<" linea: "<<this->line<<" columna: "<<this->column<<endl;\
    }\
    return BOOLEAN;\
}\


GET_TYPE_BINARY_EXPR(Mult);
GET_TYPE_BINARY_EXPR(Div);
GET_TYPE_BINARY_EXPR(Mod);
GET_TYPE_BINARY_EXPR(Add);
GET_TYPE_BINARY_EXPR(Sub);
GET_TYPE_BINARY_EXPR(Range);
GET_TYPE_BINARY_EXPR(And);
GET_TYPE_BINARY_EXPR(Or);
GET_TYPE_BINARY_EXPR_BOOL(Gt);
GET_TYPE_BINARY_EXPR_BOOL(Lt);
GET_TYPE_BINARY_EXPR_BOOL(Gte);
GET_TYPE_BINARY_EXPR_BOOL(Lte);
GET_TYPE_BINARY_EXPR_BOOL(Eq);
GET_TYPE_BINARY_EXPR_BOOL(Neq);

