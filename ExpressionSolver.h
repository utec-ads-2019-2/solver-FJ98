// Created by felix on 10/2/19.
#ifndef SOLVER_FJ98_EXPRESSIONSOLVER_H
#define SOLVER_FJ98_EXPRESSIONSOLVER_H

#include <bits/stdc++.h>

#include <utility>

using namespace std;


class InfixToPostfix{
private:
    std::string _expression;
    struct Node {
        std::string _data;
        Node* _right;
        Node* _left;
        Node(): _data{""}, _left{nullptr}, _right{nullptr} {}
        explicit Node(std::string data): _data{std::move(data)}, _left{nullptr}, _right{nullptr} {}
    };
    std::stack<Node> postfixStack;
    Node* root;

private:
    static bool isOperand(const std::string&);
    static bool isOperator(const std::string&);
    static int operatorPrecedence(const std::string&);
    static bool priority(const std::string&, const std::string&);
//    bool nextCharIsOperator(int);

public:
    explicit InfixToPostfix(std::string);
    std::string infixToPostfix();
    void buildTreeFromPostfix();

    void printEquation();
};




class Equation {
private:
    const int N_OPERATIONS = 5;
    const double EPS = 1e-3;
    const double DEFAULT_VALUE = 0.0;
    enum class Operation { ADD, SUB, MUL, DIV, POW };
    enum class Type { VALUE, OPERATION, VARIABLE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS };

    struct Element {
        Type type;
        double val;
        Operation op;
        std::string var;
        inline bool isValue () const { return type == Type::VALUE; }
        inline bool isOperation () const { return type == Type::OPERATION; }
        inline bool isVariable () const { return type == Type::VARIABLE; }
        inline bool isLeftParenthesis () const { return type == Type::LEFT_PARENTHESIS; }
        inline bool isRightParenthesis () const { return type == Type::RIGHT_PARENTHESIS; }
    };

    struct Node {
        Element* elem;
        Node* left;
        Node* right;
        Node () : left{nullptr}, right{nullptr} {}
        ~Node () {}
    };

    std::string equation;
    std::string equivalence;
    std::vector <Element> array;
    std::vector <int> level;
    std::vector <int> match;
    std::vector < std::vector <std::vector <int>> > position; // [operation][level]
    std::map <std::string, double> values;
    Node* root = 0;

    void clear (Node*& cur);
    void deleteSpaces ();
    void reduceSigns ();
    void createArray ();
    void transformUnaryOperations ();
    void computeLevelAndMatch ();
    void computeOperationsPositions ();
    void computePositions (std::vector <std::vector <int>>& row, Operation op);
    void buildTree ();
    void build (int l, int r, Node*& cur);
    int getNextOperation (int l, int r);
    int findNextOperation (int l, int r, Operation op);
    double eval (Node* cur);

public:
    Equation () {}
    ~Equation () { clear(root); }
    inline std::string getEquation () const { return equation; }
    inline std::string getEquivalence () const { return equivalence; }
    static Equation* buildFromEquation (std::string equation);
    void askValues ();
    double eval ();
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
