#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../window_controller.h"
#include "../window_controller_child.h"

namespace esphome {
namespace window_simple {

class WindowSimpleChildClass : public WindowSimpleClient, public PollingComponent {
   public:
      void child_setup();
   protected:
}
}
}