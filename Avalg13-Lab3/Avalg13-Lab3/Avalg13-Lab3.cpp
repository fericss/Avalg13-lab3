// Avalg13-Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string game_start_intro = "Bla bla bla, Bloooooo\nTo view a list of commands type: list";



int main(int argc, _TCHAR* argv[])
{
	Game g = Game();
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
		if (!g.lookup_and_call(args,&g)){
			cout << "Unknown command: " << command << endl;
		}
		
	}

	return 0;
}

