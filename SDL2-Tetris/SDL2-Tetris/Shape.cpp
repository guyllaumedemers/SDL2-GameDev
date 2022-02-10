#include "Shape.h"

Shape::Shape(const int& row, const int& col)
{
	tiles = new bool* [row];
	for (int i = 0; i < row; ++i) {
		tiles[i] = new bool[col];
		for (int j = 0; j < col; ++j) {
			tiles[i][j] = false;
		}
	}
}

Shape::~Shape()
{

}
