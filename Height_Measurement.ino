#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns and 2 rows

#define TRIG_PIN 9
#define ECHO_PIN 10
#define GROUND_READINGS 10
#define MIN_GROUND_HEIGHT 183 // 6 feet in cm

// Variables to store ground level and height
float groundLevel = 0.0;
float objectHeight = 0.0;

// Flag to indicate if ground level has been measured
bool groundMeasured = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init(); // initialize the LCD
  lcd.backlight();
}

void loop() {
  // Measure ground level if not done yet
  if (!groundMeasured) {
    measureGroundLevel();
    return;
  }

  // Measure height of object
  objectHeight = measureDistance(1);
  Serial.print("Object height: ");
  Serial.print(objectHeight);
  Serial.println(" cm");

  // Calculate and display the actual height of the object
  if (objectHeight > groundLevel) {
    float actualHeight = objectHeight - groundLevel;
    Serial.print("Actual height of the object: ");
    Serial.print(actualHeight);
    Serial.println(" cm");

    // Convert height to feet
    float actualHeightInFeet = convertToFeet(actualHeight);
    Serial.print("Actual height in feet: ");
    Serial.print(actualHeightInFeet);
    Serial.println(" ft");

    // Display height on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Height: ");
    lcd.print(actualHeightInFeet);
    lcd.print(" ft");
  } else {
    Serial.println("Object height is less than ground level.");
  }

  delay(1000); // Wait for a while before taking the next measurement
}

void measureGroundLevel() {
  // Measure ground level
  groundLevel = measureDistance(GROUND_READINGS);
  Serial.print("Ground level: ");
  Serial.print(groundLevel);
  Serial.println(" cm");

  // Check if ground level is greater than 6 ft (183 cm)
  if (groundLevel > MIN_GROUND_HEIGHT) {
    groundMeasured = true;
    Serial.println("Ground level measured successfully.");
  } else {
    Serial.println("Ground level is too low. Remount the sensor or adjust the height.");
    Serial.println("Please ensure the ground level is greater than 6 ft (183 cm).");
    delay(5000); // Wait 5 seconds before retrying
  }
}

float measureDistance(int readings) {
  long duration = 0;
  float distance = 0.0;

  for (int i = 0; i < readings; i++) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);
    distance += (duration * 0.034 / 2); // Speed of sound is 0.034 cm/µs
    delay(50); // Delay between readings
  }

  distance /= readings; // Calculate average distance
  return distance;
}

float convertToFeet(float centimeters) {
  return centimeters / 30.48; // 1 foot = 30.48 centimeters
}



