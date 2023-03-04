#include "ast.h"

/*PRINTS*/

void CharExpression::print(){
    cout << "char expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void StringExpression::print(){
    cout << "string expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void IntExpression::print(){
    cout << "int expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void FloatExpression::print(){
    cout << "float expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void BooleanExpression::print(){
    cout << "boolean expr: " << this->value << " line: " << this->line << " column : " << this->column << endl;
}

void IdExpression::print(){
    cout<<"Id expr: "<< this->id <<" line: "<< this->line << " column : "<<this->column<<endl;
}

void ArrayAccessExpression::print(){
    cout<<"Array access expr: "<< this->id <<" line: "<< this->line << " column : "<<this->column<<endl;
}

void MethodCallExpression::print(){
    cout<<"Method call expression: "<<this->id->id<<" line:" <<this->line << " column : "<<this->column<<endl;
}

void UnaryExpression::print(){
    cout<<"Unary expr operator: " << this->op << " expression: " << this->expr << " line: "<< this->line << " column : "<<this->column<<endl;
}

void IncreDecreExpression::print(){
    cout<<"Incre/decre expr operator: " << this->op << " expression: " << this->expr << " line: "<< this->line << " column : "<<this->column<<endl;
}

#define PRINT_BINARY_EXPRESSION(name)\
void name##Expression::print(){\
    cout<<""<<endl;\
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
