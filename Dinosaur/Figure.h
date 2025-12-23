#include "Pixel3D.h"
class Figure {
    Pixel3D pixels;
    int currentLayer = 0;
    int top = 0, left = 0;
    int color;
public:
    Figure() = default;
    Figure(int layers, int h, int w)
        : pixels(layers, h, w) {
    }

    int getTop() const { return top; }
    int getLeft() const { return left; }
    int getHeight() const { return pixels.getHeight(); }
    int getWidth() const { return pixels.getWidth(); }


    void setPos(int t, int l);

    void Move(int dy, int dx) {
        top += dy;
        left += dx;
    }

    int getPixel(int y, int x) const {
        return pixels.at(currentLayer, y, x);
    }
    void setPixel(int layer, int y, int x, int v) {
        pixels.at(layer, y, x) = v;
    }

    void nextLayer();
};



