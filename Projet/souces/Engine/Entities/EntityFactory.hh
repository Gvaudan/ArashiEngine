//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ENTITYFACTORY_HH
#define ARASHIENGINE_ENTITYFACTORY_HH

#include <Templates/TemplateSingleton.hh>

#include "defs.h"
#include "IEntity.hh"

class EntityFactory : public TemplateSingleton<EntityFactory> {
  typedef std::unique_ptr<IEntityCreator> ptr_creator_t;
 public:
  bool register_type(Entities::Type p_type, IEntityCreator *p_creator);
  IEntity *create(Entities::Type type);
 private:
  std::map<Entities::Type, ptr_creator_t> m_creators;
};

#endif //ARASHIENGINE_ENTITYFACTORY_HH
