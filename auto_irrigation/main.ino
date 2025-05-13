//Auto Irrigation

//For Relay motor
#define RELAY_PIN 9

//For RTC module


//For Soil Sensor
#define sensorPower 7
#define sensorPin A0

//For Soil Sensor values
#define soilWet 500
#define soilDry 750

void setup() {
    Serial.begin(9600);
    pinMode(sensorPower, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    digitalWrite(sensorPower, LOW);
    digitalWrite(sensorPower, LOW);

}

void loop() {
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
        delay(60000); //for 60 seconds (change accordingly)
        digitalWrite(RELAY_PIN, LOW);
        Serial.println("Pump is off!");
        delay(4000); 
    }

    Serial.println();
    delay(5000);
}

int readSensor() {
    digitalWrite(sensorPower, HIGH);
    delay(10);
    int val = analogRead(sensorPin);
    digitalWrite(sensorPower, LOW);
    return val;
}
