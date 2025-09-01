#include <Arduino.h>

// Definition der Pins, die für die einzelnen Sensoren verwendet werden.
//  
const int pin = 13;

void setup() {
  // Beginnen Sie die serielle Kommunikation für die Fehlersuche
  Serial.begin(9600);

  // Setzen Sie die Pins als Eingänge
  pinMode(pin, INPUT);
}

void loop() {
  // Lesen Sie den Status jedes Sensors
  bool linieErkannt = digitalRead(pin);

  // Drucken Sie den Status jedes Sensors auf die serielle Konsole
  Serial.println("");
  Serial.print("Linie erkannt: ");
  Serial.print(linieErkannt);

  // Warten Sie eine kurze Zeit, bevor Sie die nächste Messung durchführen
  delay(500);
}
