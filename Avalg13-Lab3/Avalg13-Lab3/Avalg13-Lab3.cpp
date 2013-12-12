// Avalg13-Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Avalg13-Lab3.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;


Game g;
string game_start_intro = "Bla bla bla, Bloooooo\nTo view a list of commands type: list";


struct
{
	(void)(Game::*fn)(const vector<string> & args);
	const char* key;
}
function_lookup_table[] =
{
	{ &Game::quitGame,"quit"},
	{ &Game::listCommands, "list" }
};





void Game::listCommands(const vector<string> & args){
	for each (auto var in function_lookup_table)
	{
		cout << var.key << endl;
	}
}

void Game::quitGame(const vector<string> & args){


	exit(0);
}


bool Game::lookup_and_call(const vector<string> & args){
	for (int i = 0; function_lookup_table[i].fn; i++){
		if (args[0] == function_lookup_table[i].key){
			(g.*(function_lookup_table[i].fn))(args);
			return true;
		}
	}
	return false;
}


int main(int argc, _TCHAR* argv[])
{
	g = Game();
	string command;

	cout << game_start_intro << endl;

	vector<string> args = vector<string>();
	while (true){
		cout << ">>";
		getline(cin, command);
		args.clear();
		for (size_t p = 0, q = 0; p != command.npos; p = q){
			args.push_back(command.substr(p + (p != 0), (q = command.find(' ', p + 1)) - p - (p != 0)));
		}
		if (!g.lookup_and_call(args)){
			cout << "Unknown command: " << command << endl;
		}
		
	}

	return 0;
}

