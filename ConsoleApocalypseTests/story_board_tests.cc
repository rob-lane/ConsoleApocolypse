#include <string>
#include "gmock\gmock.h"
#include "gtest\gtest.h"
#include "story_board.h"

using namespace std;

namespace console_apoc {

	class StoryBoardTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			story_board_ = new StoryBoard(test_story_board_file);
		}
		virtual void TearDown() {
			if (story_board_ != NULL) {
				delete story_board_;
				story_board_ = NULL;
			}
		}

		StoryBoard* story_board_;
		const string test_story_board_file = ".\\test_story_board.json";
	};

	TEST_F(StoryBoardTest, CreatesGameStateManager) {
		string error_msg = "The story board should create a game state manager\
						            on instantiation";
    ASSERT_TRUE(story_board_->game_state_manager() != NULL) << error_msg;
	}

  TEST_F(StoryBoardTest, CreatesGameStoryMap) {
    string error_msg = "The story board should create a populated game state\
                       to story sequence map";
    ASSERT_TRUE(story_board_->game_story_states() != NULL) << error_msg;
    EXPECT_TRUE(story_board_->game_story_states()->size() > 0) << error_msg;
  }

}