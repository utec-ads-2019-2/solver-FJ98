// Created by felix on 10/2/19.
#include "ExpressionSolver.h"

InfixToPostfix::InfixToPostfix(std::string  expression): _expression{std::move(expression)}, root{nullptr} {}

bool InfixToPostfix::isOperand(const std::string& myChar) { return !isOperator(myChar) && myChar != "(" && myChar != ")"; }
bool InfixToPostfix::isOperator(const std::string& ch) { return ch == "^" || ch == "*" || ch == "/" || ch == "+" || ch == "-"; }
bool InfixToPostfix::priority(const std::string& ch, const std::string& opInTheStack) { return (isOperator(ch) && operatorPrecedence(ch) <= operatorPrecedence(opInTheStack)); }


int InfixToPostfix::operatorPrecedence(const std::string& operaTor)
{
    if(operaTor == "^") { return 3; }
    else if(operaTor == "*" || operaTor == "/") { return 2; }
    else if(operaTor == "+" || operaTor == "-") { return 1; }
    else { return -1; }
}

std::string InfixToPostfix::infixToPostfix()
{
    std::stack<std::string> operatorsStack;
    std::stack<Node*> nodesStack;
    std::stack<Node*> saveNodesStack;
    std::string postfixExp;
    std::vector<std::string> stackImitator;
    for (int i = 0; i < static_cast<int>(this->_expression.size()); ++i)
    {
        //if(myInfixChar == ' ' || myInfixChar == ',') { continue; }
        string s;
        s.push_back(this->_expression[i]);
        string nextChar;

        if (isOperand(s)) {
//            if (i > 0 && postfixExp.at(postfixExp.size()-1) != ' ') { postfixExp += " "; }

            nextChar.push_back(this->_expression[i+1]);
            if (isOperand(nextChar) && i + 1 < static_cast<int>(this->_expression.size())) {
                s.push_back(this->_expression[i + 1]);
                postfixExp += s;

                auto newNode = new Node{s};
                nodesStack.push(newNode);
                stackImitator.push_back(s);
                ++i;
            }else{
                postfixExp += s;

                auto newNode = new Node{s};
                nodesStack.push(newNode);
                stackImitator.push_back(s);
            }


        }

        else if (isOperator(s)) {
//            postfixExp += " ";
            while(!operatorsStack.empty() && operatorsStack.top() != "(" && priority(s, operatorsStack.top()))
            {
                postfixExp += operatorsStack.top();
//                stackImitator.push_back(operatorsStack.top());
                auto newNode = new Node{operatorsStack.top()};
                nodesStack.push(newNode);
                stackImitator.push_back(operatorsStack.top());

                operatorsStack.pop();
            }
            operatorsStack.push(s);

        }

        else if (s == "(") { operatorsStack.push(s);}

        else if (s == ")") {
//            postfixExp += " ";
            while(!operatorsStack.empty())
            {
                if (operatorsStack.top() == "(") { operatorsStack.pop(); break; }
                postfixExp += operatorsStack.top();

                auto newNode = new Node{operatorsStack.top()};
                nodesStack.push(newNode);
                stackImitator.push_back(operatorsStack.top());

                operatorsStack.pop();
            }

        }
    }

    while (!operatorsStack.empty())
    {
//        postfixExp += " ";
        postfixExp += operatorsStack.top();

        auto newNode = new Node{operatorsStack.top()};
        nodesStack.push(newNode);
        stackImitator.push_back(operatorsStack.top());

//        new Node(operatorStack.top())
//        if (node.isOperator())

        operatorsStack.pop();
    }
    this->_expression = postfixExp;

//    cout << "My nodes stack TOP: " << nodesStack.top()->_data << endl;
//    cout << "My nodes stack: ";
    for (int j = nodesStack.size(); j > 0; --j) {
//        cout << nodesStack.top()->_data << " ";
        this->postfixStack.push(nodesStack.top());
        nodesStack.pop();
    } /*cout << endl;*/
//
//    cout << "My postfix stack TOP: " << postfixStack.top()->_data << endl;
//    cout << "My postfix stack: ";
//    for (int k = postfixStack.size(); k > 0; --k) {
//        cout << postfixStack.top()->_data << " ";
//        postfixStack.pop();
//    } cout << endl;

//    cout << "stackImitator: ";
//    for (auto && item: stackImitator) {
//        cout << item << " ";
//    } cout << endl;
    return postfixExp;
}


void InfixToPostfix::printEquation() { std::cout << this->_expression << std::endl; }


void InfixToPostfix::buildTreeFromPostfix()
{
    buildTree(this->root);
}

void InfixToPostfix::buildTree(Node* tempRoot)
{
    std::stack<Node*> treeHelper;
    int sizet = treeHelper.size();

//    if (!isOperator(postfixStack.top()->_data)) {
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//    }
    // FIRST ITERATION
//    while (!isOperator(postfixStack.top()->_data)) {
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//    }
//    tempRoot = postfixStack.top();
//    tempRoot->_right = treeHelper.top();
//    treeHelper.pop();
//    tempRoot->_left = treeHelper.top();
//    treeHelper.pop();
//    postfixStack.pop();

    if (!isOperator(postfixStack.top()->_data)) {
        treeHelper.push(postfixStack.top());
        postfixStack.pop();
        treeHelper.push(postfixStack.top());
        postfixStack.pop();
    }

    if (!tempRoot){ return; }

    buildTree(tempRoot->_left);

    treeHelper.pop();
    buildTree(tempRoot->_right);
    treeHelper.pop();
    postfixStack.pop();

//    privateTraverseInOrder(tempRoot);

}

void InfixToPostfix::privateTraverseInOrder(Node* traverse)
{
    if (!traverse) return;
    privateTraverseInOrder(traverse->_left);
    cout << traverse->_data << " ";
    privateTraverseInOrder(traverse->_right);
}




//void InfixToPostfix::buildTreeFromPostfix()
//{
//    buildTree(this->root);
//}
//
//void InfixToPostfix::buildTree(Node* tempRoot)
//{
//    std::stack<Node*> treeHelper(postfixStack);
//    int sizet = treeHelper.size();
////    cout << "My postfix stack TOP: " << this->postfixStack.top()->_data << endl;
////    cout << "My postfix stack: ";
////    for (int k = postfixStack.size(); k > 0; --k) {
////        cout << postfixStack.top()->_data << " ";
////        treeHelper.push(postfixStack.top());
////        postfixStack.pop();
////    } cout << endl;
//
////    cout << "My helper stack TOP: " << treeHelper.top()->_data << endl;
////    cout << "My helper stack: ";
////    for (int k = treeHelper.size(); k > 0; --k) {
////        cout << treeHelper.top()->_data << " ";
////        treeHelper.pop();
////    } cout << endl;
//
//    // FIRST ITERATION
//    while (!isOperator(postfixStack.top()->_data)) {
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//    }
//    this->root = postfixStack.top();
//    this->root->_right = treeHelper.top();
//    treeHelper.pop();
//    this->root->_left = treeHelper.top();
//    treeHelper.pop();
//    postfixStack.pop();
//
//    while (!isOperator(postfixStack.top()->_data)) {
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//        treeHelper.push(postfixStack.top());
//        postfixStack.pop();
//    }
//    this->root = postfixStack.top();
//    this->root->_right = treeHelper.top();
//    treeHelper.pop();
//    this->root->_left = treeHelper.top();
//    treeHelper.pop();
//    postfixStack.pop();
//
////    this->root = postfixStack.top();
////    postfixStack.pop();
////    for (int i = this->postfixStack.size(); i > 0; --i)
////    {
////        this->root = postfixStack.top();
////        treeHelper.push(postfixStack.top());
////        if (isOperator(postfixStack.top()->_data)) {
//////            cout << this->root->_data << "\t";
////            this->root->_right = treeHelper.top();
//////            cout << this->root->_right->_data<< "\t";
////            treeHelper.pop();
////            this->root->_left = treeHelper.top();
//////            cout << this->root->_left->_data<< "\t";
////            treeHelper.pop();
////
////            treeHelper.push(postfixStack.top());
////        }
////
////        postfixStack.pop();
////    }
//
//    privateTraverseInOrder(this->root);
//
//}





//bool InfixToPostfix::nextCharIsOperator(int pos)
//{
//    std::string s;
//    s.push_back(this->_expression[pos + 1]);
//    return isOperator(s);
//}


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

