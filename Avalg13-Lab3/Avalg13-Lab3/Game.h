#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Game {
public:
	Game();
	void quitGame(const vector<string> & args, Game * g);
	void listCommands(const vector<string> & args, Game * g);
	bool lookup_and_call(const vector<string> & args, Game * g);


	

private:
};

using namespace std;

struct
{
	(void)(Game::*fn)(const vector<string> & args, Game * g);
	const char* key;
}
function_lookup_table[] =
{
	{ &Game::quitGame, "quit" },
	{ &Game::listCommands, "list" }
};


Game::Game(){


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
	for (int i = 0; function_lookup_table[i].fn; i++){
		if (args[0] == function_lookup_table[i].key){
			(g->*(function_lookup_table[i].fn))(args, g);
			return true;
		}
	}
	return false;
}




