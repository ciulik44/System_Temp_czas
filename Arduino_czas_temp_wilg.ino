/*
  PLIKI AUDIO
  1-16 - TEMPERATURA ZAKRES 15-30 STOPNI
  17-31 - WAGA ZAKRES 1-15 KILOGRAMÓW
  32-62 - DNI
  63-75 - MIESIACE
  76-81 - ROK (2023-2028)
  82-106 - GODZINY
  107-167 - MINUTY
*/
 
//data-15
//reset-2
//clk-6
 
 
#define BUTTON_T 3
#define BUTTON_W 4
#define BUTTON_C 5
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <virtuabotixRTC.h>
#include <SimpleDHT.h>
 #include <SoftwareSerial.h>
#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
 
SoftwareSerial softSerial(/*rx =*/10,/*tx =*/11);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif
 
 
//---------------------------------------------------//
//-----------------ZMIENNE GLOBALNE-----------------//
 
unsigned long currentTime = 0;
unsigned long savedTime = 0;
int pinDHT11 = 2;
int pinDHT11_2 = 9;
char weight;
 
 
 
//---------------------------------------------------//
 
SimpleDHT11 dht11(pinDHT11);
SimpleDHT11 dht12(pinDHT11_2);
 
DFRobotDFPlayerMini myDFPlayer;
virtuabotixRTC myRTC(6, 7, 8); //piny RTC!!!!!!!!!!
 
void printDetail(uint8_t type, int value);
 
 
void DFPlayerInit()
{
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(100); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);
}
 
 
void MeasureTemp()
{
  // start working...
  //Serial.println("=================================");
  //Serial.println("Sample DHT11...");
 
  // read without samples.
 
  byte temperature = 0;
  byte humidity = 0;
 int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
 
 
byte temperature_2 = 0;
  byte humidity_2 = 0;
 
  if ((err = dht11.read(&temperature_2, &humidity_2, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 sensor outdoor failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
 
 // Serial.print("Sample OK: ");
  //Serial.print((int)temperature); Serial.print(" *C, ");
  //Serial.print((int)humidity); Serial.println(" H");
 
  // DHT11 sampling rate is 1HZ.
 
  if (digitalRead(BUTTON_T)!=HIGH)
  {
   Serial.println("temperatura wewnatrz");
   Serial.print((int)temperature); Serial.print(" *C, ");
  //Serial.print((int)humidity); Serial.println(" H");
 
    Serial.println("temperatura na zewnatrz");
 Serial.print((int)temperature_2); Serial.print(" *C, ");
  //Serial.print((int)humidity_2); Serial.println(" H");
 
 
 
    switch (temperature)
    {
      case 15:
        myDFPlayer.play(14);
 
      myDFPlayer.play(84);
 
        break;
      case 16:
       myDFPlayer.play(15);
 
      myDFPlayer.play(84);
        break;
      case 17:
         myDFPlayer.play(16);
 
      myDFPlayer.play(84);
        break;
      case 18:
       myDFPlayer.play(17);
 
      myDFPlayer.play(84);
        break;
      case 19:
         myDFPlayer.play(18);
 
      myDFPlayer.play(84);
        break;
      case 20:
         myDFPlayer.play(19);
 
      myDFPlayer.play(84);
        break;
      case 21:
        myDFPlayer.play(20);
 
      myDFPlayer.play(84);
 
        break;
      case 22:
         myDFPlayer.play(21);
 
      myDFPlayer.play(84);
        break;
      case 23:
         myDFPlayer.play(22);
 
      myDFPlayer.play(84);
        break;
      case 24:
         myDFPlayer.play(23);
 
      myDFPlayer.play(84);
        break;
      case 25:
        myDFPlayer.play(24);
 
      myDFPlayer.play(84);
        break;
      case 26:
        myDFPlayer.play(25);
 
      myDFPlayer.play(84);
        break;
      case 27:
        myDFPlayer.play(26);
 
      myDFPlayer.play(84);
        break;
      case 28:
        myDFPlayer.play(27);
 
      myDFPlayer.play(84);
        break;
      case 29:
         myDFPlayer.play(28);
 
      myDFPlayer.play(84);
 
        break;
      case 30:
         myDFPlayer.play(29);
 
      myDFPlayer.play(84);
        break;
    }
 
        delay(2000);
      switch (temperature_2)
    {
      case 15:
        myDFPlayer.play(14);
 
      myDFPlayer.play(84);
        break;
      case 16:
       myDFPlayer.play(15);
 
      myDFPlayer.play(84);
        break;
      case 17:
         myDFPlayer.play(16);
 
      myDFPlayer.play(84);
        break;
      case 18:
       myDFPlayer.play(17);
 
      myDFPlayer.play(84);
        break;
      case 19:
         myDFPlayer.play(18);
 
      myDFPlayer.play(84);
        break;
      case 20:
         myDFPlayer.play(19);
 
      myDFPlayer.play(84);
        break;
      case 21:
        myDFPlayer.play(20);
 
      myDFPlayer.play(84);
 
        break;
      case 22:
         myDFPlayer.play(21);
 
      myDFPlayer.play(84);
        break;
      case 23:
         myDFPlayer.play(22);
 
      myDFPlayer.play(84);
        break;
      case 24:
         myDFPlayer.play(23);
 
      myDFPlayer.play(84);
        break;
      case 25:
        myDFPlayer.play(24);
 
      myDFPlayer.play(84);
        break;
      case 26:
        myDFPlayer.play(30);
 
      myDFPlayer.play(84);
        break;
      case 27:
        myDFPlayer.play(26);
 
      myDFPlayer.play(84);
        break;
      case 28:
        myDFPlayer.play(27);
 
      myDFPlayer.play(84);
        break;
      case 29:
         myDFPlayer.play(28);
 
      myDFPlayer.play(84);
 
        break;
      case 30:
         myDFPlayer.play(29);
 
      myDFPlayer.play(84);
        break;
    }
 
 
 
 
 
  }
 
}
 
 
void MeasureWeight()
{
 
    weight = Serial.read();
    Serial.println(weight);
    delay(1000);
 
 
 
  if (digitalRead(BUTTON_W)!=HIGH)
  {
 
  Serial.println("waga = ");
  Serial.println(weight);
 
    if (weight == '1') 
    {
          myDFPlayer.play(83);
 
    }
 
    if (weight == '2') 
    {
          myDFPlayer.play(1);
          myDFPlayer.play(83);
    }
 
    if (weight == '3') 
    {
          myDFPlayer.play(2);
          myDFPlayer.play(83);
    }
 
    if (weight == '4') 
    {
          myDFPlayer.play(3);
          myDFPlayer.play(83);
    }
 
    if (weight == '5') 
    {
          myDFPlayer.play(4);
          myDFPlayer.play(83);
    }
 
    if (weight == '6') 
    {
          myDFPlayer.play(5);
          myDFPlayer.play(83);
    }
 
    if (weight == '7') 
    {
          myDFPlayer.play(6);
          myDFPlayer.play(83);
    }
 
    if (weight == '8') 
    {
          myDFPlayer.play(7);
          myDFPlayer.play(83);
    }
 
    if (weight == '9') 
    {
          myDFPlayer.play(8);
          myDFPlayer.play(83);
    }
 
    if (weight == '10') 
    {
          myDFPlayer.play(9);
          myDFPlayer.play(83);
    }
 
  }
}
 
 
 
void RTC_read()
{
 
  myRTC.updateTime();
  delay(1000);
 
 
}
 
void RTC_init()
  {
   myRTC.setDS1302Time(00, 40, 9, 4, 15, 9, 2023); 
  }
 
void RTC_switch()
{
 
  currentTime = millis();
  if (currentTime - savedTime >= 1000UL)
  {
    savedTime = currentTime;
  }
 
 
if (digitalRead(BUTTON_C)!= HIGH)
  {
 Serial.println("data i godzina");
  //Serial.print("/");
 Serial.println(myRTC.dayofmonth);
   Serial.print("/");
 Serial.print(myRTC.month);
   Serial.print("/");  
 Serial.print(myRTC.year);
   Serial.print("  ");    
 Serial.print(myRTC.hours);
   Serial.print(":"); 
 Serial.print(myRTC.minutes); 
  Serial.print(":");   
  Serial.print(myRTC.seconds); 
  Serial.print("  ");   
    switch (myRTC.dayofmonth)
    {
      case 1:
        myDFPlayer.play(99);
        break;
      case 2:
        myDFPlayer.play(100);
        break;
      case 3:
        myDFPlayer.play(101);
        break;
      case 4:
        myDFPlayer.play(102);
        break;
      case 5:
        myDFPlayer.play(103);
        break;
      case 6:
        myDFPlayer.play(104);
        break;
      case 7:
        myDFPlayer.play(105);
        break;
      case 8:
        myDFPlayer.play(106);
        break;
      case 9:
        myDFPlayer.play(107);
        break;
      case 10:
        myDFPlayer.play(108);
        break;
      case 11:
        myDFPlayer.play(109);
        break;
      case 12:
        myDFPlayer.play(110);
        break;
      case 13:
        myDFPlayer.play(111);
        break;
      case 14:
        myDFPlayer.play(112);
        break;
      case 15:
        myDFPlayer.play(113);
        break;
      case 16:
        myDFPlayer.play(114);
        break;
      case 17:
        myDFPlayer.play(115);
        break;
      case 18:
        myDFPlayer.play(116);
        break;
      case 19:
        myDFPlayer.play(117);
        break;
      case 20:
        myDFPlayer.play(118);
        break;
      case 21:
        myDFPlayer.play(119);
        break;
      case 22:
        myDFPlayer.play(120);
        break;
      case 23:
        myDFPlayer.play(121);
        break;
      case 24:
        myDFPlayer.play(122);
        break;
      case 25:
        myDFPlayer.play(123);
        break;
      case 26:
        myDFPlayer.play(124);
        break;
      case 27:
        myDFPlayer.play(125);
        break;
      case 28:
        myDFPlayer.play(126);
        break;
      case 29:
        myDFPlayer.play(127);
        break;
      case 30:
        myDFPlayer.play(128);
        break;
       case 31:
        myDFPlayer.play(129);
        break;
 
 
    }
//-------------------------------------------------------------------//
//-------DO ZROBIENIA INSTRUKCJA SWITCH CASE DLA: M,Y,H,M)-----------//
 delay(1000);
switch (myRTC.month)
    {
   case 1:
        myDFPlayer.play(85);
        break;
      case 2:
        myDFPlayer.play(86);
        break;
      case 3:
        myDFPlayer.play(87);
        break;
      case 4:
        myDFPlayer.play(88);
        break;
      case 5:
        myDFPlayer.play(89);
        break;
      case 6:
        myDFPlayer.play(90);
        break;
      case 7:
        myDFPlayer.play(91);
        break;
      case 8:
        myDFPlayer.play(92);
        break;
      case 9:
        myDFPlayer.play(93);
        break;
      case 10:
        myDFPlayer.play(94);
        break;
      case 11:
        myDFPlayer.play(95);
        break;
      case 12:
        myDFPlayer.play(96);
        break;
    }
 
delay(1000);
  switch (myRTC.year)
    {
  case 2023:
        myDFPlayer.play(97);
        break;
}
 
 delay(2500);
  switch (myRTC.hours)
    {
  case 1:
        myDFPlayer.play(60);
        break;
      case 2:
        myDFPlayer.play(61);
        break;
      case 3:
        myDFPlayer.play(62);
        break;
      case 4:
        myDFPlayer.play(63);
        break;
      case 5:
        myDFPlayer.play(64);
        break;
      case 6:
        myDFPlayer.play(65);
        break;
      case 7:
        myDFPlayer.play(66);
        break;
      case 8:
        myDFPlayer.play(67);
        break;
      case 9:
        myDFPlayer.play(68);
        break;
      case 10:
        myDFPlayer.play(69);
        break;
      case 11:
        myDFPlayer.play(70);
        break;
      case 12:
        myDFPlayer.play(71);
        break;
  case 13:
        myDFPlayer.play(72);
        break;
      case 14:
        myDFPlayer.play(73);
        break;
      case 15:
        myDFPlayer.play(74);
        break;
      case 16:
        myDFPlayer.play(75);
        break;
      case 17:
        myDFPlayer.play(76);
        break;
      case 18:
        myDFPlayer.play(77);
        break;
      case 19:
        myDFPlayer.play(78);
        break;
      case 20:
        myDFPlayer.play(79);
        break;
      case 21:
        myDFPlayer.play(80);
        break;
      case 22:
        myDFPlayer.play(81);
        break;
      case 23:
        myDFPlayer.play(82);
        break;
      case 24: // "00"
        myDFPlayer.play(83);
        break;
    }
 
delay(1000);
  switch (myRTC.minutes)
    {
  case 1:
        myDFPlayer.play(132);
        break;
      case 2:
        myDFPlayer.play(1);
        break;
      case 3:
        myDFPlayer.play(2);
        break;
      case 4:
        myDFPlayer.play(3);
        break;
      case 5:
        myDFPlayer.play(4);
        break;
      case 6:
        myDFPlayer.play(5);
        break;
      case 7:
        myDFPlayer.play(6);
        break;
      case 8:
        myDFPlayer.play(7);
        break;
      case 9:
        myDFPlayer.play(8);
        break;
      case 10:
        myDFPlayer.play(9);
        break;
      case 11:
        myDFPlayer.play(10);
        break;
      case 12:
        myDFPlayer.play(11);
        break;
  case 13:
        myDFPlayer.play(12);
        break;
      case 14:
        myDFPlayer.play(13);
        break;
      case 15:
        myDFPlayer.play(14);
        break;
      case 16:
        myDFPlayer.play(15);
        break;
      case 17:
        myDFPlayer.play(16);
        break;
      case 18:
        myDFPlayer.play(17);
        break;
      case 19:
        myDFPlayer.play(18);
        break;
      case 20:
        myDFPlayer.play(19);
        break;
      case 21:
        myDFPlayer.play(20);
        break;
      case 22:
        myDFPlayer.play(21);
        break;
      case 23:
        myDFPlayer.play(22);
        break;
      case 24:
        myDFPlayer.play(23);
        break;
  case 25:
        myDFPlayer.play(24);
        break;
      case 26:
        myDFPlayer.play(25);
        break;
      case 27:
        myDFPlayer.play(26);
        break;
      case 28:
        myDFPlayer.play(27);
        break;
      case 29:
        myDFPlayer.play(28);
        break;
      case 30:
        myDFPlayer.play(29);
        break;
      case 31:
        myDFPlayer.play(30);
        break;
      case 32:
        myDFPlayer.play(31);
        break;
      case 33:
        myDFPlayer.play(32);
        break;
      case 34:
        myDFPlayer.play(33);
        break;
      case 35:
        myDFPlayer.play(34);
        break;
      case 36:
        myDFPlayer.play(35);
        break;
  case 37:
        myDFPlayer.play(36);
        break;
      case 38:
        myDFPlayer.play(37);
        break;
      case 39:
        myDFPlayer.play(38);
        break;
      case 40:
        myDFPlayer.play(39);
        break;
      case 41:
        myDFPlayer.play(40);
        break;
      case 42:
        myDFPlayer.play(41);
        break;
      case 43:
        myDFPlayer.play(42);
        break;
      case 44:
        myDFPlayer.play(43);
        break;
      case 45:
        myDFPlayer.play(44);
        break;
      case 46:
        myDFPlayer.play(45);
        break;
      case 47:
        myDFPlayer.play(46);
        break;
      case 48:
        myDFPlayer.play(47);
        break;
  case 49:
        myDFPlayer.play(48);
        break;
      case 50:
        myDFPlayer.play(49);
        break;
      case 51:
        myDFPlayer.play(50);
        break;
      case 52:
        myDFPlayer.play(51);
        break;
      case 53:
        myDFPlayer.play(52);
        break;
      case 54:
        myDFPlayer.play(53);
        break;
      case 55:
        myDFPlayer.play(54);
        break;
      case 56:
        myDFPlayer.play(55);
        break;
      case 57:
        myDFPlayer.play(56);
        break;
      case 58:
        myDFPlayer.play(57);
        break;
      case 59:
        myDFPlayer.play(58);
        break;
 
       }
 
//---------------------------SWITCH CASE END-------------------------//
  }
 
 
}
 
 
void setup()
{
 
#if (defined ESP32)
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
#else
  FPSerial.begin(9600);
#endif
 
  Serial.begin(9600);
  DFPlayerInit();
  RTC_init();
  pinMode(BUTTON_T, INPUT_PULLUP);
  pinMode(BUTTON_W, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
 
 
}
 
 
 
void loop() {
  RTC_read();
  RTC_switch();
 MeasureTemp();
  MeasureWeight();
}