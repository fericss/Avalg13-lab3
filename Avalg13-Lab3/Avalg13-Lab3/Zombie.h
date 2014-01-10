#pragma once
#include "GameActor.h"

namespace adventure_game {

	class Zombie :
		public GameActor
	{
	public:
		Zombie();
		~Zombie();

		virtual void action();


	};

}