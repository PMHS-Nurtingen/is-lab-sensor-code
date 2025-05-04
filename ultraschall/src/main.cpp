#include <Arduino.h>

const int triggerPin = 12;
const int echoPin = 13;

double speedOfSound = 0;

/*
 * Gibt die Schallgeschwindigkeit zurück. Die Schallgeschwindigkeit ist temperaturabhängig (je heißer, desto schneller).
 * Diese Funktion nutzt die lineare Näherungsformel c_Luft = (331,5 + 0,6v)m/s, wobei v die Temperatur ist und c die
 * Schallgeschwindigkeit in der Luft.
 * @param temperature: Temperatur in Grad Celsius
 * @return: Die Schallgeschwindigkeit in der Luft bei der angegebenen Temperatur
 */
double getSpeedOfSound(int temperatureCelsius) {
    return (331.5 + 0.6 * temperatureCelsius);
}


void setup() {
    speedOfSound = getSpeedOfSound(20);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println("---- Neue Messung");
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    unsigned long duration = pulseIn(echoPin, HIGH) / 2;  // in Mikrosekunden(µs); Durch 2 weil nur einfache Zeit nötig
    float durationS = (float) duration / 1000000; // 1 s = 1.000.000 µs
    if (duration == 0) {
        Serial.println("Fehler in der Messung");
    }

    Serial.print("Dauer 1-Strecke in Mikrosekunden: ");
    Serial.println(duration);
    Serial.print("Dauer 1-Strecke in Sekunden: ");
    Serial.println(durationS, 7);
    Serial.print("Schallgeschwindigkeit (m/s): ");
    Serial.println(speedOfSound);
    Serial.print("Distanz: ");
    Serial.print(durationS * speedOfSound * 100); // 1m = 100cm
    Serial.println(" cm");

    delay(1000); // Nur 1 Scan pro Sekunde
}