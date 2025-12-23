#include "Pixel3D.h"
#include <cstring>

Pixel3D::Pixel3D(int layers, int height, int width)
    : l(layers), h(height), w(width)
{
    data = new int[l * h * w] {0};
}

Pixel3D::~Pixel3D() {
    delete[] data;
}

Pixel3D::Pixel3D(const Pixel3D& other)
    : l(other.l), h(other.h), w(other.w)
{
    data = new int[l * h * w];
    std::memcpy(data, other.data, sizeof(int) * l * h * w);
}

Pixel3D& Pixel3D::operator=(const Pixel3D& other) {
    if (this == &other) return *this;

    delete[] data;

    l = other.l;
    h = other.h;
    w = other.w;

    data = new int[l * h * w];
    std::memcpy(data, other.data, sizeof(int) * l * h * w);

    return *this;
}

int& Pixel3D::at(int layer, int row, int col) {
    return data[idx(layer, row, col)];
}

const int& Pixel3D::at(int layer, int row, int col) const {
    return data[idx(layer, row, col)];
}

