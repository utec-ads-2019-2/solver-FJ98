// Created by felix on 10/2/19.
#ifndef SOLVER_FJ98_EXPRESSIONSOLVER_H
#define SOLVER_FJ98_EXPRESSIONSOLVER_H

#include <bits/stdc++.h>

#include <utility>

using namespace std;


class Equation{
private:
    std::string _expression;

private:
    static bool isOperand(char);
    static bool isOperator(char);
    static int operatorPrecedence(char);
    static bool priority(char, char);

public:
    explicit Equation(std::string);
    std::string infixToPostfix();
    void printEquation();
};




//class ExpressionSolver {
//private:
//    struct Node{
//        std::string _data;
//        Node* _right;
//        Node* _left;
//        Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
//        explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
//    };
//    Node* root;
//
//
//public:
//
//};


#endif //SOLVER_FJ98_EXPRESSIONSOLVER_H
