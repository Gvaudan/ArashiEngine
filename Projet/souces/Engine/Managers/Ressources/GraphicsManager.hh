//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_GRAPHICSMANAGER_HH
#define ARASHIENGINE_GRAPHICSMANAGER_HH

#include <defs.h>

#include <Templates/TemplateSingleton.hh>
#include <Thor/Resources.hpp>

typedef enum textures_type_t {
  TILESET,
  SPRITE,
  SPRITESHEET,
  UI
} TextureType;

class GraphicsManager : public TemplateSingleton<GraphicsManager> {
 public:
  void initialize();
  std::shared_ptr<sf::Texture> get_texture(std::string p_texture_id);
  void free_ressources();
  std::shared_ptr<sf::Texture> get_texture(std::string p_id, TextureType p_type);
 private:
  void load_texture(std::string p_id, std::string p_filename);
  void load_tileset(std::string p_id);
  thor::ResourceHolder<sf::Texture, std::string, thor::Resources::RefCounted> m_holder_texture;
  thor::ResourceHolder<sf::Font, std::string, thor::Resources::RefCounted> m_holder_font;

};

#endif //ARASHIENGINE_GRAPHICSMANAGER_HH