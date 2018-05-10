//
// Created by David on 08/05/2018.
//

#include "StageBuilder.hh"
#include <Data/DataManager.hh>
#include <Ressources/GraphicsManager.hh>
#include <utility>

Stage *StageBuilder::build_stage(std::string p_id) {

  std::shared_ptr<sf::Texture> texture_ptr;
  std::shared_ptr<json::Document> doc_ptr = DataManager::get_instance()->
	  get_property(p_id, PropertyType::STAGE_DEF);

  json::Document &stage_definition = (*doc_ptr.get());

  std::shared_ptr<json::Document> tilset_def_ptr = DataManager::get_instance()->
	  get_property(p_id, PropertyType::TILESET_DEF);

  json::Document &tielset_definition = (*tilset_def_ptr.get());

  texture_ptr = GraphicsManager::get_instance()->get_texture(p_id, TextureType::TILESET);

  auto stage = new Stage(p_id, stage_definition, tielset_definition, texture_ptr);

  return stage;
}