#include "heater_mode.h"


heater_mode_t::heater_mode_t() :
  _mode(0) {
}

void heater_mode_t::switch_mode() {
  ++_mode;
  if (_mode > 3) {
    _mode = 0;
  }
}

const bool heater_mode_t::is_on() const {
  return _mode > 0;
}

const bool heater_mode_t::is_off() const {
  
}

const int heater_mode_t::get_mode() const {
  return _mode;
}
