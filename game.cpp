#include "game.h"

Game::Game()
    :count(0)
{}

Game::Game(Chessboard chessboard)
    :_chessboard(chessboard),
     count(0)
{}

void Game::set_chessboard_size(size_t size)
{
    _chessboard.set_size(size);
}

void Game::add_figure(Figure* figure)
{
    _chessboard.add_figure(figure);
}

void Game::move()
{
    bool step = count % 2; // 0 - ход белых, 1 - черных


}
