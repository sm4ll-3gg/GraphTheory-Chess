#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "enums.h"
#include "figure.h"

#include <list>

class Figure;

class Chessboard
{
public:
    Chessboard();
    Chessboard(int size);
    Chessboard(const Chessboard& other);

    int                 size() const;
    std::list<Figure*>  figures() const;

    void                add_figure(Figure* figure);
    void                set_size(int size);

    bool                is_attackable(Team team, int x, int y) const; // Находится ли клетка под ударом
    bool                is_free(int x, int y) const; // Свободна ли клетка

    bool                is_correct_cords(int x, int y) const; // Могут ли быть такие координаты
    bool                is_correct_cords(const std::pair<int,int>& cord) const; // ------------------------------

    const Chessboard&   operator = (const Chessboard& chessboard);

    void                print() const;

private: // methods
    void                print_figure(Figure* figure);

private:
    int         _size;
    std::list<Figure*>  _figures; // Все фигуры, стоящие на доске
};

#endif // CHESSBOARD_H
