#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using std::string;
using std::vector;

namespace adventure_game {
	class Game {
	private:
		Player player;
	public:

		Player * getPlayer();
		Game();
		~Game();

		void quitGame(const vector<string> & args, Game * g);
		void listCommands(const vector<string> & args, Game * g);
		void go(const vector<string> & args, Game * g);
		void look(const vector<string> & args, Game * g);
		void attack(const vector<string> & args, Game * g);
		void loot(const vector<string> & args, Game * g);
		void drop(const vector<string> & args, Game * g);
		void inventory(const vector<string> & args, Game * g);
		void use(const vector<string> & args, Game * g);


		bool lookup_and_call(const vector<string> & args, Game * g) const;

	
	};
}



