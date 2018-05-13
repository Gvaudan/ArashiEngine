//
// Created by David on 06/05/2018.
//

#include <Data/DataManager.hh>
#include "Ressources/GraphicsManager.hh"
#include <rapidjson/document.h>
#include "Player.hh"

Player::Player() {
  m_inner_sprite.setColor(sf::Color::Yellow);
}

Player::~Player() = default;

void Player::handle_input_state() {
  IStateMachine::handle_input_state();
}
void Player::update(sf::Time dt) {
  ISceneNode::update(dt);
}
void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  ISceneNode::draw(target, states);
  target.draw(m_inner_sprite, states);
}

IEntity *PlayerCreator::create() const {
  std::shared_ptr<sf::Texture> texture_ptr;
  std::string sprite_sheet_name;

  auto doc_entitie_def = DataManager::get_instance()->
	  get_property("player", PropertyType::CHARACTER_DEF);

  assert(doc_entitie_def.get()->operator[]("sprite_sheet").IsString());
  sprite_sheet_name = doc_entitie_def.get()->operator[]("sprite_sheet").GetString();
  std::shared_ptr<rapidjson::Document>
	  doc_sprite_sheet = DataManager::get_instance()->get_property(sprite_sheet_name, PropertyType::SPRITESHEET_DEF);

  assert(doc_sprite_sheet.get()->operator[]("attack/frame0000").IsObject());
  auto &doc = (*doc_entitie_def.get());
  auto &doc_2 = (*doc_sprite_sheet.get());

  //TODO : Construire le character_set
  //CharacterSet character_set;

  //1 - les states :
  for (auto &current : doc["specifications"].GetObject()["animations"].GetArray()) {
	std::string animation_name = current.GetString();
	BOOST_LOG_TRIVIAL(debug) << "Parsing " << animation_name << " animation...";
	auto lenght = current.GetStringLength();

	for (rapidjson::Value::ConstMemberIterator itr = doc_2.MemberBegin();
		 itr != doc_2.MemberEnd(); ++itr) {
	  std::string frame_name = itr->name.GetString();

	  if ((frame_name.substr(0, animation_name.length()) == animation_name)) {
		auto frame_number = std::string{itr->name.GetString()}.substr(lenght + 6);
		try {
		  auto nb = std::stoi(frame_number);
		  BOOST_LOG_TRIVIAL(debug) << "Current frame : " << std::to_string(nb);
		} catch (std::invalid_argument &e) {
		  BOOST_LOG_TRIVIAL(warning) << e.what();
		}
	  }
	}
  }

  //TODO : Construire les attack_set
  //TODO : Construire les state_set

  //TODO : Charger la texture du sprite

  return new Player();
}
