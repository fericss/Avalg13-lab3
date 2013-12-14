#pragma once


namespace adventure_game {

	class GameEnviroment;

	class GameActor
	{
	public:
		GameActor();
		~GameActor();
		bool move(const int direction);
	private:
		GameEnviroment * Location;

	};
}
