#pragma once

# include <vector>
# include <SFML/Graphics.hpp>

const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 20;
const int CELL_SIZE = 18;
const int CELL_PADDING = 1;
const int TOTAL_TYPES = 7;
const float FRAME_TIME = 1.f;

const std::vector<std::vector<int>> FIGURES =
{
	{ 0,   1,   2,               3               }, // I
	{ 0,   1,   FIELD_WIDTH + 1, FIELD_WIDTH + 2 }, // Z
	{ 1,   2,   FIELD_WIDTH + 0, FIELD_WIDTH + 1 }, // S
	{ 0,   1,   2,               FIELD_WIDTH + 1 }, // T
	{ 0,   1,   2,               FIELD_WIDTH + 0 }, // L
	{ 0,   1,   2,               FIELD_WIDTH + 2 }, // J
	{ 0,   1,   FIELD_WIDTH + 0, FIELD_WIDTH + 1 }  // O
};

const std::vector<sf::Color> COLORS =
{
	sf::Color::Blue,
	sf::Color::Cyan,
	sf::Color::Magenta,
	sf::Color::Green,
	sf::Color::White,
	sf::Color::Red,
	sf::Color::Yellow
}