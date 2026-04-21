# windowController
Motorized windows: controller running 1 or 2 windowMotors

```yaml
# example configuration:
window_simple:
  id: window_simple_hub_id

number:
  - platform: window_simple
    window_simple_id: window_simple_hub_id
    name: "Hub Position"
    unit_of_measurement: "%"
    icon: "mdi:gauge"
    mode: SLIDER

cover:
  - platform: window_simple
    window_simple_id: window_simple_hub_id
    # device_class: window
    which_motor: MOTOR_A
  - platform: window_simple
    window_simple_id: window_simple_hub_id
    # device_class: window
    which_motor: MOTOR_B
```