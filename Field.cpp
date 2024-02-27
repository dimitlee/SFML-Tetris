# include <vector>
# include <random>
# include <SFML/Graphics.hpp>

# include "Field.h"
# include "Constants.h"

Field::Field()
{
	tetra = Tetramino(rand() % TOTAL_TYPES);
}

void Field::leftPressed()
{
	tetra.moveLeft();
}

void Field::rightPressed()
{
	tetra.moveRight();
}

void Field::upPressed()
{
	tetra.rotate();
}

void Field::update()
{
	tetra.moveDown();
}

std::vector<Cell> Field::getTetraCells()
{
	std::vector<Cell> tetraCells;
	for (auto& tcell : tetra.getCells())
	{
		Cell newCell =
		{
			tcell,
			tetra.getColor()
		};
		tetraCells.push_back(newCell);
	}
	return tetraCells;
}

const std::vector<Cell>& Field::getCells() const 
{
	return cells;
}