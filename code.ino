#define BLYNK_TEMPLATE_ID "TMPL3K_rOfGvz"
#define BLYNK_TEMPLATE_NAME "AirGard"
#define BLYNK_AUTH_TOKEN "FRTyHUPLwYP79-La_WqGSmQjlMeQ7tNr"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "priyanshu";
char pass[] = "12344321";

#define MQ2_AO A0
#define RELAY_PIN D5

bool manualOff = false;
bool alertSent = false;


// -------- BLYNK BUTTON V0 --------
BLYNK_WRITE(V0)
{
  int value = param.asInt();

  // Manual OFF
  if(value == 0)
  {
    manualOff = true;

    digitalWrite(RELAY_PIN, HIGH);

    Blynk.virtualWrite(V2, "MANUAL OFF");

    Serial.println("Manual OFF");
  }

  // Manual ON
  if(value == 1)
  {
    manualOff = false;

    Serial.println("Manual ON");
  }
}


// -------- GAS CHECK --------
void sendData()
{
  int gasValue = analogRead(MQ2_AO);

  Serial.println(gasValue);

  Blynk.virtualWrite(V1, gasValue);


  // If manually OFF, keep relay OFF
  if(manualOff)
  {
    digitalWrite(RELAY_PIN, HIGH);
    return;
  }


  // DANGER ZONE
  if(gasValue > 90)
  {
    digitalWrite(RELAY_PIN, HIGH); // OFF

    Blynk.virtualWrite(V2, "DANGEROUS");

    if(!alertSent)
    {
      Blynk.logEvent("gas_alert", "Warning! Gas Leakage Detected!");
      alertSent = true;
    }

    Serial.println("Danger - Relay OFF");
  }

  // MEDIUM ZONE
  else if(gasValue > 80)
  {
    alertSent = false;

    digitalWrite(RELAY_PIN, LOW); // ON

    Blynk.virtualWrite(V2, "MEDIUM");

    Serial.println("Medium - Relay ON");
  }

  // SAFE ZONE
  else
  {
    alertSent = false;

    digitalWrite(RELAY_PIN, LOW); // ON

    Blynk.virtualWrite(V2, "SAFE");

    Serial.println("Safe - Relay ON");
  }
}


void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);

  // Start relay ON
  digitalWrite(RELAY_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


void loop()
{
  Blynk.run();

  sendData();

  delay(1000);
}