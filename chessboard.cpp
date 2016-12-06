#include "chessboard.h"

#include <iostream>
#include <algorithm>

Chessboard::Chessboard()
{}

Chessboard::Chessboard(size_t size)
    :_size(size)
{
    for(size_t i = 0; i < size; ++i)
    {
        map.push_back(std::vector<Figure*>(size));

        for(size_t j = 0; j < size; ++j)
        {
            map[i][j] = nullptr;
        }
    }
}

unsigned int Chessboard::size() const
{
    return _size;
}

void Chessboard::add_figure(Figure* figure)
{
    size_t x = figure->cord().first;
    size_t y = figure->cord().second;
    map[x][y] = figure;

    //figures.push_back(figure);
}

void Chessboard::set_size(size_t size)
{
    map.clear();

    _size = size;

    for(size_t i = 0; i < size; ++i)
    {
        map.push_back(std::vector<Figure*>(size));

        for(size_t j = 0; j < size; ++j)
        {
            map[i][j] = nullptr;
        }
    }
}

void Chessboard::print_cell(Figure* figure)
{
    if(figure)
    {
        switch( figure->type() )
        {
        case Figure::Type::KING:
            if(figure->team() == Figure::Team::WHITE)
                std::cout << "♔";
            else
                std::cout << "♚";
            break;
        case Figure::Type::ROOK:
            std::cout << "♖";
        default:
            break;
        }
    }
    else
        std::cout << " ";
}


void Chessboard::print()
{
    for (size_t i = 0; i < _size*2+1; i++)
    {
        for(size_t j = 0; j < _size*2+1; j++)
        {
            if(i % 2 == 0)
            {
                std::cout << "━";
            }
            else if(j % 2 == 0)
            {
                std::cout << "┃";
            }
            else
            {
                print_cell(map[i/2][j/2]);
            }
        }
        std::cout << std::endl;
    }
}
