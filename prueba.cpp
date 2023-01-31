#include<iostream>
#include<Windows.h>
#include<time.h>
#include<cstdlib>
#define BoardSize 5
char Player1Move = 'X';
char Player2Move = 'O';
int p1 = 1;
int p2 = 2;
void menu();
void printBoard();
void input(int);
void player1();
void player2();
void p2p();
bool check();
bool defend(int, int, int);
bool attack();
void computerMoves(int);
void p2c();
using namespace std;
char board[BoardSize][BoardSize];
int b[BoardSize][BoardSize] = { 0 }; // additional array for efficient computer Vs Human Game.
int main()
{
	menu();
	system("pause");
	return 0;
}
//Main Menu Function
void menu()
{
	for (int i = 0; i < BoardSize; i++)
	{
		for (int j = 0; j < BoardSize; j++)
		{
			board[i][j] = '\0';
		}
	}
	system("CLS");
	int choice;
	cout << "\n\t\t\t\t\tTic Tac Toe Game";
	cout << "\n\n\t\t\t\t1.Human Player VS Human Player";
	cout << "\n\t\t\t\t2.Human Player VS Computer";
	cout << "\n\t\t\t\t3.Exit\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		printBoard();
		p2p();
		break;
	case 2:
		p2c();
		break;
	case 3:
		exit(1);
	default:
		cout << "Please enter a valid choice(1, 2 or 3)\n";
		system("pause");
		menu();
	}
}
//Function for display board
void printBoard()
{
	system("CLS");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t   1     2     3     4     5   \n";
	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t      1 |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  |  " << board[0][4] << "  |\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";

	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t      2 |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << "  |  " << board[1][4] << "  |\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t      3 |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << "  |  " << board[2][4] << "  |\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t      4 |  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << "  |  " << board[3][4] << "  |\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t      5 |  " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "  |  " << board[4][3] << "  |  " << board[4][4] << "  |\n";
	cout << "\t\t\t\t|     |     |     |     |     |\n";
	cout << "\t\t\t\t+-----+-----+-----+-----+-----+\n";
}
//Input Function
void input(int turn)
{
	int row, col;
	cout << "Please enter Row Number:\t";
	cin >> row;
	cout << "Please enter Column Number:\t";
	cin >> col;
	row--;
	col--;
	if (row < 5 && col < 5)
	{
		if (board[row][col] == '\0')
		{
			if (turn == 1)
			{
				board[row][col] = Player1Move;
				b[row][col] = p1;
			}
			else
			{
				board[row][col] = Player2Move;
				b[row][col] = p2;
			}
		}
		else
		{
			cout << "This Cell is already fill\n";
			input(turn);
		}
	}
	else
	{
		cout << "Please enter an Valid cell Number\n";
		input(turn);
	}
}

//Player1 Turn Function
void inline player1()
{
	system("CLS");
	printBoard();
	cout << "Player1 [X] Your Turn\n";
	input(1);
}
//Player2 Function
void inline player2()
{
	system("CLS");
	printBoard();
	cout << "Player2 [O] Your Turn\n";
	input(2);
}
//Player VS Player Game Funcation
void inline p2p()
{
	for (int i = 0; i < 13; i++)
	{
		player1();
		if (i > 3)
		{
			if (check())
			{
				system("CLS");
				printBoard();
				cout << "\n\t\t\t\tCongrats!! Player1 Won the Game!!\n";
				cout << "\n\t\t\t\t";
				system("pause");
				menu();
			}
		}
		if (i == 12)
		{
			system("CLS");
			printBoard();
			cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
			system("pause");
			menu();
		}
		player2();
		if (i > 3)
		{
			if (check())
			{
				system("CLS");
				printBoard();
				cout << "\n\t\t\t\tCongrats!! Player2 Won the Game!!\n";
				cout << "\n\t\t\t\t";
				system("pause");
				menu();
			}
		}

	}
}
//Check the Status Of Game
bool check()
{
	for (int i = 0; i < 5; i++)
	{
		if ((board[i][0] != '\0') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == board[i][4]) || (board[0][i] != '\0') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == board[3][i]) && (board[3][i] == board[4][i]))
		{
			return true;
		}
	}
	if ((board[0][0] != '\0') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4]))
	{
		return true;
	}
	else if ((board[0][4] != '\0') && (board[0][4] == board[1][3]) && (board[1][3] == board[2][2]) && (board[2][2] == board[3][1]) && (board[3][1] == board[4][0]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//defend function for Computer
bool defend(int comp, int player, int brd)
{
	if (brd < 5)
	{
		return false;
	}
	else if (b[0][0] + b[1][1] + b[2][2] + b[3][3] + b[4][4] == 4 * comp && b[0][0] != player && b[1][1] != player && b[2][2] != player && b[3][3] != player && b[4][4] != player)
	{
		for (int i = 0; i < 5; i++)
		{
			if (b[i][i] == 0)
			{
				b[i][i] = p2;
				board[i][i] = Player2Move;
				return true;
			}
		}
	}
	else if (b[0][4] + b[1][3] + b[2][2] + b[3][1] + b[4][0] == 4 * comp && b[0][4] != player && b[1][3] != player && b[2][2] != player && b[3][1] != player && b[4][0] != player)
	{
		for (int i = 0; i < 5; i++)
		{
			if (b[i][4 - i] == 0)
			{
				b[i][4 - i] = p2;
				board[i][4 - i] = Player2Move;
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == 4 * comp && b[i][0] != player && b[i][1] != player && b[i][2] != player && b[i][3] != player && b[i][4] != player)
			{
				for (int j = 0; j < 5; j++)
				{
					if (b[i][j] == 0)
					{
						b[i][j] = p2;
						board[i][j] = Player2Move;
						return true;
					}
				}
			}
			else if (b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == 4 * comp && b[0][i] != player && b[1][i] != player && b[2][i] != player && b[3][i] != player && b[4][i] != player)
			{
				for (int j = 0; j < 5; j++)
				{
					if (b[j][i] == 0)
					{
						b[j][i] = p2;
						board[j][i] = Player2Move;
						return true;
					}
				}
			}
		}
	}
	return false;
}
//attack -- take a move as to win in future
bool attack()
{
	if (b[0][0] + b[0][4] + b[4][0] + b[4][4] == p1 || b[0][0] + b[0][4] + b[4][0] + b[4][4] == 4 * p1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)
			{
				if (i == 3)
				{
					for (int j = 0; j < 5; j++)
					{
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = Player2Move;
							return true;
						}
					}
				}
				else
				{
					for (int j = 4; j >= 0; j--)
					{
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = Player2Move;
							return true;
						}
					}
				}
			}
			if (b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p2 && b[0][i] == p2 || b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2 || b[4][i] == p2)
			{
				if (i == 3)
				{
					for (int j = 0; j < 5; j++)
					{
						if (b[j][i] == 0)
						{
							b[j][i] = p2;
							board[j][i] = Player2Move;
							return true;
						}
					}
				}
				else
				{
					for (int j = 4; j >= 0; j--)
					{
						if (b[j][i] == 0)
						{
							b[j][i] = p2;
							board[j][i] = Player2Move;
							return true;
						}
					}
				}
			}
		}
		if (b[0][0] + b[1][1] + b[2][2] + b[3][3] + b[4][4] == p2 && b[0][0] == p2 || b[1][1] == p2 || b[2][2] == p2 || b[3][3] == p2 || b[4][4] == p2)
		{
			for (int i = 4; i >= 0; i--)
			{
				if ((b[i][i] == 0) && ((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && (b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)) || ((b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p2) && (b[0][i] == p2 || b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2 || b[4][i] == p2))))
				{
					b[i][i] = p2;
					board[i][i] = Player2Move;
					return true;
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][i] == 0)
				{
					if (((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p1 && (b[i][0] == p1 || b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1 || b[i][4] == p1)) || ((b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p1) && (b[0][i] == p1 || b[1][i] == p1 || b[2][i] == p1 || b[3][i] == p1 || b[4][i] == p1))))
					{
						b[i][i] = p2;
						board[i][i] = Player2Move;
						return true;
					}
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][i] == 0)
				{
					b[i][i] = p2;
					board[i][i] = Player2Move;
					return true;
				}
			}
		}
		else if (b[0][4] + b[1][3] + b[2][2] + b[3][1] + b[4][0] == p2 && b[0][4] == p2 || b[1][3] == p2 || b[2][2] == p2 || b[3][1] == p2 || b[4][0] == p2)
		{
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0 && ((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && (b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)) || ((b[0][4 - i] + b[1][4 - i] + b[2][4 - i] + b[3][4 - i] + b[4][4 - i] == p2) && (b[0][4 - i] == p2 || b[1][4 - i] == p2 || b[2][4 - i] == p2 || b[3][4 - i] == p2 || b[4][4 - i] == p2))))
				{
					b[i][4 - i] = p2;
					board[i][4 - i] = Player2Move;
					return true;
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0)
				{
					if (((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p1 && (b[i][0] == p1 || b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1 || b[i][4] == p1)) || ((b[0][4 - i] + b[1][4 - i] + b[2][4 - i] + b[3][4 - i] + b[4][4 - i] == p1) && (b[0][4 - i] == p1 || b[1][4 - i] == p1 || b[2][4 - i] == p1 || b[3][4 - i] == p1 || b[4][4 - i] == p1))))
					{
						b[i][4 - i] = p2;
						board[i][4 - i] = Player2Move;
						return true;
					}
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0)
				{
					b[i][4 - i] = p2;
					board[i][4 - i] = Player2Move;
					return true;
				}
			}
		}
	}
	else
	{
		if (b[0][0] + b[1][1] + b[2][2] + b[3][3] + b[4][4] == p2 && (b[0][0] == p2 || b[1][1] == p2 || b[2][2] == p2 || b[3][3] == p2 || b[4][4] == p2))
		{
			for (int i = 4; i >= 0; i--)
			{
				if ((b[i][i] == 0) && ((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && (b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)) || ((b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p2) && (b[0][i] == p2 || b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2 || b[4][i] == p2))))
				{
					b[i][i] = p2;
					board[i][i] = Player2Move;
					return true;
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][i] == 0)
				{
					if (((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p1 && (b[i][0] == p1 || b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1 || b[i][4] == p1)) || ((b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p1) && (b[0][i] == p1 || b[1][i] == p1 || b[2][i] == p1 || b[3][i] == p1 || b[4][i] == p1))))
					{
						b[i][i] = p2;
						board[i][i] = Player2Move;
						return true;
					}
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][i] == 0)
				{
					b[i][i] = p2;
					board[i][i] = Player2Move;
					return true;
				}
			}
		}
		else if (b[0][4] + b[1][3] + b[2][2] + b[3][1] + b[4][0] == p2 && b[0][4] == p2 || b[1][3] == p2 || b[2][2] == p2 || b[3][1] == p2 || b[4][0] == p2)
		{
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0 && ((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && (b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)) || ((b[0][4 - i] + b[1][4 - i] + b[2][4 - i] + b[3][4 - i] + b[4][4 - i] == p2) && (b[0][4 - i] == p2 || b[1][4 - i] == p2 || b[2][4 - i] == p2 || b[3][4 - i] == p2 || b[4][4 - i] == p2))))
				{
					b[i][4 - i] = p2;
					board[i][4 - i] = Player2Move;
					return true;
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0)
				{
					if (((b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p1 && (b[i][0] == p1 || b[i][1] == p1 || b[i][2] == p1 || b[i][3] == p1 || b[i][4] == p1)) || ((b[0][4 - i] + b[1][4 - i] + b[2][4 - i] + b[3][4 - i] + b[4][4 - i] == p1) && (b[0][4 - i] == p1 || b[1][4 - i] == p1 || b[2][4 - i] == p1 || b[3][4 - i] == p1 || b[4][4 - i] == p1))))
					{
						b[i][4 - i] = p2;
						board[i][4 - i] = Player2Move;
						return true;
					}
				}
			}
			for (int i = 4; i >= 0; i--)
			{
				if (b[i][4 - i] == 0)
				{
					b[i][4 - i] = p2;
					board[i][4 - i] = Player2Move;
					return true;
				}
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (b[i][0] + b[i][1] + b[i][2] + b[i][3] + b[i][4] == p2 && b[i][0] == p2 || b[i][1] == p2 || b[i][2] == p2 || b[i][3] == p2 || b[i][4] == p2)
				{
					if (i == 3)
					{
						for (int j = 0; j < 5; j++)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = Player2Move;
								return true;
							}
						}
					}
					else
					{
						for (int j = 4; j >= 0; j--)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = Player2Move;
								return true;
							}
						}
					}
				}
				else if (b[0][i] + b[1][i] + b[2][i] + b[3][i] + b[4][i] == p2 && b[0][i] == p2 || b[1][i] == p2 || b[2][i] == p2 || b[3][i] == p2 || b[4][i] == p2)
				{
					if (i == 3)
					{
						for (int j = 0; j < 5; j++)
						{
							if (b[j][i] == 0)
							{
								b[j][i] = p2;
								board[j][i] = Player2Move;
								return true;
							}
						}
					}
					else
					{
						for (int j = 4; j >= 0; j--)
						{
							if (b[j][i] == 0)
							{
								b[j][i] = p2;
								board[j][i] = Player2Move;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
//Computer Moves
void computerMoves(int x)
{
	if (!defend(p2, p1, x))
	{
		if (!defend(p1, p2, x))
		{
			if ((b[0][0] + b[0][4] + b[4][0] + b[4][4] == p1 + p2 || b[0][0] + b[0][4] + b[4][0] + b[4][4] == p1 + 2 * p2) && b[2][2] == 0)
			{
				for (int i = 0; i < 5; i += 2)
				{
					for (int j = 0; j < 5; j += 2)
					{
						if (b[i][j] == 0)
						{
							b[i][j] = p2;
							board[i][j] = Player2Move;
							goto end;
						}
					}
				}
			}
			else if (x == 2 && b[2][2] == 0)
			{
				b[2][2] = p2;
				board[2][2] = Player2Move;
				goto end;
			}
			if (!attack())
			{
				if (x == 0)
				{
					time_t seconds;
					time(&seconds);
					srand((unsigned int)seconds);
					int i, j;
					i = (rand() % 2) * 4;
					j = (rand() % 2) * 4;
					b[i][j] = p2;
					board[i][j] = Player2Move;
				}
				else if (b[2][2] == 0)
				{
					b[2][2] = p2;
					board[2][2] = Player2Move;
				}
				else
				{
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							if (b[i][j] == 0)
							{
								b[i][j] = p2;
								board[i][j] = Player2Move;
								goto end;
							}
						}
					}
				}
			}
		}
	}
end:
	cout << endl;
}
//Player VS Computer Funcation
void p2c()
{
	system("CLS");
	cout << "\n\n\n\t\t\t\tYou wanna go 1st or 2nd(1 or 2)\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\t\t\t\tYour symbol is X and Computer's symbol is O\n";
		cout << "\t\t\t\t";
		system("pause");
		for (int i = 0; i < 25;)
		{
			system("CLS");
			printBoard();
			input(p1);
			system("CLS");
			printBoard();
			i++;
			if (i > 8)
			{
				if (check())
				{
					system("CLS");
					printBoard();
					cout << "\n\t\t\t\tCongrats!! You Won the Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause");
					menu();
				}
			}
			if (i >= 24)
			{
				system("CLS");
				printBoard();
				cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
				system("pause");
				menu();
			}
			computerMoves(i);
			system("CLS");
			printBoard();
			i++;
			if (i > 9)
			{
				if (check())
				{
					system("CLS");
					printBoard();
					cout << "\n\t\t\t\Oopss!! Computer Won the Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause");
					menu();
				}
			}
		}
		break;
	case 2:
	{
		p2 = 1;
		p1 = choice;
		Player1Move = 'O';
		Player2Move = 'X';

		cout << "\t\t\t\tYour symbol is O and Computer's symbol is X\n";
		cout << "\t\t\t\t";
		system("pause");
		for (int i = 0; i < 25;)
		{
			system("CLS");
			printBoard();
			computerMoves(i);
			system("CLS");
			printBoard();
			i++;
			if (i > 8)
			{
				if (check())
				{
					system("CLS");
					printBoard();
					cout << "\n\t\t\t\Oopss!! Computer Won the Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause");
					menu();
				}
			}
			if (i >= 24)
			{
				system("CLS");
				printBoard();
				cout << "\n\t\t\t\tOopss!! Game Drawn!!\n";
				system("pause");
				menu();
			}
			input(p2);
			system("CLS");
			printBoard();
			i++;
			if (i > 9)
			{
				if (check())
				{
					system("CLS");
					printBoard();
					cout << "\n\t\t\t\tCongrats!! You Won the Game!!\n";
					cout << "\n\t\t\t\t";
					system("pause");
					menu();
				}
			}
		}
		break;

	}
	default:
		cout << "Invalid Input..!!\n ";
		system("pause");
		p2c();
		break;
	}
}