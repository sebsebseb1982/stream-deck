#define LEAP_YEAR(Y)     ( (Y>0) && !(Y%4) && ( (Y%100) || !(Y%400) ) )

void setupTime() {
  timeClient.begin();
  timeClient.update();
}

DateTime getDateTime() {
  unsigned long rawTime = timeClient.getEpochTime() / 86400L;  // in days
  unsigned long days = 0, year = 1970;
  uint8_t month;
  static const uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  while ((days += (LEAP_YEAR(year) ? 366 : 365)) <= rawTime)
    year++;
  rawTime -= days - (LEAP_YEAR(year) ? 366 : 365); // now it is days in this year, starting at 0
  days = 0;
  for (month = 0; month < 12; month++) {
    uint8_t monthLength;
    if (month == 1) { // february
      monthLength = LEAP_YEAR(year) ? 29 : 28;
    } else {
      monthLength = monthDays[month];
    }
    if (rawTime < monthLength) break;
    rawTime -= monthLength;
  }

  return {
    year,
    month + 1,
    rawTime + 1,
    timeClient.getHours(),
    timeClient.getMinutes(),
    timeClient.getSeconds()
  };
}

String getFormattedDateDDMM(DateTime dateTime) {
  String formattedDate;
  if (dateTime.day < 10) {
    formattedDate += F("0");
  }
  formattedDate += String(dateTime.day);

  formattedDate += F("/");
  if (dateTime.month < 10) {
    formattedDate += F("0");
  }
  formattedDate += String(dateTime.month);
  /*
    formattedDate += F("/");
    formattedDate += dateTime.year;
  */
  return formattedDate;
}


String getFormattedTime(DateTime dateTime) {
  String formattedTime;
  if (dateTime.hours < 10) {
    formattedTime += F("0");
  }
  formattedTime += dateTime.hours;
  formattedTime += F(":");
  if (dateTime.minutes < 10) {
    formattedTime += F("0");
  }
  formattedTime += dateTime.minutes;

  return formattedTime;
}
