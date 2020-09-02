#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#define Map_isIn(x,y) ((x) >= 0 && (x) < width && (y) >= 0 && (y) < hight)
#define BlOCK_SIZE 30
#define KEY_INTERVAL 90
#define TURN_INTERVAL 8000
using namespace sf;
using namespace std;

struct Pos {
	int x;
	int y;
	Pos();
	Pos(int x, int y);
};

class Block {
private:
	unsigned int type;
public:
	Block();
	enum BlockType {
		EMPTY, RED, BLUE, YELLOW, GREEN, LAST
	};
	Color color;
	Pos pos;
	bool split;
	Pos quantum;

	void getRect(RectangleShape& rect);
	void setType(unsigned int type);
	void setQuantum(Pos pos);
	unsigned int getType(void);
	unsigned int getScore(void);
};

class Map {
public:
	vector<vector<Block>>* map;
	bool** dp;//동적계획법을 위한 변수
	unsigned int width;
	unsigned int hight;
	Map();
	Map(unsigned int width, unsigned int hight);
	Block& getBlock(Pos pos);
	void setBlock(Pos pos, unsigned int type);
	bool canMove(Pos pos);
	void initDp(void);
	void dpCount(unsigned int i, unsigned int j, unsigned int type, vector<Pos>& pos);
	void mergeBlock(void);
	unsigned int Pang(vector<Pos>& pos);
	unsigned int refresh();
};

class Controller {
public:
	Controller(unsigned int map_width, unsigned int map_hight, Font &font);

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
	Pos cursor;
	Pos quantumCursor;
	unsigned int cursorType;

	//gameplay
	void newTurn();
	void play(RenderWindow& window, Event& e);
};
