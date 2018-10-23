#include "abstract_regime.h"
#include "pipe.h"

abstract_regime_t::abstract_regime_t(pipe_t & pipe) :
  _pipe(pipe) {
}

abstract_regime_t::~abstract_regime_t() {
}

void abstract_regime_t::switch_on_pipe() {
  _pipe.switch_on();
}

void abstract_regime_t::switch_off_pipe() {
  _pipe.switch_off();
}

bool abstract_regime_t::is_pipe_on() const {
  return _pipe.is_on();
}

bool abstract_regime_t::is_pipe_off() const {
  return _pipe.is_off();
}
