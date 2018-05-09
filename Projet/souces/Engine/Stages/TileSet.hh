//
// Created by David on 08/05/2018.
//

#ifndef ARASHIENGINE_TILESET_HH
#define ARASHIENGINE_TILESET_HH

#include <rapidjson/document.h>
#include <string>
#include <boost/shared_ptr.hpp>
#include <set>

namespace json = rapidjson;
class TileSet {
 public:
  TileSet(const std::shared_ptr<rapidjson::Document> &document);
 private:
  void build();
  std::shared_ptr<json::Document> m_document;

  std::string m_name;
  std::string m_texture_id;
  std::string m_texture_path;

  unsigned int m_tile_count;
  unsigned int m_tile_column;

  unsigned int m_tile_margin = 0;
  unsigned int m_tile_space = 0;

  unsigned int m_tile_height;
  unsigned int m_tile_width;

  unsigned int m_texture_width;
  unsigned int m_texture_height;
 public:
  const std::string &get_name() const;
  const std::string &get_texture_id() const;
  const std::string &get_texture_path() const;
  unsigned int get_tile_count() const;
  unsigned int get_tile_column() const;
  unsigned int get_tile_margin() const;
  unsigned int get_tile_space() const;
  unsigned int get_tile_height() const;
  unsigned int get_tile_width() const;
  unsigned int get_texture_width() const;
  unsigned int get_texture_height() const;
};

#endif //ARASHIENGINE_TILESET_HH