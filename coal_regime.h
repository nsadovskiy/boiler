#ifndef COAL_REGIME_H
#define COAL_REGIME_H

#include "abstract_regime.h"

class electro_heater_t;


class coal_regime_t : public abstract_regime_t {
public:
  coal_regime_t(pipe_t & pipe, int low_temp, int high_temp, electro_heater_t & electro_heater);
  
public:
  virtual void process_temperature(const float temperature);

private:
  int _low_temp;
  int _high_temp;
  electro_heater_t & _electro_heater;
};

#endif
