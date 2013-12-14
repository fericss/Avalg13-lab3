#include "stdafx.h"
#include "GameActor.h"

namespace adventure_game {

	GameActor::GameActor()
	{
		

	}


	GameActor::~GameActor()
	{
	}

	bool GameActor::move(const int direction){
		if (direction >= 0 && direction <= 4){
			return true;
		}
		else{
			return false;
		}
	}

}