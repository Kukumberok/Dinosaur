#include "DinoGame.h"
#include "Game.h"
void DinoGame::ClearArea()
{
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (y >= groundY)
                area.at(0, y, x) = GROUND_COLOR;
            else
                area.at(0, y, x) = 0;
        }
    }
}

void DinoGame::HandleJump()
{
    if (!jumping) return;

    dino.Move(velocityY, 0);

    velocityY += gravity;

    if (dino.getTop() >= groundY) {
        dino.setPos(groundY, dino.getLeft());
        jumping = false;
        velocityY = 0;
    }
}

void DinoGame::MoveWorld()
{
    cactus.Move(0, -scrollSpeed);

    if (cactus.getLeft() + cactus.getWidth() < 0) {
        cactus.setPos(groundY, w + 10);
        score++;
    }
}


void DinoGame::Tick()
{
    ClearArea();

    MoveWorld();
    HandleJump();

    if (CheckCollision(dino) != 0) {
        lose = true;
        return;
    }

    DrawFigure(dino, false);
    DrawFigure(cactus, false);

    score++;
}


void DinoGame::Control(int action)
{
    if (action == UP && !jumping) {
        jumping = true;
        velocityY = -jumpStrength;
    }

    ducking = (action == DOWN);
}


