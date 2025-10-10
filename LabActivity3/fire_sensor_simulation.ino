
#define THERMISTOR_PIN A0 //thermistor pin
#define LIGHT_SENSOR_PIN A2 //photoresistor pin
#define ALERT_PIN 12  // led+buzzer pin

const float TEMP_THRESHOLD = 50.0;  
const int LIGHT_THRESHOLD = 220;    
const int beta = 3950; // Beta value of thermistor
const int resistance = 10; //Value of pull-up resistor kΩ

float temperatureC;
int brightnessValue;

// function to read temperature

float readTemperature() {
  int analogValue = analogRead(THERMISTOR_PIN);
  
  //calculating temp in celcius using Steinhart-Hart Equation
  float tempC = beta / (log((1025.0 * resistance/analogValue - resistance )/resistance)+beta/298.0)-273.0;

  return tempC;
}

//function to read brightness
int readBrightness() {
  int value = analogRead(LIGHT_SENSOR_PIN);
  return value;
}

void setup() {
  Serial.begin(9600);
  pinMode(ALERT_PIN, OUTPUT);
  digitalWrite(ALERT_PIN, LOW);

  //label in serial moni
  Serial.println("Fire Sensor Activated!!!");
}

void loop() {
  temperatureC = readTemperature();
  brightnessValue = readBrightness();

  //used to check value in serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C | Brightness: ");
  Serial.println(brightnessValue);

  //temp>temp threshold && brightness>threshold = led+buzzer on
  if (temperatureC >= TEMP_THRESHOLD && brightnessValue >= LIGHT_THRESHOLD) {
    // Fire detected → fast blink and buzzer
    digitalWrite(ALERT_PIN, HIGH);
    delay(100);
    digitalWrite(ALERT_PIN, LOW);
    delay(100);
  } else {
    //Normal condition
    digitalWrite(ALERT_PIN, LOW);
  }

  delay(500);  //loop delay
}
