//
// Created by David on 06/05/2018.
//

#include "EntitiesManager.hh"
#include <StageBuilder.hh>
#include <memory>
#include <utility>

void EntitiesManager::initialize() {
  m_entities_factory = EntityFactory::get_instance();
  m_entities_factory->register_type(Entities::Type::PLAYER, new PlayerCreator());
  m_player.reset((Player*)m_entities_factory->create(Entities::Type::PLAYER));
}

void EntitiesManager::initialize_player() {
  m_player.reset((Player*)m_entities_factory->create(Entities::Type::PLAYER));
}
void EntitiesManager::update(sf::Time dt) {
  update_player(dt);
  update_entities(dt);
  update_stage(dt);
}

void EntitiesManager::draw(sf::RenderTarget &taget, sf::RenderStates states){
  draw_stage(taget, states);
  draw_entities(taget, states);
  draw_player(taget, states);
}
void EntitiesManager::handle_input() {

}

void EntitiesManager::set_stage(std::string p_stage_id) {
  auto stage = StageBuilder::get_instance()->build_stage(std::move(p_stage_id));
  m_stage.reset(stage);
}

void EntitiesManager::update_player(sf::Time dt) {
}
void EntitiesManager::update_stage(sf::Time dt) {
  m_stage->update(dt);
}
void EntitiesManager::update_entities(sf::Time dt) {
  if (!m_entities.empty()) {
	for (auto &entitie : m_entities) {
	  entitie.second.update(dt);
	}
  }
}
void EntitiesManager::draw_player(sf::RenderTarget &taget, sf::RenderStates states) {

}
void EntitiesManager::draw_stage(sf::RenderTarget &taget, sf::RenderStates states) {
  taget.draw((*m_stage), states);
}
void EntitiesManager::draw_entities(sf::RenderTarget &taget, sf::RenderStates states) {
  if (!m_entities.empty()) {
	for (auto &entitie : m_entities) {
	  taget.draw(entitie.second, states);
	}
  }
}
void EntitiesManager::reset_player() {
  m_player = std::make_unique<Player>();
}