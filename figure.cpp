#include "figure.h"

Figure::Figure()
    :_team(Team::NONE),
     _type(Type::NO),
     _cord(0,0)
{}

Figure::Figure(Figure::Team team, Figure::Type type, Figure::Cord cord)
    :_team(team),
     _type(type),
     _cord(cord)
{}

Figure::Team Figure::team()
{
    return _team;
}

Figure::Type Figure::type()
{
    return _type;
}

Figure::Cord Figure::cord()
{
    return _cord;
}

void Figure::move()
{

}


