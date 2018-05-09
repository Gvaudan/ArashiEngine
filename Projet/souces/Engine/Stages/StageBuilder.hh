//
// Created by David on 08/05/2018.
//

#ifndef ARASHIENGINE_STAGEBUILDER_HH
#define ARASHIENGINE_STAGEBUILDER_HH

#include <Templates/TemplateSingleton.hh>

#include "Stage.hh"
#include "TileSet.hh"

class StageBuilder : public TemplateSingleton <StageBuilder>{
 public :
  Stage *build_stage(std::string p_id);
 private:
};

#endif //ARASHIENGINE_STAGEBUILDER_HH