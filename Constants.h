#pragma once

# include <vector>
# include <SFML/Graphics.hpp>

const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 20;
const int CELL_SIZE = 40;
const int CELL_PADDING = 1;
const int TOTAL_TYPES = 7;
const float FRAME_TIME = 1.f;
const int FW = FIELD_WIDTH;

const std::vector<std::vector<int>> FIGURES =
{
	{ 0,   1,      2,      3 }, // I
	{ 0,   1, FW + 1, FW + 2 }, // Z
	{ 1,   2, FW + 0, FW + 1 }, // S
	{ 0,   1,      2, FW + 1 }, // T
	{ 0,   1,      2, FW + 0 }, // L
	{ 0,   1,      2, FW + 2 }, // J
	{ 0,   1, FW + 0, FW + 1 }  // O
};

const std::vector<std::vector<std::vector<int>>> ROTATIONS =
{
	{
		FIGURES[0],
		{1, FW + 1, 2 * FW + 1, 3 * FW + 1}
	},
	{
		FIGURES[1],
		{1, FW + 1, FW, 2 * FW}
	},
	{
		FIGURES[2],
		{0, FW, FW + 1, 2 * FW + 1}
	},
	{
		FIGURES[3],
		{2, FW + 1, FW + 2, 2 * FW + 2},
		{1, FW, FW + 1, FW + 2},
		{0, FW, FW + 1, 2 * FW}
	},
	{
		FIGURES[4],
		{0, 1, FW + 1, 2 * FW + 1},
		{2, FW, FW + 1, FW + 2},
		{0, FW, 2 * FW, 2 * FW + 1}
	},
	{
		FIGURES[5],
		{1, FW + 1, 2 * FW, 2 * FW + 1},
		{0, FW, FW + 1, FW + 2},
		{0, 1, FW, 2 * FW}
	},
	{
		FIGURES[6],
		{1, FW + 1, 2 * FW + 1, 3 * FW + 1}
	}
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
};