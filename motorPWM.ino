#define PWM_PIN 6
#define PULSE_PIN 3

// Os pulsos sao lidos a cada X mili segundos
// Pulses are read each X mili seconds
#define PULSE_DELAY 100

int pwmValue = 0;
int pulse = 0;

unsigned long previousMillisSec = 0;

void setup() { 
  Serial.begin(9600);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(PULSE_PIN, INPUT);
  attachInterrupt(1, interrupcion, RISING);

  // Frequência aproximada desejada - altere conforme necessário:
  // Desired operation frequency - change according to:
    //TCCR1B = TCCR2B & B11111000 | B00000100; // 122 Hz
    //TCCR1B = TCCR2B & B11111000 | B00000011; // 490 Hz
    //TCCR1B = TCCR2B & B11111000 | B00000010; // 3960 Hz
    TCCR1B = TCCR2B & B11111000 | B00000001; // 31372 Hz
}

void loop() {
  if (Serial.available()) {
    pwmValue = Serial.parseInt();
    while (Serial.available())
      Serial.read();

    pwmValue = constrain(pwmValue, 0, 178); // Ajustar valor máximo desejado
                                            // Adjust max value
    analogWrite(PWM_PIN, pwmValue);
  }
  if (millis() - previousMillisSec > PULSE_DELAY) {
    previousMillisSec = millis();
    noInterrupts();
    Serial.print("Pulsos: ");
    Serial.println(pulse);
    pulse = 0;
    interrupts();
    Serial.print("Saida PWM: ");
    Serial.println(pwmValue);
  }
}
void interrupcion() {
  pulse++;
}