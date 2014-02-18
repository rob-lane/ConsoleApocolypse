#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "game_state_manager.h"
#include "mock_intro_game_state.h"

using ::testing::AtLeast;

namespace console_apoc {

	class GameStateManagerTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			intro_game_state_ = new MockIntroGameState(default_intro_text_);
			second_intro_game_state_ = new MockIntroGameState();
			intro_game_state_->set_next_state(second_intro_game_state_);

			manager_with_initial_state_ = new GameStateManager(intro_game_state_);
			manager_with_null_state_ = new GameStateManager();
		}

		virtual void TearDown() {
			if (manager_with_initial_state_ != NULL) {
				manager_with_initial_state_->stop();
				delete manager_with_initial_state_;
				manager_with_initial_state_ = NULL;
			}
			if (manager_with_null_state_ != NULL) {
				manager_with_null_state_->stop();
				delete manager_with_null_state_;
				manager_with_null_state_ = NULL;
			}
		}

		GameState* current_state() {
			return manager_with_initial_state_->current_game_state();
		}

		GameStateManager *manager_with_initial_state_;
		GameStateManager *manager_with_null_state_;
		MockIntroGameState *intro_game_state_;
		MockIntroGameState *second_intro_game_state_;

		const string default_intro_text_ = "Dummy Text";
	};

	TEST_F(GameStateManagerTest, StoresInitialGameState) {
		string error_msg = "Initial game state was not persisted in manager";
		EXPECT_EQ(intro_game_state_,
			manager_with_initial_state_->current_game_state()) << error_msg;
	}

	TEST_F(GameStateManagerTest, InitializesStateOnStart) {
		EXPECT_CALL(*intro_game_state_, initialize()).Times(AtLeast(1));
		manager_with_initial_state_->start_current_state();
	}

	TEST_F(GameStateManagerTest, StartsGameOnStart) {
		EXPECT_CALL(*intro_game_state_, start()).Times(AtLeast(1));
		manager_with_initial_state_->start_current_state();
	}

	TEST_F(GameStateManagerTest, HandlesNullInitialGameState) {
		string error_msg = "Game state manager creates a default state when \
						   	initialized with a NULL state";
		EXPECT_TRUE(manager_with_null_state_->current_game_state() != NULL) 
			<< error_msg;
	}

	TEST_F(GameStateManagerTest, ChangesGameState) {
		string error_msg = "Initial game state from controctor was not persisted";
		EXPECT_EQ(intro_game_state_, current_state()) << error_msg;

		error_msg = "The next game state is not the current state after a \
					change_state call";
		manager_with_initial_state_->change_state();
		EXPECT_EQ(second_intro_game_state_, current_state()) << error_msg;
	}

	TEST_F(GameStateManagerTest, StopsPreviousStateBeforeChangingState) {
		EXPECT_CALL(*intro_game_state_, stop()).Times(AtLeast(1));
		manager_with_initial_state_->change_state();
	}
}