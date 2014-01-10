#include "stdafx.h"
#include "GameActor.h"
#include "GameEnviroment.h"
#include <iostream>


namespace adventure_game {

	GameActor::GameActor()
	{

	}


	GameActor::~GameActor()
	{
	}

	void GameActor::action(){

	}

	void GameActor::dealDamage(GameActor * actor, int d){
		std::cout << actor->name << " hit " << this->name << " for " << d << std::endl;
		health -= d;
		std::cout << name << " has " << this->health << " health left." << std::endl;
		if (health < 0){
			std::cout << this->name << " dies." << std::endl;
			this->kill();
		}
	}
	void GameActor::kill(){
		if (name == "Player"){
			std::cout << "Game is over." << std::endl;
			std::cout << "Press any key to exit ..." << std::endl;
			std::cin.ignore();
			exit(0);
		}
		if (inventory_size > 0){
			std::cout << "Items fall to the ground." << std::endl;
			for (int i = 0; i < inventory_size; i++){
				this->location->addObject(this->inventory[i]);
			}
		}
		location->deleteActor(this);
		delete this;
	}

	void GameActor::giveItem(GameObject * obj){
		inventory_size++;
		inventory_count++;
		GameObject ** inv = new GameObject*[inventory_size];
		inv[inventory_count - 1] = obj;
		for (unsigned int i = 0; i < inventory_size - 1; i++){
			inv[i] = inventory[i];
		}
		delete inventory;
		inventory = inv;
	}


	bool GameActor::move(const int direction){
		if (direction >= 0 && direction <= 4){
			if (location->getNeighbour(direction)!=0){

				if (location->getNeighbour(direction)->locked){
					std::cout << "You encounter a locked door." << std::endl;
					return false;
				}
				location->deleteActor(this);
				location = location->getNeighbour(direction);	
				location->addActor(this);

				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

}