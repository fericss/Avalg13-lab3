// Avalg13-Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"


using std::cout;
using std::cin;
using std::endl;


int main(int argc, char* argv[])
{
	adventure_game::Game g = adventure_game::Game();
	string command;

	vector<string> args = vector<string>();
	while (true){
		if (g.quit || g.getPlayer()->isDead){
			break;
		}
		cout << ">>";
		getline(cin, command);
		args.clear();
		for (size_t p = 0, q = 0; p != command.npos; p = q){
			args.push_back(command.substr(p + (p != 0), (q = command.find(' ', p + 1)) - p - (p != 0)));
			
		}
		if (!g.lookup_and_call(args, &g)){
			cout << "Unknown command: " << command << endl;
		}
		

	}

	return 0;
}
