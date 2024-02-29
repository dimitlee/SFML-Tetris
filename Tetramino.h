#pragma once

# include <vector>
# include <map>
# include <SFML/Graphics.hpp>

class Tetramino
{
	int type;
	std::vector<int> cells;
	sf::Color color;
	int offset;
	int rotIndex;

public:
	Tetramino();
	Tetramino(int type);

	bool moveDown(const std::map <int, sf::Color> & fieldCells);
	void moveLeft(const std::map <int, sf::Color> & fieldCells);
	void moveRight(const std::map <int, sf::Color> & fieldCells);
	void rotate(const std::map <int, sf::Color> & fieldCells);
	std::map <int, sf::Color> getCells();
};

