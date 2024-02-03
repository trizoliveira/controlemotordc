#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MOTOR_PIN   2  // Pino digital para controle do motor
#define BUTTON_PIN  3  // Pino digital para leitura do botão

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  lcd.begin(0x27, 16, 2);
  lcd.setCursor(0,0);
  lcd.print("Press. o Botao");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Botão pressionado, aciona o motor
    digitalWrite(MOTOR_PIN, HIGH);
    lcd.clear();
    lcd.print("Motor Ligado");
    delay(10000);  // Mantém o motor ligado por 10 segundos
    digitalWrite(MOTOR_PIN, LOW);
    lcd.clear();
    lcd.print("Press. o Botao");
  }
}
