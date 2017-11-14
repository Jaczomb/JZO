#pragma once

class Object
{
private:
	int m_x;					//zmienna odpowiadajaca punktowi na osi x
	int m_y;					//zmienna odpowiadajaca punktowi na osi y
public:
	void setX(int _x);			//metoda ustawiajaca wartosc punktu m_x
	void setY(int _y);			//metoda ustawiajaca wartosc punktu m_y
	int getX();					//metoda pobierajaca wartosc punktu m_x
	int getY();					//metoda pobierajaca wartosc punktu m_x
	Object();
	~Object();
};


