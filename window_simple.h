#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"

// Namespace definition
namespace esphome {
namespace window_simple {

// Create a non-abstract number class
class WindowPositionNumber : public number::Number {
 protected:
  void control(float value) override {
    this->publish_state(value);
    // You can also call a parent method here if you want
  }
};

class WindowSimpleHub : public PollingComponent {
  public:
    // Constructor
    // WindowSimple();
    
    // Standard component functions to override
    // void setup() override;
    void dump_config() override;
    void update() override;
    // void on_safe_shutdown() override;
    // void on_shutdown() override;

    // This is called by the Python code to link the UI slider to this class
    void set_window_position_number(WindowPositionNumber *n) {
      this->percentage_number_ = n;
    }

  protected:
    number::Number *percentage_number_{ nullptr };
    float current_internal_value_ = 0.0f;
    
};

} // namespace window_simple
} // namespace esphome