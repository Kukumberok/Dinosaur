#pragma once
#include "Figure.h"
#include <fstream>
using namespace std;
Figure ReadFigure(const char* path) {
    ifstream file(path);

    int l, h, w;
    file >> l >> h >> w;

    Figure fig(l, h, w);

    for (int layer = 0; layer < l; layer++)
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                fig.setPixel(layer, y, x, value);

    return fig;
}
