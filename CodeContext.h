#include <string>
#include "ComplexType.h"
using namespace std;

//generacion de código de expresiones
typedef struct{
    string code;
    string place; //En donde quedó el valor de la expresión, donde quedó el registro, donde quedó el label
    ComplexType * type; //el tipo de dato de esa expresión
    string globalVarName;
}CodeContext;