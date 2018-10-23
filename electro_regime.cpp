#include "electro_regime.h"
#include "electro_heater.h"
#include "temp_range.h"


electro_regime_t::electro_regime_t(const temp_range_t & temp_range, pipe_t & pipe, electro_heater_t & heater) :
  abstract_regime_t(pipe),
  _temp_range(temp_range),
  _heater(heater) {
}

void electro_regime_t::process_temperature(const float temperature) {
  
  switch_on_pipe();
  
  if (static_cast<int>(temperature) < _temp_range.get_min_value()) {
    _heater.switch_on();
  }

  if (static_cast<int>(temperature) > _temp_range.get_max_value()) {
    _heater.switch_off();
  }
}
