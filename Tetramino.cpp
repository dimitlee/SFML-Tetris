# include <vector>

# include "Tetramino.h"
# include "Constants.h"

Tetramino::Tetramino()
{
	cells = FIGURES[0];
	baseCell = cells[0];
	color = COLORS[0];
}

Tetramino::Tetramino(int type)
{
	cells = FIGURES[type];
	baseCell = cells[0];
	color = COLORS[type];
}

void Tetramino::moveDown()
{
	for (auto & c : cells)
	{
		c += FIELD_WIDTH;
	}
}

void Tetramino::moveLeft()
{
	for (auto& c : cells)
	{
		c -= 1;
	}
}

void Tetramino::moveRight()
{
	for (auto& c : cells)
	{
		c += 1;
	}
}

void Tetramino::rotate()
{
	for (auto& c : cells)
	{
		if (c != baseCell)
		{
			int x = c % FIELD_WIDTH;
			int y = c / FIELD_WIDTH;
			int baseX = baseCell % FIELD_WIDTH;
			int baseY = baseCell / FIELD_WIDTH;
			c = (baseY + x - baseX) * FIELD_WIDTH + (baseX - y + baseY);
		}

	}
}

const std::vector<int> Tetramino::getCells() const
{
	return cells;
}

sf::Color Tetramino::getColor()
{
	return color;
}