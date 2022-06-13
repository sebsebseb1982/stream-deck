#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

class Clock {
  private:
    static WiFiUDP ntpUDP;
    static NTPClient ntpClient;
    static unsigned long startMillis;
    static unsigned long currentMillis;
    static int getDay();
    static int getMonth();
  public:
    static String date;
    static String time;
    static void setup();
    static void loop();
};

#endif
