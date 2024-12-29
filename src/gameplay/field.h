#pragma once
class FieldCell
{
	bool HasReward;
	bool OccupiedBySnake;
};

class Field
{
public:
	FieldCell** cells;
	int cols;
	int rows;

	Field(int cols, int rows);
};