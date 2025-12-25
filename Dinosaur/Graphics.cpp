#include"Graphics.h"

void Graphics::run()
{
	while (window.isOpen())
	{
		handleEvents();
		game.Tick();
		render();
	}
}


