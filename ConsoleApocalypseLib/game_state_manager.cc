#include "game_state_manager.h"
#include "intro_game_state.h"

namespace console_apoc {

	GameStateManager::GameStateManager(GameStateInterface *initial_game_state) {
		if (initial_game_state != NULL) {
			current_game_state_ = initial_game_state;
		} else {
			current_game_state_ = new IntroGameState();
		}
	}

	GameStateManager::~GameStateManager() {
		if (current_game_state_ != NULL) {
			current_game_state_->stop();
			delete current_game_state_;
			current_game_state_ = NULL;
		}
	}

	GameStateInterface* GameStateManager::current_game_state() const {
		return current_game_state_;
	}

	bool GameStateManager::change_state(bool stop_previous_state) {
		GameStateInterface *next_game_state = current_game_state_->
												get_next_state();
		if (stop_previous_state) {
			current_game_state_->stop();
		}
		
		if (next_game_state != NULL) {
			current_game_state_ = next_game_state;
			current_game_state_->start();
			return true;
		}
		else {
			delete current_game_state_;
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
		delete current_game_state_;
		current_game_state_ = NULL;
	}

}