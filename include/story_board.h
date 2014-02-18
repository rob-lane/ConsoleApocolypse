#ifndef STORY_BOARD_H
#define STORY_BOARD_H

#include <string>
#include <map>
#include "json_reader.h"
#include "game_state_manager.h"
#include "intro_game_state.h"

using namespace std;

namespace console_apoc {

	class StoryBoard{
	public:
    typedef map<unsigned int, GameState*> GameStoryStateMap;

		StoryBoard(string story_board_file_name);
		virtual ~StoryBoard();

		GameStateManager* game_state_manager() const;
    GameStoryStateMap* game_story_states() const;

		virtual void start();
		virtual void pause();
		virtual void resume();
		virtual void stop();

	protected:
		GameStateManager *game_state_manager_;
    GameStoryStateMap *game_story_states_;

    void build_story_board_(Json::Value story_board_root);
    GameState* build_game_state_(string type_string, 
                                          Json::Value state_root);
    void link_story_board_();
	};

}

#endif