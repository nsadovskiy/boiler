#include "coal_regime.h"
#include "pipe.h"
#include "electro_heater.h"


coal_regime_t::coal_regime_t(pipe_t & pipe, int low_temp, int high_temp, electro_heater_t & electro_heater) :
    abstract_regime_t(pipe),
    _low_temp(low_temp),
    _high_temp(high_temp),
    _electro_heater(electro_heater) {
}
  
void coal_regime_t::process_temperature(const float temperature) {

  _electro_heater.switch_off();
  
  if (is_pipe_on() && static_cast<int>(temperature) < _low_temp) {
    switch_off_pipe();
    return;
  }

  if (is_pipe_off() && static_cast<int>(temperature) >= _high_temp) {
    switch_on_pipe();
    return;
  }
}
  
