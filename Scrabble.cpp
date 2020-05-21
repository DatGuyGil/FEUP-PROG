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
#include "boardTemplate.h"

using namespace std;

void getTiles(player &pc, int n, pool &pl)
{
	int aux1, aux2;
	srand(time(NULL));
	for (size_t i = 0; i < n; i++)
	{
		aux2 = int(pl.pl.size());
		aux1 = rand() % aux2;
		pc.hand.push_back(pl.pl[aux1]);
		pl.pl.erase(pl.pl.begin() + aux1);
	}
}


int main()
{
	int np;
	string auxs;
	int auxi;
	string move;
	printf("How many players? ");
	getline(cin, auxs);
	np = stoi(auxs);

	board bd;
	kitty kt;
	pool pol;
	bd.print();

	printf("\nThe game will now begin.\nEach player will recieve 7 tiles to play.\nWhen prompted to do so, input your move.\nYou can only place tiles on an open first letter of any word or on the next open letter of any word already started.\nMoves have to be inputed as follows '[FIRST COORDINATE][second coordinate] [LETTER TO PLAY]'.\nAlternatively, if you can't play any tiles, input 'PASS' and your turn will be skiped.\n\n");

	if (np == 2)
	{
		player p1, p2;
		getTiles(p1, 7, pol);
		getTiles(p2, 7, pol);
		while (kt.n > 0)
		{
			if (!p1.hasPlayed && !p2.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 1's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p1, auxi, pol);
				p1.hasPlayed = true;
			}
			else if (p1.hasPlayed && !p2.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 2's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int x = int(move[1]) - 97, y = int(move[0]) - 65;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p2, auxi, pol);
				p2.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed)
			{
				p1.hasPlayed = false;
				p2.hasPlayed = false;
			}
		}
		if (p1.score > p2.score)
		{
			printf("The game has finished.\nPlayer 1 is the winner. Congratulations");
			return 1;
		}
		else if (p2.score > p1.score)
		{
			printf("The game has finished.\nPlayer 2 is the winner. Congratulations");
			return 2;
		}
		else
		{
			printf("This game ended with a tie.");
			return -1;
		}
	}
	else if (np == 3)
	{
		player p1, p2, p3;
		getTiles(p1, 7, pol);
		getTiles(p2, 7, pol);
		getTiles(p3, 7, pol);
		while (kt.n > 0)
		{
			if (!p1.hasPlayed && !p2.hasPlayed && !p3.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 1's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p1, auxi, pol);
				p1.hasPlayed = true;
			}
			else if (p1.hasPlayed && !p2.hasPlayed && !p3.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 1's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p2, auxi, pol);
				p2.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed && !p3.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 3's hand: ");
					p3.printHand();
					printf("\nPlayer 3, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p3.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p3.hand));
				if (!p3.hasPlayed)
				{
					bd.processMove(move);
					p3.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p3.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p3.printHand();
					printf("\nPlayer 3, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p3.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p3.hand));
				if (!p3.hasPlayed)
				{
					bd.processMove(move);
					p3.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p3.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p3, auxi, pol);
				p3.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed && p3.hasPlayed)
			{
				printf("Round over.\n");
				p1.hasPlayed = false;
				p2.hasPlayed = false;
				p3.hasPlayed = false;
			}
		}
		if (p1.score > p2.score && p1.score > p3.score)
		{
			printf("The game has finished.\nPlayer 1 is the winner. Congratulations");
			return 1;
		}
		else if (p2.score > p1.score && p2.score > p3.score)
		{
			printf("The game has finished.\nPlayer 2 is the winner. Congratulations");
			return 2;
		}
		else if (p3.score > p1.score && p3.score > p2.score)
		{
			printf("The game has finished.\nPlayer 3 is the winner. Congratulations");
			return 3;
		}
		else
		{
			printf("This game ended with a tie.");
			return -1;
		}
	}
	else if (np == 4)
	{
		player p1, p2, p3, p4;
		getTiles(p1, 7, pol);
		getTiles(p2, 7, pol);
		getTiles(p3, 7, pol);
		getTiles(p4, 7, pol);
		while (kt.n > 0)
		{
			if (!p1.hasPlayed && !p2.hasPlayed && !p3.hasPlayed && !p4.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 1's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p1.printHand();
					printf("\nPlayer 1, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p1.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p1.hand));
				if (!p1.hasPlayed)
				{
					bd.processMove(move);
					p1.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p1.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p1.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p1, auxi, pol);
				p1.hasPlayed = true;
			}
			else if (p1.hasPlayed && !p2.hasPlayed && !p3.hasPlayed && !p4.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 2's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p2.printHand();
					printf("\nPlayer 2, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p2.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p2.hand));
				if (!p2.hasPlayed)
				{
					bd.processMove(move);
					p2.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p2.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p2.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p2, auxi, pol);
				p2.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed && !p3.hasPlayed && !p4.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 3's hand: ");
					p3.printHand();
					printf("\nPlayer 3, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p3.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p3.hand));
				if (!p3.hasPlayed)
				{
					bd.processMove(move);
					p3.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p3.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p3.printHand();
					printf("\nPlayer 3, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p3.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p3.hand));
				if (!p3.hasPlayed)
				{
					bd.processMove(move);
					p3.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p3.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p3.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p3, auxi, pol);
				p3.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed && p3.hasPlayed && !p4.hasPlayed)
			{
				auxi = 0;
				do
				{
					printf("Player 4's hand: ");
					p4.printHand();
					printf("\nPlayer 4, make your first move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p4.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p4.hand));
				if (!p4.hasPlayed)
				{
					bd.processMove(move);
					p4.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p4.score++;
						kt.n--;
					}
				}
				do
				{
					printf("Player's hand: ");
					p4.printHand();
					printf("\nPlayer 4, make your second move: ");
					getline(cin, move);
					if (move == "PASS" || move == "pass" || move == "Pass" || move == "pASS")
					{
						p4.hasPlayed = true;
						break;
					}
				} while (!bd.moveLegality(move, p4.hand));
				if (!p4.hasPlayed)
				{
					bd.processMove(move);
					p4.removeHand(move[3]);
					auxi++;
					int y = int(move[0]) - 65;
					int x = int(move[1]) - 97;
					if (x < bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ' && bd.v1[y + 1][x] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x < bd.v1[0].size() && y == bd.v1.size())
					{
						if (bd.v1[y][x + 1] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y < bd.v1.size())
					{
						if (bd.v1[y + 1][x] == ' ')
						{
							p4.score++;
							kt.n--;
						}
					}
					else if (x == bd.v1[0].size() && y == bd.v1.size())
					{
						p4.score++;
						kt.n--;
					}
				}
				printf("\n");
				bd.print();
				getTiles(p4, auxi, pol);
				p4.hasPlayed = true;
			}
			else if (p1.hasPlayed && p2.hasPlayed && p3.hasPlayed && p4.hasPlayed)
			{
				printf("Round over.\n");
				p1.hasPlayed = false;
				p2.hasPlayed = false;
				p3.hasPlayed = false;
				p4.hasPlayed = false;
			}
		}
		if (p1.score > p2.score && p1.score > p3.score && p1.score > p4.score)
		{
			printf("The game has finished.\nPlayer 1 is the winner. Congratulations");
			return 1;
		}
		else if (p2.score > p1.score && p2.score > p3.score && p2.score > p4.score)
		{
			printf("The game has finished.\nPlayer 2 is the winner. Congratulations");
			return 2;
		}
		else if (p3.score > p1.score && p3.score > p2.score && p3.score > p4.score)
		{
			printf("The game has finished.\nPlayer 3 is the winner. Congratulations");
			return 3;
		}
		else if (p4.score > p1.score && p4.score > p2.score && p4.score > p3.score)
		{
			printf("The game has finished.\nPlayer 4 is the winner. Congratulations");
			return 4;
		}
		else
		{
			printf("This game ended with a tie.");
			return -1;
		}
	}
}
