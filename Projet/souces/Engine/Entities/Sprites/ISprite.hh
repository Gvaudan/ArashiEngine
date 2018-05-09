//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ISPRITE_HH
#define ARASHIENGINE_ISPRITE_HH

#include "ISceneNode.hh"

class ISprite : public ISceneNode {
 public:
  ISprite();
  ISprite(sf::Texture &texture);
  ISprite(sf::Texture &texture, sf::IntRect &texture_rect);
 protected:
  sf::Sprite m_inner_sprite;
};

#endif //ARASHIENGINE_ISPRITE_HH
