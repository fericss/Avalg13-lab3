#include "stdafx.h"
#include "Key.h"
#include "Game.h"

namespace adventure_game {

	Key::Key()
	{
	}

	Key::Key(std::string name, std::string type, std::string description){
		setName(&name);
		setType(&type);
		setDescription(&description);
	}

	void Key::lockEnviroment(GameEnviroment * ge){
		ge->locked = true;
		this->unlocks = ge;
	}
	bool Key::unlockEnviroment(GameEnviroment * ge){
		if (this->unlocks == ge){
			ge->locked = false;
			return true;
		}
		return false;
	}
	
	void Key::lootAction(Game * _g){

	}
	void Key::dropAction(Game * g){

	}
	void Key::useObject(Game * _g){
		for (int i = 0; i < 4; i++){
			GameEnviroment * env = _g->getPlayer()->location->getNeighbour(i);
			if (this->unlockEnviroment(env)){
				std::cout << "You unlock " << *env->getType() << std::endl;
			}
		}
		
	}

	Key::~Key()
	{
	}
}