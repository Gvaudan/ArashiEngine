//
// Created by David on 06/05/2018.
//

#include <memory>
#include <utility>
#include "Stage.hh"

Stage::Stage() {

}
Stage::Stage(std::string p_id,
			 json::Document &stage_definition,
			 json::Document &tileset_definition,
			 std::shared_ptr<sf::Texture> texture) : m_texture(std::move(texture)) {
  build(std::move(stage_definition), std::move(tileset_definition));
}

void Stage::build(json::Document stage_definition, json::Document tileset_definition) {

  if (stage_definition.IsObject()) {

	if (stage_definition["layers"].IsArray()) {
	  for (json::Value::ValueIterator layer = stage_definition["layers"].Begin();
		   layer != stage_definition["layers"].End(); ++layer) {

		std::string layer_type = layer->operator[]("type").GetString();

		if (layer_type == "tilelayer") {
		  BOOST_LOG_TRIVIAL(trace) << "--";
		  build_layer(layer,{static_cast<float>(stage_definition["tilewidth"].GetDouble()),
						  static_cast<float>(stage_definition["tilewidth"].GetDouble())},
					  tileset_definition["columns"].GetUint());
		}
	  }
	}
  }
}

void Stage::build_layer(rapidjson::GenericValue<rapidjson::UTF8<char>,
												rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>::ValueIterator layer,
						sf::Vector2f p_tile_size,
						unsigned int p_tile_row) {
  std::shared_ptr<sw::TileMap<unsigned int>> tile_map(new sw::TileMap<unsigned int>());

  /*Recuperation des donnes du tiles map*/
  m_data_layers.push_back(std::make_unique<std::vector<unsigned int>>());

  for (json::Value::ConstValueIterator itr = layer->operator[]("data").GetArray().Begin();
	   itr != layer->operator[]("data").GetArray().End(); ++itr) {
	m_data_layers.back().get()->push_back(itr->GetUint() - 1);
  }
  /*BOOST_LOG_TRIVIAL(info) << "Tile Count : " << std::to_string(data.size());*/


  /*Parametres du calque*/
  unsigned int width = layer->operator[]("width").GetUint();
  unsigned int height = layer->operator[]("height").GetUint();
  float layer_width = width * p_tile_size.x;
  float layer_height = height * p_tile_size.y;

  tile_map->setLevel(*m_data_layers.back().get());
  tile_map->setLevelWidth(width);

  /*BOOST_LOG_TRIVIAL(debug) << std::to_string(width) << " | " << std::to_string(height);
  BOOST_LOG_TRIVIAL(debug) << std::to_string(layer_width) << " | " << std::to_string(layer_height);
  BOOST_LOG_TRIVIAL(debug) << std::to_string(p_tile_size.x) << " | " << std::to_string(p_tile_size.y);
*/
  tile_map->setSize({layer_width, layer_height});

  tile_map->setGridSize({width, height});

  /*Attacher la texture*/
  tile_map->setTexture((*m_texture.get()));
  tile_map->setNumberOfTextureTilesPerRow(p_tile_row);
  tile_map->setTextureTileSize({static_cast<unsigned int>(p_tile_size.x),
								static_cast<unsigned int>(p_tile_size.y)});

  /*Pousser le nouveau calque*/;
  tile_map->update();
  m_layers.push_back(tile_map);
}

void Stage::update(sf::Time dt) {
  for (const auto &layer : m_layers) {
	layer.get()->update();
  }
}
void Stage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (const auto &layer : m_layers) {
	auto &obj = *layer.get();
	target.draw(obj, states);
  }
}

Stage::~Stage() = default;