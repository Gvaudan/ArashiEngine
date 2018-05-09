//
// Created by David on 06/05/2018.
//

#include "IEntity.hh"
IEntity::IEntity() {}
IEntity::IEntity(const sf::Vector2f &velocity) : m_velocity(velocity) {}

const sf::Vector2f &IEntity::get_velocity() const {
  return m_velocity;
}
void IEntity::set_velocity(const sf::Vector2f &velocity) {
  m_velocity = velocity;
}
