#ifndef JEEDOM_H
#define JEEDOM_H

#include <Arduino.h>
#include <HTTPClient.h>

#define HTTP_RETRY 10

class Jeedom {
  private:
    unsigned int virtualId;
    TaskHandle_t taskUpdateValue;
  public:
    Jeedom();
    Jeedom(unsigned int virtualId);
    String getValue();
    void updateValue(String value);
    static void teeest(void *pvParameters);
};

struct JeedomTaskParameters {
  unsigned int virtualId;
  int value;
};

#endif
