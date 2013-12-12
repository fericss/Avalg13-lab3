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




