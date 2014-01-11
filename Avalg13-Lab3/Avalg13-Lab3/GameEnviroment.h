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
		string				    	description;
		vector<GameObject *>	objects;
		vector<GameActor *>		actors;

		GameEnviroment * dir_west;
		GameEnviroment * dir_east;
		GameEnviroment * dir_south;
		GameEnviroment * dir_north;
	public:
		bool locked;


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

		virtual void update(Game * g);
		void removeDeadActors();



	};

}