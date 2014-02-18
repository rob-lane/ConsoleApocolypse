#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include "game_state.h"

namespace console_apoc {

	class GameStateManager{
	public:
		GameStateManager(GameState* initial_game_state = 0);
		virtual ~GameStateManager();
		
		GameState* current_game_state() const;
		bool change_state(bool stop_previous_state = true, 
                      GameState* new_state = NULL);
		
		void start_current_state();
		void stop();

	private:
		GameState* current_game_state_;
	};

}


#endif