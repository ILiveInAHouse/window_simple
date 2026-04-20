import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import (
    CONF_ID,
)

CODEOWNERS = ["@ILiveInAHouse"]
DEPENDENCIES = []
AUTO_LOAD = [ ]

CONF_WINDOWCONTROLLER_ID = "windowcontroller_id"

window_simple_ns = cg.esphome_ns.namespace("window_simple")
WindowSimple = window_simple_ns.class_("WindowSimple", cg.PollingComponent)

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(WindowSimple),
        }
    )
    .extend(cv.polling_component_schema("5s"))
)

async def to_code(config):
    # Declare new component
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
