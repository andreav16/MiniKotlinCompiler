#include "ast.h"
#include <map>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

// Maps
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

void ArrayArgExpression::print()
{
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

void BlockStatement::print()
{
    cout << "Block Statement line: " << this->line << " column: " << this->column << endl;
    list<Statement *>::iterator itStmt = this->statements->begin();
    while (itStmt != this->statements->end())
    {
        (*itStmt)->print();
        itStmt++;
    }
}

void FunctionStatement::print()
{
    cout << " Function " << this->id << " Statement line: " << this->line << " column: " << this->column << endl;
    list<VarDeclarationStatement*>::iterator it = this->params->begin();
    while(it != this->params->end()){
        (*it)->print();
        it++;
    }
    this->block->print();
}

void BlockFunctionStatement::print()
{
    cout << "Block Functions Statement line: " << this->line << " column: " << this->column << endl;
    list<Statement *>::iterator itStmt = this->statements->begin();
    while (itStmt != this->statements->end())
    {
        (*itStmt)->print();
        itStmt++;
    }
}

/* Expressions Get Type*/

PrimitiveType CharExpression::getType()
{
    return CHAR;
}

PrimitiveType StringExpression::getType()
{
    return STRING;
}

PrimitiveType IntExpression::getType()
{
    return INT;
}

PrimitiveType FloatExpression::getType()
{
    return FLOAT;
}

PrimitiveType BooleanExpression::getType()
{
    return BOOLEAN;
}

PrimitiveType UnaryExpression::getType()
{
    PrimitiveType type = this->expr->getType();
    if (this->op == NOT && type != BOOLEAN)
    {
        cerr << "No se puede aplicar el operador NOT a una expresion no booleana" << endl;
    }
    else if (this->op == NEG && type != BOOLEAN)
    {
        cerr << "No se puede aplicar el operador NEG a una expresion no booleana" << endl;
    }
    return type;
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

string getTypeAsString(PrimitiveType type)
{
    if (type == STRING)
    {
        return "STRING";
    }
    else if (type == CHAR)
    {
        return "CHAR";
    }
    else if (type == BOOLEAN)
    {
        return "BOOLEAN";
    }
    else if (type == FLOAT)
    {
        return "FLOAT";
    }
    else if (type == INT)
    {
        return "INT";
    }
    return "NONE";
}
// Id
class Context
{
public:
    struct Context *prev;
    map<string, PrimitiveType> vars;
};

map<string, PrimitiveType> vars;
map<string, PrimitiveType> globalVars;
Context *currentContext = NULL;

void pushContext()
{
    vars.clear();
    Context *context = new Context();
    context->vars = vars;
    context->prev = currentContext;
    currentContext = context;
}

void popContext()
{
    if (currentContext != NULL)
    {
        Context *previous = currentContext->prev;
        free(currentContext);
        currentContext = previous;
    }
}

PrimitiveType getLocalVarType(string id)
{
    Context *context = currentContext;
    while (context != NULL)
    {
        if (context->vars[id] != 0)
        {
            return context->vars[id];
        }
        context = context->prev;
    }
    return NONE;
}

PrimitiveType getVarType(string id)
{
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

PrimitiveType IdExpression::getType()
{
    PrimitiveType type = getVarType(this->id);
    if (type == NONE)
    {
        cerr << this->id << " no declarada linea: " << this->line << " column " << this->column << endl;
    }
    return type;
}

PrimitiveType ArrayAccessExpression::getType()
{
    if(this->index->getType() != INT){
        cerr << "indice debe ser de tipo entero linea:" << this->line << " column: " << this->column << endl;
        return NONE;
    }
    return this->id->getType();//probar
}

PrimitiveType MethodCallExpression::getType()
{
    MethodInformation *method = methods[this->id->id];
    if (method == NULL)
    {
        cerr << this->id->id << " no declarado linea: " << this->line << " column " << this->column << endl;
        return NONE;
    }

    if (method->parameters->size() > this->args->size())
    {
        cerr << "Muy pocos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return NONE;
    }

    if (method->parameters->size() < this->args->size())
    {
        cerr << "Muchos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return NONE;
    }
    //validación de tipo
    list<VarDeclarationStatement *>::iterator paramsIt = method->parameters->begin();
    list<Expression *>::iterator argsIt = this->args->begin();//call
    while (argsIt != this->args->end())
    {
        if ((*argsIt)->getType() != (*paramsIt)->type->primitiveType)
        {
            cerr << "Tipo de dato incorrecto en parámetros, se esperaba tipo: " 
            << getTypeAsString((*paramsIt)->type->primitiveType) 
            << " se obtuvo: " << getTypeAsString((*argsIt)->getType()) 
            << " linea: " << this->line << " column " << this->column << endl;
            return NONE;
        }
        argsIt++;
        paramsIt++;
    }
    return method->returnType;
}

PrimitiveType IncreDecreExpression::getType()
{
    return this->expr->getType();
}

PrimitiveType ArrayArgExpression::getType()
{
    return this->getType(); // no se
}

#define GET_TYPE_BINARY_EXPR(name)                                                                                                                                                   \
    PrimitiveType name##Expression::getType()                                                                                                                                        \
    {                                                                                                                                                                                \
        string leftType = getTypeAsString(this->left->getType());                                                                                                                    \
        string rightType = getTypeAsString(this->right->getType());                                                                                                                  \
        PrimitiveType type = exprResultTypes[leftType + "," + rightType];                                                                                                            \
        if (type == 0)                                                                                                                                                               \
        {                                                                                                                                                                            \
            cerr << "El tipo de dato " << leftType << " no puede ser operado con el tipo de dato " << rightType << " linea: " << this->line << " columna: " << this->column << endl; \
        }                                                                                                                                                                            \
        return type;                                                                                                                                                                 \
    }

#define GET_TYPE_BINARY_EXPR_BOOL(name)                                                                                                                                              \
    PrimitiveType name##Expression::getType()                                                                                                                                        \
    {                                                                                                                                                                                \
        string leftType = getTypeAsString(this->left->getType());                                                                                                                    \
        string rightType = getTypeAsString(this->right->getType());                                                                                                                  \
        if (leftType != rightType)                                                                                                                                                   \
        {                                                                                                                                                                            \
            cerr << "El tipo de dato " << leftType << " no puede ser operado con el tipo de dato " << rightType << " linea: " << this->line << " columna: " << this->column << endl; \
        }                                                                                                                                                                            \
        return BOOLEAN;                                                                                                                                                              \
    }

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

/*Evaluate Semantic of Declarations*/
void VarDeclarationStatement::evaluateSemantic()
{
    if (getVarType(this->id) != NONE)
    {
        cerr << "Ya existe una variable con el nombre " << (this->id) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
     // En el caso que sea un tipo Array
     ArrayType *arrayType = static_cast<ArrayType *>(this->type);
     if (this->type->isArray && arrayType->size <= 0)
     {
         cerr << "El fin de un arreglo debe ser mayor a 0 linea " << this->line << " columna: " << this->column << endl;
         return;
     }
     currentContext->vars[this->id] = this->type->primitiveType;
}

void VarDeclAssignStatement::evaluateSemantic()
{
    // pend
}

void ArrayVarDeclAssignStatement::evaluateSemantic()
{
    // pend
}

/*Evaluate Semantic of Statements*/

void PrintStatement::evaluateSemantic()
{
    PrimitiveType type = this->expression->getType();
    if (type != STRING)
    {
        cerr << "Solo se permite imprimir tipo de dato STRING linea:" << this->line << " columna: " << this->column << endl;
        return;
    }
}

void IfStatement::evaluateSemantic()
{
    if (this->expression->getType() != BOOLEAN)
    {
        cerr << "El if requiere una expresion booleana linea: " << this->line << " columna " << this->column << endl;
        return;
    }
    pushContext();
    this->trueStatement->evaluateSemantic();
    popContext();
    if (this->falseStatement != NULL)
    {
        this->falseStatement->evaluateSemantic();
    }
}

void AssignationStatement::evaluateSemantic()
{
   if (this->isArray && this->index->getType() != INT)
    {
        cerr << "El indice en el arreglo debe ser un entero linea: " << this->line << " columna: " << this->column << endl;
        return;
    }
    PrimitiveType varType = getVarType(this->id);
    PrimitiveType exprType = this->expression->getType();
    if (varType != exprType)
    {
        cerr << "No se puede asignar " << getTypeAsString(exprType) << " a la variable de tipo " << getTypeAsString(varType) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
}

void CommentStatement::evaluateSemantic()
{
    // Confirmar que no ocupa validación de semántica :)
}

void ForStatement::evaluateSemantic()
{
    PrimitiveType varType = getVarType(this->iteratorId);
    PrimitiveType fromExprType = this->fromExpr->getType();
    PrimitiveType toExprType = this->toExpr->getType();
    if (varType != fromExprType)
    {
        cerr << "No se puede asignar " << getTypeAsString(fromExprType) << " a la variable de tipo " << getTypeAsString(varType) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    if (varType != toExprType)
    {
        cerr << "No se puede asignar " << getTypeAsString(toExprType) << " a la variable de tipo " << getTypeAsString(varType) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    pushContext();
    this->stmt->evaluateSemantic();
    popContext();
}

void ReturnStatement::evaluateSemantic()
{
    // validar que el expression->getType sea el mismo que el tipo de la función en la que está
}

void ExpressionStatement::evaluateSemantic()
{
    this->expr->getType();
}

void IncreDecreStatement::evaluateSemantic()
{
    if(this->expr->getType() != INT && this->expr->getType() != FLOAT){
        cerr << "Variable debe ser de tipo entero linea: " << this->line << " columna: " << this->column <<
        " tipo de dato recibido: "<<this->expr->getType()<< endl;
        return;
    }
}

void WhileStatement::evaluateSemantic()
{
    if (this->expr->getType() != BOOLEAN)
    {
        cerr << "El while requiere una expresion booleana línea: " << this->line << " columna " << this->column << endl;
        return;
    }
    pushContext();
    this->stmt->evaluateSemantic();
    popContext();
}

void BlockStatement::evaluateSemantic()
{
    pushContext();
    list<Statement *>::iterator itStmt = this->statements->begin();
    while (itStmt != this->statements->end())
    {
        (*itStmt)->evaluateSemantic();
        itStmt++;
    }
    popContext();
}

void FunctionStatement::evaluateSemantic()
{

    // Un método no puede recibir más de 4 parametros
     if (this->params->size() > 4)
    {
        cerr << "Solo se soportan 4 parametros por método, método " << this->id << " linea " << this->line << " columna " << this->column << endl;
        return;
    }
    if (methods[this->id] != NULL)
    {
        cerr << "Ya existe un método con el nombre " << this->id << " linea " << this->line << " columna " << this->column << endl;
        return;
    }
    methods[this->id] = new MethodInformation(this->returnType->primitiveType, this->params);
    pushContext();
    this->block->evaluateSemantic();
    list<VarDeclarationStatement *>::iterator itStmt = this->params->begin();
    while (itStmt != this->params->end())
    {
        (*itStmt)->evaluateSemantic();
        itStmt++;
    }
    popContext();
}

void BlockFunctionStatement::evaluateSemantic()
{
    list<Statement *>::iterator itStmt = this->statements->begin();
    while (itStmt != this->statements->end())
    {
        (*itStmt)->evaluateSemantic();
        itStmt++;
    }
}
