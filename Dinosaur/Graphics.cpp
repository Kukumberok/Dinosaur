#include <SFML/Graphics.hpp>
using namespace sf;
class Graphics {
public:
    int animation()
    {
        RenderWindow window(VideoMode(600, 400), L"Moving figure", Style::Default);
        window.setVerticalSyncEnabled(true);
        Vector2f a1{ 100,100 };
        Vector2f a2{ 500,200 };
        Vector2f a3{ 500,200 };
        Vector2f a4{ 100,300 };
        Vector2f a5{ 300,500 };
        bool lu = true;
        ConvexShape convex;
        convex.setPointCount(5);
        convex.setFillColor(Color::Magenta);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            if (lu) { a1.y += 1; a4.y -= 1; a2.y -= 1; a3.y += 1; a5.y -= 1;  if (a1.y > 200) lu = false; }
            else { a1.y -= 1; a4.y += 1; a2.y += 1; a3.y -= 1; a5.y +1; if (a1.y < 100) lu = true; }
            convex.setPoint(0, a1);
            convex.setPoint(1, a2);
            convex.setPoint(2, a3);
            convex.setPoint(3, a4);
            convex.setPoint(4, a5);
            window.clear(Color::Black);
            window.draw(convex);
            window.display();
        }
        return 0;
    }
};