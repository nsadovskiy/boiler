#include <Arduino.h>
#include "temp_range.h"


temp_range_t::temp_range_t(const int hysteresis, const int min_val, const int max_val, const int min_range, const int max_range) :
  _min_val(min_val),
  _max_val(max_val),
  _min_range(min_range),
  _max_range(max_range),
  _hysteresis(hysteresis),
  _value(min_val) {
}

void temp_range_t::set_pot_value(const int value) {

  if (value > _max_range) {
    _value = _min_val;
  }
  
  if (value < _min_range) {
    _value = _min_val;
  }
  
  _value = map(value, _min_range, _max_range, _min_val, _max_val);
}

const int temp_range_t::get_min_value() const {
  return _value;
}

const int temp_range_t::get_max_value() const {
  return _value + _hysteresis;
}
