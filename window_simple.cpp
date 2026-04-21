#include "esphome/core/log.h"
#include "esphome/core/hal.h"
#include "window_simple.h"

namespace esphome {
namespace window_simple {

static const char *TAG = "window_simple_component";

void WindowPositionNumber::control(float value) {
    this->publish_state(value);
    // You can also call a parent method here if you want
    if (this->parent_ != nullptr) {
        this->parent_->print_number_change(value);
    }
}

void WindowSimpleHub::update() {
}

void WindowSimpleHub::setup() {
    // each component type (sensor, fan, etc) is a new child
    // each component type's device_id specified in the .yaml is a new child
    for (auto *child : this->children_) {
        child->child_setup();
    }
}

// Called once after booting and then each time a new client connects
//   to monitor logs
void WindowSimpleHub::dump_config() {
    ESP_LOGCONFIG(TAG, "WindowSimple:");
    LOG_UPDATE_INTERVAL(this);
}

void WindowSimpleHub::print_number_change(float new_n) {
    ESP_LOGI(TAG, "new_n=%f", new_n);
}
}
}