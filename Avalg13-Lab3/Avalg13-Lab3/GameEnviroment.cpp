#include "stdafx.h"
#include "GameEnviroment.h"
#include "GameActor.h"
#include "GameObject.h"

namespace adventure_game {
	GameEnviroment::GameEnviroment()
	{
		objects = vector<GameObject>();
		actors = vector<GameActor>();
		neighbours = vector<GameEnviroment>();
	}

	

	void GameEnviroment::addObject(const GameObject & ob){

	}
	void GameEnviroment::deleteObject(GameObject & ob){

	}
	GameObject * GameEnviroment::removeObject(GameObject & ob){
		return nullptr;
	}


	void GameEnviroment::addActor(const GameActor & ob){

	}
	void GameEnviroment::deleteActor(GameActor & ob){

	}
	GameActor * GameEnviroment::removeActor(GameActor & ob){
		return nullptr;
	}

	void GameEnviroment::randomlyGenerate(){

	}


	GameEnviroment * GameEnviroment::getNeighbour(const unsigned int direction){

		while (neighbours.size() < direction){
			GameEnviroment g = GameEnviroment();
			g.randomlyGenerate();
			neighbours.push_back(g);
		}
		return &neighbours[direction];

	}

	GameEnviroment::~GameEnviroment()
	{

	}

}