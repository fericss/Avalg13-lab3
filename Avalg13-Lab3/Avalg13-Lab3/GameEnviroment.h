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
		vector<GameObject>		objects;
		vector<GameActor>		actors;
		vector<GameEnviroment>	neighbours;
	public:

		GameEnviroment();
		~GameEnviroment();

		
		void addObject(const GameObject & ob);
		void deleteObject(GameObject & ob);
		GameObject * removeObject(GameObject & ob);
		

		void addActor(const GameActor & ob);
		void deleteActor(GameActor & ob);
		GameActor * removeActor(GameActor & ob);

		GameEnviroment * getNeighbour(const unsigned int direction);

		void randomlyGenerate();

	
	};

}