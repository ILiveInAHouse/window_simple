import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.components import number
from esphome.const import CONF_ID

CODEOWNERS = ["@ILiveInAHouse"]
DEPENDENCIES = []
AUTO_LOAD = [ ]
MULTI_CONF = False

from esphome.components.window_simple import WindowSimpleHub, window_simple_ns
WindowPositionNumber = window_simple_ns.class_("WindowPositionNumber", number.Number)

# Key for the parent ID in YAML
CONF_WINDOW_SIMPLE_ID = "window_simple_id"

# CONFIG_SCHEMA = number.number_schema.extend({
#     cv.GenerateID(): cv.declare_id(number.Number), # We use the standard Number class
#     cv.GenerateID(CONF_WINDOW_CONTROLLER_ID): cv.use_id(WindowController),
# }).extend(cv.COMPONENT_SCHEMA)
CONFIG_SCHEMA = (
    number.number_schema(WindowPositionNumber)
    .extend({
        cv.GenerateID(CONF_WINDOW_SIMPLE_ID): cv.use_id(WindowSimpleHub),
    })
    .extend(cv.COMPONENT_SCHEMA)
)

async def to_code(config):
    # Find the parent component
    parent = await cg.get_variable(config[CONF_WINDOW_SIMPLE_ID])
    var = cg.new_Pvariable(config[CONF_ID]) # Manually create the specific class
    await number.register_number(var, config, min_value=0, max_value=100, step=1)
    # # Create the number entity (the limb)
    # var = await number.new_number(
    #     config, 
    #     min_value=0, 
    #     max_value=100, 
    #     step=1
    # )

    # Give the pointer to the parent
    cg.add(parent.set_window_position_number(var))