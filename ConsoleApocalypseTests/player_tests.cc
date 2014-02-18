#include "gtest/gtest.h"
#include "player.h"

namespace console_apoc{

	TEST(PlayerTest, ChangesName) {
		string old_name = "old name";
		string new_name = "new name";

		Player *test_player = new Player(old_name);
		EXPECT_EQ(old_name, test_player->name()) << "The constructor doesn't \
													persist the provided name";
		test_player->setName(new_name);
		EXPECT_EQ(new_name, test_player->name()) << "The player doesn't persist\
													the new name";
	}

	TEST(PlayerTest, HandlesBlankName) {
		string blank_name = "";
		Player *test_player = new Player(blank_name);
		EXPECT_NE(blank_name, test_player->name()) << "The player supplies a \
													  default name";
	}
}