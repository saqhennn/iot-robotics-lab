int gasSensor = A0;
int greenLED = 6;
int redLED = 7;
int buzzer = 8;
int gasLimit = 400;

void setup() {

  Serial.begin(9600);
  pinMode(gasSensor, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  // Read gas sensor
  int gasValue = analogRead(gasSensor);

  // Display sensor reading
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  // Check gas level
  if (gasValue > gasLimit) {

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    Serial.println("ALERT! Gas or smoke detected!");
  }

  else {

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    Serial.println("Environment is NORMAL");

  }

  delay(1000);

}

