#pragma once
#include "map.h"
#include <stdlib.h>
#include <iostream>

char Player1Move = 'X';
char Player2Move = 'O';
int b[MAPSIZE][MAPSIZE] = { 0 };
int p1 = 1;
int p2 = 2;

struct Game
{
void menu() {

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			m.map[i][j] = '\0';
		}
	}
	system("CLS");
	int choice;
	std::cout << " -------------- 3 EN RAYA --------------------" << std::endl;
	std::cout << "\n1.Play";
	std::cout << "\n2.Exit\n";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		Play();
		break;
	case 2:
		exit(1);
	default:
		std::cout << "Entra un comando válido '1' o '2'.\n";
		system("pause");
		menu();
	}
}

void input(int turn)
{
	int row, col;
	std::cout << "Please enter Row Number: ";
	std::cin >> row;
	std::cout << "Please enter Column Number: ";
	std::cin >> col;
	row--;
	col--;
	if (row < 3 && col < 3)
	{
		if (m.map[row][col] == '\0')
		{
			if (turn == 1)
			{
				m.map[row][col] = Player1Move;
				b[row][col] = p1;
			}
			else
			{
				m.map[row][col] = Player2Move;
				b[row][col] = p2;
			}
		}
		else
		{
			std::cout << "This Cell is already fill\n";
			input(turn);
		}
	}
	else
	{
		std::cout << "Please enter an Valid cell Number\n";
		input(turn);
	}
}

bool check()
{
	for (int i = 0; i < 5; i++)
	{
		if ((m.map[i][0] != '\0') && (m.map[i][0] == m.map[i][1]) && (m.map[i][1] == m.map[i][2]) && (m.map[i][2] == m.map[i][3]) && (m.map[i][3] == m.map[i][4]) || (m.map[0][i] != '\0') && (m.map[0][i] == m.map[1][i]) && (m.map[1][i] == m.map[2][i]) && (m.map[2][i] == m.map[3][i]) && (m.map[3][i] == m.map[4][i]))
		{
			return true;
		}
	}
	if ((m.map[0][0] != '\0') && (m.map[0][0] == m.map[1][1]) && (m.map[1][1] == m.map[2][2]) && (m.map[2][2] == m.map[3][3]) && (m.map[3][3] == m.map[4][4]))
	{
		return true;
	}
	else if ((m.map[0][4] != '\0') && (m.map[0][4] == m.map[1][3]) && (m.map[1][3] == m.map[2][2]) && (m.map[2][2] == m.map[3][1]) && (m.map[3][1] == m.map[4][0]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void computerMoves(int x)
{

}

void Play();
};
Game g;