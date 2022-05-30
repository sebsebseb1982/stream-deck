#include "widget-button-callback.h"
#include "jeedom.h"

void increment(int virtualId) {
  Jeedom jeedom(virtualId);
  float value = jeedom.getValue().toFloat();
  jeedom.updateValue(String(value + 1));
}


void decrement(int virtualId) {
  Jeedom jeedom(virtualId);
  float value = jeedom.getValue().toFloat();
  jeedom.updateValue(String(value - 1));
}

void setToOne(int virtualId) {
  Jeedom jeedom(virtualId);
  jeedom.updateValue("1");
}
