#include "gtest/gtest.h"
#include "intro_game_state.h"

namespace console_apoc{

	class IntroGameStateTest : public ::testing::Test {
	protected:
		void SetUp() {
			state_with_message_ = new IntroGameState(default_message_);
			state_with_null_message_ = new IntroGameState();
		}

		void TearDown() {
			if (state_with_message_ == NULL) {
				state_with_message_->stop();
				delete state_with_message_;
				state_with_message_ = NULL;
			}
		}

		IntroGameState *state_with_message_;
		IntroGameState *state_with_null_message_;
		const string default_message_ = "Welcome to the super awesome test \
										game";
	};

	TEST_F(IntroGameStateTest, PersistsIntroText) {
		EXPECT_EQ(default_message_, state_with_message_->intro_text());
	}

	TEST_F(IntroGameStateTest, HandlesBlankIntroText) {
		EXPECT_NE(default_message_, state_with_null_message_->intro_text());
		EXPECT_TRUE(state_with_null_message_->intro_text().size() > 0);
	}

}