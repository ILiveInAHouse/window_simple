#include "esphome/core/log.h"
#include "esphome/core/hal.h"
#include "window_simple.h"

namespace esphome {
namespace window_simple {

static const char *TAG = "window_simple_component";

void WindowSimpleHub::update() {
}

// Called once after booting and then each time a new client connects
//   to monitor logs
void WindowSimpleHub::dump_config() {
    ESP_LOGCONFIG(TAG, "WindowSimple:");
    LOG_UPDATE_INTERVAL(this);
}

}
}