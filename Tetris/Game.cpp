#include "Game.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

void Game::Play()
{
	unsigned char znak;
	Board();
	do
	{
		Scene();

		if (CheckEnd() == 1)
		{
			system("cls");
			cout << "KONIEC GRY" << endl;
			cout << "Twoj wynik to : " << getScore();
			Sleep(1000);
			znak = 27;
		}
		else
		{
			Init(m_x, m_y, m_rot, getOpcja());

			Print();

			znak = _getch();
		}
		if (znak == 97 || znak == 65)//<--a
		{
			if (Check(0, -1) == 1)
			{
				m_y--;
			}
		}
		if (znak == 100 || znak == 68)//<--d
			if (Check(0, 1) == 1)
			{
				m_y++;
			}
		if (znak == 119 || znak == 87)//<--w
			if (Check(-1, 0) == 1)
			{
				m_x--;
			}
		if (znak == 115 || znak == 83)//<--s
			if (Check(1, 0) == 1)
			{
				m_x++;
			}
		if (znak == 101|| znak==69)//<--e
		{
			setOpcja(rand() % 5 + 1);
		}
		if (znak == 113 || znak == 81)//<--q
		{
			m_rot++;
		}
		if (znak == 13)//<--Enter
		{
			if (m_x > 5)
			{
				Redraw();
				setScore(getScore()+4);
				CheckLineY();
				m_x = 2;
				m_y = 34;
				setOpcja(rand() % 5 + 1);
			}
		}
		if (znak == 32)//<--Spacja
		{
			for (int i = 1; i < m_wys - 1; i++)
			{
				if (Check(i + 1 - 1, 0) == 1)
				{
					m_x++;
				}
				else break;
			}
		}
		Sleep(200);
		system("cls");
	} while (znak != 27); //ESC

}
Game::Game()
{
}

Game::~Game()
{
}
