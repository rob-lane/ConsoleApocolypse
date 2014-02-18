#include "gmock/gmock.h"
#include "intro_game_state.h"

namespace console_apoc {

	class MockIntroGameState : public IntroGameState {
	public:

		MockIntroGameState(string msg) : IntroGameState(msg) {}
		MockIntroGameState() : IntroGameState() {}

		MOCK_METHOD0(initialize, void());
		MOCK_METHOD0(start, void());
		MOCK_METHOD0(stop, void());
		MOCK_METHOD0(pause, void());
		MOCK_METHOD0(resume, void());
	};

}