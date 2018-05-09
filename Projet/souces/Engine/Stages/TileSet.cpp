//
// Created by David on 08/05/2018.
//

#include "TileSet.hh"
TileSet::TileSet(const std::shared_ptr<rapidjson::Document> &document) : m_document(document) {
  build();
}

void TileSet::build() {
  json::Document &doc = (*m_document.get());
  m_name = doc["name"].GetString();

  m_tile_column = doc["columns"].GetUint();
  m_tile_count = doc["tilecount"].GetUint();
  m_tile_column = doc["columns"].GetUint();
  m_tile_width = doc["tilewidth"].GetUint();
  m_tile_height = doc["tileheight"].GetUint();

  m_texture_width = doc["imagewidth"].GetUint();
  m_texture_height = doc["imageheight"].GetUint();
}
const std::string &TileSet::get_name() const {
  return m_name;
}
const std::string &TileSet::get_texture_id() const {
  return m_texture_id;
}
const std::string &TileSet::get_texture_path() const {
  return m_texture_path;
}
unsigned int TileSet::get_tile_count() const {
  return m_tile_count;
}
unsigned int TileSet::get_tile_column() const {
  return m_tile_column;
}
unsigned int TileSet::get_tile_margin() const {
  return m_tile_margin;
}
unsigned int TileSet::get_tile_space() const {
  return m_tile_space;
}
unsigned int TileSet::get_tile_height() const {
  return m_tile_height;
}
unsigned int TileSet::get_tile_width() const {
  return m_tile_width;
}
unsigned int TileSet::get_texture_width() const {
  return m_texture_width;
}
unsigned int TileSet::get_texture_height() const {
  return m_texture_height;
}
