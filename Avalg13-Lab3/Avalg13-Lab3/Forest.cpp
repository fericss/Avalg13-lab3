#include "stdafx.h"
#include "Forest.h"
#include "Game.h"
namespace adventure_game {

	Forest::Forest()
	{
	}


	Forest::~Forest()
	{
	}

	Forest::Forest(string description, string type) : GameEnviroment(description, type){}

	void Forest::update(Game * g){
		GameEnviroment::update(g);
		vector<GameActor*> * actors = g->getPlayer()->location->getActors();
		for (auto var = actors->begin(); var != actors->end(); ++var){
			if ((*var)->health < 99){
				std::cout << "Pleasent winds heals " << (*var)->name << " for 2 point" << std::endl;
				(*var)->dealDamage(-2);
			}
		}


	}
}