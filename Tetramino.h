#pragma once

# include <vector>
# include <SFML/Graphics.hpp>

class Tetramino
{
	int baseCell;
	std::vector<int> cells;
	sf::Color color;

public:
	Tetramino();
	Tetramino(int type);

	void moveDown();
	void moveLeft();
	void moveRight();
	void rotate();
	const std::vector<int> getCells() const;
	sf::Color getColor();
};

