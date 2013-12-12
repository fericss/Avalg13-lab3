#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace adventure_game {
	class Game {
	public:
		Game();
		void quitGame(const vector<string> & args, Game * g);
		void listCommands(const vector<string> & args, Game * g);
		bool lookup_and_call(const vector<string> & args, Game * g);
	private:

	};
}



