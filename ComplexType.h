#ifndef COMPLEX_TYPE_H
#define COMPLEX_TYPE_H
#include "constants.h"

/*1. TYPES*/
class ComplexType
{
public:
    ComplexType(PrimitiveType primitiveType, bool isArray)
    {
        this->primitiveType = primitiveType;
        this->isArray = isArray;
    }
    PrimitiveType primitiveType;
    bool isArray;
};

class ArrayType : public ComplexType
{
public:
    ArrayType(int size, PrimitiveType primitiveType)
        : ComplexType(primitiveType, true)
    {
        this->primitiveType = primitiveType;
        this->size = size;
    }
    int size;
    PrimitiveType primitiveType;
};

#endif // !1
