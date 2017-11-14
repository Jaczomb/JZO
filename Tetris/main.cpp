#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Game.h"
using namespace std;

int main()
{
	Game m;					// tworzenie opiektu klasy Gra (Game)
	m.Play();				// uruchomienie metody odpowiedzialnej za uruchomienie gry
	return 0;
}