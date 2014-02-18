#include "story_board.h"

namespace console_apoc {

  StoryBoard::StoryBoard(string story_board_file_name) {
    game_story_states_ = new GameStoryStateMap();

    JsonReader reader(story_board_file_name);
    build_story_board_(reader.root());  

    game_state_manager_ = new GameStateManager((*game_story_states_)[0]);
  }

  StoryBoard::~StoryBoard() {
    if (game_state_manager_ != NULL) {
      delete game_state_manager_;
      game_state_manager_ = NULL;
    }
    if (game_story_states_ != NULL) {
      game_story_states_->erase(game_story_states_->begin(), 
                                game_story_states_->end());
      delete game_story_states_;
      game_story_states_ = NULL;
    }
  }

  GameStateManager* StoryBoard::game_state_manager() const {
    return game_state_manager_;
  }

  StoryBoard::GameStoryStateMap* StoryBoard::game_story_states() const {
    return game_story_states_;
  }

  void StoryBoard::start() {
    game_state_manager()->start_current_state();
  }

  void StoryBoard::stop() {
    game_state_manager()->change_state(true, (*game_story_states_)[0]);
  }

  void StoryBoard::pause() {
    game_state_manager()->current_game_state()->pause();
  }

  void StoryBoard::resume() {
    game_state_manager()->current_game_state()->resume();
  }

  void StoryBoard::build_story_board_(Json::Value story_board_root) {
    Json::Value story_board_elements = story_board_root["storyBoard"];
    for (unsigned int i = 0; i < story_board_elements.size(); i++)
    {
      Json::Value element = story_board_elements[i];
      string element_type = element["type"].asString();
      (*game_story_states_)[i] = build_game_state_(element_type, element);
    }
    link_story_board_();
  }

  GameState* StoryBoard::build_game_state_(string type_string,
                                            Json::Value state_root) {
    GameState *game_state = NULL;
    if (type_string.compare("Intro") == 0) {
      game_state = new IntroGameState(state_root["introText"].asString());
    }
    return game_state;
  }

  void StoryBoard::link_story_board_() {
    GameStoryStateMap::iterator state_iter = game_story_states_->begin();
    for (state_iter; state_iter != game_story_states_->end(); state_iter++)
    {
      int state_key = state_iter->first;
      GameState* state = state_iter->second;
      if (game_story_states_->size() > state_key + 1 && state != NULL)
      {
        state->set_next_state((*game_story_states_)[state_key++]);
      }
    }
  }
}