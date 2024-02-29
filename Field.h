#pragma once

# include <map>
# include <SFML/Graphics.hpp>

# include "Tetramino.h"

class Field
{
	std::map <int, sf::Color> cells;
	Tetramino tetra;
	bool gameOver;

	void newTetramino();
	void clear();

public:
	Field();
	void leftPressed();
	void rightPressed();
	void upPressed();
	void update();
	bool isGameOver();
	const std::map <int, sf::Color> & getCells() const;
	std::map <int, sf::Color> getTetraCells();
};

