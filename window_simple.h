#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"

// Namespace definition
namespace esphome {
namespace window_simple {

class WindowSimple : public PollingComponent {
  public:
    // Constructor
    // WindowSimple();
    
    // Standard component functions to override
    // void setup() override;
    void dump_config() override;
    // void update() override;
    // void on_safe_shutdown() override;
    // void on_shutdown() override;

    // This is called by the Python code to link the UI slider to this class
    void set_window_position_number(number::Number *n) {
      this->percentage_number_ = n;
      
      // Set up a callback: When the slider moves, run this lambda
      this->percentage_number_->add_on_state_callback([this](float value) {
        this->process_new_value(value);
      });
    }

    void process_new_value(float value) {
      ESP_LOGI("custom", "New percentage received: %.1f%%", value);
      // Logic: e.g., Update a PWM fan speed or a motor position
      this->current_internal_value_ = value;
    }
    
  protected:
    number::Number *percentage_number_{ nullptr };
    float current_internal_value_ = 0.0f;
    
};

} // namespace window_simple
} // namespace esphome