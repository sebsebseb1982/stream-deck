#include "duration.h"
#include "clock.h"

String Clock::date = "";
String Clock::time = "";
WiFiUDP Clock::ntpUDP;
NTPClient Clock::ntpClient;
unsigned long Clock::startMillis = -THIRTHY_SECONDS;
unsigned long Clock::currentMillis = 0;

void Clock::setup() {
  // https://github.com/arduino-libraries/NTPClient/issues/1
  // J'ai ajouté un constructeur par défaut dans la lib
  ntpClient = NTPClient(
                ntpUDP,
                "europe.pool.ntp.org",
                3600,
                60000
              );
  ntpClient.begin();
  loop();
}

void Clock::loop() {
  currentMillis = millis();
  if (currentMillis - startMillis >= THIRTHY_SECONDS) {
    ntpClient.update();

    String formattedTime;
    if (ntpClient.getHours() < 10) {
      formattedTime += F("0");
    }
    formattedTime += ntpClient.getHours();
    formattedTime += F(":");
    if (ntpClient.getMinutes() < 10) {
      formattedTime += F("0");
    }
    formattedTime += ntpClient.getMinutes();
    time = formattedTime ;

    String formattedDate;
    if (Clock::getDay() < 10) {
      formattedDate += F("0");
    }
    formattedDate += Clock::getDay();
    formattedDate += F("/");
    if (Clock::getMonth() < 10) {
      formattedDate += F("0");
    }
    formattedDate += Clock::getMonth();
    date = formattedDate ;

    startMillis = currentMillis;
  }
}


// https://github.com/arduino-libraries/NTPClient/pull/161/files
int Clock::getDay() {
  long days = ntpClient.getEpochTime()  / 86400L;
  int fullYears = days / 365;
  int overDays = days % 365;

  int leapYears = (fullYears - 2) / 4;
  if (leapYears > overDays) {
    fullYears--;
  }

  int currentYear = 1970 + fullYears;

  int thisYearIsLeap = currentYear % 4 == 0 ? 1 : 0;

  int dayOfYear = (days - leapYears) % ( 365 + thisYearIsLeap);
  if (dayOfYear == 0) {
    dayOfYear = 365 + thisYearIsLeap;
  }

  int daysInMonth[12] = {31, 28 + thisYearIsLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for ( int month = 0; month < 12; month++) {
    if (dayOfYear < daysInMonth[month]) {
      return dayOfYear;
    } else {
      dayOfYear -= daysInMonth[month];
    }
  }

  return -1;
}

int Clock::getMonth() {

  long days = ntpClient.getEpochTime()  / 86400L;
  int fullYears = days / 365;
  int overDays = days % 365;

  int leapYears = (fullYears - 2) / 4;
  if (leapYears > overDays) {
    fullYears--;
  }

  int currentYear = 1970 + leapYears;

  int thisYearIsLeap = currentYear % 4 == 0 ? 1 : 0;

  int dayOfYear = (days - leapYears) % ( 365 + thisYearIsLeap);
  if (dayOfYear == 0) {
    dayOfYear = 365 + thisYearIsLeap;
  }

  int daysInMonth[12] = {31, 28 + thisYearIsLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for ( int month = 0; month < 12; month++) {
    if (dayOfYear < daysInMonth[month]) {
      return month + 1;
    } else {
      dayOfYear -= daysInMonth[month];
    }
  }

  return -1;
}
