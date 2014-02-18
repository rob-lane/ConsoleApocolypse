#include "intro_game_state.h"

namespace console_apoc{

	IntroGameState::IntroGameState(string intro_text) {
		if (intro_text.size() > 0)  {
			delete intro_text_;
			intro_text_ = NULL;
			intro_text_ = new string(intro_text);
		}
	}

	IntroGameState::~IntroGameState() {
		if (intro_text_ != NULL) {
			delete intro_text_;
			intro_text_ = NULL;
		}
		else if (next_game_state_) {
			delete next_game_state_;
			next_game_state_ = NULL;
		}
	}

	string &IntroGameState::intro_text() const {
		return *intro_text_;
	}

	string &IntroGameState::to_string() {
		return *(new string("Introduction State"));
	}

	void IntroGameState::initialize() {

	}

	void IntroGameState::start() {

	}

	void IntroGameState::stop() {

	}

	void IntroGameState::pause() {

	}

	void IntroGameState::resume() {

	}

}