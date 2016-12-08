#include "chessboard.h"
#include "game.h"

#include <iostream>

int main()
{
    // Предполагается, что все введенные значения корректны!

    int s = 0;

    std::cout << "Введите размер поля: ";
    std::cin >> s;
    Chessboard chessboard(s);

    int x = 0;
    int y = 0;

    std::cout << "Введите координаты x и y для белого короля:" << std::endl;
    std::cin >> x >> y;
    Figure* whiteKing = new Figure(Team::WHITE, Type::KING, Figure::Cord(x,y)); // 0 0
    chessboard.add_figure(whiteKing);

    std::cout << "Введите координаты x и y для белой ладьи:" << std::endl;
    std::cin >> x >> y;
    Figure* whiteRook = new Figure(Team::WHITE, Type::ROOK, Figure::Cord(x,y)); // 0 3
    chessboard.add_figure(whiteRook);

    std::cout << "Введите координаты x и y для черного короля:" << std::endl;
    std::cin >> x >> y;
    Figure* blackKing = new Figure(Team::BLACK, Type::KING, Figure::Cord(x,y)); // 1 2
    chessboard.add_figure(blackKing);


    Game game(chessboard);

    game.start_game();
    std::cout << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
