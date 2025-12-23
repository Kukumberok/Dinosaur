#include "Game.cpp"
#include "Figure.cpp"
#include <SFML/Graphics.hpp>
using namespace sf;
class Graphics
{
    Game* game;
    RenderWindow* window;
public:

    void ChangeControll(int* keys, int n)
    {
        controller.ChangeControll(keys, n);
    }
    void ChangeColorSheme(const char filename[])
    {
        colors.Load(filename);
    }
    Graphics(Game* game, RenderWindow* window)
    {
        this->game = game;
        this->window = window;
        colors.Load("BaseColors.txt");
    }
    void Show()
    {
        window->clear(colors.getColors()[0]);

        Font font;
        font.loadFromFile("Arial.ttf");
        char* score = new char[10];
        _itoa_s(game->getScore(), score, 10, 10);

        Text text(score, font, 30);
        text.setFillColor(
            colors.getColors()[colors.getMaxCount() - 1]);
        text.setPosition(Vector2f(0, 0));
        window->draw(text);

        for (int i = 0; i < game->getHeingh(); i++)
        {
            for (int j = 0; j < game->getWidth(); j++)
            {
                if (game->getArea()[i][j] != 0)
                {
                    RectangleShape r(Vector2f(40, 40));
                    r.setPosition(Vector2f(j * 40, i * 40));
                    r.setFillColor(colors.getColors()[game->getArea()[i][j]]);
                    window->draw(r);
                }
            }
        }

        window->display();
    }
    void StartGame()
    {
        window->setVerticalSyncEnabled(true);
        while (window->isOpen())
        {
            Event event;
            while (window->pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window->close();
                if (event.type == Event::KeyPressed)
                {
                    if (game->isLose() == false)
                    {
                        int k = event.key.code;
                        for (int i = 0; i < controller.getLenght(); i++)
                            if (controller.getKeys()[i] == k)
                            {
                                game->Control(i);
                                break;
                            }
                    }
                }
            }
            if (game->isLose() == false)
            {
                game->Tick();
                Show();
            }
            sleep(milliseconds(game->getSpeed()));

            if (game->isLose() == true)
            {

                Texture texture;
                Sprite sprite;
                texture.loadFromFile("go.JPG");
                sprite.setTexture(texture);
                sprite.setScale(0.4, 1);
                window->clear(Color::Yellow);
                window->draw(sprite);
                window->display();
            }
        }
    }
};