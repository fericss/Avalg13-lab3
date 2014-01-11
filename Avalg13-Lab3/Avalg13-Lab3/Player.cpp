#include "stdafx.h"
#include "Player.h"

static const int WEST = 0;
static const int NORTH = 1;
static const int EAST = 2;
static const int SOUTH = 3;

namespace adventure_game {


	Player::Player() : GameActor()
	{
		name = "Player";
		description = "The player";

		health = 100;
		damage = 10;

		inventory_size = 1;
		inventory = new GameObject*[inventory_size];

		beach = new GameEnviroment("on a beach", "beach");
		forest = new Forest("in a forest", "forest");
		hut = new GameEnviroment("in a hut", "hut");
		cellar = new GameEnviroment("in a cellar", "cellar");
		desert = new Desert("in a desert", "desert");

		zom1 = new Zombie();
		zom2 = new Zombie();
		hut_key = new Key("Bone_key", "Key", "This looks nasty");

		location = beach;

		beach->setNeighbour(WEST, forest);

		desert->addActor(zom1);

		forest->setNeighbour(NORTH, hut);
		forest->setNeighbour(SOUTH, desert);


		hut_key->lockEnviroment(cellar);
		zom2->giveItem(hut_key);
		hut->addActor(zom2);
		hut->setNeighbour(NORTH, cellar);
	}

	void Player::action(){

	}


	Player::~Player()
	{
		delete beach;
		delete hut;
		delete cellar;
		delete desert;
		delete forest;
		delete hut_key;

		delete zom1;
		delete zom2;
	}


}