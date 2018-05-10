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
typedef std::unique_ptr<std::vector<unsigned int>> ptr_data_layer_t;
typedef std::shared_ptr<sw::TileMap<unsigned int>> ptr_layer_t;
typedef std::shared_ptr<sf::Texture> ptr_texture_t;
class Stage : public ISceneNode {
 public:
  Stage();
  ~Stage() override;
  Stage(std::string p_id,
		json::Document &stage_definition,
		json::Document &tileset_definition,
		ptr_texture_t texture);
  void update(sf::Time dt) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

 private:
  void build(json::Document stage_definition, json::Document tileset_definition);

  void build_layer(json::GenericValue<json::UTF8<char>,
									  json::MemoryPoolAllocator<json::CrtAllocator>>::ValueIterator,
				   sf::Vector2f p_tile_size,
				   unsigned int p_tile_row);

  std::vector<ptr_data_layer_t> m_data_layers;
  std::vector<ptr_layer_t> m_layers;
  std::shared_ptr<sf::Texture> m_texture;
};

#endif //ARASHIENGINE_ISTAGE_HH
