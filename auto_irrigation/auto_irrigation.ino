//Auto Irrigation
#include "RTClib.h"
#include <Wire.h>

//For Valve
#define RELAY_PIN 9


//For Soil Sensor
#define sensorPower 7
#define sensorPin A0

/*For Soil Sensor values
change according to the soil, check regularly*/
#define soilWet 500
#define soilDry 750


RTC_DS3231 rtc;

void setup() {
    Serial.begin(9600);
    pinMode(sensorPower, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    Wire.begin();
    rtc.begin();

    digitalWrite(sensorPower, LOW);
    digitalWrite(sensorPower, LOW);

    if (rtc.lostPower()) {
        Serial.println("RTC lost power, setting time to compile time");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

}

void loop() {
    Time t=timeRead();
    int hour=t.hour;
    int minute=t.minute;
    
    if (hour<6 || hour>18){
        Serial.println("Exempt Watering Time!");
        digitalWrite(RELAY_PIN,LOW);
    }
    else {
        int moisture = readSensor();
        Serial.print("Analog Output: ");
        Serial.println(moisture);

        if (moisture < soilWet) {
            Serial.println("Status: Soil is too wet");
        } else if (moisture >= soilWet && moisture < soilDry) {
            Serial.println("Status: Soil moisture is perfect");
        } else {
            digitalWrite(RELAY_PIN, HIGH);
            Serial.println("Status: Soil is too dry - time to water!");
            Serial.println("Pump is on!");
            delay(180000);
            digitalWrite(RELAY_PIN, LOW);
            Serial.println("Pump is off!");
        } 
    }

    Serial.println();
    delay(10000);
}

int readSensor() {
    digitalWrite(sensorPower, HIGH);
    delay(10);
    int val = analogRead(sensorPin);
    digitalWrite(sensorPower, LOW);
    return val;
}

struct Time
{
    int hour;
    int minute;
};

Time timeRead(){
    DateTime now=rtc.now();

    Time t;
    t.hour=now.hour();
    t.minute=now.minute();
    return t;
}