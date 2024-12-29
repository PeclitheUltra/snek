#pragma once
struct int2
{
public:
	int x;
	int y;

	int2(int x, int y);

	int2 operator+(int2 other);
};

class SnakeElement
{
public:
	int2 pos;
	SnakeElement* nextElement;
	SnakeElement(int2 pos);
	void Move(int2 newPos);
};

class Snake
{
public:
	int2 direction;
	SnakeElement* head;
	Snake(int2 pos, int2 direction);
	void MoveForward();
};