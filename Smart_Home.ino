#define BLYNK_TEMPLATE_ID "TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "AUTH_TOKEN"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
char ssid[] = "WIFI";
char pass[] = "PASSWORD";
#define SS_PIN 5
#define RST_PIN 22
MFRC522 rfid(SS_PIN, RST_PIN);
Servo door;
const int ledPin = 2;
const int fanPin = 27;
const int ledChannel = 0;
const int fanChannel = 1;
byte card[4] = {0xA3,0x6F,0x22,0x15};
void setup()
{
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  door.attach(14);
  door.write(0);
  ledcSetup(ledChannel,5000,8);
  ledcAttachPin(ledPin,ledChannel);
  ledcSetup(fanChannel,5000,8);
  ledcAttachPin(fanPin,fanChannel);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
}
BLYNK_WRITE(V0)
{
  int brightness = param.asInt();
  ledcWrite(ledChannel,brightness);
}
BLYNK_WRITE(V1)
{
  int speed = param.asInt();
  ledcWrite(fanChannel,speed);
}
BLYNK_WRITE(V2)
{
  if(param.asInt()==1)
  {
    openDoor();
  }
}
void loop()
{
  Blynk.run();
  if(!rfid.PICC_IsNewCardPresent())
    return;
  if(!rfid.PICC_ReadCardSerial())
    return;
  bool ok = true;
  for(int i=0;i<4;i++)
  {
    if(rfid.uid.uidByte[i]!=card[i])
      ok=false;
  }
  if(ok)
  {
    Serial.println("Access Granted");
    openDoor();
  }
  else
  {
    Serial.println("Access Denied");
  }
  rfid.PICC_HaltA();
}
void openDoor()
{
  door.write(90);
  delay(3000);
  door.write(0);
}
