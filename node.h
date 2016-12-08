#ifndef NODE_H
#define NODE_H

#include "chessboard.h"

#include <list>
#include <queue>

struct Node
{
    int         count; // номер хода
    Chessboard  chessboard;

    Node* parent;
    std::list<Node*> childs;
};

#endif // NODE_H
