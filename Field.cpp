# include <map>
# include <set>
# include <cstdlib>
# include <time.h>
# include <SFML/Graphics.hpp>
# include <iostream>

# include "Field.h"
# include "Constants.h"

using namespace std;
using namespace sf;

Field::Field()
{
	srand(time(0));
	tetra = Tetramino(rand() % TOTAL_TYPES);
	gameOver = false;
}

void Field::newTetramino()
{
	map <int, Color> tetraCells = tetra.getCells();
	cells.insert(tetraCells.begin(), tetraCells.end());
	tetra = Tetramino(rand() % TOTAL_TYPES);
	for (auto const& c : tetra.getCells())
	{
		if (cells.find(c.first) != cells.end()) gameOver = true;
	}
}

void Field::leftPressed()
{
	tetra.moveLeft(cells);
}

void Field::rightPressed()
{
	tetra.moveRight(cells);
}

void Field::upPressed()
{
	tetra.rotate(cells);
}

void Field::update()
{
	bool isFinished = tetra.moveDown(cells);
	if (isFinished)
	{
		newTetramino();
		clear();
	}
}

void Field::clear()
{
	int yOffset = 0;
	for (int y = FIELD_HEIGHT - 1; y >= 0; y--)
	{
		cout << "Row " << y << "\n";
		int rowCount = 0;
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			int pos = y * FIELD_WIDTH + x;
			if (cells.find(pos) != cells.end()) rowCount++;
		}
		if (rowCount == FIELD_WIDTH)
		{
			cout << "Found complete row " << y << "\n";
			yOffset++;
			for (int x = 0; x < FIELD_WIDTH; x++)
			{
				cells.erase(y * FIELD_WIDTH + x);
			}
		}
		else if (yOffset > 0)
		{
			cout << "Moving row " << y << " by an offset " << yOffset << "\n";
			for (int x = 0; x < FIELD_WIDTH; x++)
			{
				int pos = y * FIELD_WIDTH + x;
				int newPos = pos + yOffset * FIELD_WIDTH;
				if (cells.find(pos) != cells.end())
				{
					cells[newPos] = cells[pos];
					cells.erase(pos);
				}
			}
		}
	}
}

bool Field::isGameOver()
{
	return gameOver;
}

map <int, Color> Field::getTetraCells()
{
	return tetra.getCells();
}

const map <int, Color> & Field::getCells() const 
{
	return cells;
}