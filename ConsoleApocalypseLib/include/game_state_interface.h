#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>

using namespace std;

namespace console_apoc {

	class GameStateInterface{
	public:		
		virtual void initialize() = 0;
		
		virtual void start() = 0;
		virtual void pause() = 0;
		virtual void resume() = 0;
		virtual void stop() = 0;
		
		virtual string& to_string() = 0;
		virtual GameStateInterface* get_next_state() = 0;

	};

}

#endif