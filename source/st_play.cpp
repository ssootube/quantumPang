#include <vector>
#include <string.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include "st_play.h"



Vector2i traversal[4] = { Vector2i(0,-1),Vector2i(0,1),Vector2i(-1,0),Vector2i(1,0) };

Block::Block()
{//Block 생성자
	type = EMPTY;
	color = Color::Black;
	split = false;
};

void Block::getRect(RectangleShape& rect)
{
	if (split)
		color.a = 100;//알파 값을 반투명하게 만든다
	else
		color.a = 255;//알파 값을 불투명하게 만든다.
	rect.setFillColor(color);
	Vector2f temp;
	temp.x = pos.x * BLOCK_SIZE;
	temp.y = pos.y * BLOCK_SIZE;
	rect.setPosition(temp);
}

void Block::setType(unsigned int type)
{
	this->type = type;
	switch (type)
	{
	case EMPTY:
		this->color = Color::Black;
		this->split = false;
		break;
	case RED:
		this->color = Color::Red;
		break;
	case BLUE:
		this->color = Color::Blue;
		break;
	case YELLOW:
		this->color = Color::Yellow;
		break;
	case GREEN:
		this->color = Color::Green;
		break;
	default:
		this->color = Color::Black;
		break;
	}
}

void Block::setQuantum(Vector2i pos)
{
	quantum = pos;
}

unsigned int Block::getType(void)
{
	return type;
}

unsigned int Block::getScore(void)
{//블록 별 점수를 반환합니다.
	switch (type)
	{
	case EMPTY:
		return 0;
	default:
		return 1;
	}
}

Map::Map(option &op) :op(op)
{//Map 생성자

	//map 선언 및 할당(c++에서 new는 malloc이랑 같다)
	map = new vector<vector<Block>>(op.hight, vector<Block>(op.width, Block()));
	for(unsigned int i = 0; i < op.width; ++i)
		for (unsigned int j = 0; j < op.hight; ++j)
		{
			(*map)[j][i].pos.x = i, (*map)[j][i].pos.y = j;
		}

	//dp 선언 및 할당(c++에서 new는 malloc이랑 같다)
	dp = new bool* [op.hight];
	for (unsigned int i = 0; i < op.hight; ++i)
		dp[i] = new bool[op.width];
}
Block& Map::getBlock(Vector2i pos) {
	return (*map)[pos.y][pos.x];
}
void Map::setBlock(Vector2i pos, unsigned int type)
{//pos위치가 map을 벗어나지 않았다면, 블록의 type을 설정한다
	if (Map_isIn(pos.x, pos.y))
		getBlock(pos).setType(type);
}
bool Map::canMove(Vector2i pos)
{//pos위치에 다른 블록을 놓을 수 있는지 반환한다. 놓을 수 있으면 true, 놓을 수 없으면 false를 반환한다
	if (Map_isIn(pos.x, pos.y))
		if (getBlock(pos).getType() == Block::EMPTY)
			return true;
	return false;
}
void Map::initDp()
{//동적계획법을 위해 dp를 초기화하는 함수
	for (unsigned int i = 0; i < op.hight; i++)
		memset(dp[i], 0, sizeof(bool) * op.width);
}
void Map::dpCount(unsigned int i, unsigned int j, unsigned int type, vector<Vector2i>& pos)
{
	//동적계획법을 이용하여 인접한 같은 type의 블록의 위치를 pos에 반환한다
	if (!Map_isIn(j, i))
		return;
	if (!dp[i][j])
	{
		if (type == (*map)[i][j].getType() && (*map)[i][j].split == false)
		{
			dp[i][j] = true;
			pos.push_back(Vector2i(j, i));
			for (int k = 0; k < 4; ++k)
				dpCount(i + traversal[k].y, j + traversal[k].x, type, pos);
			return;
		}
		else
			return;
	}
	return;
}

void Map::mergeBlock(unsigned int type)
{
	for (unsigned int i = 0; i < op.hight; ++i)
	{
		for (unsigned int j = 0; j < op.width; ++j)
		{
			if ((*map)[i][j].split && (op.mergeMode == 0 || (*map)[i][j].getType() == type))
			{
				bool temp = rand() % 2;
				if (temp)
				{
					(*map)[i][j].split = false;
					getBlock((*map)[i][j].quantum).setType(Block::EMPTY);
				}
				else
				{
					getBlock((*map)[i][j].quantum).split = false;
					(*map)[i][j].setType(Block::EMPTY);
				}
			}
		}
	}
}

unsigned int Map::Pang(vector<Vector2i>& pos)
{//pos에 담긴 모든 위치에 해당하는 블록들을 터뜨리고 점수를 반환한다(블록의 type을 EMPTY로 만든다)
	unsigned int score = 0;
	int i = 1;
	for (auto iter : pos)
	{
		score += getBlock(iter).getScore() * i++;
		setBlock(iter, Block::EMPTY);
	}
	return score;
}
unsigned int Map::refresh()
{//맵에 터질 블록이 존재한다면 모두 터뜨린 후, 그 점수를 반환합니다.
	initDp();
	unsigned int score = 0;
	for (unsigned int i = 0; i < op.hight; ++i)
	{
		for (unsigned int j = 0; j < op.width; ++j)
		{
			if (dp[i][j])
				continue;
			vector<Vector2i> temp;
			dpCount(i, j, (*map)[i][j].getType(), temp);
			if (temp.size() >= 3)
				score += Pang(temp);
		}
	}
	return score;
}

Controller::Controller(option &op, Font &font) :map(Map(op)), lastTime(0), lastKeyTyped(0), gameMode(0),op(op)
{//Controller 생성자

	score = 0;
	cursor.x = 0;
	cursor.y = 0;
	Vector2f temp;
	temp.x = BLOCK_SIZE; temp.y = BLOCK_SIZE;
	rect.setSize(temp);

	temp.y = BLOCK_SIZE * op.hight; temp.x = 10;
	text.setFont(font);//점수 표시용 폰트 설정
	text.setFillColor(FT_C_score);
	text.setCharacterSize(FT_S_score);
	text.setPosition(temp);

	newTurn();
	srand(clock());
}

void Controller::newTurn()
{
	lastTime = clock();
	if(gameMode == GAME_MODE::NORMAL)
		cursorType = rand() % (Block::LAST - 1) + 1;
}
void Controller::drawMap(RenderWindow& window)
{
	for (auto row : (*map.map))
	{
		for (auto block : row)
		{
			block.getRect(rect);
			window.draw(rect);
		}
	}
}

void Controller::drawCursor(RenderWindow& window)
{
	Block temp;
	temp.setType(cursorType);
	Vector2f temp2;
	temp2.x = cursor.x * BLOCK_SIZE; temp2.y = cursor.y * BLOCK_SIZE;
	temp.color.a = 200;
	rect.setFillColor(temp.color);
	rect.setPosition(temp2);
	window.draw(rect);
}

void Controller::drawScore(RenderWindow& window)
{
	text.setString(L"점수:"+to_string(score)+L"\n시간:"+to_string((int)(clock() - lastTime)/1000)+L"초\n\n조작법\n양자 분리:<ALT>\n양자 병합:<c>\n블록 놓기: <space>");
	window.draw(text);
}

void Controller::play(RenderWindow& window)
{
	if (clock() - lastTime > TURN_INTERVAL)
	{
		if(score >= 10)
			score -= 10;
		newTurn();
	}

	score += map.refresh();
	drawMap(window);
	drawCursor(window);
	drawScore(window);
}

void Controller::inputProcess(Event& e)
{//사용자의 입력을 처리합니다
	if (e.type == Event::KeyPressed)
	{
		if (clock() - lastKeyTyped > KEY_INTERVAL)
		{//키를 연속으로 입력받는 속도를 조절한다. 너무 빠르면 살짝 눌러도 미친듯이 연타된다.
			lastKeyTyped = clock();
			if (e.key.code == Keyboard::Space)
			{
				if (map.getBlock(cursor).getType() == Block::EMPTY && gameMode == GAME_MODE::NORMAL)
				{
					map.setBlock(cursor, cursorType);
					newTurn();
				}

			}
			else if (e.key.code == Keyboard::Right)
				cursor.x = (cursor.x + 1) % op.width;
			else if (e.key.code == Keyboard::Left)
				cursor.x = (cursor.x - 1 + op.width) % op.width;
			else if (e.key.code == Keyboard::Up)
				cursor.y = (cursor.y - 1 + op.hight) % op.hight;
			else if (e.key.code == Keyboard::Down)
				cursor.y = (cursor.y + 1) % op.hight;
			else if (e.key.code == Keyboard::C)//merge
				map.mergeBlock(cursorType);
			else if (e.key.code == Keyboard::LAlt || e.key.code == Keyboard::RAlt)//split
			{
				if (map.getBlock(cursor).getType() == Block::EMPTY)
				{
					if (gameMode == GAME_MODE::NORMAL)
					{
						gameMode = GAME_MODE::SPLIT;
						map.setBlock(cursor, cursorType);
						map.getBlock(cursor).split = true;
						quantumCursor = cursor;
					}
					else
					{
						map.setBlock(cursor, cursorType);
						map.getBlock(cursor).split = true;
						map.getBlock(cursor).quantum = quantumCursor;
						map.getBlock(quantumCursor).quantum = cursor;
						gameMode = GAME_MODE::NORMAL;
						newTurn();
					}
				}
			}
		}
	}
}
