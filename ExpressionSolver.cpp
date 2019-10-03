// Created by felix on 10/2/19.
#include "ExpressionSolver.h"

PostFixExp::PostFixExp(std::string  expression): _expression{std::move(expression)} {}

bool PostFixExp::isOperand(std::string myChar) { return !isOperator(myChar) && myChar != "(" && myChar != ")"; }
bool PostFixExp::isOperator(std::string ch) { return ch == "^" || ch == "*" || ch == "/" || ch == "+" || ch == "-"; }
bool PostFixExp::priority(std::string ch, std::string opInTheStack) { return (isOperator(ch) && operatorPrecedence(ch) <= operatorPrecedence(opInTheStack)); }


int PostFixExp::operatorPrecedence(std::string operaTor)
{
    if(operaTor == "^") { return 3; }
    else if(operaTor == "*" || operaTor == "/") { return 2; }
    else if(operaTor == "+" || operaTor == "-") { return 1; }
    else { return -1; }
}

std::string PostFixExp::infixToPostfix()
{
    std::stack<std::string> operatorsStack;
    std::string postfixExp;
    std::vector<std::string> stackImitator;
    for (int i = 0; i < static_cast<int>(this->_expression.size()); ++i)
    {
        //if(myInfixChar == ' ' || myInfixChar == ',') { continue; }
        string s;
        s.push_back(this->_expression[i]);
        string nextChar;

        if (isOperand(s)) {
            if (i > 0 && postfixExp.at(postfixExp.size()-1) != ' ') { postfixExp += " "; }

            nextChar.push_back(this->_expression[i+1]);
            if (isOperand(nextChar) && i + 1 < static_cast<int>(this->_expression.size())) {
                s.push_back(this->_expression[i + 1]);
                postfixExp += s;
                stackImitator.push_back(s);
                ++i;
            }else{
                postfixExp += s;
                stackImitator.push_back(s);
            }


        }

        else if (isOperator(s)) {
            postfixExp += " ";
            while(!operatorsStack.empty() && operatorsStack.top() != "(" && priority(s, operatorsStack.top()))
            {
                postfixExp += operatorsStack.top();
//                stackImitator.push_back(operatorsStack.top());
                operatorsStack.pop();
            }
            operatorsStack.push(s);
            stackImitator.push_back(s);
        }

        else if (s == "(") { operatorsStack.push(s);}

        else if (s == ")") {
            postfixExp += " ";
            while(!operatorsStack.empty())
            {
                if (operatorsStack.top() == "(") { operatorsStack.pop(); break; }
                postfixExp += operatorsStack.top();

                operatorsStack.pop();
            }

        }
    }

    while (!operatorsStack.empty())
    {
        postfixExp += " ";
        postfixExp += operatorsStack.top();

//        new Node(operatorStack.top())
//        if (node.isOperator())

        operatorsStack.pop();
    }
    this->_expression = postfixExp;

    cout << "stackImitator: ";
    for (auto && item: stackImitator) {
        cout << item << " ";
    } cout << endl;
    return postfixExp;
}

void PostFixExp::printEquation() { std::cout << this->_expression << std::endl; }

bool PostFixExp::nextCharIsOperator(int pos)
{
    std::string s;
    s.push_back(this->_expression[pos + 1]);
    return isOperator(s);
}















//// Returns root of constructed tree for given
//// postfix expression
//et* constructTree(char postfix[])
//{
//    stack<et *> st;
//    et *t, *t1, *t2;
//
//    // Traverse through every character of
//    // input expression
//    for (int i=0; i<strlen(postfix); i++)
//    {
//        // If operand, simply push into stack
//        if (!isOperator(postfix[i]))
//        {
//            t = newNode(postfix[i]);
//            st.push(t);
//        }
//        else // operator
//        {
//            t = newNode(postfix[i]);
//
//            // Pop two top nodes
//            t1 = st.top(); // Store top
//            st.pop();      // Remove top
//            t2 = st.top();
//            st.pop();
//
//            //  make them children
//            t->right = t1;
//            t->left = t2;
//
//            // Add this subexpression to stack
//            st.push(t);
//        }
//    }
//
//    //  only element will be root of expression
//    // tree
//    t = st.top();
//    st.pop();
//
//    return t;
//}