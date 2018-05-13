//
// Created by David on 10/05/2018.
//

#ifndef ARASHIENGINE_IPLAYERSTATE_HH
#define ARASHIENGINE_IPLAYERSTATE_HH

#include "../Player.hh"

class IPlayerState : public IState {
 public:
  virtual IPlayerState *handle_input_player(Player &player) = 0;
  virtual IPlayerState *update_player(Player &player) = 0;
  virtual void draw_player(Player &player) = 0;
 protected:
};

#endif //ARASHIENGINE_IPLAYERSTATE_HH
