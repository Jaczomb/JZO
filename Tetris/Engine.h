#pragma once
#include "Object.h"

class Engine
{
private:
	char znakRys;				// zmienna odpowiedzialna za znak z kodu ascii
	Object m_punkt[4];			// tablica skladajaca sie na dana figure
	int score = 0;				// zmienna odpowiadaj¹ca za wynik
	int m_opcja = 0;			// zmienna odpowiadaj¹ca za wywo³anie losowej figury
	bool **m_tabb;				// tablica planszy 1
	bool **m_tabsc;				// tablica planszy 2
	bool **m_tabpom;			// tablica planszy 3
public:
	int m_x;					// zmienna odpowiadajaca punktowi na mapie x
	int m_y;					// zmienna odpowiadajaca punktowi na mapie y
	int m_rot;					// zmienna odpowiadajaca numerowi rotacji
	int m_wys;					// zmienna odpowiadajaca wysokosci na mapie
	int m_szer;					// zmienna odpowiadajaca szerokosci na mapie


	void Board();				// tworzenie elementow planszy
	void setScore(int _score);	// ustawianie wyniku
	int getScore();				// pobieranie wyniku
	void setOpcja(int _opcja);	// ustawianie numeru losowej figury
	int getOpcja();				// pobieranie numeru losowej figury

	//Ponizsze metody przyjmuja argumenty:
	//_x - pozycja srodkowego punktu figury na osi x
	//_y - pozycja srodkowego punktu figury na osi y
	//_rot - zmienna odpowiadajaca za rotacje figury 
	//       (0- 0 stopnii, 1 - figura obrocona o 90 stopnii, 
	//        2 - obrocona o 180 stopnii, 3 - o 270 stopnii)
	void Init(int &_x, int &_y, int &_rot, int init);
	void Init_L(int &_x, int &_y, int &_rot);	//metoda wywolania figury w kszta³cie litery L
	void Init_rL(int &_x, int &_y, int &_rot);  //metoda wywolania figury w kszta³cie odwroconej litery L
	void Init_B(int &_x, int &_y, int&_rot);    //metoda wywolania figury w kszta³cie kwadratu
	void Init_Z(int &_x, int &_y, int &_rot);   //metoda wywolania figury w kszta³cie litery Z
	void Init_rZ(int &_x, int &_y, int &_rot);  //metoda wywolania figury w kszta³cie odwroconej litery Z
	void Init_II(int &_x, int &_y, int &_rot);  //metoda wywolania figury w kszta³cie litery I
	void Init_Y(int &_x, int &_y, int &_rot);   //metoda wywolania figury w kszta³cie litery Y
	//---------------------------------------------------------------------------------------------------

	bool CheckEnd();							//metoda sprawdzaj¹ca czy przypadkiem gra sie nie skonczyla
	bool Check(int _x = 0, int _y = 0, int m_gamma = 0); //sprawdzanie czy jakas figura dotyka innej

	void Redraw();								// przerysowanie mapy

	void CheckLineY();							// sprawdza czy nie ma pelnej linii klockow premiowanej
												// dodatkowymi punktami

	void Scene();								// rysowanie mapy
	void Print();								// wypisanie wyniku zasad i sterowania

	//kostruktor, destruktor
	Engine(int _wys = 23, int _szer = 66);
	~Engine();
};