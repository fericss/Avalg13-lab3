#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameEnviroment.h"


using std::string;
using std::vector;
using std::endl;
using std::cout;

namespace adventure_game {

	static const int WEST = 0;
	static const int NORTH = 1;
	static const int EAST = 2;
	static const int SOUTH = 3;
	string game_start_intro =
		"You wake up on a beach after an accident, you must find help.\nTo view a list of commands type: list";

	struct
	{
		void (Game::*fn)(const vector<string> & args, Game * g);
		const char* key;
	}
	function_lookup_table[] =
	{
		{ &Game::quitGame, "quit" },
		{ &Game::go, "go" },
		{ &Game::look, "look" },
		{ &Game::attack, "attack" },
		{ &Game::loot, "loot" },
		{ &Game::drop, "drop" },
		{ &Game::inventory, "inventory" },
		{ &Game::use, "use" },
		{ &Game::listCommands, "list" }
	};


	Game::Game(){
		cout << game_start_intro << endl;
		player = new Player();
		quit = false;
	}
	Game::~Game(){
		delete player;
	}

	void Game::loot(const vector<string> & args, Game * g){
		if (args.size() < 2){
			cout << "Loot what?" << endl;
			return;
		}
		GameEnviroment * env = g->player->location;
		if (g->player->inventory_size == g->player->inventory_count){
			cout << "Inventory is full." << endl;
			return;
		}
		for (unsigned int i = 0; i < env->getObjects()->size(); i++){
			if (args[1] == *env->getObjects()->at(i)->getName()){
				g->player->inventory[g->player->inventory_count] = env->getObjects()->at(i);
				g->player->inventory_count++;
				env->getObjects()->at(i)->lootAction(g);
				env->deleteObject(env->getObjects()->at(i));
				return;
			}
		}
		cout << "Can't find " << args[1] << endl;
	}

	void Game::drop(const vector<string> & args, Game * g){
		if (args.size() < 2){
			cout << "Drop what?" << endl;
			return;
		}
		GameEnviroment * env = g->player->location;

		for ( int i = 0; i < g->player->inventory_count; i++){
			if (args[1] == *g->player->inventory[i]->getName()){


				env->getObjects()->push_back(g->player->inventory[i]);
				g->player->inventory_count--;

			}
		}
	}

	void Game::inventory(const vector<string> & args, Game * g){
		cout << g->player->inventory_count << " out of " << g->player->inventory_size << " items." << endl;
		for ( int i = 0; i < g->player->inventory_count; i++){
			cout << *g->player->inventory[i]->getName() << endl;
		}
	}
	void Game::use(const vector<string> & args, Game * g){
		for ( int i = 0; i < g->player->inventory_count; i++){
			if (*g->player->inventory[i]->getName() == args[1]){
				cout << "You use " << args[1] << endl;
				g->player->inventory[i]->useObject(g);
				return;
			}
		}
		cout << "You cannot find an item called " << args[1] << " in your inventory." << endl;

	}
	void Game::listCommands(const vector<string> & args, Game * g){
		for (auto &var : function_lookup_table)
		{
			cout << var.key << endl;
		}
	}
	void Game::attack(const vector<string> & args, Game * g){
		if (args.size() < 2){
			cout << "Attack what?" << endl;
			return;
		}
		vector<GameActor*> actors = *g->player->location->getActors();
		for (unsigned i = 0; i < actors.size(); i++){
			if (actors[i]->name == args[1]){
				actors[i]->dealDamage(g->player, g->player->damage);
				return;
			}
		}
		cout << "No target named: " << args[1] << endl;
	}
	void Game::look(const vector<string> & args, Game * g){
		GameEnviroment * env = g->player->location;
		cout << "You are " << *env->getDescription() << endl;

		if (env->getNeighbour(WEST) != NULL){
			cout << "To the west you can see a " << *env->getNeighbour(WEST)->getType() << endl;
		}
		if (env->getNeighbour(EAST) != NULL){
			cout << "To the east you can see a " << *env->getNeighbour(EAST)->getType() << endl;
		}
		if (env->getNeighbour(NORTH) != NULL){
			cout << "To the north you can see a " << *env->getNeighbour(NORTH)->getType() << endl;
		}
		if (env->getNeighbour(SOUTH) != NULL){
			cout << "To the south you can see a " << *env->getNeighbour(SOUTH)->getType() << endl;
		}
		for (unsigned int i = 0; i < env->getActors()->size(); i++){
			if (env->getActors()->at(i)->name != "Player")
				cout << "You see a " << env->getActors()->at(i)->name << endl;

		}
		for (unsigned int i = 0; i < env->getObjects()->size(); i++){
			cout << "You see a " << *env->getObjects()->at(i)->getName() << " on the ground" << endl;

		}

	}
	void Game::go(const vector<string> & args, Game * g){
		int direction = 0;
		if (args.size() < 2){
			cout << "Directions: west, north, east, south" << endl;
			return;
		}
		else if (args[1] == "west"){
			direction = WEST;
		}
		else if (args[1] == "north"){
			direction = NORTH;
		}
		else if (args[1] == "east"){
			direction = EAST;
		}
		else if (args[1] == "south"){
			direction = SOUTH;
		}
		else{
			cout << "unknown direction" << endl;
			return;
		}

		cout << "Walking towards " << args[1] << endl;
		if (player->move(direction)){
			look(args, g);
		}
		else{
			cout << "You were unable to go " << args[1] << endl;
		}


	}
	void Game::quitGame(const vector<string> & args, Game * g){
		g->quit = true;
	}


	bool Game::lookup_and_call(const vector<string> & args, Game * g) const{
		for (auto &var : function_lookup_table)
		{
			if (args[0] == var.key)
			{
				g->player->location->update(g);
				(g->*(var.fn))(args, g);
				return true;
			}
		}
		return false;
	}
	Player * Game::getPlayer(){
		return player;
	}
}
