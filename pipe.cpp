#include <Arduino.h>
#include "pipe.h"


pipe_t::pipe_t(const int relay_pin) :
  _relay_pin(relay_pin),
  _pipe_state(false) {
}

void pipe_t::init() {
  pinMode(_relay_pin, OUTPUT);
}

void pipe_t::switch_on() {
  if (is_off()) {
    digitalWrite(_relay_pin, HIGH);
    _pipe_state = true;
  }
}

void pipe_t::switch_off() {
  if (is_on()) {
    digitalWrite(_relay_pin, LOW);
    _pipe_state = false;
  }
}

const bool pipe_t::is_on() const {
  return _pipe_state;
}

const bool pipe_t::is_off() const {
  return !_pipe_state;
}
