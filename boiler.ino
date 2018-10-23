#include "LiquidCrystal_I2C.h"
#include "cactus_io_DS18B20.h"
#include "settings.h"
#include "heater_mode.h"
#include "temp_range.h"
#include "pipe.h"
#include "electro_regime.h"
#include "coal_regime.h"
#include "electro_heater.h"


volatile int wait_tick = 0;
DS18B20 ds(9);
LiquidCrystal_I2C lcd(0x27, 16, 2);
pipe_t pipe(RELAY_PIN);
heater_mode_t heater_mode;
electro_heater_t electro_heater(heater_mode);
temp_range_t temp_range(HEATER_HYSTERESIS, HEATER_MIN_TEMP, HEATER_MAX_TEMP, POT_MIN_VALUE, POT_MAX_VALUE);
electro_regime_t electro_heating(temp_range, pipe, electro_heater);
coal_regime_t coal_heating(pipe, PIPE_LOW_TEMPERATURE, PIPE_HIGH_TEMPERATURE, electro_heater);


void on_press_button() {
  if (wait_tick == 0) {
    heater_mode.switch_mode();
    wait_tick = static_cast<int>(static_cast<float>(300)/static_cast<float>(REFRESH_PERIOD));
  }
}

void setup() {

  pipe.init();

  lcd.init();
  lcd.backlight();

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), on_press_button, FALLING);
}

void lcd_out(float current_temp) {
  lcd.setCursor(0, 0);
  
  lcd.print(String(current_temp, 1));
  lcd.print((char)223);
  
  lcd.setCursor(0, 1);
  lcd.print(String(temp_range.get_min_value()));
  lcd.print("-");
  lcd.print(String(temp_range.get_max_value()));
  lcd.print("  ");
  lcd.print(heater_mode.get_mode());
}


void loop() {

  ds.readSensor();
  float current_temp = ds.getTemperature_C();
  
  temp_range.set_pot_value(analogRead(TEMP_POT_PIN));

  abstract_regime_t & heater = heater_mode.is_on() ? static_cast<abstract_regime_t &>(electro_heating) : static_cast<abstract_regime_t &>(coal_heating);
  heater.process_temperature(current_temp);

  lcd_out(current_temp);

//  dtostrf(ds.getTemperature_C(), 4, 2, currentTemp);

  //sprintf(line1, "%5s C", String(ds.getTemperature_C(), 1).c_str());
  //lcd.setCursor(0, 0);
//  lcd.print(String(ds.getTemperature_C(), 1));
  //lcd.print(line1);

//  lcd.print(String(val-5));
//  lcd.print("-");
//  lcd.print(String(val));

  if (wait_tick > 0) {
    --wait_tick;
  };

  delay(REFRESH_PERIOD);
}
