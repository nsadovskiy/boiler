#ifndef HEATER_H
#define HEATER_H


class heater_mode_t {

public:
    heater_mode_t();
    
public:
    void switch_mode();
    const bool is_on() const;
    const bool is_off() const;
    const int get_mode() const;

private:
    volatile int _mode;
};

#endif
