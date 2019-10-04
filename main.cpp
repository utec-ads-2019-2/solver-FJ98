#include "ExpressionSolver.h"
using namespace std;

int main() {
    cout << "==============================================" << endl;
    cout << "               Equations Solver               " << endl;
    cout << "==============================================" << endl;
    std::string equations[] = {"12/4*((3+1)*3)+3", "2+(3)", "7/4*((1+2)^4*2)+3",
                               "1-2*5/2+1-2^4+1", "((7*3)/4+6*(3^2)/2)"};
    float results[] = {39, 5, 286.5, -18, 32.25};
    const unsigned int size = sizeof(equations) / sizeof(string);
    for (int i = 0; i < static_cast<int>(size); ++i) {
        cout << "Equation -> " << i + 1 << endl;
        try {
            Equation equation(equations[i]);
            cout << "Original Expression: " << equation.getEquation() << endl;
            equation.infixToPostfix();
            cout << "Postfix Expression: " << equation.getEquation() << endl;
            equation.buildTreeFromPostfix();
            cout << "Tree (Traversed In Order): "; equation.traverseInOrder(); cout << endl;
            cout << "Tree (Traversed Post Order): "; equation.traversePostOrder(); cout << endl;
            cout << "Answer:" << equation.solveEquation() << endl << endl;
            assert(equation.solveEquation() == results[i]);
        } catch (char const *msg) {
            cerr << msg << endl;
        }
    }

    cout << "\n==============================================" << endl;
    vector <string> more_equations = { "12/4*((a+b)*a)+a", "2+(a)", "7/4*((a+b)^4*b)+3",
    "1-a*5/2+b-2^4+1", "((7*a)/4+b*(3^2)/2)"
    };

    for (int i = 0; i < static_cast<int>(more_equations.size()); ++i) {
        cout << "Equation -> " << i + 1 << endl;
        try {
            Equation equation(more_equations[i]);
            cout << "Original Expression: " << equation.getEquation() << endl;
            equation.infixToPostfix();
            cout << "Postfix Expression: " << equation.getEquation() << endl;
            equation.buildTreeFromPostfix();
            cout << "Tree (Traversed In Order): "; equation.traverseInOrder(); cout << endl;
            cout << "Tree (Traversed Post Order): "; equation.traversePostOrder(); cout << endl;
            cout << "Answer:" << equation.solveEquation() << endl << endl;
        } catch (char const* msg) {
            cerr << msg << endl;
        }
    }

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
