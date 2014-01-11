#pragma once
#include "GameEnviroment.h"
namespace adventure_game {
	class Forest : public GameEnviroment
	{
	public:
		Forest();
		~Forest();
		Forest(string description, string type);
		virtual void update(Game * g);
	};

}

