#include "stdafx.h"
#include "Desert.h"
#include "Game.h"
namespace adventure_game {

	Desert::Desert()
	{
	}


	Desert::~Desert()
	{
	}

	Desert::Desert(string description, string type) : GameEnviroment(description, type){}

	void Desert::update(Game * g){
		GameEnviroment::update(g);
		vector<GameActor*> * actors = g->getPlayer()->location->getActors();
		for (auto var = actors->begin(); var != actors->end(); ++var){
			std::cout << "Harsh winds hits " << (*var)->name << " for 2 damage" << std::endl;
			(*var)->dealDamage(2);
			
		}
		
		
	}
}