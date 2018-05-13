//
// Created by David on 06/05/2018.
//

#include <utility>
#include "DataManager.hh"

void DataManager::initialize() {
}
std::shared_ptr<rapidjson::Document> DataManager::get_property(std::string p_id, PropertyType p_type) {
  std::shared_ptr<rapidjson::Document> shared_ptr;

  std::string path;
  std::string &property_name = p_id;

  switch (p_type) {
	case PropertyType::SETTING_DEF : break;
	case PropertyType::STAGE_DEF :path.append(FOLDER_STAGES).append(property_name);
	  break;
	case PropertyType::TILESET_DEF : p_id.append("_tileset");
	  path.append(FOLDER_STAGES).append(property_name);
	  break;
	case PropertyType::SPRITESHEET_DEF : path.append(FOLDER_TEXTURE).append("sprites/").append(property_name);
	  break;
	case PropertyType::ENTITIE_DEF : break;
	case PropertyType::CHARACTER_DEF : path.append(FOLDER_ENTITIES).append("characters/").append(property_name);
	  break;
	case PropertyType::MENU_DEF : break;
	default: break;
  }

  BOOST_LOG_TRIVIAL(debug) << "Getting : " << p_id;
  shared_ptr = m_property_holder.acquire(p_id, load_property(path), thor::Resources::Reuse);
  return shared_ptr;
}

rapidjson::Document *DataManager::open_json(std::string p_path) {
  BOOST_LOG_TRIVIAL(info) << "Openning json : " << p_path;

  rapidjson::Document *doc = nullptr;

  Ostreams::file_source fs{p_path.append(".json")};
  if (fs.is_open()) {
	Ostreams::stream<Ostreams::file_source> stream{fs};

	std::stringstream string_stream;
	string_stream << stream.rdbuf();
	doc = new rapidjson::Document;
	doc->Parse(string_stream.str().c_str());
	assert(doc->IsObject());
	return doc;
  }
}

thor::ResourceLoader<rapidjson::Document> DataManager::load_property(std::string p_path) {
  BOOST_LOG_TRIVIAL(debug) << "Loading " << p_path;
  return thor::ResourceLoader<rapidjson::Document>(
	  [=]() { return std::unique_ptr<rapidjson::Document>(open_json(p_path)); }, p_path);
}