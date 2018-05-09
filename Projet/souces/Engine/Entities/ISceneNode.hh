//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ISCENENODE_HH
#define ARASHIENGINE_ISCENENODE_HH

#include "defs.h"
#include "EntitiesTypes.hh"

#include <memory>

class ISceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
  typedef std::unique_ptr<ISceneNode> ptr_node_t;
  typedef std::shared_ptr<ISceneNode> ptr_parent_t;
 public:
  ISceneNode();

  /***
   * @brief attache un enfant au noeud
   * @param child - std::unique_ptr<ISceneNode> reference de l'enfant
   */
  virtual void attach_child(ptr_node_t child);
  /**
   * @brief detache l'enfant du noeud
   * @param node - std::unique_ptr<ISceneNode> reference de l'enfant
   * @return - std::unique_ptr<ISceneNode> retourne l'enfant detache
   */
  virtual ptr_node_t detach_child(const ISceneNode &node);
/**
 * @brief update le noeud et ses enfants
 * @param dt - temps ecoule depuis le dernier appel
 */
  virtual void update(sf::Time dt);
  /**
   * @brief draw le noeud et ses enfants
   * @param target - la fenetre cible
   * @param states - l'etat de rendu de la fenetre
   */
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  sf::Vector2f get_world_position() const;
  sf::Transform get_world_transform() const;
  const std::string &get_id() const;
  const Entities::entitie_type &get_type() const;

  /**
   * @brief renseigne le parent du noeud
   * @param p_parent - std::shared_pointer<ISceneNode> : reference vers le parent
   */
  void set_parent(ptr_parent_t p_parent);

 protected:
  Entities::Type m_type;
  std::string m_id;
  std::vector<ptr_node_t> m_child_node_list;
  ptr_parent_t m_parent_node;

 protected:
  /**
   * @brief update a jours le noeud
   * @param dt - temps ecoule depuis le dernier appel
   */
  virtual void update_current(sf::Time dt);
  /**
   * @brief update les enfants du noeuds
   * @param dt temps ecoule depuis le dernier appel
   */
  virtual void update_child(sf::Time dt);

  /**
   * @brief dessine le noeud
   * @param target - fenetre de rendu
   * @param states - states de rendi
   */
  virtual void draw_current(sf::RenderTarget &target, sf::RenderStates states) const;
  /**
   * @brief draw les enfants du noeud
   * @param target - fenetre de rendu
   * @param states - etats de rendu
   */
  void draw_children(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //ARASHIENGINE_ISCENENODE_HH