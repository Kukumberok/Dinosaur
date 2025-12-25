#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Controller.h"
#include "ColorPalette.h"

class Graphics {
private: 
	sf::RenderWindow& window;
	Game& game;
	Controller& controller;
	ColorPalette palette;
	int pixelSize;
public:
	Graphics(sf::RenderWindow& window, Game& game, Controller& controller, int pixelSize = 20);

	void run();
private:
	void handleEvents(); 
	void render() const;
	void drawArea(const Pixel3D& area) const;
	void drawGround(int groundY) const;
	void drawScore(int score) const;
};