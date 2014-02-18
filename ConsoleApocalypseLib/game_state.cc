#include "game_state.h"

namespace console_apoc {

  GameState::GameState() {
    next_game_state_ = NULL;
    prev_game_state_ = NULL;
  }

  GameState::~GameState() {
    next_game_state_ = NULL;
    prev_game_state_ = NULL;
  }

  GameState* GameState::get_next_state() {
    return next_game_state_;
  }

  GameState* GameState::get_previous_state() {
    return prev_game_state_;
  }

  void GameState::set_next_state(GameState* next_game_state) {
    next_game_state_ = next_game_state;
  }

  void GameState::set_previous_state(GameState* prev_game_state) {
    prev_game_state_ = prev_game_state;
  }

}