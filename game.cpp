#include "game.h"

Game::Game()
    :count(0)
{}

Game::Game(Chessboard chessboard)
    :count(0),
      _chessboard(chessboard)
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

    std::list<Figure*> figures = _chessboard.figures();
    for(auto it = figures.begin(); it != figures.end(); ++it)
    {
        Figure* figure = *it;
        if( figure->team() == step )
        {
            figure->print();
        }
    }

    count++;
}
