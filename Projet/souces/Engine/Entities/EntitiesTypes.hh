//
// Created by David on 06/05/2018.
//

#ifndef ARASHIENGINE_ENTITIESTYPES_HH
#define ARASHIENGINE_ENTITIESTYPES_HH

namespace Entities {
typedef enum entitie_type {
  PLAYER,
  ENNEMIE,
  BOSS,
  OBJECT,
  TILE,
  SPRITE,
  BASE
} Type;

typedef enum entity_state {
  WALKING,
  JUMPING,
  ATTACK
} State;
}
#endif //ARASHIENGINE_ENTITIESTYPES_HH
