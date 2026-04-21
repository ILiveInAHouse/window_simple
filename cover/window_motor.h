#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../window_simple.h"
#include "../window_simple_child.h"

namespace esphome {
namespace window_simple {

class WindowSimpleMotorClass : public WindowSimpleClient, public PollingComponent {
   public:
      void child_setup();
      void set_whichMotor(WhichMotorEnum whichMotor_) {
         this->whichMotor = whichMotor_;
      }
      WhichMotorEnum whichMotor;
      void update() override;
      void publish_info() override;
};
}
}