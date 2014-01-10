#include "stdafx.h"
#include "Player.h"
#include "GameEnviroment.h"
#include "Zombie.h"
#include "Key.h"
static const int WEST = 0;
static const int NORTH = 1;
static const int EAST = 2;
static const int SOUTH = 3;

namespace adventure_game {
	GameEnviroment * beach, * forest, * hut, * cellar;
	GameObject * hut_key;

	Player::Player()
	{
		name = "Player";
		description = "The player";

		health = 100;
		damage = 10;
		
		inventory_size = 1;
		inventory = new GameObject*[inventory_size];

		beach =		new GameEnviroment("on a beach", "beach");
		forest =	new GameEnviroment("in a forest", "forest");
		hut =		new GameEnviroment("in a hut", "hut");
		cellar =	new GameEnviroment("in a cellar", "cellar");


		location = beach;

		beach->setNeighbour(WEST, forest);


		forest->setNeighbour(NORTH, hut);

		
		Zombie * zom = new Zombie();
		Key * bone_key = new Key("Bone_key", "Key", "This looks nasty");
		bone_key->lockEnviroment(cellar);
		zom->giveItem(bone_key);
		hut->addActor(zom);
		hut->setNeighbour(NORTH, cellar);
	}

	void Player::action(){
		if (health < 100){
			health++;
		}
	}


	Player::~Player()
	{
	}


}