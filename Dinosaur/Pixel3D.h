#pragma once

class Pixel3D {
private:
    int* data = nullptr;
    int l = 0, h = 0, w = 0;

    int idx(int layer, int row, int col) const {
        return layer * h * w + row * w + col;
    }

public:
    Pixel3D() = default;
    Pixel3D(int layers, int height, int width);

    ~Pixel3D();

    Pixel3D(const Pixel3D& other);
    Pixel3D& operator=(const Pixel3D& other);

    int getLayers() const { return l; }
    int getHeight() const { return h; }
    int getWidth()  const { return w; }

    int& at(int layer, int row, int col);
    const int& at(int layer, int row, int col) const;
};

