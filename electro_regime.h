#ifndef ELECTRO_REGIME_H
#define ELECTRO_REGIME_H

#include "abstract_regime.h"


class temp_range_t;
class pipe_t;
class electro_heater_t;


class electro_regime_t : public abstract_regime_t {

public:
  electro_regime_t(const temp_range_t & temp_range, pipe_t & pipe, electro_heater_t & heater);
  
public:
  virtual void process_temperature(const float temperature);

private:
  const temp_range_t & _temp_range;
  electro_heater_t & _heater;
};

#endif
