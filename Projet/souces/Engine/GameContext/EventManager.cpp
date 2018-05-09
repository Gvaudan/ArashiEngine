//
// Created by David on 06/05/2018.
//

#include "EventManager.hh"

void EventManager::process_events(sf::Window &window) {
  sf::Event event;

  while (window.pollEvent(event)) {
	if (event.type == sf::Event::Closed) { window.close(); }
  }
}