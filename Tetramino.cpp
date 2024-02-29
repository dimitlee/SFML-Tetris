# include <vector>
# include <map>
# include <iostream>
# include <SFML/Graphics.hpp>

# include "Tetramino.h"
# include "Constants.h"

using namespace std;
using namespace sf;

Tetramino::Tetramino()
{
	type = 0;
	rotIndex = 0;
	cells = FIGURES[0];
	color = COLORS[0];
	offset = 4;
}

Tetramino::Tetramino(int type)
{
	this->type = type;
	cells = FIGURES[type];
	color = COLORS[type];
	offset = 4;
	rotIndex = 0;
}

bool Tetramino::moveDown(const map <int, Color>& fieldCells)
{
	int new_offset = offset + FIELD_WIDTH;
	for (auto& c : cells)
	{
		if (fieldCells.find(c + new_offset) != fieldCells.end()) return true;
		if ((c + new_offset) / FIELD_WIDTH >= FIELD_HEIGHT) return true;
	}
	offset += FIELD_WIDTH;
	return false;
}

void Tetramino::moveLeft(const map <int, Color>& fieldCells)
{
	int new_offset = offset - 1;
	int leftmostX = FIELD_WIDTH;
	for (auto& c : cells)
	{
		int x = (c + offset) % FIELD_WIDTH;
		if (fieldCells.find(c + new_offset) != fieldCells.end()) return;
		if (x < leftmostX) leftmostX = x;
	}
	if (leftmostX == 0) return;
	offset -= 1;
	return;
}

void Tetramino::moveRight(const map <int, Color>& fieldCells)
{
	int newOffset = offset + 1;
	int rightmostX = 0;

	for (auto& c : cells)
	{
		int x = (c + offset) % FIELD_WIDTH;

		if (fieldCells.find(c + newOffset) != fieldCells.end()) return;
		if (x > rightmostX) rightmostX = x;
	}
	if (rightmostX == FIELD_WIDTH - 1) return;
	offset += 1;
	return;
}

void Tetramino::rotate(const map <int, Color>& fieldCells)
{
	rotIndex = (rotIndex + 1) % ROTATIONS[type].size();
	cells = ROTATIONS[type][rotIndex];
}

map <int, Color> Tetramino::getCells()
{
	map <int, Color> tetraCells;
	for (auto& c : cells)
	{
		tetraCells[c + offset] = color;
	}
	return tetraCells;
}