# include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>
# include <map>

# include "Field.h"
# include "Constants.h"

using namespace std;
using namespace sf;

int main()
{   
    // Window
    RenderWindow window(VideoMode(FIELD_WIDTH*CELL_SIZE, FIELD_HEIGHT*CELL_SIZE), "SFML works!");
    Clock clock;

    Field field = Field();
 
    while (window.isOpen())
    {
        if (field.isGameOver())
        {
            cout << "Game Over!";
            break;
        }
        window.clear(Color::Black);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyReleased)
            {
                switch (event.key.code)
                {
                case Keyboard::Left:
                    field.leftPressed();
                    break;
                case Keyboard::Right:
                    field.rightPressed();
                    break;
                case Keyboard::Up:
                    field.upPressed();
                    break;
                case Keyboard::Down:
                    field.update();
                    break;
                default:
                    break;
                }
            }
        }

        Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > FRAME_TIME)
        {
            field.update();
            clock.restart();
        }

        for (int i = 1; i < FIELD_WIDTH; i++)
        {
            Vertex line[] =
            {
                Vertex(Vector2f(i * CELL_SIZE, 0)),
                Vertex(Vector2f(i * CELL_SIZE, FIELD_HEIGHT * CELL_SIZE))
            };
            window.draw(line, 2, Lines);
        }

        for (int i = 1; i < FIELD_HEIGHT; i++)
        {
            Vertex line[] =
            {
                Vertex(Vector2f(0, i * CELL_SIZE)),
                Vertex(Vector2f(FIELD_WIDTH * CELL_SIZE, i * CELL_SIZE))
            };
            window.draw(line, 2, Lines);
        }

        for (auto const& c : field.getCells())
        {
            RectangleShape shape(Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
            shape.setPosition((c.first % FIELD_WIDTH) * CELL_SIZE + 1, (c.first / FIELD_WIDTH) * CELL_SIZE + 1);
            shape.setFillColor(c.second);
            window.draw(shape);
        }

        for (auto const& c : field.getTetraCells())
        {
            RectangleShape shape(Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
            shape.setPosition((c.first % FIELD_WIDTH) * CELL_SIZE + 1, (c.first / FIELD_WIDTH) * CELL_SIZE + 1);
            shape.setFillColor(c.second);
            window.draw(shape);
        }

        window.display();
    }

    return 0;
}
