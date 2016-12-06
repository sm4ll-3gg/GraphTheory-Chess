#include "chessboard.h"

#include <iostream>

Chessboard::Chessboard()
{}

Chessboard::Chessboard(size_t size)
    :_size(size)
{}

unsigned int Chessboard::size() const
{
    return _size;
}


std::list<Figure *> Chessboard::figures() const
{
    return _figures;
}

void Chessboard::add_figure(Figure* figure)
{
    size_t x = figure->cord().first;
    size_t y = figure->cord().second;

    if(x < _size && y < _size)
        _figures.push_back(figure);
    else
        std::cout << "Фигура не может быть добавлена так как имеет некорректные координаты" << std::endl;
}

void Chessboard::set_size(size_t size)
{
    _size = size;
}


void Chessboard::print() const
{
    for(auto it = _figures.begin(); it != _figures.end(); ++it)
    {
        (*it)->print();
    }
}
