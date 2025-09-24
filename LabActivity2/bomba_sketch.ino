int ledPins[] = {12, 11, 10, 9, 8};
int numLeds = 5;
int i = 0;
int sensorValue;
int brightness;

void setup() {
  i = 0;
  while (i < numLeds) {
    pinMode(ledPins[i], OUTPUT);
    i++;
  }
}

void loop() {
  sensorValue = analogRead(A0);                 
  brightness = map(sensorValue, 0, 1023, 0, 255); 

  // on leds pin 12 to 8
  i = 0;
  while (i < numLeds) {
    analogWrite(ledPins[i], brightness);
    delay(1000);
    i++;
  }

  // off on leds pin 12 to 8
  i = 0;
  while (i < numLeds) {
    analogWrite(ledPins[i], 0);
    delay(1000);
    i++;
  }
}
