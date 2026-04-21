#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "window_simple_child.h"

// Namespace definition
namespace esphome {
namespace window_simple {

enum WhichMotorEnum { MOTOR_NONE = 0, MOTOR_A = 1, MOTOR_B = 2 };

// Forward declaration so the Number knows the Hub exists
class WindowSimpleHub;
class WindowControllerClient;

// Create a non-abstract number class
class WindowPositionNumber : public number::Number {
public:
  // Store a pointer to the parent hub
  void set_parent(WindowSimpleHub *parent) { this->parent_ = parent; }
protected:
  WindowSimpleHub *parent_;

  void control(float value) override;
};

class WindowSimpleHub : public PollingComponent {
  public:
    // Constructor
    // WindowSimple();
    
    // Standard component functions to override
    void setup() override;
    void dump_config() override;
    void update() override;
    // void on_safe_shutdown() override;
    // void on_shutdown() override;
    void print_number_change(float new_n);
    void publish_info();
  
    // This is called by the Python code to link
    //   the UI slider to this class
    void set_window_position_number(WindowPositionNumber *n) {
      this->percentage_number_ = n;
      // Tell the child who its parent is
      this->percentage_number_->set_parent(this);

      // Instead of a parent pointer, you can register a callback that
      //   runs the parent's method
      // this->percentage_number_->add_on_state_callback([this](float value) {
      //     this->on_slider_changed(value);
      // });
    }
    void register_child(WindowSimpleClient *obj);

  protected:
    std::vector<WindowSimpleClient *> children_;
    WindowPositionNumber *percentage_number_{ nullptr };
    
};

} // namespace window_simple
} // namespace esphome