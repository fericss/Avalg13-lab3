#include "stdafx.h"
#include "GameObject.h"
#include "GameEnviroment.h"


namespace adventure_game {

	GameObject::GameObject()
	{
	}


	GameObject::~GameObject()
	{
	}


	void GameObject::setDescription(string * _s){
		description = *_s;
	}
	string * GameObject::getDescription(){
		return &description;
	}
	void GameObject::setName(string * _s){
		name = *_s;
	}
	string * GameObject::getName(){
		return &name;
	}
	void GameObject::setType(string * _s){
		type = *_s;
	}
	string * GameObject::getType(){
		return &type;
	}
	
	void GameObject::lootAction(Game * g){

	}
	void GameObject::dropAction(Game * g){

	}
	void GameObject::useObject(Game * g){

	}


}