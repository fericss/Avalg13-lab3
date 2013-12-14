#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::endl;
using std::cout;

namespace adventure_game {

	static const int WEST	= 0;
	static const int NORTH	= 1;
	static const int EAST	= 2;
	static const int SOUTH	= 3;
	string game_start_intro =
		"Bla bla bla, Bloooooo\nTo view a list of commands type: list";

	struct
	{
		(void)(Game::*fn)(const vector<string> & args, Game * g);
		const char* key;
	}
	function_lookup_table[] =
	{
		{ &Game::quitGame,		"quit" },
		{ &Game::go, "go" },
		{ &Game::listCommands,	"list" }
	};


	Game::Game(){
		cout << game_start_intro << endl;
	}
	Game::~Game(){
	}

	void Game::listCommands(const vector<string> & args, Game * g){
		for each (auto var in function_lookup_table)
		{
			cout << var.key << endl;
		}
	}
	void Game::go(const vector<string> & args, Game * g){
		if (args.size() < 2){
			cout << "Directions: west, north, east, south" << endl;
		}
		else if (args[1] == "west"){
			cout << "going west" << endl;
			player.move(WEST);
		}
		else if (args[1] == "north"){
			cout << "going north" << endl;
			player.move(NORTH);
		}
		else if (args[1] == "east"){
			cout << "going east" << endl;
			player.move(EAST);
		}
		else if (args[1] == "south"){
			cout << "going south" << endl;
			player.move(SOUTH);
		}
		else{
			cout << "unknown direction" << endl;
		}

		
	}
	void Game::quitGame(const vector<string> & args, Game * g){
		exit(0);
	}


	bool Game::lookup_and_call(const vector<string> & args, Game * g) const{
		for each (auto var in function_lookup_table)
		{
			if (args[0] == var.key)
			{
				(g->*(var.fn))(args, g);
				return true;
			}
		}
		return false;
	}
}
