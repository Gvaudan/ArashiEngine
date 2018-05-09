//
// Created by David on 06/05/2018.
//

#include "ISprite.hh"

ISprite::ISprite() {}

ISprite::ISprite(sf::Texture &texture) {
  m_inner_sprite.setTexture(texture);
}

ISprite::ISprite(sf::Texture &texture, sf::IntRect &texture_rect) {
  m_inner_sprite.setTexture(texture);
  m_inner_sprite.setTextureRect(texture_rect);
}