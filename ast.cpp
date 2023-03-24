#include "ast.h"
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include "asm.h"
#include <algorithm>

using namespace std;
extern asmcode assemblyResult;
int globalStackpointer = 0;

class CodeGenerationVarInfo
{
public:
    CodeGenerationVarInfo(bool isParameter, ComplexType *type, int offset)
    {
        this->isParameter = isParameter;
        this->type = type;
        this->offset = offset;
    }
    bool isParameter;
    ComplexType *type;
    int offset;
};
// Maps
map<string, MethodInformation *> methods = {};
map<string, CodeGenerationVarInfo *> codeGenerationVars = {};

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
    list<VarDeclarationStatement *>::iterator it = this->params->begin();
    while (it != this->params->end())
    {
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

ComplexType *CharExpression::getType()
{
    return new ComplexType((PrimitiveType)CHAR, false);
}

ComplexType *StringExpression::getType()
{
    return new ComplexType((PrimitiveType)STRING, false);
}

ComplexType *IntExpression::getType()
{
    return new ComplexType((PrimitiveType)INT, false);
}

ComplexType *FloatExpression::getType()
{
    return new ComplexType((PrimitiveType)FLOAT, false);
}

ComplexType *BooleanExpression::getType()
{
    return new ComplexType((PrimitiveType)BOOLEAN, false);
}

ComplexType *UnaryExpression::getType()
{
    ComplexType *type = this->expr->getType();
    if (this->op == NOT && type->primitiveType != BOOLEAN)
    {
        cerr << "No se puede aplicar el operador NOT a una expresion no booleana" << endl;
    }
    else if (this->op == NEG && type->primitiveType != BOOLEAN)
    {
        cerr << "No se puede aplicar el operador NEG a una expresion no booleana" << endl;
    }
    return type;
}

map<string, PrimitiveType> exprResultTypes = 
{
    {"INT,INT", INT},
    {"INT,FLOAT", FLOAT},
    {"FLOAT,INT", FLOAT},
    {"FLOAT,FLOAT", FLOAT},
    {"STRING,STRING", STRING},
    {"STRING,CHAR", STRING},
    {"CHAR,STRING", STRING},
    {"CHAR,CHAR", CHAR},
    {"BOOLEAN,BOOLEAN", BOOLEAN}
};

string getTypeAsString(ComplexType *type)
{
    if (type->isArray)
    {
        if (type->primitiveType == STRING)
        {
            return "STRING_ARRAY";
        }
        else if (type->primitiveType == CHAR)
        {
            return "CHAR_ARRAY";
        }
        else if (type->primitiveType == BOOLEAN)
        {
            return "BOOLEAN_ARRAY";
        }
        else if (type->primitiveType == FLOAT)
        {
            return "FLOAT_ARRAY";
        }
        else if (type->primitiveType == INT)
        {
            return "INT_ARRAY";
        }
    }
    else
    {
        if (type->primitiveType == STRING)
        {
            return "STRING";
        }
        else if (type->primitiveType == CHAR)
        {
            return "CHAR";
        }
        else if (type->primitiveType == BOOLEAN)
        {
            return "BOOLEAN";
        }
        else if (type->primitiveType == FLOAT)
        {
            return "FLOAT";
        }
        else if (type->primitiveType == INT)
        {
            return "INT";
        }
        return "NONE";
    }
}
// Id
class Context
{
public:
    struct Context *prev;
    map<string, ComplexType *> vars;
};

map<string, ComplexType *> vars;
map<string, ComplexType *> globalVars;
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

ComplexType *getLocalVarType(string id)
{
    Context *context = currentContext;
    while (context != NULL)
    {
        if (context->vars[id] != NULL)
        {
            return context->vars[id];
        }
        context = context->prev;
    }
    return new ComplexType((PrimitiveType)NONE, false);
}

ComplexType *getVarType(string id)
{
    ComplexType *resultType = new ComplexType((PrimitiveType)NONE, false);
    if (currentContext != NULL)
    {
        resultType = getLocalVarType(id);
    }
    if (resultType->primitiveType != NONE)
    {
        return resultType;
    }
    return globalVars[id] != 0 ? globalVars[id] : resultType;
}

ComplexType *IdExpression::getType()
{
    ComplexType *type = getVarType(this->id);
    if (type->primitiveType == NONE)
    {
        cerr << this->id << " no declarada linea: " << this->line << " column " << this->column << endl;
    }
    return type;
}

ComplexType *ArrayAccessExpression::getType()
{
    if (this->index->getType()->primitiveType != INT)
    {
        cerr << "indice debe ser de tipo entero linea:" << this->line << " column: " << this->column << endl;
        return new ComplexType((PrimitiveType)NONE, false);
    }
    return this->id->getType(); // probar
}

ComplexType *MethodCallExpression::getType()
{
    MethodInformation *method = methods[this->id->id];
    if (method == NULL)
    {
        cerr << this->id->id << " no declarado linea: " << this->line << " column " << this->column << endl;
        return new ComplexType((PrimitiveType)NONE, false);
    }

    if (method->parameters->size() > this->args->size())
    {
        cerr << "Muy pocos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return new ComplexType((PrimitiveType)NONE, false);
    }

    if (method->parameters->size() < this->args->size())
    {
        cerr << "Muchos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return new ComplexType((PrimitiveType)NONE, false);
    }
    // validación de tipo
    list<VarDeclarationStatement *>::iterator paramsIt = method->parameters->begin();
    list<Expression *>::iterator argsIt = this->args->begin(); // call
    while (argsIt != this->args->end())
    {
        if ((*argsIt)->getType()->primitiveType != (*paramsIt)->type->primitiveType)
        {
            cerr << "Tipo de dato incorrecto en parámetros, se esperaba tipo: "
                 << getTypeAsString((*paramsIt)->type->primitiveType)
                 << " se obtuvo: " << getTypeAsString((*argsIt)->getType())
                 << " linea: " << this->line << " column " << this->column << endl;
            return new ComplexType((PrimitiveType)NONE, false);
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
    ComplexType *name##Expr::getType()                                                                                                                                               \
    {                                                                                                                                                                                \
        string leftType = getTypeAsString(this->left->getType());                                                                                                                    \
        string rightType = getTypeAsString(this->right->getType());                                                                                                                  \
        PrimitiveType type = exprResultTypes[leftType + "," + rightType];                                                                                                            \
        if (type == 0)                                                                                                                                                               \
        {                                                                                                                                                                            \
            cerr << "El tipo de dato " << leftType << " no puede ser operado con el tipo de dato " << rightType << " linea: " << this->line << " columna: " << this->column << endl; \
        }                                                                                                                                                                            \
        return new ComplexType(type, this->left->getType()->isArray || this->right->getType()->isArray);                                                                             \
    }

#define GET_TYPE_BINARY_EXPR_BOOL(name)                                                                                                                                              \
    ComplexType *name##Expression::getType()                                                                                                                                        \
    {                                                                                                                                                                                \
        string leftType = getTypeAsString(this->left->getType());                                                                                                                    \
        string rightType = getTypeAsString(this->right->getType());                                                                                                                  \
         if (leftType != rightType)                                                                                                                                                   \
        {                                                                                                                                                                            \
            cerr << "El tipo de dato " << leftType << " no puede ser operado con el tipo de dato " << rightType << " linea: " << this->line << " columna: " << this->column << endl; \
        }                                                                                                                                                                            \
        return new ComplexType(BOOLEAN, false);                                                                                                                                                          \
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
    if (this->expr->getType() != INT && this->expr->getType() != FLOAT)
    {
        cerr << "Variable debe ser de tipo entero linea: " << this->line << " columna: " << this->column << " tipo de dato recibido: " << this->expr->getType() << endl;
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

/* End Evaluate Semantic*/

/* Begin Generation Code*/

const char *intTemps[]{"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
set<string> intTempMap;
#define INT_TEMP_COUNT 10

const char *floatTemps[]{"$f0", "$f1", "$f2", "$f3", "$f4", "$f5", "$f6", "$f7", "$f8", "$f9", "$f10", "$f11", "$f12", "$f13", "$f14", "$f15", "$f16", "$f17", "$f18", "$f19", "$f20", "$f21", "$f22", "$f23", "$f24", "$f25", "$f26", "$f27", "$f28", "$f29", "$f30", "$f31"};
set<string> floatTempMap;
#define FLOAT_TEMP_COUNT 32

string getIntTemp()
{
    for (int i = 0; i < INT_TEMP_COUNT; i++)
    {
        // cada que se utilice un registro, lo voy a marcar
        // si llegué al final no lo he utilizado
        if (intTempMap.find(intTemps[i]) == intTempMap.end())
        {
            intTempMap.insert(intTemps[i]);
            return string(intTemps[i]);
        }
    }
    cerr << " No hay registros temporales disponibles" << endl;
    exit(0);
}

string getFloatTemp()
{
    for (int i = 0; i < FLOAT_TEMP_COUNT; i++)
    {
        if (floatTempMap.find(floatTemps[i]) == floatTempMap.end())
        {
            floatTempMap.insert(floatTemps[i]);
            return string(floatTemps[i]);
        }
    }
    cerr << " No hay registros temporales disponibles" << endl;
    exit(0);
}

void releaseRegister(string temp)
{
    intTempMap.erase(temp);
    floatTempMap.erase(temp);
}

int labelCounter = 0;
string newLabel(string prefix)
{
    stringstream label;
    label << prefix << "_" << labelCounter;
    labelCounter++;
    return label.str();
}