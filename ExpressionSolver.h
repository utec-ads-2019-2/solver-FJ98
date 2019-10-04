// Created by felix on 10/2/19.
#ifndef SOLVER_FJ98_EXPRESSIONSOLVER_H
#define SOLVER_FJ98_EXPRESSIONSOLVER_H

#include <bits/stdc++.h>

#include <utility>

using namespace std;

struct Node {
    std::string _data;
    Node* _right;
    Node* _left;
    Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
    explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
    void killSelf() {
        if (this->_left) this->_left->killSelf();
        else if (this->_right) this->_right->killSelf();

        delete this;
    }
//    static char isNumberDigit() {this->_data };
    float execute() {
        const char* dat = this->_data.c_str();
        switch (*dat) {
            case '+': return this->_left->execute() + this->_right->execute();
            case '-': return this->_left->execute() - this->_right->execute();
            case '*': return this->_left->execute() * this->_right->execute();
            case '/': return this->_left->execute() / this->_right->execute();
            case '^': return std::pow(this->_left->execute(), this->_right->execute());
            default:  { return stof(this->_data); }
        }
    }
};

class InfixToPostfix{
private:
    std::string _expression;

    std::stack<Node*> postfixStack;
    Node* root;

    std::map<std::string, float> values;

private:
    static bool isOperand(const std::string&);
    static bool isOperator(const std::string&);
    static bool isValidForVariableName (const std::string&);
    static int operatorPrecedence(const std::string&);
    static bool priority(const std::string&, const std::string&);
    static void privateTraverseInOrder(Node* traverse);
    bool foundInMyMap(const std::string&);
    int valueInMyMapCorrespondingToVariable(const std::string&);

public:
    explicit InfixToPostfix(std::string);
    std::string infixToPostfix();
    void buildTreeFromPostfix();
    Node* buildTree(Node*);
    static size_t privateFindHeight(Node*);
    inline void traverseInOrder() { privateTraverseInOrder(this->root); }
    void printEquation();
    float solveEquation();
    void askValues();
    std::string getEquation() { return this->_expression; }
    ~InfixToPostfix();
};


//class ExpressionSolver {
//private:
//    struct Node {
//        std::string _data;
//        Node* _right;
//        Node* _left;
//        Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
//        explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
//    };
//    Node* root;
//
//public:
//    ExpressionSolver();
//    Node* buildTreeFromEquation();
//
//};


#endif //SOLVER_FJ98_EXPRESSIONSOLVER_H
