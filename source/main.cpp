#include <iostream>
#include "st_play.h"
#include "st_menu.h"
#include "st_option.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>

#define TITLE "QuantumPang v1.1 by Ssootube"
#define safe_delete(pointer) if(pointer != NULL) delete pointer;
using namespace std;
using namespace sf;

void	hideConsole(void)
{
	//콘솔 창을 보이지 않도록 합니다.
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_SHOW);
}

int main(void)
{
	hideConsole();
	Font font;
	font.loadFromFile("font/D2Coding/D2Coding-Ver1.3.2-20180524.ttf");
	option op;
	RenderWindow* window;
	window = new RenderWindow(VideoMode(op.width * BLOCK_SIZE, op.hight * BLOCK_SIZE + 7 * FT_S_score), TITLE);
	window->setFramerateLimit(60);

	//메뉴
	MainMenu mainMenu(font);
	OptionMenu optionMenu(font, op);

	unsigned int Mode = Menu::MainMenu;
	Controller* controller = NULL;
	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed)
				window->close();
			else
			{
				switch (Mode)
				{
				case Menu::MainMenu:
				{
					unsigned int temp = mainMenu.inputProcess(e, *window);
					switch (temp)
					{
					case Menu::SELF:
					case Menu::MainMenu:
						break;
					case Menu::START:
						safe_delete(controller);
						controller = new Controller(op, font);
						Mode = temp;
						break;
					case Menu::OPTION:
						Mode = temp;
						break;
					}
				}
					break;
				case Menu::START:
					controller->inputProcess(e);
					break;
				case Menu::OPTION:
					unsigned int temp = optionMenu.inputProcess(e, *window);
					switch (temp)
					{
					case Menu::SELF:
						break;
					case Menu::MainMenu:
						window->close();
						safe_delete(window);
						window = new RenderWindow(VideoMode(op.width*BLOCK_SIZE, op.hight*BLOCK_SIZE + 7*FT_S_score), TITLE);
						Mode = temp;
						break;
					}
					break;
				}


			}

		}

		window->clear();
		switch (Mode)
		{
		case Menu::MainMenu:
			mainMenu.display(*window);
			break;
		case Menu::START:
			controller->play(*window);
			break;
		case Menu::OPTION:
			optionMenu.display(*window);
			break;
		}
		window->display();

	}
}
