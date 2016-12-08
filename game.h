#ifndef GAME_H
#define GAME_H

#include "chessboard.h"
#include "tree.h"

class Game
{
public:
    Game();
    Game(Chessboard chessboard);

    void    start_game();
    void    move();

private: // methods
    void        change_condition(Figure* figure, const Chessboard& chessboard);

private:
    enum Condition { GAME = 0, MATE = 1, SALEMATE = 2 };

    Node*       end; // последний ход

    Condition   condition;
    Tree        tree;

    int temp;
};

#endif // GAME_H
