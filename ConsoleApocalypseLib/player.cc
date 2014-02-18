#include "player.h"

namespace console_apoc {

	Player::Player(string name) {
		if (name.size() > 0) {
			name_ = name;
		}
	}

	string Player::name() const {
		return name_;
	}

	void Player::setName(string name) {
		name_ = name;
	}

}