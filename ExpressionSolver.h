// Created by felix on 10/2/19.
#ifndef SOLVER_FJ98_EXPRESSIONSOLVER_H
#define SOLVER_FJ98_EXPRESSIONSOLVER_H

#include <bits/stdc++.h>

#include <utility>

using namespace std;


class PostFixExp{
private:
    std::string _expression;

private:
    bool isOperand(std::string);
    bool isOperator(std::string);
    int operatorPrecedence(std::string);
    bool priority(std::string, std::string);
    bool nextCharIsOperator(int pos);

public:
    explicit PostFixExp(std::string);
    std::string infixToPostfix();

    void printEquation();
};

class TreeBuilder{
private:
    struct Node {
        std::string _data;
        Node* _right;
        Node* _left;
        Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
        explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
    };
    Node* root;

public:
//    ExpressionSolver();
    Node* buildTreeFromEquation();

};

class ExpressionSolver {
private:
    struct Node {
        std::string _data;
        Node* _right;
        Node* _left;
        Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
        explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
    };
    Node* root;

public:
    ExpressionSolver();
    Node* buildTreeFromEquation();

};


#endif //SOLVER_FJ98_EXPRESSIONSOLVER_H
