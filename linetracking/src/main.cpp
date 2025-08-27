#include <linetracking.h>

LineTracking lineTracking(A2, A1, A0);

void setup() {
  Serial.begin(9600);
}

void testLineTracking() {
    Serial.print("Left/Center/Right ");
    Serial.print(lineTracking.left());
    Serial.print(" / ");
    Serial.print(lineTracking.center());
    Serial.print(" / ");
    Serial.println(lineTracking.right());
}

void loop() {
  Serial.println("---- Neue Messung");
  testLineTracking();
  delay(1000); // Nur 1 Scan pro Sekunde
}
