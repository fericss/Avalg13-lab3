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
		{ &Game::listCommands,	"list" }
	};


	Game::Game(){
		cout << game_start_intro << endl;
	}

	void Game::listCommands(const vector<string> & args, Game * g){
		for each (auto var in function_lookup_table)
		{
			cout << var.key << endl;
		}
	}

	void Game::quitGame(const vector<string> & args, Game * g){
		exit(0);
	}


	bool Game::lookup_and_call(const vector<string> & args, Game * g){
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
