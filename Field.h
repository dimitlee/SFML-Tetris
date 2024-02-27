#pragma once

# include <vector>
# include <SFML/Graphics.hpp>

# include "Tetramino.h"

struct Cell
{
	int pos;
	sf::Color color;
};

class Field
{
	std::vector<Cell> cells;
	Tetramino tetra;

public:
	Field();
	void leftPressed();
	void rightPressed();
	void upPressed();
	void update();
	const std::vector<Cell> & getCells() const;
	std::vector<Cell> getTetraCells();
};

