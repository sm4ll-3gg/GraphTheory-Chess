#include "figure.h"

#include <iostream>
#include <math.h>

Figure::Figure()
    :_team(Team::NONE),
      _type(Type::NO),
      _cord(0,0),
      _prev_cord(0,0)
{}

Figure::Figure(Team team, Type type, Figure::Cord cord)
    :_team(team),
      _type(type),
      _cord(cord),
      _prev_cord(cord)
{}

const Team& Figure::team() const
{
    return _team;
}

const Type& Figure::type() const
{
    return _type;
}

const Figure::Cord& Figure::cord() const
{
    return _cord;
}

const Figure::Cord& Figure::prev_cord() const
{
    return _prev_cord;
}

void Figure::set_cord(const Chessboard& chessboard, int x, int y)
{
    if(x < chessboard.size() && y < chessboard.size())
    {
        _cord.first = x;
        _cord.second = y;
    }
    else
    {
        std::cout << "Неверные координаты в set_cord" << std::endl;
    }
}

void Figure::set_cord(const Chessboard& chessboard, const Cord& cord)
{
    if(chessboard.is_correct_cords(cord))
    {
        _cord = cord;
    }
    else
    {
        std::cout << "Неверные координаты в set_cord" << std::endl;
    }
}

void Figure::set_prev_cord(const Chessboard& chessboard, const Figure::Cord& cord)
{
    if(chessboard.is_correct_cords(cord))
    {
        _prev_cord = cord;
    }
    else
    {
        std::cout << "Неверные координаты в set_prev_cord" << std::endl;
    }
}

bool Figure::can_attack(int x, int y) const
{
    switch (_type)
    {
    case Type::KING:
        //Фигуры находятся на смежных клетках
        if( abs(_cord.first - x) <= 1 && abs(_cord.second - y) <= 1 )
            return true;
        break;
    case Type::ROOK:
        //Фигуры стоят на одной линии (но не в одной точке)
        if( (_cord.first == x) ^ (_cord.second == y))
            return true;
        break;
    default:
        std::cout << "Не правильная фигура" << std::endl;
        break;
    }

    return false;
}

std::list<Figure::Cord> Figure::find_way(const Chessboard& chessboard) const
{
    std::list<Cord> ways;

    switch (_type)
    {
    case Type::KING:
        for(int i = _cord.first - 1; i <= _cord.first + 1; ++i)
        {
            for(int j = _cord.second - 1; j <= _cord.second + 1; ++j)
            {
                if(can_go(chessboard, i, j))
                {
                    ways.push_back(Cord(i,j));
                }
            }
        }

        break;
    case Type::ROOK:
        for(int i = 0; i < chessboard.size(); ++i)
        {
            if(can_go(chessboard, i, _cord.second))
                ways.push_back(Cord(i, _cord.second));

            if(can_go(chessboard, _cord.first, i))
                ways.push_back(Cord(_cord.first, i));
        }
        break;
    default:
        break;
    }

    return ways;
}

const Figure &Figure::operator =(const Figure &figure)
{
    _team = figure._team;
    _type = figure._type;
    _cord = figure._cord;
    _prev_cord = figure._prev_cord;

    return *this;
}

void Figure::print() const
{
    switch( _type )
    {
    case Type::KING:
        if(_team == Team::WHITE)
            std::cout << "♔";
        else
            std::cout << "♚";
        break;
    case Type::ROOK:
        std::cout << "♖";
    default:
        break;
    }
}

bool Figure::can_go(const Chessboard& chessboard, int x, int y) const
{
    if(!chessboard.is_correct_cords(x, y))
        return false;

    bool attackable = !chessboard.is_attackable(_team, x, y);
    bool isFree = chessboard.is_free(x, y);
    //bool isNotPrevMove = (x != _prev_cord.first) || (y != _prev_cord.second);

    return attackable && isFree /*&& isNotPrevMove*/;
}


