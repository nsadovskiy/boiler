#include <Arduino.h>
#include "electro_heater.h"
#include "heater_mode.h"
#include "settings.h"


electro_heater_t::electro_heater_t(const heater_mode_t & mode):
  _mode(mode),
  _current_mode(0) {

    pinMode(HEATER_PIN1, OUTPUT);
    pinMode(HEATER_PIN2, OUTPUT);
    pinMode(HEATER_PIN3, OUTPUT);
}

void electro_heater_t::switch_on() {

  if (_current_mode != _mode.get_mode()) {
    _current_mode = _mode.get_mode();
    switch_relays();
  }
}

void electro_heater_t::switch_off() {
  if (_current_mode) {
    _current_mode = 0;
    switch_relays();
  }
}

bool electro_heater_t::is_on() const {
  return _current_mode != 0;
}

bool electro_heater_t::is_off() const {
  return !is_on();
}


void electro_heater_t::switch_relays() {
  digitalWrite(HEATER_PIN1, _current_mode >= 1 ? HIGH : LOW);
  digitalWrite(HEATER_PIN2, _current_mode >= 2 ? HIGH : LOW);
  digitalWrite(HEATER_PIN3, _current_mode >= 3 ? HIGH : LOW);
}
