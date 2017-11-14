#include "Engine.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void Engine::Board()
{
	m_tabb = new bool *[m_wys];
	m_tabpom = new bool *[m_wys];
	m_tabsc = new bool *[m_wys];
	for (int i = 0; i < m_wys; i++)
	{
		m_tabb[i] = new bool[m_szer];
		m_tabpom[i] = new bool[m_szer];
		m_tabsc[i] = new bool[m_szer];
	}

	for (int i = 0; i < m_wys; i++)
	{
		for (int j = 0; j < m_szer; j++)
		{
			m_tabpom[i][j] = false;

		}
	}
}
void Engine::setScore(int _score)
{
	score = _score;
}

int Engine::getScore()
{
	return score;
}

void Engine::setOpcja(int _opcja)
{
	m_opcja = _opcja;
}

int Engine::getOpcja()
{
	return m_opcja;
}
void Engine::Scene()
{
	for (int i = 0; i < m_wys; i++)
	{
		for (int j = 0; j < m_szer; j++)
		{
			if (j == 0 || j == m_szer - 1 || i == 0 || i == m_wys - 1 || j == 22 || j == 45)
			{
				m_tabsc[i][j] = true;
				m_tabb[i][j] = true;
			}
			else
			{
				m_tabsc[i][j] = false;
				m_tabb[i][j] = false;
			}
		}
	}
	for (int i = 0; i < m_wys; i++)
	{
		for (int j = 0; j < m_szer; j++)
		{
			if (m_tabpom[i][j] == true)
			{
				m_tabb[i][j] = true;
			}

		}
	}
}
void Engine::Init(int &_x, int &_y, int &_rot, int init)
{
	//int init = rand() % 6;
	if (init == 1)
		//Init_L(_x, _y, _rot);
		Init_II(_x, _y, _rot);
	else if (init == 2)
		Init_rL(_x, _y, _rot);
	else if (init == 3)
		Init_B(_x, _y, _rot);
	else if (init == 4)
		Init_Z(_x, _y, _rot);
	else if (init == 5)
		Init_rZ(_x, _y, _rot);
	//else if (init == 6)
		//Init_II(_x, _y, _rot);
	//else if (init == 7)
		//Init_Y(_x, _y, _rot);
}

void Engine::Init_L(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);

		m_tabb[_x + 1][_y] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y);

		m_tabb[_x + 2][_y] = true;
		m_punkt[2].setX(_x + 2);
		m_punkt[2].setY(_y);

		m_tabb[_x + 2][_y + 1] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y + 1);
	}
	else if (_rot % 4 == 1)
	{
		m_tabb[_x + 1][_y] = true;
		m_punkt[0].setX(_x + 1);
		m_punkt[0].setY(_y);

		m_tabb[_x][_y] = true;
		m_punkt[1].setX(_x);
		m_punkt[1].setY(_y);

		m_tabb[_x][_y + 1] = true;
		m_punkt[2].setX(_x);
		m_punkt[2].setY(_y + 1);

		m_tabb[_x][_y + 2] = true;
		m_punkt[3].setX(_x);
		m_punkt[3].setY(_y + 2);
	}
	else if (_rot % 4 == 2)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);

		m_tabb[_x][_y + 1] = true;
		m_punkt[1].setX(_x);
		m_punkt[1].setY(_y + 1);

		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y + 1);

		m_tabb[_x + 2][_y + 1] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y + 1);
	}
	else if (_rot % 4 == 3)
	{
		m_tabb[_x + 1][_y] = true;
		m_punkt[0].setX(_x + 1);
		m_punkt[0].setY(_y);

		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[0].setX(_x + 1);
		m_punkt[0].setY(_y + 1);

		m_tabb[_x + 1][_y + 2] = true;
		m_punkt[0].setX(_x + 1);
		m_punkt[0].setY(_y + 2);

		m_tabb[_x][_y + 2] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y + 2);
	}

}
bool Engine::Check(int _x, int _y, int m_gamma) 
{
	int sciana = 0;
	int inny = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_tabsc[m_punkt[i].getX() + _x][m_punkt[i].getY() + _y] == true)
		{
			sciana++;

		}
		if (m_tabpom[m_punkt[i].getX() + _x][m_punkt[i].getY() + _y] == true)
		{
			inny++;
		}
	}
	if (sciana == 0 && inny == 0)
		return true;
}
void Engine::Redraw()
{
	for (int i = 0; i < 4; i++)
	{
		m_tabpom[m_punkt[i].getX()][m_punkt[i].getY()] = true;
	}
}
void Engine::CheckLineY()
{
	//23<>44   34
	for (int i = 5; i < m_wys - 1; i++)
	{
		int licz = 0;
		for (int j = 23; j < 45; j++)
		{
			if (m_tabb[i][j] == true)
			{
				licz++;
			}
			if (licz == 22)
			{
				score += 22;
				for (int k = 23; k < 45; k++)
				{
					for (int q = i; q > 1; q--)
					{
						m_tabpom[q][k] = m_tabpom[q - 1][k];
					}
				}
			}
		}
		licz = 0;

	}
}

bool Engine::CheckEnd()
{
	//23<>44   34
	int i = 7;
	bool koniec = false;
		for (int j = 23; j < 45; j++)
		{
			if (m_tabb[i][j] == true)
			{
				koniec = true;
				break;
			}
		}
		return koniec;
}

void Engine::Init_rL(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);
		m_tabb[_x + 1][_y] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y);
		m_tabb[_x + 2][_y] = true;
		m_punkt[2].setX(_x + 2);
		m_punkt[2].setY(_y);
		m_tabb[_x + 2][_y - 1] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y - 1);
	}
	else if (_rot % 4 == 1)
	{
		m_tabb[_x][_y - 1] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y - 1);

		m_tabb[_x + 1][_y - 1] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y - 1);

		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);

		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[3].setX(_x + 1);
		m_punkt[3].setY(_y + 1);
	}
	else if (_rot % 4 == 2)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);

		m_tabb[_x][_y + 1] = true;
		m_punkt[1].setX(_x);
		m_punkt[1].setY(_y + 1);

		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);

		m_tabb[_x + 2][_y] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y);
	}
	else if (_rot % 4 == 3)
	{
		m_tabb[_x + 1][_y - 1] = true;
		m_punkt[0].setX(_x + 1);
		m_punkt[0].setY(_y - 1);

		m_tabb[_x + 1][_y] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y);

		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y + 1);

		m_tabb[_x + 2][_y + 1] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y + 1);
	}
}
void Engine::Init_B(int &_x, int &_y, int&_rot)
{
	m_tabb[_x][_y] = true;
	m_punkt[0].setX(_x);
	m_punkt[0].setY(_y);
	m_tabb[_x][_y + 1] = true;
	m_punkt[1].setX(_x);
	m_punkt[1].setY(_y + 1);
	m_tabb[_x + 1][_y] = true;
	m_punkt[2].setX(_x + 1);
	m_punkt[2].setY(_y);
	m_tabb[_x + 1][_y + 1] = true;
	m_punkt[3].setX(_x + 1);
	m_punkt[3].setY(_y + 1);
}
void Engine::Init_Z(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0 || _rot % 4 == 2)
	{
		m_tabb[_x][_y - 1] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y - 1);
		m_tabb[_x][_y] = true;
		m_punkt[1].setX(_x);
		m_punkt[1].setY(_y);
		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);
		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[3].setX(_x + 1);
		m_punkt[3].setY(_y + 1);
	}
	else if (_rot % 4 == 1 || _rot % 4 == 3)
	{
		m_tabb[_x][_y + 1] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y + 1);
		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y + 1);
		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);
		m_tabb[_x + 2][_y] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y);
	}
}
void Engine::Init_rZ(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0 || _rot % 4 == 2)
	{
		m_tabb[_x][_y + 1] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y + 1);

		m_tabb[_x][_y] = true;
		m_punkt[1].setX(_x);
		m_punkt[1].setY(_y);

		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);

		m_tabb[_x + 1][_y - 1] = true;
		m_punkt[3].setX(_x + 1);
		m_punkt[3].setY(_y - 1);
	}
	else if (_rot % 4 == 1 || _rot % 4 == 3)
	{
		m_tabb[_x][_y - 1] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y - 1);

		m_tabb[_x + 1][_y - 1] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y - 1);

		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);

		m_tabb[_x + 2][_y] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y);
	}
}
void Engine::Init_II(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0 || _rot % 4 == 2)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);

		m_tabb[_x + 1][_y] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y);

		m_tabb[_x + 2][_y] = true;
		m_punkt[2].setX(_x + 2);
		m_punkt[2].setY(_y);


		m_tabb[_x + 3][_y] = true;
		m_punkt[3].setX(_x + 3);
		m_punkt[3].setY(_y);
	}
	else if (_rot % 4 == 1 || _rot % 4 == 3)
	{
		m_tabb[_x + 2][_y - 2] = true;
		m_punkt[0].setX(_x + 2);
		m_punkt[0].setY(_y - 2);

		m_tabb[_x + 2][_y - 1] = true;
		m_punkt[1].setX(_x + 2);
		m_punkt[1].setY(_y - 1);
		m_tabb[_x + 2][_y] = true;
		m_punkt[2].setX(_x + 2);
		m_punkt[2].setY(_y);
		m_tabb[_x + 2][_y + 1] = true;
		m_punkt[3].setX(_x + 2);
		m_punkt[3].setY(_y + 1);
	}
}
void Engine::Init_Y(int &_x, int &_y, int &_rot)
{
	if (_rot % 4 == 0)
	{
		m_tabb[_x][_y] = true;
		m_punkt[0].setX(_x);
		m_punkt[0].setY(_y);

		m_tabb[_x + 1][_y - 1] = true;
		m_punkt[1].setX(_x + 1);
		m_punkt[1].setY(_y - 1);

		m_tabb[_x + 1][_y] = true;
		m_punkt[2].setX(_x + 1);
		m_punkt[2].setY(_y);

		m_tabb[_x + 1][_y + 1] = true;
		m_punkt[3].setX(_x + 1);
		m_punkt[3].setY(_y + 1);
	}
	else if (_rot % 4 == 1)
	{
		m_tabb[_x][_y] = true;
		m_tabb[_x + 1][_y] = true;
		m_tabb[_x + 1][_y + 1] = true;
		m_tabb[_x + 2][_y] = true;
	}
	else if (_rot % 4 == 2)
	{
		m_tabb[_x + 1][_y - 1] = true;
		m_tabb[_x + 1][_y] = true;
		m_tabb[_x + 1][_y + 1] = true;
		m_tabb[_x + 2][_y] = true;
	}
	else if (_rot % 4 == 3)
	{
		m_tabb[_x][_y] = true;
		m_tabb[_x + 1][_y] = true;
		m_tabb[_x + 1][_y - 1] = true;
		m_tabb[_x + 2][_y] = true;
	}
}

void Engine::Print()
{
	for (int i = 0; i < m_wys; i++)
	{
		for (int j = 0; j < m_szer; j++)
		{
			if (m_tabb[i][j] == 1)
				cout << znakRys;
			else if (i == 2 && j == 47)
			{
				cout << "    WYNIK: " << getScore();
				break;
			}
			else if (i == 6 && j == 47)
			{
				cout << "   LINIA SMIERCI  " << znakRys;
				break;
			}
			else if (i == 7 && j == 46)
			{
				for (int i = 0; i < 20; i++)
					cout << znakRys;
				break;
			}
			else if (i == 9 && j == 47)
			{
				cout << "  STEROWANIE :    " << znakRys;
				break;
			}
			else if (i == 10 && j == 47)
			{
				cout << "E - start gry     " << znakRys;
				break;
			}
			else if (i == 12 && j == 47)
			{
				cout << "        W         " << znakRys;
				break;
			}
			else if (i == 13 && j == 47)
			{
				cout << "        ^         " << znakRys;
				break;
			}
			else if (i == 14 && j == 47)
			{
				cout << "   A <- | -> D    " << znakRys;
				break;
			}
			else if (i == 15 && j == 47)
			{
				cout << "        v         " << znakRys;
				break;
			}
			else if (i == 16 && j == 47)
			{
				cout << "        S         " << znakRys;
				break;
			}
			else if (i == 17 && j == 46)
			{
				cout << "SPACJA - na sam dol" << znakRys;
				break;
			}
			else if (i == 18 && j == 46)
			{
				cout << "ENTER - zapisz     " << znakRys;
				break;
			}
			else if (i == 19 && j == 46)
			{
				cout << "   klocek na mapie " << znakRys;
				break;
			}
			else if (i == 20 && j == 46)
			{
				cout << "Q - rotacja o 90 st" << znakRys;
				break;
			}
			else if (i == 21 && j == 47)
			{
				cout << "ESC - koniec gry  " << znakRys;
				break;
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}

Engine::Engine(int _wys, int _szer) : m_wys(_wys), m_szer(_szer)
{
	srand(time(NULL));
	m_x = 2;
	m_y = 34;
	znakRys = 219;
	//musi byc do InitRand()
}

Engine::~Engine()
{
}

