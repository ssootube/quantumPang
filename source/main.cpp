#include <iostream>
#include "st_play.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>

using namespace std;
using namespace sf;

void	hideConsole(void)
{
	//콘솔 창을 보이지 않도록 합니다.
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_HIDE);
}

int main(void)
{
	hideConsole();
	Font font;
	font.loadFromFile("font/D2Coding/D2Coding-Ver1.3.2-20180524.ttf");
	RenderWindow window(VideoMode(300, 600), "QuantumPang v1.1 by Ssootube");
	window.setFramerateLimit(60);
	Controller controller(10, 10, font);
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			else
				controller.play(window, e);
		}
		controller.play(window, e);
	}
}
