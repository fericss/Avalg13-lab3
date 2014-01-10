#pragma once
#include <string>
using std::string;

namespace adventure_game {
	class Game;
	class GameEnviroment;

	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void setDescription(string *);
		string * getDescription();

		void setName(string *);
		string * getName();

		void setType(string *);
		string * getType();

		GameEnviroment * location;

		virtual void lootAction(Game * g);
		virtual void dropAction(Game * g);
		virtual void useObject(Game * g);

	private:
		string					name;
		string					type;
		string					description;


	};

}
