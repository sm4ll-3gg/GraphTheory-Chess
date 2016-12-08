#include "game.h"

#include <stack>

Game::Game()
    :end(nullptr),
      condition(GAME),
      tree()
{}

Game::Game(Chessboard chessboard)
    :end(nullptr),
      condition(GAME),
      tree(chessboard),
      temp(0)
{}

void Game::start_game()
{
    while(condition == GAME)
    {
        move();
    }

    std::stack<Node*> game;
    Node* temp = end;
    while(temp != nullptr)
    {
        game.push(temp);
        temp = temp->parent;
    }

    while(!game.empty())
    {
        Node* node = game.top();
        game.pop();

        node->chessboard.print();
    }
}

void Game::move()
{
    Node* leaf = tree.take_leaf();

    bool course = leaf->count % 2; // 1 - ход белых, 0 - черных

    if(leaf != nullptr)
    {
        Chessboard chessboard = leaf->chessboard;



        std::list<Figure*> figures = chessboard.figures();
        for(auto it = figures.begin(); it != figures.end(); ++it)
        {
            Figure* figure = *it;
            Figure backup = *figure;

            if(figure->team() == course)
            {
                std::list< std::pair<int, int> > ways = figure->find_way(chessboard);

                if(ways.empty())
                {
                    if(figure->team() == Team::BLACK && figure->type() == Type::KING)
                    {
                        std::pair<int, int> cords = figure->cord();
                        if(chessboard.is_attackable(figure->team(), cords.first, cords.second))
                        {
                            condition = Condition::MATE;
                            end = leaf;
                            return;
                        }
                    }
                }
                else
                {
                    for(auto it = ways.begin(); it != ways.end(); ++it)
                    {
                        std::pair<int, int> cords = *it;

                        figure->set_prev_cord(chessboard, figure->cord());
                        figure->set_cord(chessboard, cords.first, cords.second);

                        Node* node = new Node;
                        node->count = leaf->count+1;
                        node->chessboard = chessboard;
                        node->parent = leaf;

                        leaf->childs.push_back(node);
                        tree.push(node);

                        node = nullptr;
                        *figure = backup;
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Все очень-очень плохо" << std::endl;
    }

}
