#pragma once

#include "Pixel3D.h"
#include "Figure.h"
#include "OwingArray.h"

class Game {
protected:
    Pixel3D area;        
    int h = 0, w = 0;

    int score = 0;
    bool lose = false;
    int speedMs = 200;
       
    int scrollSpeed;

    OwningArray<Figure> figures;

public:
    Game(int height, int width, int figureCount)
        : area(1, height, width),
        h(height), w(width),
        figures(figureCount) {
    }

    virtual ~Game() = default;

    bool isLose() const { return lose; }
    int getScore() const { return score; }
    int getSpeedMs() const { return speedMs; }

    int getHeight() const { return h; }
    int getWidth() const { return w; }

    const Pixel3D& getArea() const { return area; }

protected:
    int CheckCollision(const Figure& fig) const;
    void DrawFigure(const Figure& fig, bool clear);

    void MoveFigure(int idx, int dt, int dl);

public:
    virtual void Control(int key) = 0;
    virtual void Tick() = 0;
};
