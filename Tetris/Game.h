#pragma once
#include "Engine.h"

class Game : public Engine
{
public:
	void Play();				//metoda odpowiedzialna za start gry
	Game();
	~Game();
};