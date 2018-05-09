//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ISTATE_HH
#define ARASHIENGINE_ISTATE_HH

#include "Entities.hh"

class IEntity;
class IState {
 public:

  virtual IState *update(sf::Time p_eleapsed_time);
  virtual IState *handle_input();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates &states);

  virtual void on_start();
  virtual void on_stop();
  virtual void on_reload();

  void push_action(std::string p_name, thor::Action p_action);
  void clear_actions();

  void push_event(sf::Event &p_event);
  void clear_events();

  const std::string &get_id() const;
  void set_id(const std::string &id);
  unsigned int get_reload_count();
  bool is_reloadable();

  protected:
  virtual void init_actions();
  virtual void build_animiations();
  bool m_is_cancelable = true;
  bool m_is_reloadable = true;

 private:
  std::string m_id;
  unsigned int m_reload_count = 0;
};

#endif //ARASHIENGINE_ISTATE_HH