//
// Created by David on 10/05/2018.
//

#ifndef ARASHIENGINE_IPLAYERNEUTRALSTATE_HH
#define ARASHIENGINE_IPLAYERNEUTRALSTATE_HH

#include "IPlayerState.hh"

class PlayerNeutralState : public IPlayerState {
 public:
  IPlayerState *handle_input_player(Player &player) override;
  IPlayerState *update_player(Player &player) override;
  void draw_player(Player &player) override;
  void on_start() override;
  void on_stop() override;
  void on_reload() override;

  protected:
  void init_actions() override;
  void build_animiations() override;
};

#endif //ARASHIENGINE_IPLAYERNEUTRALSTATE_HH
