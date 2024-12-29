#include "snake.h"


int2::int2(int x, int y) : x(x), y(y) {}
int2 int2::operator+(int2 other)
{
	return int2(this->x + other.x, this->y + other.y);
}


SnakeElement::SnakeElement(int2 pos) : pos(pos), nextElement(nullptr) {}
void SnakeElement::Move(int2 newPos)
{
	int2 oldPos = pos;
	pos = newPos;
	if (nextElement != nullptr)
	{
		nextElement->Move(oldPos);
	}
}

Snake::Snake(int2 pos, int2 direction) : direction(direction)
{
	head = new SnakeElement(pos);
}

void Snake::MoveForward()
{
	head->Move(head->pos + direction);
}