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
};

class InfixToPostfix{
private:
    std::string _expression;

    std::stack<Node*> postfixStack;
    Node* root;

private:
    static bool isOperand(const std::string&);
    static bool isOperator(const std::string&);
    static int operatorPrecedence(const std::string&);
    static bool priority(const std::string&, const std::string&);
    static void privateTraverseInOrder(Node* traverse);

public:
    explicit InfixToPostfix(std::string);
    std::string infixToPostfix();
    void buildTreeFromPostfix();
    Node* buildTree(Node*);
    size_t privateFindHeight(Node*);
    inline void traverseInOrder() { privateTraverseInOrder(this->root); }
    void printEquation();
    float solveEquation();
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
