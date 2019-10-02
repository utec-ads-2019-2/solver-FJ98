// Created by felix on 10/2/19.
#include "ExpressionSolver.h"

Equation::Equation(std::string  expression): _expression{std::move(expression)} {}

bool Equation::isOperand(char myChar) { return !isOperator(myChar) && myChar != '(' && myChar != ')'; }

bool Equation::isOperator(char myChar)
{
    return myChar == '^' || myChar == '*' || myChar == '/' || myChar == '+' || myChar == '-';
}

int Equation::operatorPrecedence(char operaTor)
{
    if(operaTor == '^') { return 3; }
    else if(operaTor == '*' || operaTor == '/') { return 2; }
    else if(operaTor == '+' || operaTor == '-') { return 1; }
    else { return -1; }
}
bool Equation::priority(char myChar, char opInTheStack)
{
    return (isOperator(myChar) && operatorPrecedence(myChar) <= operatorPrecedence(opInTheStack));
}

std::string Equation::infixToPostfix()
{
    std::stack<char> operatorsStack;
    std::string postfixExp;

    for (auto && myInfixChar : this->_expression)
    {
        if(myInfixChar == ' ' || myInfixChar == ',') { continue; }

        if (isOperand(myInfixChar)) { postfixExp += myInfixChar; }

        else if (isOperator(myInfixChar)) {
            while(!operatorsStack.empty() && operatorsStack.top() != '(' && priority(myInfixChar, operatorsStack.top()))
            {
                postfixExp += operatorsStack.top();
                postfixExp += ' ';
                operatorsStack.pop();
            }
            postfixExp += ' ';
            operatorsStack.push(myInfixChar);
        }

        else if (myInfixChar == '(') { operatorsStack.push(myInfixChar); }

        else if (myInfixChar == ')') {
            while(!operatorsStack.empty())
            {
                if (operatorsStack.top() == '(') { operatorsStack.pop(); break; }
                postfixExp += operatorsStack.top();
                postfixExp += ' ';
                operatorsStack.pop();
            }

        }
    }

    while (!operatorsStack.empty())
    {
        postfixExp += operatorsStack.top();
        postfixExp += ' ';
        operatorsStack.pop();
    }
    this->_expression = postfixExp;
    return postfixExp;
}

void Equation::printEquation() { cout << this->_expression << endl; }
