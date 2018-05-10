//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_EVENTMANAGER_HH
#define ARASHIENGINE_EVENTMANAGER_HH

#include <Templates/TemplateSingleton.hh>
#include "defs.h"

/**
 * @brief Decrypte et dispatche les evennements du context
 */
class EventManager : public TemplateSingleton<EventManager> {
 public:
  /**
   * @brief Dispatche les events de la fenetre vers les differents modules
   * @param window - reference vers  la fenetre des events
   */
  void process_events(sf::Window &window);
};

#endif //ARASHIENGINE_EVENTMANAGER_HH
