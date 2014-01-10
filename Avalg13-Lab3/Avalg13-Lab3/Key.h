#pragma once
#include "GameActor.h"
#include <string>
#include "GameEnviroment.h"


namespace adventure_game {

	class Key :
		public GameObject
	{
	public:
		Key();
		Key(std::string name, std::string type, std::string description);
		~Key();

		void lockEnviroment(GameEnviroment *);
		bool unlockEnviroment(GameEnviroment *);

		GameEnviroment * unlocks;

		virtual void lootAction(Game * g);
		virtual void dropAction(Game * g);
		virtual void useObject(Game * g);
	private:
	};

}

