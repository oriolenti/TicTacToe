#include "MainManager.h"

void Game::Play()
{
	system("CLS");
	std::cout << "You wanna go 1st or 2nd(1 or 2)";
	int choice;
	std::cin >> choice;
	switch (choice)

	{
	case 1:
		std::cout << "\Your symbol is X and Computer's symbol is O\n";
		std::cout << "\n";
		system("pause");
		for (int i = 0; i < 9;)
		{
			system("CLS");
			m.PrintMap();
			input(p1);
			system("CLS");
			m.PrintMap();
			i++;
			if (i > 3)
			{
				if (check())
				{
					system("CLS");
					m.PrintMap();
					std::cout << "\nGanaste!!\n";
					std::cout << "\n";
					system("pause");
					menu();
				}
			}
			if (i >= 6)
			{
				system("CLS");
				m.PrintMap();
				std::cout << "\nEmpate!!\n";
				system("pause");
				menu();
			}
			computerMoves(i);
			system("CLS");
			m.PrintMap();
			i++;
			if (i > 4)
			{
				if (check())
				{
					system("CLS");
					m.PrintMap();
					std::cout << "\nPerdiste!!\n";
					std::cout << "\n";
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

		std::cout << "Your symbol is O and Computer's symbol is X\n";
		system("pause");
		for (int i = 0; i < 9;)
		{
			system("CLS");
			m.PrintMap();
			computerMoves(i);
			system("CLS");
			m.PrintMap();
			i++;
			if (i > 3)
			{
				if (check())
				{
					system("CLS");
					m.PrintMap();
					std::cout << "\n\Oopss!! Computer Won the Game!!\n";
					std::cout << "\n";
					system("pause");
					menu();
				}
			}
			if (i >= 6)
			{
				system("CLS");
				m.PrintMap();
				std::cout << "\nEs Empate!!\n";
				system("pause");
				menu();
			}
			input(p2);
			system("CLS");
			m.PrintMap();
			i++;
			if (i > 4)
			{
				if (check())
				{
					system("CLS");
					m.PrintMap();
					std::cout << "\nCongrats!! You Won the Game!!\n";
					std::cout << "\n";
					system("pause");
					menu();
				}
			}
		}
		break;

	}
	default:
		std::cout << "Invalid Input..!!\n ";
		system("pause");
		Play();
		break;
	}
}