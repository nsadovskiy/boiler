#ifndef ABSTRACT_REGIME_H
#define ABSTRACT_REGIME_H


class pipe_t;


class abstract_regime_t {
public:
  abstract_regime_t(pipe_t & pipe);
  virtual ~abstract_regime_t();
  
public:
  virtual void process_temperature(const float temperature) = 0;

public:
  void switch_on_pipe();
  void switch_off_pipe();
  bool is_pipe_on() const;
  bool is_pipe_off() const;

private:
  pipe_t & _pipe;
};

#endif
