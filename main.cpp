
//#include "funciones.h"
#include "ExpressionSolver.h"
using namespace std;

int main() {

    std::string equations[] = { "7/4*((3+1)*3)+3", "7/4*((2+8)*2)+3", "2+(3)", "7/4*((1+2)^4*2)+3",
                           "7*1", "1-2*5/2+1-2^4+1", "((7*3)/4+6*(3^2)/2)*(1)", "(5+3)+(21/3*5)-(5^3-2)" };
    float results[] = { 24, 38, 5, 286.5, 7, -18, 32.25, -80 };
    const unsigned int size = sizeof(equations) / sizeof(string);
    for (int i = 0; i < static_cast<int>(size); ++i) {
        cout << "Equation -> " << i << endl;
        try {
            InfixToPostfix equation(equations[i]);
//            equation.printEquation();
            equation.infixToPostfix();
//            equation.printEquation();
            equation.buildTreeFromPostfix();
            cout << "Rpta:" << equation.solveEquation() << endl;
            assert(equation.solveEquation() == results[i]);
        } catch (char const* msg) {
            cerr << msg << endl;
        }
    }

//    cout << "aaaaaaa" << endl;
//    string infix = "7/4*((1+2)^4*2)+3";
//    auto postfix = infixToPostfix(infix);
//    cout << postfix << endl;
//    InfixToPostfix equation("7/4*((1+2)^2*2)+3");
//    equation.printEquation();
//    equation.infixToPostfix();
//    equation.printEquation();
//    equation.buildTreeFromPostfix();
//    cout << "Rpta:" << equation.solveEquation() << endl;
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
