#include "stdafx.h"
#include "Zombie.h"
#include "GameEnviroment.h"
#include "Key.h"

namespace adventure_game {

	Zombie::Zombie() : GameActor()
	{
		name = "Zombie";
		description = "Reanimated corpse";

		health = 15;
		damage = 2;
	}


	Zombie::~Zombie()
	{
	}

	void Zombie::action(){
		if (health < 10){
			damage = 10;
		}
		else{
			damage = 2;
		}

		vector<GameActor*> actors = *location->getActors();
		for (unsigned int i = 0; i < actors.size(); i++){
			if (actors[i] != this){
				actors[i]->dealDamage(this, damage);
			}
		}
	}

}