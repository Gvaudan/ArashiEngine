//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ICHARACTER_HH
#define ARASHIENGINE_ICHARACTER_HH

#include "Logic.hh"
#include "Entities.hh"

class ICharacter : public IEntity, public IStateMachine {
 public:
  unsigned int get_max_life() const;
  unsigned int get_life() const;

 protected:
  unsigned int m_max_life;
  unsigned int m_life;
};

typedef struct s_state_definition {
  std::string m_id;
} StateDefinition;

typedef struct s_character_attack_definition {
  std::string m_id;

} AttackDefinition;

typedef struct s_character_set {
  unsigned int m_max_life{};
  std::map<std::string, StateDefinition> m_state_definitions;
  std::map<std::string, AttackDefinition> m_attack_definitions;
  thor::Animator<ICharacter, std::string> m_animator;
} CharacterSet;

#endif //ARASHIENGINE_ICHARACTER_HH