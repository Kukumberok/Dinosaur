#include "Game.h"
int Game::CheckCollision(const Figure& fig) const {
    const int top = fig.getTop();
    const int left = fig.getLeft();
    const int fh = fig.getHeight();
    const int fw = fig.getWidth();

    for (int y = 0; y < fh; y++) {
        for (int x = 0; x < fw; x++) {
            const int pix = fig.getPixel(y, x);
            if (pix == 0) continue;

            const int ay = top + y;
            const int ax = left + x;

            if (ay < 0 || ax < 0 || ay >= h || ax >= w) return -1;

            if (area.at(0, ay, ax) != 0) return area.at(0, ay, ax);
        }
    }
    return 0;
}

void Game::DrawFigure(const Figure& fig, bool clear) {
    const int top = fig.getTop();
    const int left = fig.getLeft();
    const int fh = fig.getHeight();
    const int fw = fig.getWidth();

    for (int y = 0; y < fh; y++) {
        for (int x = 0; x < fw; x++) {
            const int pix = fig.getPixel(y, x);
            if (pix == 0) continue;

            const int ay = top + y;
            const int ax = left + x;

            if (ay < 0 || ax < 0 || ay >= h || ax >= w) continue;

            area.at(0, ay, ax) = clear ? 0 : pix;
        }
    }
}

void Game::MoveFigure(int idx, int dt, int dl) {
    DrawFigure(figures[idx], true);
    figures[idx].Move(dt, dl);
        
    if (CheckCollision(figures[idx]) != 0) {
        figures[idx].Move(-dt, -dl);
    }

    DrawFigure(figures[idx], false);
}
