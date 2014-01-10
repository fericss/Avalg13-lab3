#include "stdafx.h"
#include "Zombie.h"
#include "GameEnviroment.h"
#include "Key.h"

namespace adventure_game {

	Zombie::Zombie()
	{
		name = "Zombie";
		description = "Reanimated corpse";

		health = 15;
		damage = 2;

		/*
		inventory_size = 1;
		inventory_count++;
		inventory = new GameObject*[inventory_size];
		inventory[0] = new Key("Bone_key", "Key", "This looks nasty");*/
	}


	Zombie::~Zombie()
	{
	}

	void Zombie::action(){
		vector<GameActor*> actors = *location->getActors();
		for (unsigned int i = 0; i < actors.size(); i++){
			if (actors[i] != this){
				actors[i]->dealDamage(this, damage);
			}
		}
	}

}