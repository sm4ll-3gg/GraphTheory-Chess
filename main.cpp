#include "chessboard.h"
#include "game.h"

#include <iostream>

int main()
{
    Chessboard chessboard(4);
//    Figure* whiteKing = new Figure(Team::WHITE, Type::KING, Figure::Cord(0,0));
//    chessboard.add_figure(whiteKing);
//    Figure* whiteRook = new Figure(Team::WHITE, Type::ROOK, Figure::Cord(1,3));
//    chessboard.add_figure(whiteRook);
//    Figure* blackKing = new Figure(Team::BLACK, Type::KING, Figure::Cord(3,2));
//    chessboard.add_figure(blackKing);

    Figure* whiteKing = new Figure(Team::WHITE, Type::KING, Figure::Cord(0,0));
    chessboard.add_figure(whiteKing);
    Figure* whiteRook = new Figure(Team::WHITE, Type::ROOK, Figure::Cord(0,3));
    chessboard.add_figure(whiteRook);
    Figure* blackKing = new Figure(Team::BLACK, Type::KING, Figure::Cord(1,2));
    chessboard.add_figure(blackKing);


    Game game(chessboard);

    game.start_game();
    std::cout << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
