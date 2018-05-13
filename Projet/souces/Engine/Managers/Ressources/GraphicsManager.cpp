//
// Created by David on 06/05/2018.
//

#include "GraphicsManager.hh"
void GraphicsManager::initialize() {

}
std::shared_ptr<sf::Texture> GraphicsManager::get_texture(std::string p_texture_id) {
  return std::shared_ptr<sf::Texture>();
}
void GraphicsManager::free_ressources() {

}

std::shared_ptr<sf::Texture> GraphicsManager::get_texture(std::string p_id, TextureType p_type) {
  std::string file_name;

  switch (p_type) {
	case TextureType::TILESET: file_name = std::string(FOLDER_TEXTURE).append("tiles/").append(p_id).append(".png");
	  break;
	case TextureType::SPRITESHEET : file_name = std::string(FOLDER_TEXTURE).append("sprites/").append(p_id).append(".png");
	  break;
	default: break;
  }
  BOOST_LOG_TRIVIAL(info) << "Try to open : " << file_name;

  std::shared_ptr<sf::Texture> texture;
  try {
	texture = m_holder_texture.acquire(p_id, thor::Resources::fromFile<sf::Texture>(file_name), thor::Resources::Reuse);
  } catch (thor::ResourceLoadingException &e) {
	BOOST_LOG_TRIVIAL(fatal) << e.what();
  }

  return texture;
}
void GraphicsManager::load_texture(std::string p_id, std::string p_filename) {
  m_holder_texture.acquire(p_id, thor::Resources::fromFile<sf::Texture>(p_filename), thor::Resources::Reuse);
}
void GraphicsManager::load_tileset(std::string p_id) {

}
