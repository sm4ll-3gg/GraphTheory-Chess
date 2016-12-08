#ifndef FIGURE_H
#define FIGURE_H

#include "enums.h"
#include "chessboard.h"

#include <iostream>
#include <list>

class Chessboard;

class Figure
{
public:
    typedef std::pair<int, int> Cord;

    Figure();
    Figure(Team team, Type type, Cord cord);

    const Team&     team() const;
    const Type&     type() const;
    const Cord&     cord() const;
    const Cord&     prev_cord() const;

    void            set_cord(const Chessboard& chessboard, int x, int y);
    void            set_cord(const Chessboard& chessboard, const Cord& cord);
    void            set_prev_cord(const Chessboard& chessboard, const Cord& cord);

    bool            can_attack(int x, int y) const; // Может ли фигура атаковать данную точку
    std::list<Cord> find_way(const Chessboard& chessboard) const; // Находит все возможные ходы из данной точки

    const Figure&   operator =(const Figure& figure);

    void            print() const;

private: // methods
    bool    can_go(const Chessboard& chessboard, int x, int y) const; // Может ли фигура пойти в данную точку

private:
    Team _team;
    Type _type;
    Cord _cord;
    Cord _prev_cord; // Координаты предыдущего хода
};

#endif // FIGURE_H
