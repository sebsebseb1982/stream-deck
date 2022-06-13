#include "jeedom.h"
#include "jeedom.secret.h"

Jeedom::Jeedom() {
}

Jeedom::Jeedom(
  unsigned int virtualId
) {
  this->virtualId = virtualId;
}

String Jeedom::getValue() {
  String url;
  url += F("http://");
  url += JEEDOM_HOST;
  url += F("/core/api/jeeApi.php?apikey=");
  url += JEEDOM_API_KEY;
  url += F("&type=cmd&id=");
  url += String(virtualId);
  HTTPClient http;
  http.begin(url);

  /*http.setTimeout(100);
  http.setConnectTimeout(100);*/

  String message;
  message += F("Récupération du virtual ");
  message += String(virtualId);
  message += F(" (GET ");
  message += url;
  message += F(")");
  //Serial.println(message);

  int httpCode;
  int retry = 0;

  do {
    httpCode = http.GET();
    retry ++;
    //Serial.println("...");
  } while (httpCode <= 0 && retry < HTTP_RETRY);

  if (httpCode > 0) {
    String virtualValue = http.getString();

    String message;
    message += F("OK -> valeur = ");
    message += virtualValue;
    //Serial.println(message);
    //Serial.println("");
    http.end();
    return virtualValue;
  } else {
    String error;
    error += F("KO -> code erreur = ");
    error += String(httpCode);
    Serial.println(error);
    //Serial.println("");
    http.end();
    return "Erreur";
  }
}

void Jeedom::updateValue(String value) {
  String url;
  url += F("http://");
  url  += JEEDOM_HOST;
  url  += F("/core/api/jeeApi.php?plugin=virtual&apikey=");
  url  += JEEDOM_VIRTUAL_API_KEY;
  url  += F("&type=virtual&id=");
  url  += String(virtualId);
  url  += F("&value=");
  url  += value;
  HTTPClient http;
  http.begin(url);

  String message;
  message += F("Mise a jour du virtual ");
  message += String(virtualId);
  message += F(" (GET ");
  message += url;
  message += F(")");
  //Serial.println(message);

  int httpCode;
  int retry = 0;

  do {
    httpCode = http.GET();
    retry ++;
    //Serial.println("...");
  } while (httpCode <= 0 && retry < HTTP_RETRY);

  if (httpCode > 0) {
    //Serial.println("OK");
    //Serial.println("");
  } else {
    String error;
    error += F("KO -> code erreur = ");
    error += String(httpCode);
    //Serial.println(error);
    //Serial.println("");
  }
  http.end();
}
