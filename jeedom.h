#ifndef JEEDOM_H
#define JEEDOM_H

#include <Arduino.h>
#include <HTTPClient.h>

#define HTTP_RETRY 10

class Jeedom {
  private:
    unsigned int virtualId;
  public:
    Jeedom();
    Jeedom(unsigned int virtualId);
    String getValue();
    void updateValue(String value);
};

#endif
