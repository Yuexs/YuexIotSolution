#Created by VisualGDB. Right-click on the component in Solution Explorer to edit properties using convenient GUI.

# componet standalone mode
ifndef CONFIG_IOT_SOLUTION_EMBED   

COMPONENT_ADD_INCLUDEDIRS := ./status_led/include
COMPONENT_SRCDIRS := ./status_led

else

ifdef CONFIG_IOT_LED_ENABLE
COMPONENT_ADD_INCLUDEDIRS := ./status_led/include
COMPONENT_SRCDIRS := ./status_led
else
# Disable component
COMPONENT_ADD_INCLUDEDIRS :=
COMPONENT_ADD_LDFLAGS :=
COMPONENT_SRCDIRS :=
endif

endif