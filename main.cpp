# include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>

# include "Field.h"
# include "Constants.h"

int main()
{   
    // Window
    sf::RenderWindow window(sf::VideoMode(FIELD_WIDTH*CELL_SIZE, FIELD_HEIGHT*CELL_SIZE), "SFML works!");
    sf::Clock clock;

    Field field = Field();
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > FRAME_TIME)
        {
            field.update();
        }
        clock.restart();

        for (Cell c : field.getCells())
        {
            sf::RectangleShape shape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            shape.setPosition((c.pos % FIELD_WIDTH) * CELL_SIZE, (c.pos / FIELD_WIDTH) * CELL_SIZE);
            shape.setFillColor(c.color);
            window.draw(shape);
        }

        for (Cell c : field.getTetraCells())
        {
            sf::RectangleShape shape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            shape.setPosition((c.pos % FIELD_WIDTH) * CELL_SIZE, (c.pos / FIELD_WIDTH) * CELL_SIZE);
            shape.setFillColor(c.color);
            window.draw(shape);
        }

        window.clear();
        window.display();
    }

    return 0;
}
