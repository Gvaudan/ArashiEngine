//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ISTATEMACHINE_HH
#define ARASHIENGINE_ISTATEMACHINE_HH

#include "IState.hh"

class IStateMachine {
 public:
  virtual void push_state(IState *p_state);

  virtual void change_state(IState *p_state);

  virtual void pop_state();

  virtual void update_state(sf::Time p_eleapsed_time);

  virtual void draw_state(sf::RenderTarget &target, sf::RenderStates &states);

  virtual void handle_input_state();

  virtual IState *get_current_state();

  virtual void update_state_event(sf::Event &p_event);

  virtual void clear_state_event();

 protected:
  std::vector<IState*> m_state_list;
};

#endif //ARASHIENGINE_ISTATEMACHINE_HH
