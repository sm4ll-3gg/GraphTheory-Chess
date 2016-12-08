#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree
{
    Node* root;
    std::queue<Node*> leaves;

public:
    Tree();
    Tree(Chessboard chessboard);

    void    push(Node* node);

    Node*   take_leaf();
};

#endif // TREE_H
