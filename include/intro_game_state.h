#ifndef INTRO_GAME_STATE_H
#define INTRO_GAME_STATE_H

#include <string>
#include "game_state.h"

using namespace std;

namespace console_apoc {

	class IntroGameState : public GameState {
	public:
		IntroGameState(string intro_text = "");
		virtual ~IntroGameState();
		string& intro_text() const;

		virtual void initialize();
		virtual void start();
		virtual void stop();
		virtual void pause();
		virtual void resume();

		string& to_string();

	private:
		string *intro_text_ = new string("Welcome to the game");
	};

}

#endif