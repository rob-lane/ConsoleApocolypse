#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>

using namespace std;

namespace console_apoc {

	class GameState{
	public:		
    GameState();
    virtual ~GameState();

		virtual void initialize() = 0;
		
		virtual void start() = 0;
		virtual void pause() = 0;
		virtual void resume() = 0;
		virtual void stop() = 0;
		
		virtual string& to_string() = 0;
		virtual GameState* get_next_state();
    virtual GameState* get_previous_state();
    virtual void set_next_state(GameState* next_game_state);
    virtual void set_previous_state(GameState* prev_game_state);

  protected:
    GameState* next_game_state_;
    GameState* prev_game_state_;

	};

}

#endif