#include "field.h"

Field::Field(int cols, int rows) : cols(10), rows(10)
{
	cells = new FieldCell * [rows];
	for (int i = 0; i < rows; i++)
	{
		cells[i] = new FieldCell[cols];
	}
}
