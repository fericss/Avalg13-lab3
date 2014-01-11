#pragma once
#include "GameEnviroment.h"
namespace adventure_game {
	class Desert : public GameEnviroment
	{
	public:
		Desert();
		~Desert();
		Desert(string description, string type);
		virtual void update(Game * g);
	};

}

