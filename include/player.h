#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

namespace console_apoc {

	class Player
	{
	public:
		Player(string name);
		Player() {};
		string name() const;
		void setName(string name);

	private:
		string name_ = "Player";

	};

}

#endif