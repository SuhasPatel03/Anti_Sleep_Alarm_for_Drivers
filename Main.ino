const int blinkPin = 2;
const int motorPin = 13;
const int buzzerPin = 8;
long time;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(blinkPin, INPUT);
  digitalWrite(motorPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(blinkPin)) {
    time = millis();
    while (!digitalRead(blinkPin)) {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(motorPin, LOW);
      delay(1000);
    }
    Serial.println("Driver is AWAKE");
  } else {
    if (TimeDelay() >= 4000)  // Adjusted the comparison value to milliseconds
      {digitalWrite(buzzerPin, HIGH);
       Serial.println("Driver is SLEEPING");
       }

    if (TimeDelay() >= 5000)  // Adjusted the comparison value to milliseconds
      digitalWrite(motorPin, HIGH);
  }
}

int TimeDelay() {
  long t = millis() - time;
  return t;
}