#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "st_font.h"
#include "st_option.h"

using namespace std;
using namespace sf;



class TextBox {
public:
	enum {TEXT, UINT};
	Text text;
	unsigned short type;
	TextBox(String text, Vector2f pos, Font &font);
	bool isIn(Vector2i pos);
	void display(RenderWindow& window);

	unsigned int data;
	unsigned int limit;
};

class Menu {
public:
	enum {
		SELF, MainMenu, START, OPTION
	};
	Menu(String title, vector<String> menu, Font &font);
	Text title;
	vector<TextBox> menu;
	void display(RenderWindow &window);
	int inputProcess(Event &e, RenderWindow &window);
	virtual int selectMenu() = 0;//순수 가상 함수, 외부 컨트롤이 필요한 경우 양수 값을 반환한다.
	unsigned int cursor;
};

class MainMenu : public Menu {
public:
	MainMenu(Font &font);
	int selectMenu();
};

class OptionMenu : public Menu {
public:
	option& op;
	OptionMenu(Font& font, option &op);
	int selectMenu();
};
