#pragma once
#include <SFML/Graphics.hpp>
class ColorPalette {
private:
	int color;
public:
	ColorPalette(int c = 128) : color(c);
	int get() { return color; }
};