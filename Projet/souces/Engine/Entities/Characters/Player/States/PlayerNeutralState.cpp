//
// Created by David on 10/05/2018.
//

#include "PlayerNeutralState.hh"
IPlayerState *PlayerNeutralState::handle_input_player(Player &player) {
  return nullptr;
}
IPlayerState *PlayerNeutralState::update_player(Player &player) {
  return nullptr;
}
void PlayerNeutralState::draw_player(Player &player) {

}
void PlayerNeutralState::on_start() {
  IState::on_start();
}
void PlayerNeutralState::on_stop() {
  IState::on_stop();
}
void PlayerNeutralState::on_reload() {
  IState::on_reload();
}
void PlayerNeutralState::init_actions() {
  IState::init_actions();
}
void PlayerNeutralState::build_animiations() {
  IState::build_animiations();
}
