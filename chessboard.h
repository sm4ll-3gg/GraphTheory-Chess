#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "figure.h"

#include <vector>

class Chessboard
{
public:
    Chessboard();
    Chessboard(size_t size);

    unsigned int    size() const;
    void            add_figure(Figure* figure);

    void            set_size(size_t size);

    void            print();

private: // methods
    void            print_cell(Figure*);

private:
    size_t _size;

    std::vector< std::vector<Figure*> > map;
    //std::list<Figure*> figures; // Все фигуры, стоящие на доске
};

#endif // CHESSBOARD_H
