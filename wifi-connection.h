#include <Arduino.h>

class WiFiConnection {
  public:
    static unsigned int nbConnection;
    static void connect();
    static void loop();
};
