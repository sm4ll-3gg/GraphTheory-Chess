#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "figure.h"

#include <list>

class Chessboard
{
public:
    Chessboard();
    Chessboard(size_t size);

    unsigned int        size() const;
    std::list<Figure*>  figures() const;

    void                add_figure(Figure* figure);
    void                set_size(size_t size);

    void                print() const;

private: // methods
    void                print_figure(Figure* figure);

private:
    size_t              _size;
    std::list<Figure*>  _figures; // Все фигуры, стоящие на доске
};

#endif // CHESSBOARD_H
