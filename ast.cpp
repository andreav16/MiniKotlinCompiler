#include "ast.h"
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include "asm.h"
#include "algorithm"

using namespace std;
extern asmcode assemblyResult;
int globalStackpointer = 0;

class CodeGenerationVarInfo
{
public:
    CodeGenerationVarInfo(bool isParameter, ComplexType *type, int offset)
    {
        this->isParameter = isParameter;
        this->offset = offset;
        this->type = type;
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

void ReadExpression::print()
{
    cout << "Read expr of type " << this->primitiveType << " Line: " << this->line << " column : " << this->column << endl;
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
    return new ComplexType(CHAR, false);
}

ComplexType *StringExpression::getType()
{
    return new ComplexType(STRING, false);
}

ComplexType *IntExpression::getType()
{
    return new ComplexType(INT, false);
}

ComplexType *FloatExpression::getType()
{
    return new ComplexType(FLOAT, false);
}

ComplexType *BooleanExpression::getType()
{
    return new ComplexType(BOOLEAN, false);
}

ComplexType *UnaryExpression::getType()
{
    ComplexType *type = this->expr->getType();
    if (this->op == NOT && type->primitiveType != BOOLEAN)
    {
        cerr << "No se puede aplicar el operador NOT a una expresion no booleana linea: " << this->line << " columna: " << this->column << endl;
    }
    else if (this->op == NEG && (type->primitiveType != INT || type->primitiveType != FLOAT)) // ESTO YA NO SE USA EN EL PARSER
    {
        cerr << "No se puede aplicar el operador NEG a una expresion no booleana linea: " << this->line << " columna: " << this->column << endl;
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
        {"BOOLEAN,BOOLEAN", BOOLEAN}};

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

#define GET_TYPE_BINARY_EXPR(name)                                                                                                                                                   \
    ComplexType *name##Expression::getType()                                                                                                                                         \
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
    ComplexType *name##Expression::getType()                                                                                                                                         \
    {                                                                                                                                                                                \
        string leftType = getTypeAsString(this->left->getType());                                                                                                                    \
        string rightType = getTypeAsString(this->right->getType());                                                                                                                  \
        if (leftType != rightType)                                                                                                                                                   \
        {                                                                                                                                                                            \
            cerr << "El tipo de dato " << leftType << " no puede ser operado con el tipo de dato " << rightType << " linea: " << this->line << " columna: " << this->column << endl; \
        }                                                                                                                                                                            \
        return new ComplexType(BOOLEAN, false);                                                                                                                                      \
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
    return new ComplexType(NONE, false);
}

ComplexType *getVarType(string id)
{
    ComplexType *resultType = new ComplexType(NONE, false);
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
        return new ComplexType(NONE, false);
    }
    return this->id->getType(); // probar
}

ComplexType *MethodCallExpression::getType()
{
    MethodInformation *method = methods[this->id->id];
    if (method == NULL)
    {
        cerr << this->id->id << " no declarado linea: " << this->line << " column " << this->column << endl;
        return new ComplexType(NONE, false);
    }

    if (method->parameters->size() > this->args->size())
    {
        cerr << "Muy pocos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return new ComplexType(NONE, false);
    }

    if (method->parameters->size() < this->args->size())
    {
        cerr << "Muchos argumentos para el método: " << this->id->id << " linea: " << this->line << " column " << this->column << endl;
        return new ComplexType(NONE, false);
    }
    // validación de tipo
    list<VarDeclarationStatement *>::iterator paramsIt = method->parameters->begin();
    list<Expression *>::iterator argsIt = this->args->begin(); // call
    while (argsIt != this->args->end())
    {
        if ((*argsIt)->getType()->primitiveType != (*paramsIt)->type->primitiveType)
        {
            cerr << "Tipo de dato incorrecto en parámetros, se esperaba tipo: "
                 << getTypeAsString((*paramsIt)->type)
                 << " se obtuvo: " << getTypeAsString((*argsIt)->getType())
                 << " linea: " << this->line << " column " << this->column << endl;
            return new ComplexType((PrimitiveType)NONE, false);
        }
        argsIt++;
        paramsIt++;
    }
    return method->returnType;
}

ComplexType *IncreDecreExpression::getType()
{
    return this->expr->getType();
}

ComplexType *ArrayArgExpression::getType()
{
    return this->getType();
}

ComplexType *ReadExpression::getType()
{
    return new ComplexType(this->primitiveType, false);
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
    if (getVarType(this->id)->primitiveType != NONE)
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
    currentContext->vars[this->id] = this->type;
}

void VarDeclAssignStatement::evaluateSemantic()
{
    // Declaration
    if (getVarType(this->decl->id)->primitiveType != NONE)
    {
        cerr << "Ya existe una variable con el nombre " << (this->decl->id) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    currentContext->vars[this->decl->id] = this->decl->type;
    // Assignation
    ComplexType *varType = getVarType(this->decl->id);
    ComplexType *exprType = this->expr->getType();
    if (varType->primitiveType != exprType->primitiveType)
    {
        cerr << "No se puede asignar " << getTypeAsString(exprType) << " a la variable de tipo " << getTypeAsString(varType) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
}

void ArrayVarDeclAssignStatement::evaluateSemantic()
{
    PrimitiveType declType = getVarType(this->id)->primitiveType;
    if (declType != NONE)
    {
        cerr << "Ya existe una variable con el nombre " << this->id << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }

    if (this->type->isArray && this->size <= 0)
    {
        cerr << "El tamanio de un arreglo debe ser mayor a 0. Linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    if (this->initializer->getType()->primitiveType != this->type->primitiveType)
    {
        cerr << "No se puede inicializar un arreglo de tipo " << getTypeAsString(this->type) << " con el tipo " << getTypeAsString(this->initializer->getType())
             << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    ArrayType *arrayType = static_cast<ArrayType *>(this->type);
    arrayType->size = this->size;
    currentContext->vars[this->id] = arrayType;
}

/*Evaluate Semantic of Statements*/

void PrintStatement::evaluateSemantic()
{
    PrimitiveType type = this->expression->getType()->primitiveType;
    if (type != STRING && type != INT && type != FLOAT)
    {
        cerr << "Solo se permite imprimir tipo de dato STRING, INT o FLOAT, tipo de dato encontrado: " << type
             << ". Linea:" << this->line << " columna: " << this->column << endl;
        return;
    }
}

void IfStatement::evaluateSemantic()
{
    if (this->expression->getType()->primitiveType != BOOLEAN)
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
    if (this->isArray && this->index->getType()->primitiveType != INT)
    {
        cerr << "El indice en el arreglo debe ser un entero linea: " << this->line << " columna: " << this->column << endl;
        return;
    }
    ComplexType *varType = getVarType(this->id);
    ComplexType *exprType = this->expression->getType();
    if (varType->primitiveType != exprType->primitiveType)
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
    ComplexType *varType = getVarType(this->iteratorId);
    ComplexType *fromExprType = this->fromExpr->getType();
    ComplexType *toExprType = this->toExpr->getType();
    if (varType->primitiveType != fromExprType->primitiveType)
    {
        cerr << "No se puede asignar " << getTypeAsString(fromExprType) << " a la variable de tipo " << getTypeAsString(varType) << " linea " << this->line << " columna: " << this->column << endl;
        return;
    }
    if (varType->primitiveType != toExprType->primitiveType)
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
    map<string, MethodInformation *>::reverse_iterator methodIt = methods.rbegin();
    if (methodIt != methods.rend())
    {
        cout << (*methodIt).first << endl;
    }
    if (this->expression->getType()->primitiveType != methodIt->second->returnType->primitiveType)
    {
        cerr << "No se puede retornar tipo " << getTypeAsString(this->expression->getType()) << " en funcion de tipo" << getTypeAsString(methodIt->second->returnType) << " linea: " << this->line << " columna: " << this->column << endl;
        return;
    }
}

void ExpressionStatement::evaluateSemantic()
{
    this->expr->getType();
}

void IncreDecreStatement::evaluateSemantic()
{
    if (this->expr->getType()->primitiveType != INT && this->expr->getType()->primitiveType != FLOAT)
    {
        cerr << "Variable debe ser de tipo entero linea: " << this->line << " columna: " << this->column << " tipo de dato recibido: " << getTypeAsString(this->expr->getType()) << endl;
        return;
    }
}

void WhileStatement::evaluateSemantic()
{
    if (this->expr->getType()->primitiveType != BOOLEAN)
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
    methods[this->id] = new MethodInformation(this->returnType, this->params);
    pushContext();
    list<VarDeclarationStatement *>::iterator itStmt = this->params->begin();
    while (itStmt != this->params->end())
    {
        (*itStmt)->evaluateSemantic();
        itStmt++;
    }
    this->block->evaluateSemantic();
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

void StringExpression::generateCode(CodeContext &context)
{
    string label = newLabel("string");
    stringstream code;
    code << label << ": .asciiz " << this->value << endl;
    context.code = "";
    context.place = label;
    context.type = new ComplexType((PrimitiveType)STRING, false);
    string finalCode = code.str();
    replace(finalCode.begin(), finalCode.end(), '\'', '\"');
    assemblyResult.data += finalCode;
}

void IntExpression::generateCode(CodeContext &context)
{
    stringstream code;
    string temp = getIntTemp();
    code << "li " << temp << ", " << this->value << endl;
    context.code = code.str();
    context.place = temp;
    context.type = new ComplexType((PrimitiveType)INT, false);
}

void FloatExpression::generateCode(CodeContext &context)
{
    stringstream code;
    string temp = getFloatTemp();
    code << "li.s " << temp << ", " << this->value << endl;
    context.code = code.str();
    context.place = temp;
    context.type = new ComplexType((PrimitiveType)FLOAT, false);
}

void CharExpression::generateCode(CodeContext &context)
{
    stringstream code;
    string temp = getIntTemp();
    code << "li " << temp << ", '" << this->value << "'" << endl;
    context.code = code.str();
    context.place = temp;
    context.type = new ComplexType((PrimitiveType)CHAR, false);
}

void BooleanExpression::generateCode(CodeContext &context)
{
    // No se probará
}

void IdExpression::generateCode(CodeContext &context)
{
    if (codeGenerationVars.find(this->id) == codeGenerationVars.end())
    {
        context.globalVarName = this->id;
        context.type = globalVars[this->id];
        if (globalVars[this->id]->isArray)
        {
            string temp = getIntTemp();
            context.code = "la " + temp + ", " + this->id + "\n";
            context.place = temp;
        }
        if (globalVars[this->id]->primitiveType == FLOAT)
        {
            string floatTemp = getFloatTemp();
            context.place = floatTemp;
            context.code = "l.s " + floatTemp + ", " + this->id + "\n";
        }
        else if (globalVars[this->id]->primitiveType == INT)
        {
            string intTemp = getIntTemp();
            context.place = intTemp;
            context.code = "lw " + intTemp + ", " + this->id + "\n";
        }
    }
    else
    {
        context.type = codeGenerationVars[this->id]->type;
        if (codeGenerationVars[this->id]->type->primitiveType == FLOAT && !codeGenerationVars[this->id]->type->isArray)
        {
            string floatTemp = getFloatTemp();
            context.place = floatTemp;
            context.code = "l.s " + floatTemp + ", " + to_string(codeGenerationVars[this->id]->offset) + "($sp)\n";
        }
        else if (codeGenerationVars[this->id]->type->primitiveType == INT && !codeGenerationVars[this->id]->type->isArray)
        {
            string intTemp = getIntTemp();
            context.place = intTemp;
            context.code = "lw " + intTemp + ", " + to_string(codeGenerationVars[this->id]->offset) + "($sp)\n";
        }
        else if (codeGenerationVars[this->id]->type->isArray)
        {
            string intTemp = getIntTemp();
            context.code = "la " + intTemp + to_string(codeGenerationVars[this->id]->offset) + "($sp)\n";
            context.place = intTemp;
        }
    }
}

void ArrayAccessExpression::generateCode(CodeContext &context)
{
    CodeContext indexCode;
    stringstream code;
    this->index->generateCode(indexCode);
    releaseRegister(indexCode.place);

    string temp = getIntTemp();
    string address = getIntTemp();
    code << indexCode.code << endl
         << "li $a0, 4" << endl
         << "mult $a0, " << indexCode.place << endl
         << "mflo " << temp << endl;

    if (codeGenerationVars.find(this->id->id) == codeGenerationVars.end())
    {
        code << "la " << address << ", " << this->id->id << endl
             << "add " << temp << ", " << address << ", " << temp << endl;
        releaseRegister(address);
        if (globalVars[this->id->id]->primitiveType == INT)
        {
            code << "lw " << temp << ", 0(" << temp << ")" << endl;
            context.place = temp;
            context.type = new ComplexType(INT, false);
        }
        else
        {
            string value = getFloatTemp();
            code << "l.s " << value << ", 0(" << temp << ")" << endl;
            context.place = value;
            context.type = new ComplexType(FLOAT, false);
            releaseRegister(temp);
        }
    }
    else
    {
        if (!codeGenerationVars[this->id->id]->isParameter)
        {
            code << "la " << address << ", " << codeGenerationVars[this->id->id]->offset << "($sp)" << endl;
        }
        else
        {
            code << "lw " << address << ", " << codeGenerationVars[this->id->id]->offset << "($sp)" << endl;
        }
        code << "add " << temp << ", " << address << ", " << temp << endl;
        if (codeGenerationVars[this->id->id]->type->primitiveType == INT)
        {
            code << "lw " << temp << ", 0(" << temp << ")" << endl;
            context.place = temp;
            context.type = codeGenerationVars[this->id->id]->type;
        }
        else
        {
            string value = getFloatTemp();
            code << "l.s " << value << ", 0(" << temp << ")" << endl;
            context.place = value;
            context.type = codeGenerationVars[this->id->id]->type;
            releaseRegister(temp);
        }
    }
    context.code = code.str();
}

void MethodCallExpression::generateCode(CodeContext &context)
{
}

void IncreDecreExpression::generateCode(CodeContext &context)
{
}

void UnaryExpression::generateCode(CodeContext &context)
{
}

#define GEN_CODE_BINARY_EXPR(name) \
    void name##Expression::generateCode(CodeContext &context){};

string intArithmetic(CodeContext &leftCode, CodeContext &rightCode, CodeContext &resultCode, char op)
{
    resultCode.place = getIntTemp();
    stringstream code;
    switch (op)
    {
    case '+':
        code << "add " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    case '-':
        code << "sub " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    case '*':
        code << "mult " << leftCode.place << ", " << rightCode.place << endl
             << "mflo " << resultCode.place;
        break;
    case '/':
        code << "div " << leftCode.place << ", " << rightCode.place << endl
             << "mflo " << resultCode.place;
        break;
    default:
        break;
    }
    return code.str();
}

string floatArithmetic(CodeContext &leftCode, CodeContext &rightCode, CodeContext &resultCode, char op)
{
    resultCode.place = getFloatTemp();
    stringstream code;
    switch (op)
    {
    case '+':
        code << "add.s " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    case '-':
        code << "sub.s " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    case '*':
        code << "mul.s " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    case '/':
        code << "div.s " << resultCode.place << ", " << leftCode.place << ", " << rightCode.place << endl;
        break;
    default:
        break;
    }
    return code.str();
}

void toFloat(CodeContext &context)
{
    string floatTemp = getFloatTemp();
    stringstream code;
    code << context.code
         << "mtc1 " << context.place << ", " << floatTemp << endl
         << "cvt.s.w " << floatTemp << ", " << floatTemp << endl;
    releaseRegister(context.place);
    context.place = floatTemp;
    context.type = new ComplexType(FLOAT, false);
    context.code = code.str();
}

string concatString(CodeContext &leftCode, CodeContext &resultCode, char op)
{
    resultCode.place = getIntTemp();
    stringstream code;
    if (op == '+')
    {
        code << "la " << resultCode.place << ", " << leftCode.place << endl;
    }
    return code.str();
}

#define GEN_ARIT_CODE_BINARY_EXPR(name, op)                                                         \
    void name##Expression::generateCode(CodeContext &context)                                       \
    {                                                                                               \
        CodeContext leftCode, rightCode;                                                            \
        stringstream code;                                                                          \
        this->left->generateCode(leftCode);                                                         \
        this->right->generateCode(rightCode);                                                       \
        if (leftCode.type->primitiveType == INT && rightCode.type->primitiveType == INT)            \
        {                                                                                           \
            context.type = leftCode.type;                                                           \
            releaseRegister(leftCode.place);                                                        \
            releaseRegister(rightCode.place);                                                       \
            code << leftCode.code << endl                                                           \
                 << rightCode.code << endl                                                          \
                 << intArithmetic(leftCode, rightCode, context, op) << endl;                        \
        }                                                                                           \
        else if (leftCode.type->primitiveType == STRING && rightCode.type->primitiveType == STRING) \
        {                                                                                           \
            context.type = leftCode.type;                                                           \
            releaseRegister(leftCode.place);                                                        \
            releaseRegister(rightCode.place);                                                       \
            code << leftCode.code << endl                                                           \
                 << concatString(leftCode, context, op) << endl;                                    \
        }                                                                                           \
        else                                                                                        \
        {                                                                                           \
            context.type = new ComplexType(FLOAT, false);                                           \
            if (leftCode.type->primitiveType != FLOAT)                                              \
                toFloat(leftCode);                                                                  \
            if (rightCode.type->primitiveType != FLOAT)                                             \
                toFloat(rightCode);                                                                 \
            releaseRegister(leftCode.place);                                                        \
            releaseRegister(rightCode.place);                                                       \
            code << leftCode.code << endl                                                           \
                 << rightCode.code << endl                                                          \
                 << floatArithmetic(leftCode, rightCode, context, op) << endl;                      \
        }                                                                                           \
        context.code = code.str();                                                                  \
    }

GEN_ARIT_CODE_BINARY_EXPR(Mult, '*');
GEN_ARIT_CODE_BINARY_EXPR(Div, '/');
GEN_ARIT_CODE_BINARY_EXPR(Mod, '%');
GEN_ARIT_CODE_BINARY_EXPR(Add, '+');
GEN_ARIT_CODE_BINARY_EXPR(Sub, '-');

// Preguntar range
GEN_CODE_BINARY_EXPR(Range);
GEN_CODE_BINARY_EXPR(Gt);
GEN_CODE_BINARY_EXPR(Lt);
GEN_CODE_BINARY_EXPR(Gte);
GEN_CODE_BINARY_EXPR(Lte);
GEN_CODE_BINARY_EXPR(Or);
GEN_CODE_BINARY_EXPR(And);
GEN_CODE_BINARY_EXPR(Eq);
GEN_CODE_BINARY_EXPR(Neq);

void ParamExpression::generateCode(CodeContext &context)
{
}

void ArrayArgExpression::generateCode(CodeContext &context)
{
}

void ReadExpression::generateCode(CodeContext &context)
{
}

string VarDeclarationStatement::generateCode()
{
    codeGenerationVars[this->id] = new CodeGenerationVarInfo(false, this->type, globalStackpointer);
    if (!this->type->isArray)
    {
        globalStackpointer += 4;
    }
    else
    {
        // falta lógica arreglos
    }

    return "";
}

string VarDeclAssignStatement::generateCode()
{
    return "";
}

string ArrayVarDeclAssignStatement::generateCode()
{
    return "";
}

string PrintStatement::generateCode()
{
    stringstream code;
    CodeContext exprContext;
    cout<<"linea:"<<this->expression->line;
    this->expression->generateCode(exprContext);
    cout << "expresion llega" << exprContext.place;
    if (exprContext.type->primitiveType == INT)
    {
        code << "move $a0, " << exprContext.place << endl
             << "li $v0, 1" << endl;
    }
    else if (exprContext.type->primitiveType == FLOAT)
    {
        code << "mov.s $f12, " << exprContext.place << endl
             << "li $v0, 2" << endl;
    }
    else if (exprContext.type->primitiveType == STRING)
    {
        cout<<"ahora "<<exprContext.place;
        code << "la $a0, " << exprContext.place << endl
             << "li $v0, 4" << endl;
    }
    else if (exprContext.type->primitiveType == CHAR)
    {
        code << "move $a0, " << exprContext.place << endl
             << "li $v0, 11" << endl;
    }

    code << "syscall" << endl;
    code << "la $a0, nextline" << endl
         << "li $v0, 4" << endl
         << "syscall" << endl;
    return code.str();
}

string IfStatement::generateCode()
{
    return "";
}

string AssignationStatement::generateCode()
{
    CodeContext rightSideCode;
    stringstream code;
    this->expression->generateCode(rightSideCode);
    code << rightSideCode.code;
    if (codeGenerationVars.find(this->id) == codeGenerationVars.end())
    {
        if (this->isArray)
        {
            CodeContext indexCode;
            this->index->generateCode(indexCode);
            string temp = getIntTemp();
            string address = getIntTemp();
            releaseRegister(indexCode.place);
            code << indexCode.code << endl
                 << "li $a0, 4" << endl
                 << "mult $a0, " << indexCode.place << endl
                 << "mflo " << temp << endl;
            code << "la " << address << ", " << this->id << endl;
            code << "add " << temp << ", " << temp << ", " << address << endl;
            code << rightSideCode.code << endl
                 << "sw " << rightSideCode.place << ", 0(" << temp << ")" << endl;
            releaseRegister(temp);
            releaseRegister(address);
            releaseRegister(indexCode.place);
        }
        else if (rightSideCode.type->primitiveType == INT)
        {
            code << "sw " << rightSideCode.place << ", " << this->id << endl;
        }
        else if (rightSideCode.type->primitiveType == FLOAT)
        {
            code << "s.s " << rightSideCode.place << ", " << this->id << endl;
        }
        else if (rightSideCode.type->primitiveType == STRING)
        {
            cout << "string place " << rightSideCode.place << endl;
            cout << "id: " << this->id << endl;
        }
    }
    else
    {
        if (this->isArray)
        {
            CodeContext indexCode;
            this->index->generateCode(indexCode);
            string temp = getIntTemp();
            string address = getIntTemp();
            releaseRegister(indexCode.place);
            code << indexCode.code << endl
                 << "li $a0, 4" << endl
                 << "mult $a0, " << indexCode.place << endl
                 << "mflo " << temp << endl;
            if (!codeGenerationVars[this->id]->isParameter)
            {
                code << "la " << address << ", " << codeGenerationVars[this->id]->offset << "($sp)" << endl;
            }
            else
            {
                code << "lw " << address << ", " << codeGenerationVars[this->id]->offset << "($sp)" << endl;
            }
            code << "add " << temp << ", " << temp << ", " << address << endl;
            code << rightSideCode.code << endl
                 << "sw " << rightSideCode.place << ", 0(" << temp << ")" << endl;
            releaseRegister(temp);
            releaseRegister(address);
            releaseRegister(indexCode.place);
        }
        else if (rightSideCode.type->primitiveType == INT)
        {
            code << "sw " << rightSideCode.place << ", " << codeGenerationVars[this->id]->offset << "($sp)" << endl;
        }
        else if (rightSideCode.type->primitiveType == FLOAT)
        {
            code << "s.s " << rightSideCode.place << ", " << codeGenerationVars[this->id]->offset << "($sp)" << endl;
        }
        else if (rightSideCode.type->primitiveType == STRING)
        {
            cout << "string place " << rightSideCode.place << endl;
            cout << "id: " << this->id << endl;
        }
    }
    releaseRegister(rightSideCode.place);
    return code.str();
}

string CommentStatement::generateCode()
{
    return "";
}

string ForStatement::generateCode()
{
    return "";
}

string ReturnStatement::generateCode()
{
    return "";
}

string ExpressionStatement::generateCode()
{
    CodeContext exprCode;
    this->expr->generateCode(exprCode);
    releaseRegister(exprCode.place);
    return exprCode.code;
}

string IncreDecreStatement::generateCode()
{
    return "";
}

string WhileStatement::generateCode()
{
    return "";
}

string BlockStatement::generateCode()
{
    stringstream code;
    list<Statement *>::iterator declIt = this->statements->begin();
    while (declIt != this->statements->end())
    {
        code << (*declIt)->generateCode();
        declIt++;
    }
    return code.str();
}

string saveState()
{
    stringstream code;
    code << "sw $ra, " << globalStackpointer << "($sp)" << endl;
    globalStackpointer += 4;
    return code.str();
}

string retrieveState(string state)
{
    string::size_type n = 0;
    string originalStateStatement = "sw";
    while ((n = state.find(originalStateStatement, n)) != string::npos)
    {
        state.replace(n, originalStateStatement.size(), "lw");
        n += originalStateStatement.size();
    }
    return state;
}

string FunctionStatement::generateCode()
{
    int stackPointer = 4;
    globalStackpointer = 0;
    stringstream code;
    code << this->id << ": " << endl;
    string state = saveState();
    code << state << endl;
    if (this->params->size() > 0)
    {
        list<VarDeclarationStatement *>::iterator paramsIt = this->params->begin();
        for (int i = 0; i < this->params->size(); i++)
        {
            code << "sw $a" << i << ", " << stackPointer << "($sp)" << endl;
            codeGenerationVars[(*paramsIt)->id] = new CodeGenerationVarInfo(true, (*paramsIt)->type, stackPointer);
            stackPointer += 4;
            globalStackpointer += 4;
            paramsIt++;
        }
    }
    code << this->block->generateCode() << endl;
    stringstream stackPointerCode;
    stackPointerCode << endl
                     << "addiu $sp, $sp, -" << globalStackpointer << endl;
    code << retrieveState(state) << endl
         << "addiu $sp, $sp, " << globalStackpointer << endl
         << "jr $ra" << endl;
    // codeGenerationVars.clear();
    string finalCode = code.str();
    finalCode.insert(this->id.size() + 2, stackPointerCode.str());
    return finalCode;
}

string BlockFunctionStatement::generateCode()
{
    stringstream code;
    CodeContext litCode;
    stringstream literals;
    code << literals.str() << endl;
    list<Statement *>::iterator it = this->statements->begin();
    while (it != this->statements->end())
    {
        code << (*it)->generateCode();
        it++;
    }

    code << "li $v0, 10" << endl
         << "syscall" << endl;
    return code.str();
}
