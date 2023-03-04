#include <string>
#include "constants.h"
#include <list>
#include <vector>

using namespace std;
class Node{
    public:
        int line;
        int column;
        Node(int line, int column){
            this->line = line;
            this->column = column;
        }
        virtual void print() = 0;
};
 /*Types*/
class ComplexType{
    public:
        ComplexType(PrimitiveType primitiveType, bool isArray){
            this->primitiveType = primitiveType;
            this->isArray = isArray;
        }
        PrimitiveType primitiveType;
        bool isArray;
};

class ArrayType : public ComplexType{
    public:
        ArrayType(int start, int end, PrimitiveType primitiveType)
            : ComplexType(primitiveType, true){
            this->start = start;
            this->end = end;
            this->primitiveType = primitiveType;
        }
        int start, end;
        PrimitiveType primitiveType;
};

/*Expressions*/
class Expression : public Node{
    public:
        Expression(int line, int column) : Node(line, column){

        }
        virtual void print() = 0;
};

/*Statements*/
class Statement : public Node{
    public:
        Statement(int line, int column) : Node(line, column){}
        virtual void print() = 0;
};

class PrintStatement: public Statement{
    public:
        PrintStatement(Expression * expression, int line, int column):Statement(line, column){
            this->expression = expression;
        }
        Expression * expression;
        void print();
};

class IfStatement: public Statement{
    public:
        IfStatement(Expression * expression, Statement * trueStatement, Statement * falseStatement, int line, int column):Statement(line, column){
            this->expression = expression;
            this->trueStatement = trueStatement;
            this->falseStatement = falseStatement;
        }
        Expression * expression;
        Statement * trueStatement;
        Statement * falseStatement;
        void print();
};

class AssignationStatement: public Statement{
    public:
        AssignationStatement(string id, Expression * expression, Expression * index, int line, int column):Statement(line, column){
            this->id= id;
            this->expression = expression;
            this->index = index;
            this->isArray = index != NULL;
        }
        string id;
        Expression * expression;
        Expression * index;
        bool isArray;
};

class CommentStatement: public Statement{
    public:
        CommentStatement(string comment, int line, int column):Statement(line, column){
            this->comment=comment;
        }
        string comment;
};

class ForStatement: public Statement{
    public:
        ForStatement(VarDeclarationStatement * varDeclaration, Expression * fromExpr, Expression * toExpr, Statement * stmt, int line, int column):Statement(line, column){
            this->varDeclaration = varDeclaration;
            this->fromExpr = fromExpr;
            this->toExpr = toExpr;
            this->stmt = stmt;
        }
        VarDeclarationStatement * varDeclaration;
        Expression * fromExpr;
        Expression * toExpr;
        Statement * stmt;
};


/*Declarations*/
class Declaration : public Statement{
    public:
        Declaration(int line, int column) : Statement(line, column){}
        virtual void print() = 0;
        virtual void evaluateSemantic() = 0;
};

class VarDeclarationStatement: public Declaration{
    public:
        VarDeclarationStatement(string id, ComplexType * type, int line, int column):Declaration(line, column){
            this->id = id;
            this->type = type;
        }
        string id;
        ComplexType * type;

};