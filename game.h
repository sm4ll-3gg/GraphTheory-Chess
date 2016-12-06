#ifndef GAME_H
#define GAME_H

#include <chessboard.h>

class Game
{
public:
    Game();
    Game(Chessboard chessboard);

    void    set_chessboard_size(size_t size);
    void    add_figure(Figure* figure);
    void    foo()
    {
        _chessboard.print();
    }

private: // methods
    void    move();

private:
    size_t      count; // Счетчик ходов
    Chessboard  _chessboard;
    //Tree
};

#endif // GAME_H
