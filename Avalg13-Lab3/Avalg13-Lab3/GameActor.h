#pragma once
#include <string>
#include "GameObject.h"
namespace adventure_game {

	class GameEnviroment;

	class GameActor
	{
	public:
		GameActor();
		~GameActor();
		bool move(const int direction);

		virtual void action();

		GameEnviroment * location;

		void dealDamage(GameActor * actor, int d);
		void kill();
		void giveItem(GameObject * obj);


		std::string name;
		std::string description;
		int health = 1;
		int damage = 0;

		GameObject ** inventory;
		int inventory_size = 0;
		int inventory_count = 0;

	private:
		

	};
}
