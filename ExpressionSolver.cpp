// Created by felix on 10/2/19.
#include "ExpressionSolver.h"

// CONSTRUCTOR
Equation::Equation(std::string  expression): _expression{std::move(expression)}, root{nullptr} {}

//---------------------------------------------HELP-FUNCTIONS-----------------------------------------------------------
bool Equation::isOperand(const std::string& myChar) { return !isOperator(myChar) && myChar != "(" && myChar != ")"; }
bool Equation::isOperator(const std::string& ch) {return ch == "^" || ch == "*" || ch == "/" || ch == "+" || ch == "-";}
bool Equation::priority(const std::string& ch, const std::string& opInStk) {
    return (isOperator(ch) && opPrecedence(ch) <= opPrecedence(opInStk));
}
bool Equation::isValidForVariableName(const std::string& ch) {
    return  ch == "_" || ("a" <= ch && ch <= "z") || ("A" <= ch && ch <= "Z");
}
bool Equation::foundInMyMap(const std::string & myCh) { auto it = values.find(myCh); return it != values.end(); }

int Equation::opPrecedence(const std::string& operaTor)
{
    if(operaTor == "^") { return 3; }
    else if(operaTor == "*" || operaTor == "/") { return 2; }
    else if(operaTor == "+" || operaTor == "-") { return 1; }
    else { return -1; }
}
int Equation::valueInMyMapCorrespondingToVariable(const std::string & myCh)
{
    auto it = values.find(myCh);
    if (it != values.end()){ return it->second; }
    return 0;
}

void Equation::privateTraverseInOrder(Node* traverse)
{
    if (!traverse) return;
    privateTraverseInOrder(traverse->_left);
    cout << traverse->_data << " ";
    privateTraverseInOrder(traverse->_right);
}
void Equation::privateTraversePostOrder(Node* traverse)
{
    if (!traverse) return;
    privateTraversePostOrder(traverse->_left);
    privateTraversePostOrder(traverse->_right);
    cout << traverse->_data << " ";
}
void Equation::traverseInOrder() { this->privateTraverseInOrder(this->root); }
void Equation::traversePostOrder() { this->privateTraversePostOrder(this->root); }
//----------------------------------------------------------------------------------------------------------------------

//---------------------------------------------PRINCIPAL-FUNCTIONS------------------------------------------------------
std::string Equation::infixToPostfix()
{
    std::stack<std::string> operatorsStack;
    std::stack<Node*> nodesStack;
    std::string postfixExp;
    for (int i = 0; i < static_cast<int>(this->_expression.size()); ++i)
    {
        //if(myInfixChar == ' ' || myInfixChar == ',') { continue; }
        string s;
        s.push_back(this->_expression[i]);
        string nextChar;

        // TO IDENTIFY IF IT IS A NUMBER OR VARIABLE
        if (isOperand(s)) {
            nextChar.push_back(this->_expression[i+1]);

            // To identify if it is a variable
            if (isValidForVariableName(s)) {
                if (foundInMyMap(s)){
                    s = to_string(valueInMyMapCorrespondingToVariable(s));

                    postfixExp += s;
                    auto newNode = new Node{s};
                    nodesStack.push(newNode);
                }
                else {
                    float value;
                    cout << "Inserta el valor de la variable " << s << " : ";
                    cin >> value;
                    values.insert({s, value});
                    s = to_string(valueInMyMapCorrespondingToVariable(s));

                    postfixExp += s;
                    auto newNode = new Node{s};
                    nodesStack.push(newNode);
                }
            }

            // To identify if there is a number with more than one digit
            else if (isOperand(nextChar) && i + 1 < static_cast<int>(this->_expression.size())) {
                s.push_back(this->_expression[i + 1]);

                postfixExp += s;
                auto newNode = new Node{s};
                nodesStack.push(newNode);

                ++i;
            }else{
                postfixExp += s;
                auto newNode = new Node{s};
                nodesStack.push(newNode);
            }

        }

        // TO IDENTIFY IF IT IS AN OPERATOR
        else if (isOperator(s)) {
            while(!operatorsStack.empty() && operatorsStack.top() != "(" && priority(s, operatorsStack.top()))
            {
                postfixExp += operatorsStack.top();
                auto newNode = new Node{operatorsStack.top()};
                nodesStack.push(newNode); operatorsStack.pop();
            }
            operatorsStack.push(s);
        }

        // TO IDENTIFY LEFT PARENTHESIS
        else if (s == "(") { operatorsStack.push(s);}

        // TO IDENTIFY RIGHT PARENTHESIS
        else if (s == ")") {
            while(!operatorsStack.empty())
            {
                if (operatorsStack.top() == "(") { operatorsStack.pop(); break; }

                postfixExp += operatorsStack.top();
                auto newNode = new Node{operatorsStack.top()};
                nodesStack.push(newNode);
                operatorsStack.pop();
            }
        }
    }

    while (!operatorsStack.empty())
    {
        postfixExp += operatorsStack.top();
        auto newNode = new Node{operatorsStack.top()};
        nodesStack.push(newNode);
        operatorsStack.pop();
    }

    this->_expression = postfixExp; /* Now _expression is a postfix expression*/

    // TO HAVE POSTFIX STACK IN CORRECT ORDER
    for (int j = nodesStack.size(); j > 0; --j) {
        this->postfixStack.push(nodesStack.top());
        nodesStack.pop();
    }
    return postfixExp;
}

void Equation::buildTreeFromPostfix() { this->root = buildTree(this->root); }
/*  TO BUILD THE TREE:
 *  Push <operand1> onto the stack, Push <operand2> onto the stack
 *  Pop <operand1> and <operand2>, create <operator1>-node (with <operand1> and <operand2> below), push it on the stack
 *  Push <operand3> on stack Push <operand3> on stack
 *  Pop <operand3> and <operand4> and combine to form the <operator2>-node
 *  etc.*/
Node* Equation::buildTree(Node* tempRoot)
{
    std::stack<Node*> treeHelper;
    while (!postfixStack.empty())
    {
        if (!isOperator(postfixStack.top()->_data)) {
            treeHelper.push(postfixStack.top()); postfixStack.pop();
        }else {
            tempRoot = postfixStack.top();postfixStack.pop();
            tempRoot->_right = treeHelper.top(); treeHelper.pop();
            tempRoot->_left = treeHelper.top(); treeHelper.pop();

            treeHelper.push(tempRoot);
        }
    }
    if (!treeHelper.empty()) {
        treeHelper.push(tempRoot);
        tempRoot = treeHelper.top(); treeHelper.pop();
    }
    return tempRoot;
}

float Equation::solveEquation() { return this->root->execute(); } /* RECURSIVE FUNCTION*/
// ---------------------------------------------------------------------------------------------------------------------

// DESTRUCTOR
Equation::~Equation() {
    if (!this->root) { return; }
    else { this->root->killSelf(); }
}