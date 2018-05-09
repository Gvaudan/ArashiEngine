//
// Created by David on 06/05/2018.
//

#include <utility>
#include "ISceneNode.hh"
ISceneNode::ISceneNode() {}
void ISceneNode::attach_child(ISceneNode::ptr_node_t child) {
  child->set_parent(ptr_parent_t(this));
}

ISceneNode::ptr_node_t ISceneNode::detach_child(const ISceneNode &node) {
  auto found = std::find_if(m_child_node_list.begin(), m_child_node_list.end(), [&](ptr_node_t &p) {
	return p.get();
  });
  return ISceneNode::ptr_node_t();
}

void ISceneNode::update(sf::Time dt) {
  update_child(dt);
  update_current(dt);
}

void ISceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  draw_children(target, states);
  draw_current(target, states);
}

sf::Vector2f ISceneNode::get_world_position() const {
  return get_world_transform() * sf::Vector2f();
}

sf::Transform ISceneNode::get_world_transform() const {
  sf::Transform transform = sf::Transform::Identity;
  std::shared_ptr<const ISceneNode> start_node(this);

  for (auto curent_node = start_node; curent_node != nullptr;
	   curent_node = curent_node->m_parent_node) {
	transform *= curent_node->getTransform();
  }
  return transform;
}

const std::string &ISceneNode::get_id() const {
  return m_id;
}

const Entities::Type &ISceneNode::get_type() const {
  return m_type;
}

void ISceneNode::update_current(sf::Time dt) {
}

void ISceneNode::update_child(sf::Time dt) {
  for(ptr_node_t &current : m_child_node_list){
	current->update(dt);
  }
}

void ISceneNode::draw_current(sf::RenderTarget &target, sf::RenderStates states) const {

}

void ISceneNode::draw_children(sf::RenderTarget &target, sf::RenderStates states) const {
  for(const ptr_node_t &current : m_child_node_list){
	current->draw(target, states);
  }
}

void ISceneNode::set_parent(ISceneNode::ptr_parent_t p_parent) {
  m_parent_node = std::move(p_parent);
}