//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_CONTEXT_HH
#define ARASHIENGINE_CONTEXT_HH

#include <Templates/TemplateSingleton.hh>

#include "../../Events/EventManager.hh"
#include "InputManager.hh"
#include "Data/DataManager.hh"
#include "EntitiesManager.hh"

#include "IStateMachine.hh"
#include "defs.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace Context {
namespace pt = boost::property_tree;
class Context : public IStateMachine,
				public TemplateSingleton<Context> {
 public:
  bool initialize();
  void run();
  void clean();
  void exit();
 private:
  void update();
  void handle_events();
  void render();

  void load_parameters();
  void set_window();

  sf::RenderWindow m_window;
  pt::ptree m_contex_config;

  EntitiesManager* m_entities_manager;
  EventManager *m_event_manager;
  InputManager *m_input_manager;
  DataManager *m_data_manager;
};
}

#endif //ARASHIENGINE_CONTEXT_HH
