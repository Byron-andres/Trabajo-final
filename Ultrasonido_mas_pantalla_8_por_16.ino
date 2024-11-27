#include <LiquidCrystal.h>

const int pin_TRIG = 2; // Pin para enviar pulsos
const int pin_ECHO = 3; // Pin para recibir la señal de rebote
const float velocidadSonido = 0.034; // Velocidad del sonido en cm/us

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(pin_TRIG, OUTPUT);
  pinMode(pin_ECHO, INPUT);
  lcd.begin(16, 2);
  lcd.clear(); // Limpia la pantalla al inicio
  Serial.begin(9600);

}

void loop() {
  digitalWrite(pin_TRIG, LOW);
  delayMicroseconds(5); // Estabiliza el sensor

  digitalWrite(pin_TRIG, HIGH); // Envía el pulso para iniciar el sensor
  delayMicroseconds(10);
  digitalWrite(pin_TRIG, LOW);

  int tiempoSenal = pulseIn(pin_ECHO, HIGH); // Tiempo que dura el pin ECHO en HIGH
  int distanciaCM = (velocidadSonido * tiempoSenal) / 2; // Convierte el tiempo en distancia (cm)
  float distanciaM = distanciaCM / 100.0; // Convierte la distancia a metros

  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");   
  lcd.print(distanciaCM); // Muestra la distancia en centímetros
  lcd.print(" cm  "); // Espacios adicionales para borrar caracteres anteriores

  lcd.setCursor(0, 1);
  lcd.print("Distancia: ");
  lcd.print(distanciaM); // Muestra la distancia en metros
  lcd.print(" m   "); // Espacios adicionales para borrar caracteres anteriores
  Serial.print(distanciaM);
  delay(1000); // Espera un segundo antes de la siguiente medición
  
}