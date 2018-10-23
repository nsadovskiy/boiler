#ifndef PIPE_H
#define PIPE_H


class pipe_t {
public:
    pipe_t(const int relay_pin);

public:
    void init();
    void switch_on();
    void switch_off();
    const bool is_on() const;
    const bool is_off() const;

private:
    const int _relay_pin;
    bool _pipe_state;
};

#endif
