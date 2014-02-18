#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include "game_state_interface.h"

namespace console_apoc {

	class GameStateManager{
	public:
		GameStateManager(GameStateInterface* initial_game_state = 0);
		virtual ~GameStateManager();
		
		GameStateInterface* current_game_state() const;
		bool change_state(bool stop_previous_state = true);
		
		void start_current_state();
		void stop();

	private:
		GameStateInterface* current_game_state_;
	};

}


#endif