#include "tree.h"

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(Chessboard chessboard)
{
    root = new Node;
    root->count = 0;
    root->chessboard = chessboard;
    root->parent = nullptr;

    leaves.push(root);
}

void Tree::push(Node* node)
{
    leaves.push(node);
}

Node* Tree::take_leaf()
{
    if(!leaves.empty())
    {
        Node* leaf = leaves.front();
        leaves.pop();

        return leaf;
    } else return nullptr;
}
