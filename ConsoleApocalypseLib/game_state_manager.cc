#include "game_state_manager.h"
#include "intro_game_state.h"

namespace console_apoc {

	GameStateManager::GameStateManager(GameState *initial_game_state) {
		if (initial_game_state != NULL) {
			current_game_state_ = initial_game_state;
		} else {
			current_game_state_ = new IntroGameState();
		}
	}

	GameStateManager::~GameStateManager() {
		if (current_game_state_ != NULL) {
			current_game_state_->stop();
			current_game_state_ = NULL;
		}
	}

	GameState* GameStateManager::current_game_state() const {
		return current_game_state_;
	}

	bool GameStateManager::change_state(bool stop_previous_state, 
                                      GameState* new_state) {
    GameState *next_state = NULL;
    if (new_state == NULL) {
      next_state = current_game_state_->get_next_state();
    }
    else {
      next_state = new_state;
    }
		if (stop_previous_state) {
			current_game_state_->stop();
		}
		
		if (next_state != NULL) {
			current_game_state_ = next_state;
			return true;
		}
		else {
			current_game_state_ = NULL;
			return false;
		}
	}

	void GameStateManager::start_current_state() {
		current_game_state_->initialize();
		current_game_state_->start();
	}

	void GameStateManager::stop() {
		current_game_state_->stop();
		current_game_state_ = NULL;
	}

}