//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_IENTITY_HH
#define ARASHIENGINE_IENTITY_HH

#include "ISceneNode.hh"

class IEntity : public ISceneNode {
 public:
  IEntity();
  explicit IEntity(const sf::Vector2f &velocity);

  const sf::Vector2f &get_velocity() const;
  void set_velocity(const sf::Vector2f &velocity);

 protected:
  std::shared_ptr<sf::Texture> m_sprite_texture;
  sf::Vector2f m_velocity;
  sf::Sprite m_inner_sprite;
};

class IEntityCreator {
 public:
  virtual IEntity *create() const = 0;
};

#endif //ARASHIENGINE_IENTITY_HH
