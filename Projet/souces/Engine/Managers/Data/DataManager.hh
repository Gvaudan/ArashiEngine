//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_DATAMANAGER_HH
#define ARASHIENGINE_DATAMANAGER_HH

#include "defs.h"

#include <Templates/TemplateSingleton.hh>

#include <Thor/Resources.hpp>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/filesystem.hpp>

#include <iostream>

namespace FileSystem = boost::filesystem;
namespace Ostreams = boost::iostreams;

typedef enum property_type_t {
  ENTITIE_DEF,
  STAGE_DEF,
  TILESET_DEF,
  MENU_DEF,
  SETTING_DEF
} PropertyType;

class DataManager : public TemplateSingleton<DataManager> {
 public:
  void initialize();
  std::shared_ptr<rapidjson::Document> get_property(std::string p_id, PropertyType p_type);
 private:

  thor::ResourceLoader<rapidjson::Document> load_property(std::string p_path);
  std::shared_ptr<rapidjson::Document> load_entitie_property(std::string p_id);
  rapidjson::Document * open_json(std::string p_path);

  thor::ResourceHolder<rapidjson::Document, std::string, thor::Resources::RefCounted> m_property_holder;
};

#endif //ARASHIENGINE_DATAMANAGER_HH
