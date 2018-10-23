#ifndef ELECTRO_HEATER_H
#define ELECTRO_HEATER_H


class heater_mode_t;


class electro_heater_t {
public:
  electro_heater_t(const heater_mode_t & mode);

public:
  void switch_on();
  void switch_off();

  bool is_on() const;
  bool is_off() const;

private:
  void switch_relays();

private:
  const heater_mode_t & _mode;
  int _current_mode;
};

#endif
