//
// Created by David on 06/05/2018.
//

#include <StageBuilder.hh>
#include "Context.hh"
#include "Stage.hh"

namespace Context {

bool Context::initialize() {

  load_parameters();

  //*Initialiser la fenetre
  set_window();

  /*TODO : Charger les modules
   * */
  m_event_manager = EventManager::get_instance();
  m_input_manager = InputManager::get_instance();
  m_data_manager = DataManager::get_instance();
  m_data_manager->initialize();

  m_entities_manager = EntitiesManager::get_instance();
  m_entities_manager->initialize();
  m_entities_manager->initialize_player();
  m_entities_manager->set_stage("grassland");

  /*TODO : Creer le context de jeu
   * */
  return true;
}
void Context::run() {

  while (m_window.isOpen()) {

	handle_events();
	update();
	render();

  }
  exit();
}
void Context::clean() {

}
void Context::exit() {

}
void Context::update() {

}
void Context::handle_events() {
  m_event_manager->process_events(m_window);
}
void Context::render() {
  m_window.clear();
  m_entities_manager->draw(m_window, sf::RenderStates::Default);
  m_window.display();
}
void Context::load_parameters() {
  pt::ptree window_set;

  try {
	pt::read_json(CONFIG_FILE, m_contex_config);
  } catch (const pt::ptree_error &e) {
	BOOST_LOG_TRIVIAL(fatal) << e.what();
  }
}

void Context::set_window() {
  pt::ptree window_set;
  unsigned int width = BASE_WINDOW_WIDTH;
  unsigned int height = BASE_WINDOW_HEIGHT;

  try {
	window_set = m_contex_config.get_child("window");
	width = window_set.get<unsigned int>("width", BASE_WINDOW_HEIGHT);
	height = window_set.get<unsigned int>("height", BASE_WINDOW_HEIGHT);
  } catch (pt::ptree_error &e) {
	BOOST_LOG_TRIVIAL(fatal) << e.what();
  }
  if (m_window.isOpen()) {
	m_window.setSize(sf::Vector2u(width, height));
  } else {
	m_window.create(sf::VideoMode(width, height), WINDOW_NAME);
  }
}
}
