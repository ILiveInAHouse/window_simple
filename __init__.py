import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import (
    CONF_ID,
)

CODEOWNERS = ["@ILiveInAHouse"]
DEPENDENCIES = []
AUTO_LOAD = [ ]

CONF_WINDOWSIMPLE_ID = "window_simple_id"

window_simple_ns = cg.esphome_ns.namespace("window_simple")
WindowSimpleHub = window_simple_ns.class_("WindowSimpleHub", cg.PollingComponent)

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(WindowSimpleHub),
        }
    )
    .extend(cv.polling_component_schema("5s"))
)

WINDOWSIMPLE_CLIENT_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_WINDOWSIMPLE_ID): cv.use_id(WindowSimpleHub),
    }
)

async def register_windowsimple_child(var, config):
    parent = await cg.get_variable(config[CONF_WINDOWSIMPLE_ID])
    cg.add(parent.register_child(var))

async def to_code(config):
    # Declare new component
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
