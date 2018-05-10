//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ENTITIESMANAGER_HH
#define ARASHIENGINE_ENTITIESMANAGER_HH

#include "../Entities/Characters/Player/Player.hh"

#include "StageBuilder.hh"
#include "EntityFactory.hh"
#include "EntitiesManager.hh"

class EntitiesManager : public TemplateSingleton<EntitiesManager> {
 public:
  void initialize_player();

  void update(sf::Time dt);
  void draw(sf::RenderTarget &taget, sf::RenderStates states);

  void handle_input();

  void set_stage(std::string p_stage_id);
  void reset_player();
 private:
  void update_player(sf::Time dt);
  void update_stage(sf::Time dt);
  void update_entities(sf::Time dt);

  void draw_player(sf::RenderTarget &taget, sf::RenderStates states);
  void draw_stage(sf::RenderTarget &taget, sf::RenderStates states);
  void draw_entities(sf::RenderTarget &taget, sf::RenderStates states);

 private:
  std::unique_ptr<Player> m_player;
  std::map<std::string, IEntity> m_entities;
  std::unique_ptr<Stage> m_stage;
};

#endif //ARASHIENGINE_ENTITIESMANAGER_HH
