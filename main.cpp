
//#include "funciones.h"
#include "ExpressionSolver.h"
using namespace std;

int main() {

//    cout << "aaaaaaa" << endl;
//    string infix = "7/4*((1+2)^4*2)+3";
//    auto postfix = infixToPostfix(infix);
//    cout << postfix << endl;
    InfixToPostfix equation("75/44*((12+21)^48*25)+3");
    equation.printEquation();
    equation.infixToPostfix();
    equation.printEquation();
    equation.buildTreeFromPostfix();
//    equation.printEquation();
//    auto post = equation.infixToPostfix();
//    cout << post << endl;


    return 0;
}

/* Evaluate postfix expression:
 * 1) Scan the expression from left to right.
 * 2) Find this pattern: <operand> <operand> <operator> */

/* Infix format: <operand> <operator> <operand>
 * Postfix format: <operand> <operand> <operator> */

/* Order of operators
 * 1) Parenthesis: () {} []
 * 2) Exponents: (right to left)
 * 3) Multiplication and Division: (left to right)
 * 4) Addition and Subtraction: (left to right)*/

/*
solver de ecuaciones -> armar un árbol de expresiones
"7/4*((3+1)*3)+3",
"2+(3)",
"7/4*((1+2)^4*2)+3",
"1-2*5/2+1-2^4+1",
"((7*3)/4+6*(3^2)/2)"
ecuaciones que el solver debe soportar: +-*^/
y trabajar con variables aparte de constantes
*/
