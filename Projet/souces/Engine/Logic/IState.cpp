//
// Created by David on 06/05/2018.
//

#include "IState.hh"
const std::string &IState::get_id() const {
  return m_id;
}
void IState::set_id(const std::string &id) {
  m_id = id;
}
IState *IState::handle_input() {
  return nullptr;
}
IState *IState::update(sf::Time p_eleapsed_time) {
  return nullptr;
}
void IState::draw(sf::RenderTarget &target, sf::RenderStates &states) {

}
void IState::on_start() {

}
void IState::on_stop() {

}
void IState::on_reload() {

}
void IState::init_actions() {

}
void IState::build_animiations() {

}
unsigned int IState::get_reload_count() {
  return m_reload_count;
}
bool IState::is_reloadable() {
  return m_is_reloadable;
}
void IState::push_action(std::string p_name, thor::Action p_action) {

}
void IState::push_event(sf::Event &p_event) {

}
void IState::clear_actions() {

}
void IState::clear_events() {

}
