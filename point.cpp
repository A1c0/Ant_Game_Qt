#include "point.h"

int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    this->x = value;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    this->y = value;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
