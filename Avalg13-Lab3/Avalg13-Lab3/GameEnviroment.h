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
	public:
		GameEnviroment();
		~GameEnviroment();
	private:
		string					type;
		string					description;
		vector<GameObject>		objects;
		vector<GameActor>		actors;
		vector<GameEnviroment>	enviroments;
	};

}