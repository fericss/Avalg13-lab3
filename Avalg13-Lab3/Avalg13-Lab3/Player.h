#pragma once
#include "GameActor.h"
#include "GameEnviroment.h"
#include "Zombie.h"
#include "Desert.h"
#include "Forest.h"
#include "Key.h"
#include <iostream>

namespace adventure_game {

	class Player :
		public GameActor
	{
	public:
		Player();
		~Player();

		virtual void action();
	private:
		GameEnviroment * beach, *hut, *cellar;
		Desert * desert;
		Forest * forest;
		Key * hut_key;
		Zombie * zom1, * zom2;

	};
}

