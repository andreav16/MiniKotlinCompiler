#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "CodeContext.h"

using namespace std;

class Node
{
public:
    int line;
    int column;
    Node(int line, int column)
    {
        this->line = line;
        this->column = column;
    }
    virtual void print() = 0;
};




/*2. EXPRESSIONS*/
class Expression : public Node
{
public:
    Expression(int line, int column) : Node(line, column)
    {
    }
    virtual void print() = 0;
    virtual ComplexType* getType() = 0;
};

//2.1 Literals

class CharExpression: public Expression 
{
public:
    CharExpression(char value, int line, int column): Expression(line, column){
        this->value = value;
    }
    char value;
    void print();
    ComplexType* getType();
};

class StringExpression: public Expression
{
public:
    StringExpression(string value, int line, int column): Expression(line, column){
        this->value = value;
    }
    string value;
    void print();
    ComplexType* getType();
};

class IntExpression: public Expression
{
public:
    IntExpression(int value, int line, int column): Expression(line, column){
        this->value = value;
    }
    int value;
    void print();
    ComplexType* getType();
};

class FloatExpression: public Expression{
public:
    FloatExpression(float value, int line, int column): Expression(line, column){
        this->value = value;
    }
    float value;
    void print();
    ComplexType* getType();
};

class BooleanExpression: public Expression{
public:
    BooleanExpression(bool value, int line, int column): Expression(line, column){
        this->value = value;
    }
    bool value;
    void print();
    ComplexType* getType();
};

//2.2 Factors

class IdExpression: public Expression{
public:
    IdExpression(string id, int line, int column): Expression(line, column){
        this->id = id;
    }
    string id;
    void print();
    ComplexType* getType();
};

class ArrayAccessExpression: public Expression{
public:
    ArrayAccessExpression(IdExpression * id, Expression * index, int line, int column): Expression(line, column){
        this->id = id;
        this->index = index;
    }
    IdExpression * id;
    Expression * index;
    void print();
    ComplexType* getType();
};

class MethodCallExpression: public Expression{
public:
    MethodCallExpression(IdExpression * id, list<Expression *> * args, int line, int column): Expression(line, column){
        this->id = id;
        this->args = args;
    }
    IdExpression * id;
    list<Expression *> * args;
    void print();
    ComplexType* getType();
};

//2.3 Incre Decre
class IncreDecreExpression: public Expression {
public: 
    IncreDecreExpression(IncreDecreOperator op, Expression * expression, int line, int column)
        : Expression(line , column){
            this->op = op;
            this->expr = expression;
    } 
    IncreDecreOperator op;
    Expression * expr;
    void print();
    ComplexType* getType();
};

//2.4 Unary
class UnaryExpression: public Expression {
public: 
    UnaryExpression(UnaryOperator op, Expression * expression, int line, int column)
        : Expression(line, column){
            this->op = op;
            this->expr = expression;
    }
    UnaryOperator op;
    Expression * expr;
    void print();
    ComplexType* getType();
};

//2.5 Binary

class BinaryExpression: public Expression{
public:
    BinaryExpression(Expression * left, Expression * right, int line, int column) :
        Expression(line, column){
            this->left = left;
            this->right = right;
    }
    Expression * left;
    Expression * right;
    virtual ComplexType* getType() = 0;
    virtual void print() = 0;
};

#define IMPLEMENT_BINARY_EXPR(name) \
class name##Expression  : public BinaryExpression{\
public: \
    name##Expression(Expression * left, Expression * right, int line, int column): BinaryExpression(left, right, line, column){}\
    void print();\
    ComplexType* getType();\
};


IMPLEMENT_BINARY_EXPR(Mult);
IMPLEMENT_BINARY_EXPR(Div);
IMPLEMENT_BINARY_EXPR(Mod);
IMPLEMENT_BINARY_EXPR(Add);
IMPLEMENT_BINARY_EXPR(Sub);
IMPLEMENT_BINARY_EXPR(Range);

IMPLEMENT_BINARY_EXPR(Gt);
IMPLEMENT_BINARY_EXPR(Lt);
IMPLEMENT_BINARY_EXPR(Gte);
IMPLEMENT_BINARY_EXPR(Lte);

IMPLEMENT_BINARY_EXPR(Or);
IMPLEMENT_BINARY_EXPR(And);
IMPLEMENT_BINARY_EXPR(Eq);
IMPLEMENT_BINARY_EXPR(Neq);

//2.6 Params Expr

class ParamExpression: public Expression{
public:
    ParamExpression(string id, ComplexType* type, int line, int column)
        : Expression(line, column){
        this->id = id;
        this->type = type;
    }
    string id;
    ComplexType* type;
    void print();
    ComplexType* getType();
};


// 2.7 Args Expr

class ArrayArgExpression: public Expression{
    public:
        ArrayArgExpression(ComplexType * type, list<Expression *> * literals, int line, int column)
            : Expression(line, column)
        {
            this->type = type;
            this->literals = literals;
        }
        ComplexType * type;
        list<Expression *> * literals;
        void print();
        ComplexType* getType();
        
};

/*STATEMENT ABSTRACT CLASS*/
class Statement : public Node
{
public:
    Statement(int line, int column) : Node(line, column) {}
    virtual void print() = 0;
    virtual void evaluateSemantic() = 0;
};

/*3. DECLARATIONS*/
class Declaration : public Statement
{
public:
    Declaration(int line, int column) : Statement(line, column) {}
    virtual void print() = 0;
    virtual void evaluateSemantic() =0;
};

class VarDeclarationStatement : public Declaration
{
public:
    VarDeclarationStatement(string id, ComplexType * type, int line, int column) : Declaration(line, column)
    {
        this->id = id;
        this->type = type;
    }
    string id;
    ComplexType * type;
    void print();
    void evaluateSemantic();
};

class VarDeclAssignStatement : public Declaration
{
public:
    VarDeclAssignStatement(VarDeclarationStatement * decl, Expression * expr, int line, int column) 
        : Declaration(line, column)
    {
        this->decl = decl;
        this->expr = expr;
    }
    VarDeclarationStatement * decl;
    Expression * expr;
    void print();
    void evaluateSemantic();
};

class ArrayVarDeclAssignStatement : public Declaration
{
public:
    ArrayVarDeclAssignStatement(string id, ComplexType *type, int size, Expression * initializer, int line, int column) 
        : Declaration(line, column)
    {
        this->id = id;
        this->type = type;
        this->size = size;
        this->initializer = initializer;
    }
    string id;
    ComplexType *type;
    int size;
    Expression * initializer;
    void print();
    void evaluateSemantic();
};

/*Pend de revisar*/
class MethodInformation{
    public:
        ComplexType* returnType;
        list<VarDeclarationStatement *> * parameters;
        MethodInformation(ComplexType* returnType, list<VarDeclarationStatement *>  * parameters){
            this->returnType = returnType;
            this->parameters = parameters;
        }
};

/*4. STATEMENTS*/

class PrintStatement : public Statement
{
public:
    PrintStatement(Expression *expression, int line, int column) : Statement(line, column)
    {
        this->expression = expression;
    }
    Expression *expression;
    void print();
    void evaluateSemantic();
};

class IfStatement : public Statement
{
public:
    IfStatement(Expression *expression, Statement *trueStatement, Statement *falseStatement, int line, int column) : Statement(line, column)
    {
        this->expression = expression;
        this->trueStatement = trueStatement;
        this->falseStatement = falseStatement;
    }
    Expression *expression;
    Statement *trueStatement;
    Statement *falseStatement;
    void print();
    void evaluateSemantic();
};

class AssignationStatement : public Statement
{
public:
    AssignationStatement(string id, Expression *expression, Expression *index, int line, int column) : Statement(line, column)
    {
        this->id = id;
        this->expression = expression;
        this->index = index;
        this->isArray = index != NULL;
    }
    string id;
    Expression *expression;
    Expression *index;
    bool isArray;
    void print();
    void evaluateSemantic();
};

class CommentStatement : public Statement
{
public:
    CommentStatement(string comment, int line, int column) : Statement(line, column)
    {
        this->comment = comment;
    }
    string comment;
    void print();
    void evaluateSemantic();
};

class ForStatement : public Statement
{
public:
    ForStatement(string iteratorId, Expression *fromExpr, Expression *toExpr, Statement *stmt, int line, int column) : Statement(line, column)
    {
        this->iteratorId = iteratorId;
        this->fromExpr = fromExpr;
        this->toExpr = toExpr;
        this->stmt = stmt;
    }
    string iteratorId;
    Expression *fromExpr;
    Expression *toExpr;
    Statement *stmt;
    void print();
    void evaluateSemantic();
};

class ReturnStatement: public Statement{
    public:
        ReturnStatement(Expression * expression, int line, int column):Statement(line, column){
            this->expression = expression;
        }
        Expression * expression;
        void print();
        void evaluateSemantic();
};

class ExpressionStatement : public Statement{
    public:
        ExpressionStatement(Expression * expr, int line, int column)
            : Statement(line, column){
            this->expr = expr;
        }
        Expression * expr;
        void print();
        void evaluateSemantic();
};

class IncreDecreStatement: public Statement{
    public:
        IncreDecreStatement(IncreDecreExpression * expr, int line, int column)
            : Statement(line, column){
                this->expr = expr;
        }
        IncreDecreExpression * expr;
        void print();
        void evaluateSemantic();
};

class WhileStatement: public Statement{
    public:
        WhileStatement(Expression * expr, Statement * stmt, int line, int column):
            Statement(line, column){
                this->expr = expr;
                this->stmt = stmt;
        }
        Expression * expr;
        Statement * stmt;
        void print();
        void evaluateSemantic();
};


class BlockStatement: public Statement{
    public:
        BlockStatement(list<Statement *> * statements, int line, int column):
            Statement(line, column) {
                this->statements = statements;
        }
        list<Statement *> * statements;
        void print();
        void evaluateSemantic();
};

class FunctionStatement: public Statement{
    public:
        FunctionStatement(string id, list<VarDeclarationStatement *> * params, ComplexType * returnType , Statement * block, int line, int column)
            : Statement(line, column) {
                this->id = id;
                this->params = params;
                this->returnType = returnType;
                this->block = block;
        }
        string id;
        list<VarDeclarationStatement *> * params;
        ComplexType * returnType;
        Statement * block;
        void print();
        void evaluateSemantic();
};

class BlockFunctionStatement: public Statement{
    public:
        BlockFunctionStatement(list<Statement *> * statements, int line, int column):
            Statement(line, column) {
                this->statements = statements;
        }
        list<Statement *> * statements;
        void print();
        void evaluateSemantic();
};