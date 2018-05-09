//
// Created by David on 06/05/2018.
//

#include "EntityFactory.hh"
bool EntityFactory::register_type(Entities::Type p_type, IEntityCreator *p_creator) {
  auto it = m_creators.find(p_type);
  if (!m_creators.empty()) {
	if (it != m_creators.end()) {
	  delete p_creator;
	  return false;
	}
  }
  m_creators[p_type] = ptr_creator_t(p_creator);
  return true;
}
IEntity *EntityFactory::create(Entities::Type type) {

  if (!m_creators.empty()) {
	auto it = m_creators.find(type);
	if (it == m_creators.end()) {
	  BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << "Try to create an unregistered entitie";
	  return nullptr;
	}
	return m_creators[type]->create();
  }
  return nullptr;
}
