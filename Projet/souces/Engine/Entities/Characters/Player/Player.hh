//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_PLAYER_HH
#define ARASHIENGINE_PLAYER_HH

#include "../ICharacter.hh"

class Player : public ICharacter {
 public:
  Player();
  ~Player() override;

  void handle_input_state() override;
  void update(sf::Time dt) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

class PlayerCreator : public IEntityCreator {
 public:
  IEntity *create() const override;
};

#endif //ARASHIENGINE_PLAYER_HH
