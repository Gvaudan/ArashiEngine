//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ISTAGE_HH
#define ARASHIENGINE_ISTAGE_HH

#include "Entities.hh"
#include <SelbaWard/TileMap.hpp>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

namespace json = rapidjson;

class Stage : public ISceneNode {
 public:
  Stage();
  Stage(std::string p_id,
		json::Document &stage_definition,
		json::Document &tileset_definition,
		std::shared_ptr<sf::Texture> texture);
  void update(sf::Time dt) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
 private:

  void build(json::Document stage_definition, json::Document tileset_definition);

  void build_layer(rapidjson::GenericValue<rapidjson::UTF8<char>,
										   rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>::ValueIterator);

  std::vector<std::vector<unsigned int>> m_data_layers;
  std::vector<std::shared_ptr<sw::TileMap<unsigned int>>> m_layers;
  std::shared_ptr<sf::Texture> m_texture;
};

#endif //ARASHIENGINE_ISTAGE_HH
