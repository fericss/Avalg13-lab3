#include "stdafx.h"
#include "GameEnviroment.h"
#include "GameActor.h"
#include "GameObject.h"

namespace adventure_game {
	GameEnviroment::GameEnviroment()
	{
		objects = vector<GameObject*>();
		actors = vector<GameActor*>();
	}
	GameEnviroment::GameEnviroment(string _description, string _type){
		GameEnviroment();
		description = _description;
		type = _type;
	}

	

	void GameEnviroment::addObject(GameObject * ob){
		ob->location = this;
		objects.push_back(ob);
	}
	void GameEnviroment::deleteObject(GameObject * ob){
		for (unsigned int i = 0; i < objects.size(); i++){
			if (objects[i] == ob){
				objects.erase(objects.begin() + i);
			}
		}
	}
	vector<GameObject*> * GameEnviroment::getObjects(){
		return &objects;
	}



	void GameEnviroment::addActor(GameActor * ob){
		ob->location = this;
		actors.push_back(ob);
	}
	void GameEnviroment::deleteActor(GameActor * ob){
		for (unsigned int i = 0; i < actors.size(); i++){
			if (actors[i] == ob){
				actors.erase(actors.begin() + i);
			}
		}
	}
	vector<GameActor*> * GameEnviroment::getActors(){
		return &actors;
	}




	string * GameEnviroment::getDescription(){
		return &description;
	}
	void GameEnviroment::setDescription(string * _s){
		description = *_s;
	}

	static const int WEST	= 0;
	static const int NORTH	= 1;
	static const int EAST	= 2;
	static const int SOUTH	= 3;
	GameEnviroment * GameEnviroment::getNeighbour(const unsigned int direction){
		if (direction == WEST){
			return dir_west;
		}
		else if (direction == EAST){
			return dir_east;
		}
		else if (direction == NORTH){
			return dir_north;
		}
		else if (direction == SOUTH){
			return dir_south;

		}
		else return nullptr;
	}
	void GameEnviroment::setNeighbour(const unsigned int direction, GameEnviroment * g){
		if (direction == WEST){
			dir_west = g;
			if (g->getNeighbour(EAST) == 0){
				g->setNeighbour(EAST, this);
			}
			
		}
		else if (direction == EAST){
			dir_east = g;
			if (g->getNeighbour(WEST) == 0){
				g->setNeighbour(WEST, this);
			}
		}
		else if (direction == NORTH){
			dir_north = g;
			if (g->getNeighbour(SOUTH) == 0){
				g->setNeighbour(SOUTH, this);
			}
		}
		else if (direction == SOUTH){
			dir_south = g;
			if (g->getNeighbour(NORTH) == 0){
				g->setNeighbour(NORTH, this);
			}

		}
	}

	void GameEnviroment::setType(string * _s){
		type = *_s;
	}
	string * GameEnviroment::getType(){
		return &type;
	}


	GameEnviroment::~GameEnviroment()
	{

	}

}