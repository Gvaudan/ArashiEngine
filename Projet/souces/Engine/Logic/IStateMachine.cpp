//
// Created by David on 06/05/2018.
//

#include "IStateMachine.hh"

void IStateMachine::push_state(IState *p_state) {
  m_state_list.push_back(p_state);
  m_state_list.back()->on_start();
}

void IStateMachine::change_state(IState *p_state) {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  if (!m_state_list.empty()) {
	if (m_state_list.back()->get_id() == p_state->get_id()) {
	  if (m_state_list.back()->is_reloadable()) { m_state_list.back()->on_start(); }
	  return;
	}
	m_state_list.back()->on_stop();
	delete m_state_list.back();
	m_state_list.pop_back();
  }
  m_state_list.push_back(p_state);
  m_state_list.back()->on_start();
}

void IStateMachine::pop_state() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : START";

  if (!m_state_list.empty()) {
	m_state_list.back()->on_stop();
	delete m_state_list.back();
	m_state_list.pop_back();

	if (!m_state_list.empty()) { m_state_list.back()->on_start(); }
  }
}

void IStateMachine::update_state(sf::Time p_eleapsed_time) {
  if (!m_state_list.empty()) {
	m_state_list.back()->update(p_eleapsed_time);
  }
}

void IStateMachine::draw_state(sf::RenderTarget &target, sf::RenderStates &states) {
  if (!m_state_list.empty()) {
	m_state_list.back()->draw(target, states);
  } else {
	BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

void IStateMachine::handle_input_state() {
  if (!m_state_list.empty()) {
	auto return_state = m_state_list.back()->handle_input();
	if (return_state != nullptr) {
	  change_state(return_state);
	}
  } else {
	BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

IState *IStateMachine::get_current_state() {
  if (!m_state_list.empty()) {
	return m_state_list.back();
  }
  return nullptr;
}

void IStateMachine::update_state_event(sf::Event &p_event) {
  if (!m_state_list.empty()) {
	m_state_list.back()->push_event(p_event);
  } else {
	BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

void IStateMachine::clear_state_event() {
  if (!m_state_list.empty()) {
	m_state_list.back()->clear_events();
  } else {
	BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}