#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <cwchar>
#include <ctime>

using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void setcolour(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void bubbleSort(vector<char> &v, char order = 'a')
{
	int a, b;
	if (order == 'a')
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			b = 0;
			for (size_t j = 0; j < (v.size() - 1); j++)
			{
				if (v[j] > v[j + 1])
				{
					a = v[j];
					v[j] = v[j + 1];
					v[j + 1] = a;
					b++;
				}
			}
			if (b == 0)
			{
				break;
			}
		}
	}
	else if (order == 'd')
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			b = 0;
			for (size_t j = 0; j < (v.size() - 1); j++)
			{
				if (v[j] < v[j + 1])
				{
					a = v[j];
					v[j] = v[j + 1];
					v[j + 1] = a;
					b++;
				}
			}
			if (b == 0)
			{
				break;
			}
		}
	}
}

class board
{
public:								//funções para mexer com os vetores
	board();
	void print();
	bool moveLegality(string move, vector<char> hand);
	void processMove(string move);
	vector<vector<char>> v1;		//vetor com letras
	vector<vector<bool>> v2;		//vetor com bools para saber que letras são a vermelho
private:

};
board::board()						//função iniciadora que põe tudo em ordem
{
	string fileName, line, num;
	int size;
	ifstream file;
	ofstream pool;

	pool.open("pool.txt");
	printf("File containing board details (With file extension - ex: board.txt): ");
	getline(cin, fileName);
	printf("File name chosen: %s \n", fileName.c_str());
	file.open(fileName);
	getline(file, line);
	num = line[0];
	num.push_back(line[1]);
	size = stoi(num);
	printf("Creating board of size %i \n\n", size);

	v1.resize(size);									//resize vetor de letras
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i].resize(size);
	}
	v2.resize(size);									//resize vetor de bools
	for (size_t i = 0; i < v2.size(); i++)
	{
		v2[i].resize(size);
	}
														//preencher os vetores com valores apropriados
	for (size_t y = 0; y < v1.size(); y++)
	{
		for (size_t x = 0; x < v1[y].size(); x++)
		{
			v1[y][x] = ' ';
			v2[y][x] = false;
		}
	}
	
	while (getline(file, line))
	{
		if (line[3] == 'x')
		{
			continue;
		}
		else
		{
			int y = int(line[0]) - 65;
			int x = int(line[1]) - 97;
			string word;
			for (size_t i = 5; i < line.length(); i++)
			{
				word.push_back(line[i]);
			}
			if (x >= int(v1.size()) || y >= int(v1[0].size()))
			{
				printf("Command '%s' is out of bounds.\n", line.c_str());
				break;
			}
			else
			{
				if (line[3] == 'H')
				{
					if (x + word.size() > v1[0].size())
					{
						printf("Word '%s' is too long.\n", word.c_str());
						break;
					}
					else
					{
						for (size_t i = 0; i < word.length(); i++)
						{
							if (v1[y][x+i] == word[i])
							{
								v1[y][x + i] = word[i];
							}
							else
							{
								v1[y][x + i] = word[i];
								pool << word[i] << endl;
							}
						}
					}
				}
				else if (line[3] == 'V')
				{
					if (y + word.size() > v1.size())
					{
						printf("Word '%s' is too long.\n", word.c_str());
						break;
					}
					else
					{
						for (size_t i = 0; i < word.length(); i++)
						{
							if (v1[y+i][x] == word[i])
							{
								v1[y + i][x] = word[i];
							}
							else
							{
								v1[y + i][x] = word[i];
								pool << word[i] << endl;
							}
						}
					}
				}
			}
		}
	}
	pool.close();
}
void board::print()
{
	vector<string> aux1, aux2;
	aux1 = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t" };
	aux2 = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T" };
	printf(" ");
	for (size_t i = 0; i < v1.size(); i++)
	{
		printf(" %s", aux1[i].c_str());
	}
	printf("\n");
	for (size_t y = 0; y < v1[0].size(); y++)
	{
		printf("%s ", aux2[y].c_str());
		setcolour(112);
		for (size_t x = 0; x < v1[y].size(); x++)
		{
			if (x == v1[y].size() - 1)
			{
				if (v2[y][x] == true)
				{
					setcolour(116);
					printf("%c", v1[y][x]);
					setcolour(7);
					printf(" \n");
				}
				else
				{
					printf("%c", v1[y][x]);
					setcolour(7);
					printf(" \n");
				}
			}
			else
			{
				if (v2[y][x] == true)
				{
					setcolour(116);
					printf("%c ", v1[y][x]);
					setcolour(112);
				}
				else
				{
					printf("%c ", v1[y][x]);
				}
			}
		}
	}
}
bool board::moveLegality(string move, vector<char> hand)
{
	int aux = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		if (hand[i] == move[3])
		{
			continue;
		}
		else
		{
			aux++;
		}
	}
	if (aux == hand.size())
	{
		printf("That letter is not in your hand. The letter you want to play must be in yout hand\n");
		return false;
	}
	int y = int(move[0]) - 65;
	int x = int(move[1]) - 97;
	if (y >= int(v1.size()) || x >= int(v1[0].size()))
	{
		printf("That move is out of bounds of the grid. You must choose a space within the limits of the grid.\n");
		return false;
	}
	else if (v1[y][x] == ' ')
	{
		printf("Space is empty. You must select an ocupied state.\n");
		return false;
	}
	else if (v1[y][x] != move[3])
	{
		printf("The selected space and the inputed letter do not match. You must input a letter in its matching space.\n");
		return false;
	}
	else if (v2[y][x])
	{
		printf("That space was already played. You must chose an unplayed space.\n");
		return false;
	}
	else if (y == 0 && x != 0)
	{
		for (int xi = x; xi > 0; xi--)
		{
			if (xi == x) continue;
			if (v1[y][xi] == ' ')
			{
				break;
			}
			else if (v1[y][xi] != ' ' && v2[y][xi])
			{
				continue;
			}
			else if (v1[y][xi] != ' ' && !v2[y][xi])
			{
				printf("This word hasn't been initiated. You can only intiate new words of fill out the next letters of already initiated words.\n");
				return false;
			}
		}
		return true;
	}
	else if (x == 0 && y != 0)
	{
		for (int yi = y; yi > 0; yi--)
		{
			if (yi == y) continue;
			if (v1[yi][x] == ' ')
			{
				break;
			}
			else if (v1[yi][x] != ' ' && v2[yi][x])
			{
				continue;
			}
			else if (v1[yi][x] != ' ' && !v2[yi][x])
			{
				printf("This word hasn't been initiated. You can only intiate new words of fill out the next letters of already initiated words.\n");
				return false;
			}
		}
	}
	else
	{
		return true;
	}
}
void board::processMove(string move)
{
	int y = int(move[0]) - 65;
	int x = int(move[1]) - 97;
	v2[y][x] = true;
}

class kitty
{
public:
	kitty();
	int n;
private:

};
kitty::kitty()
{
	kitty::n = 0;
	string line;
	ifstream file;
	file.open("board.txt");
	while (getline(file, line))
	{
		if (line[3] == 'x')
		{
			continue;
		}
		else
		{
			kitty::n++;
		}
	}
}

class pool
{
public:
	pool();
	vector<char> pl;
private:

};
pool::pool()
{
	string line;
	char aux;
	ifstream file;
	file.open("pool.txt");
	while (getline(file, line))
	{
		aux = line[0];
		pool::pl.push_back(aux);
	}
	file.close();
	bubbleSort(pl);
}

class player
{
public:
	player();
	void removeHand(char c);
	void printHand();
	bool hasPlayed;
	size_t score;
	vector<char> hand;
private:

};
player::player()
{
	player::hasPlayed = false;
	player::score = 0;
	player::hand = {};
}
void player::removeHand(char c)
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		if (c == hand[i])
		{
			hand.erase(hand.begin() + i);
			break;
		}
	}
}
void player::printHand()
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		printf("%c", hand[i]);
	}
}
