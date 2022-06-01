#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "weather-forecast.h"
#include "weather-forecast.secret.h"

WeatherForecastClient::WeatherForecastClient() {}

TwoDaysWeatherForecasts WeatherForecastClient::getWeatherForecasts() {
  HTTPClient http;
  http.begin(API_OPENWEATHERMAP, root_ca);

  String message;
  message += F("Récupération de la météo");
  message += F(" (GET ");
  message += API_OPENWEATHERMAP;
  message += F(")");
  Serial.println(message);

  int httpCode;
  int retry = 0;

  do {
    httpCode = http.GET();
    retry ++;
    Serial.println("...");
  } while (httpCode <= 0 && retry < HTTP_RETRY);

  if (httpCode > 0) {
    Serial.println("OK");
    Serial.println("");

    String response = http.getString();
    http.end();
    DynamicJsonDocument doc(8192);
    DeserializationError error = deserializeJson(doc, response);
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return {{0, "", 0, 0}};
    }

    return {
      {
        doc["daily"][0]["dt"],
        doc["daily"][0]["weather"][0]["icon"],
        doc["daily"][0]["temp"]["min"],
        doc["daily"][0]["temp"]["max"]
      },
      {
        doc["daily"][1]["dt"],
        doc["daily"][1]["weather"][0]["icon"],
        doc["daily"][1]["temp"]["min"],
        doc["daily"][1]["temp"]["max"]
      }
    };

  } else {
    String error;
    error += F("KO -> code erreur = ");
    error += String(httpCode);
    Serial.println(error);
    Serial.println("");
    return {{0, "", 0, 0}};
  }
}
