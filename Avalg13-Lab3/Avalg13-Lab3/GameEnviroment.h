#pragma once
#include <string>
#include <vector>
#include "GameActor.h"
#include "GameObject.h"

using std::string;
using std::vector;

namespace adventure_game {

	class GameEnviroment
	{
	private:
		string					type;
		string					description;
		vector<GameObject *>	objects;
		vector<GameActor *>		actors;
		
		GameEnviroment * dir_west = 0;
		GameEnviroment * dir_east = 0;
		GameEnviroment * dir_south = 0;
		GameEnviroment * dir_north = 0;
	public:
		bool locked = false;


		GameEnviroment();
		GameEnviroment(string description, string type);
		~GameEnviroment();

		
		void addObject(GameObject * ob);
		void deleteObject(GameObject * ob);
		vector<GameObject*> * getObjects();

		void addActor(GameActor * ob);
		void deleteActor(GameActor * ob);
		vector<GameActor*> * getActors();

		GameEnviroment * getNeighbour(const unsigned int direction);
		void setNeighbour(const unsigned int direction, GameEnviroment * g);

		void setDescription(string *);
		string * getDescription();

		void setType(string *);
		string * getType();


	
	};

}