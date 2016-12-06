#include "game.h"

#include <iostream>

int main()
{
    Game game;
    game.set_chessboard_size(4);

    Figure* whiteKing = new Figure(Figure::Team::WHITE, Figure::Type::KING, Figure::Cord(0,0));
    game.add_figure(whiteKing);
    Figure* whiteRook = new Figure(Figure::Team::WHITE, Figure::Type::ROOK, Figure::Cord(1,3));
    game.add_figure(whiteRook);
    Figure* blackKing = new Figure(Figure::Team::BLACK, Figure::Type::KING, Figure::Cord(3,2));
    game.add_figure(blackKing);

    game.foo();

    std::cout << "Hello World!" << std::endl;
    return 0;
}
