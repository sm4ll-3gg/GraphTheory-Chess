#include "chessboard.h"

#include <iostream>

Chessboard::Chessboard()
{}

Chessboard::Chessboard(int size)
{
    _size = size >= 0 ? size : 0;
}

Chessboard::Chessboard(const Chessboard& other)
{
    _size = other._size;

    std::list<Figure*> figures = other._figures;
    for(auto it = figures.begin(); it != figures.end(); ++it)
    {
        Figure* figure = *it;
        Figure* temp = new Figure;
        *temp = *figure;

        _figures.push_back(temp);
    }
}

int Chessboard::size() const
{
    return _size;
}


std::list<Figure*> Chessboard::figures() const
{
    return _figures;
}

void Chessboard::add_figure(Figure* figure)
{
    int x = figure->cord().first;
    int y = figure->cord().second;

    if(x < _size && y < _size)
        _figures.push_back(figure);
    else
        std::cout << "Фигура не может быть добавлена так как имеет некорректные координаты" << std::endl;
}

void Chessboard::set_size(int size)
{
    _size = size >= 0 ? size : 0;
}

bool Chessboard::is_attackable(Team team, int x, int y) const
{
    if(!is_correct_cords(x, y))
        return true;

    for(auto it = _figures.begin(); it != _figures.end(); ++it)
    {
        if( (*it)->team() != team)
        {
            if( (*it)->can_attack(x,y) )
                return true;
        }
    }

    return false;
}

bool Chessboard::is_free(int x, int y) const
{
    if(is_correct_cords(x, y))
    {
        for(auto it = _figures.begin(); it != _figures.end(); ++it)
        {
            std::pair<int, int> cords = (*it)->cord();
            if(cords.first == x && cords.second == y)
                return false;
        }

        return true;
    }

    return false;
}

const Chessboard& Chessboard::operator =(const Chessboard& chessboard)
{
    _figures.clear();

    _size = chessboard._size;

    std::list<Figure*> figures = chessboard._figures;
    for(auto it = figures.begin(); it != figures.end(); ++it)
    {
        Figure* figure = *it;
        Figure* temp = new Figure;
        *temp = *figure;

        _figures.push_back(temp);
    }

    return *this;
}


void Chessboard::print() const
{
    for(int i = 0; i < _size*2+1; ++i)
    {
        for(int j = 0; j < _size*2+1; ++j)
        {
            if(i % 2 == 0)
            {
                std::cout << " - ";
            }
            else if(j % 2 == 0)
            {
                std::cout << " | ";
            }
            else
            {
                for(auto it = _figures.begin(); it != _figures.end(); ++it)
                {
                    std::pair<int, int> cords = (*it)->cord();

                    if(cords.first == i/2 && cords.second == j/2)
                        (*it)->print();
                    else
                        std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

bool Chessboard::is_correct_cords(int x, int y) const
{
    if( x >= 0 && y >= 0 && x < _size && y < _size)
        return true;

    return false;
}

bool Chessboard::is_correct_cords(const std::pair<int, int> &cord) const
{
    int x = cord.first;
    int y = cord.second;

    if( x >= 0 && y >= 0 && x < _size && y < _size)
        return true;

    return false;
}
