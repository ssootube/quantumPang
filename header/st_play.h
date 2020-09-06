#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "st_font.h"
#include "st_option.h"

#define Map_isIn(x,y) ((x) >= 0 && (x) < op.width && (y) >= 0 && (y) < op.hight)
#define BLOCK_SIZE 30
#define KEY_INTERVAL 90
#define TURN_INTERVAL 8000

using namespace sf;
using namespace std;

class Block {
private:
	unsigned int type;
public:
	Block();
	enum BlockType {
		EMPTY, RED, BLUE, YELLOW, GREEN, LAST
	};
	Color color;
	Vector2i pos;
	bool split;
	Vector2i quantum;

	void getRect(RectangleShape& rect);
	void setType(unsigned int type);
	void setQuantum(Vector2i pos);
	unsigned int getType(void);
	unsigned int getScore(void);
};

class Map {
public:
	vector<vector<Block>>* map;
	bool** dp;//동적계획법을 위한 변수
	option &op;
	Map();
	Map(option &op);
	Block& getBlock(Vector2i pos);
	void setBlock(Vector2i pos, unsigned int type);
	bool canMove(Vector2i pos);
	void initDp(void);
	void dpCount(unsigned int i, unsigned int j, unsigned int type, vector<Vector2i>& pos);
	void mergeBlock(unsigned int type);
	unsigned int Pang(vector<Vector2i>& pos);
	unsigned int refresh();
};

class Controller {
public:
	Controller(option &op, Font &font);

	option& op;
	//time
	clock_t lastTime;
	clock_t lastKeyTyped;

	//draw
	RectangleShape rect;
	Text text;

	void drawMap(RenderWindow& window);
	void drawCursor(RenderWindow& window);
	void drawScore(RenderWindow& window);

	//info
	enum GAME_MODE {
		NORMAL, SPLIT
	};
	unsigned int score;
	unsigned int gameMode;
	Map map;

	//cursor
	Vector2i cursor;
	Vector2i quantumCursor;
	unsigned int cursorType;

	//gameplay
	void newTurn();
	void play(RenderWindow& window);
	void inputProcess(Event& e);
};
