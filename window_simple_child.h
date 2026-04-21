#pragma once

#include "esphome/core/helpers.h"

namespace esphome {
namespace window_simple {

// Forward declare WindowControllerHub
class WindowSimpleHub;

class WindowSimpleClient : public Parented<WindowSimpleHub> {
 public:
//   virtual void on_status(const BedjetStatusPacket *data) = 0;
//   virtual void on_bedjet_state(bool is_ready) = 0;
  virtual void child_setup() = 0;
  virtual void publish_info() = 0;

 protected:
  friend WindowSimpleHub;
//   virtual std::string describe() = 0;
};

}  // namespace window_controller
}  // namespace esphome
