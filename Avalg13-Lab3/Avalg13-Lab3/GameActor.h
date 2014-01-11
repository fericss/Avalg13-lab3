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
		void dealDamage(int d);
		void kill();
		void giveItem(GameObject * obj);


		std::string name;
		std::string description;
		int health;
		int damage;

		GameObject ** inventory;
		int inventory_size;
		int inventory_count;

		bool isDead;

	private:


	};
}
