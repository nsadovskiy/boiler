#ifndef TEMP_RANGE_H
#define TEMP_RANGE_H


class temp_range_t {
public:
    temp_range_t(const int hysteresis, const int min_val, const int max_val, const int min_range, const int max_range);

public:
  void set_pot_value(const int value);
  const int get_min_value() const;
  const int get_max_value() const;

private:
    int _value;
    int _min_val;
    int _max_val;
    int _min_range;
    int _max_range;
    int _hysteresis;
};

#endif
