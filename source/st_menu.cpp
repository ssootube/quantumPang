#include "st_menu.h"
#include <string>
#include <iostream>

TextBox::TextBox(String text, Vector2f pos, Font& font):type(TextBox::TEXT)
{
	this->text.setFont(font);
	this->text.setPosition(pos);
	this->text.setFillColor(FT_C_menuList);
	this->text.setCharacterSize(FT_S_menuList);
	this->text.setString(text);
	this->data = 0;
}

bool TextBox::isIn(Vector2i pos)
{

	FloatRect temp = text.getGlobalBounds();
	if (temp.left <= pos.x && temp.left + temp.width >= pos.x && temp.top <= pos.y && temp.top + temp.height >= pos.y)
		return true;
	return false;
}

void TextBox::display(RenderWindow& window)
{
	switch (type)
	{
	case TEXT:
		window.draw(text);
		break;
	case UINT:
	{
		Text temp;
		temp.setFont(*(text.getFont()));
		temp.setFillColor(FT_C_menuList);
		temp.setCharacterSize(FT_S_menuList);
		temp.setPosition(text.getPosition().x + text.getGlobalBounds().width, text.getPosition().y);
		temp.setString(L"← "+to_string(data)+L" →");
		window.draw(text);
		window.draw(temp);
	}
		break;
	}

}

Menu::Menu(String title, vector<String> menu, Font &font)
{
	this->cursor = 0;
	this->title.setFont(font);
	this->title.setPosition(Vector2f(0, 0));
	this->title.setFillColor(FT_C_menuTitle);
	this->title.setCharacterSize(FT_S_menuTitle);
	this->title.setString(title);
	unsigned int i = 0;
	for (auto iter : menu)
		this->menu.push_back(TextBox(iter, Vector2f(15, (i++) * FT_S_menuList + FT_S_menuTitle), font));

}

void Menu::display(RenderWindow& window)
{

	window.draw(title);
	for (auto iter : menu)
		iter.display(window);

	//포인터 처리
	CircleShape pointer;
	FloatRect temp = menu[cursor].text.getGlobalBounds();
	pointer.setRadius(5);
	pointer.setFillColor(Color::Red);
	pointer.setPosition(temp.left - 10, temp.top - pointer.getRadius()/2 + temp.height/2);
	window.draw(pointer);
}

int Menu::inputProcess(Event& e, RenderWindow &window)
{
	if (e.type == Event::KeyPressed)
	{
		if (e.key.code == Keyboard::Up)
			cursor = (cursor - 1 + menu.size()) % menu.size();
		else if (e.key.code == Keyboard::Down)
			cursor = (cursor + 1) % menu.size();
		else if (e.key.code == Keyboard::Enter || e.key.code == Keyboard::Space)
			return selectMenu();
		else if (e.key.code == Keyboard::Left)
			menu[cursor].data = (menu[cursor].data - 1) % menu[cursor].limit;
		else if (e.key.code == Keyboard::Right)
			menu[cursor].data = (menu[cursor].data + 1) % menu[cursor].limit;
	}
	else if (e.type == sf::Event::MouseButtonPressed)
	{
		if (e.mouseButton.button == sf::Mouse::Left)
		{
			for (int i = 0; i < menu.size(); ++i)
			{
				if (menu[i].isIn(Mouse::getPosition(window)))
				{
					cursor = i;
					return selectMenu();
				}
			}
		}
	}
	else if (e.type == sf::Event::MouseMoved)
	{
		for (int i = 0; i < menu.size(); ++i)
			if (menu[i].isIn(Mouse::getPosition(window)))
				cursor = i;
	}

	return SELF;
}

MainMenu::MainMenu(Font &font):Menu(L"퀀텀팡", { L"게임 시작",L"게임 설정" }, font)
{
}

int MainMenu::selectMenu()
{
	switch (cursor)
	{
	case 0:
		return START;
	case 1:
		return OPTION;
	default:
		return SELF;
	}
}

OptionMenu::OptionMenu(Font& font, option &op) :Menu(L"옵션", {L"가로 사이즈",L"세로 사이즈",L"병합 모드",L"옵션 저장"},font),op(op)
{
	menu[0].type = TextBox::UINT;
	menu[1].type = TextBox::UINT;
	menu[2].type = TextBox::UINT;
	menu[0].data = op.width;
	menu[1].data = op.hight;
	menu[2].data = op.mergeMode;
	menu[0].limit = 31;
	menu[1].limit = 31;
	menu[2].limit = 2;
}

int OptionMenu::selectMenu()
{
	switch (cursor)
	{
	case 3:
		op.width = menu[0].data;
		op.hight = menu[1].data;
		op.mergeMode = menu[2].data;
		return MainMenu;
	default:
		return SELF;
	}
	return 0;
}
