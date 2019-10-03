// Created by felix on 10/1/19.
//#ifndef SOLVER_FJ98_FUNCIONES_H
//#define SOLVER_FJ98_FUNCIONES_H
//
//#include<bits/stdc++.h>
//
//using namespace std;
//
//
//int ctoi(char);
//bool isNumericDigit(char);
//
//int resolveOperation(char, int, int);
//int evaluatePostfix(const string&);
//
//bool isOperand(char);
//bool isOperator(char);
//int operatorPrecedence(char);
//bool isHigherPriority(char, char);
//std::string infixToPostfix(const std::string&);
//
//
//int ctoi(char digitToConvert)
//{
//    return (digitToConvert - '0');
//}
//
//bool isOperand(char character)
//{
//    return !isOperator(character) && character != '(' && character != ')';
//}
//
//bool isOperator(char character)
//{
//    return character == '^' || character == '*' || character == '/' || character == '+' || character == '-';
//}
//
//int operatorPrecedence(char operaTor)
//{
//    if(operaTor == '^') return 3;
//    else if(operaTor == '*' || operaTor == '/') return 2;
//    else if(operaTor == '+' || operaTor == '-') return 1;
//    else return -1;
//}
//bool isHigherPriority(char myCharacter, char operatorInTheStack)
//{
//    return (isOperator(myCharacter) && operatorPrecedence(myCharacter) <= operatorPrecedence(operatorInTheStack));
//}
//
//std::string infixToPostfix(const std::string& infixExpression)
//{
//    std::stack<char> stackOfOperators;
//    std::string postfixExpression;
//
//    for (auto && myInfixChar : infixExpression)
//    {
//        if(myInfixChar == ' ' || myInfixChar == ',') { continue; }
//
//        if (isOperand(myInfixChar)) { postfixExpression += myInfixChar; }
//
//        else if (isOperator(myInfixChar)) {
//            while(!stackOfOperators.empty() && stackOfOperators.top() != '(' &&  isHigherPriority(myInfixChar, stackOfOperators.top()) /*compareOperators(stackOfOperators.top(), myInfixChar) <= 0*/)
//            {
//                postfixExpression += stackOfOperators.top();
//                postfixExpression += ' ';
//                stackOfOperators.pop();
//            }
//            postfixExpression += ' ';
//            stackOfOperators.push(myInfixChar);
//        }
//
//        else if (myInfixChar == '(') { stackOfOperators.push(myInfixChar); }
//
//        else if (myInfixChar == ')')
//        {
//            while(!stackOfOperators.empty())
//            {
//                if (stackOfOperators.top() == '(') { stackOfOperators.pop(); break; }
//                postfixExpression += stackOfOperators.top();
//                postfixExpression += ' ';
//                stackOfOperators.pop();
//            }
//
//        }
//    }
//
//    while (!stackOfOperators.empty())
//    {
//        postfixExpression += stackOfOperators.top();
//        postfixExpression += ' ';
//        stackOfOperators.pop();
//    }
//
//    return postfixExpression;
//}
//
//int compareOperators(char op1, char op2) {
//    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
//    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
//    return 0;
//}
//
//
//int resolveOperation(char op, int operand1, int operand2)
//{
//
//    if (op == '+') { return operand1 + operand2; }
//    else if (op == '-') { return operand1 - operand2; }
//    else if (op == '*') { return operand1 * operand2; }
//    else if (op == '/') { return operand1 / operand2; }
//    else if (op == '^') { return std::pow(operand1, operand2); }
//
//    else cout << "NO SYMBOL" << endl;
//    return -1;
//}
//
//int evaluatePostfix(const string& expression)
//{
//    stack<int> S;
//
//
//    return S.top();
//}
//
//
//#endif //SOLVER_FJ98_FUNCIONES_H
