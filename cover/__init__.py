import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    ENTITY_CATEGORY_DIAGNOSTIC,
    STATE_CLASS_MEASUREMENT,
)

from .. import WINDOWSIMPLE_CLIENT_SCHEMA, window_simple_ns, register_windowsimple_child

AUTO_LOAD = []
DEPENDENCIES = ["window_simple"]

CONF_WINDOW_NUMBER = "window_number"
CONF_FAULTS = "faults"
CONF_WHICH_MOTOR = "which_motor"

WindowSimpleMotorClass = window_simple_ns.class_(
    "WindowSimpleMotorClass", cg.PollingComponent
)

WhichMotor = window_simple_ns.enum("WhichMotorEnum")
MOTOR_ENUMS = {
    "MOTOR_NONE": WhichMotor.MOTOR_NONE,
    "MOTOR_A": WhichMotor.MOTOR_A,
    "MOTOR_B": WhichMotor.MOTOR_B,
}

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(WindowSimpleMotorClass),
        cv.Required(CONF_WHICH_MOTOR): cv.enum(MOTOR_ENUMS, upper=True, space="_"),
    }
#    .extend(cv.polling_component_schema("5s"))
) .extend(WINDOWSIMPLE_CLIENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await register_windowsimple_child(var, config)
    cg.add(var.set_whichMotor(config[CONF_WHICH_MOTOR]))
