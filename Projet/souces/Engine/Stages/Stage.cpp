//
// Created by David on 06/05/2018.
//

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
	BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << ": Good";

	if (stage_definition["layers"].IsArray()) {
	  for (json::Value::ValueIterator layer = stage_definition["layers"].Begin();
		   layer != stage_definition["layers"].End(); ++layer) {
		BOOST_LOG_TRIVIAL(trace) << "--";
		build_layer(layer);
	  }
	}
  }
}

void Stage::build_layer(rapidjson::GenericValue<rapidjson::UTF8<char>,
												rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>::ValueIterator layer) {

  std::shared_ptr<sw::TileMap<unsigned int>> tile_map(new sw::TileMap<unsigned int>());

  if (layer->HasMember("data")) {
	BOOST_LOG_TRIVIAL(info) << layer->operator[]("name").GetString();

	/*Recuperation des donnes du tiles map*/
	std::vector<unsigned int> data;
	for (json::Value::ConstValueIterator itr = layer->operator[]("data").GetArray().Begin();
		 itr != layer->operator[]("data").GetArray().End(); ++itr) {
	  data.push_back(itr->GetUint());
	}
	BOOST_LOG_TRIVIAL(info) << "Tile Count : " << std::to_string(data.size());
	tile_map->setLevel(data);

	/*Parametres du calque*/
	unsigned int width = layer->operator[]("width").GetUint();
	unsigned int height = layer->operator[]("height").GetUint();




	/*Attacher la texture*/
	tile_map->setTexture((*m_texture.get()));
	/*Pousser le nouveau calque*/;
	m_layers.push_back(tile_map);
  }
}

void Stage::update(sf::Time dt) {
  ISceneNode::update(dt);
}
void Stage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  ISceneNode::draw(target, states);
}