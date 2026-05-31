#include <LiquidCrystal.h>

// LiquidCrystal (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define sensorTemp A0
#define sensorLuz A1
#define sensorPIR 7
#define trig 8
#define echo 9

#define rojo 6
#define verde 10
#define azul 13

#define buzzer A2

float temperatura;
int luz;
int movimiento;

long duracion;
float distancia;

bool noche;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  pinMode(sensorPIR, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

void loop()
{
  // Temperatura
  int valorTemp = analogRead(sensorTemp);
  float voltaje = valorTemp * 5.0 / 1024.0;
  temperatura = (voltaje - 0.5) * 100;

  // Luz
  luz = analogRead(sensorLuz);

  // Movimiento
  movimiento = digitalRead(sensorPIR);

  // Distancia
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH);
  distancia = duracion * 0.034 / 2;

  // menos del 20% de luz = noche
  noche = (luz < 205);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  Serial.print("Luz: ");
  Serial.println(luz);

  Serial.print("Movimiento: ");
  Serial.println(movimiento);

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // para que no se mezclen la informacion en el Serial Monitor
  Serial.println("----------------"); 

  // LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.print(" L:");
  lcd.print(luz);

  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(distancia);
  lcd.print(" M:");
  lcd.print(movimiento);

  // Apagar los leds y el buzzer
  digitalWrite(rojo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);

  noTone(buzzer);

  // Temperatura > 39°C para encender el buzzer
  if (temperatura > 39)
  {
    digitalWrite(rojo, HIGH);

    tone(buzzer, 1000);
    delay(500);

    noTone(buzzer);
  }

  // Para detectar el movimiento
  if (movimiento == HIGH)
  {
    // Amarillo
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);

    tone(buzzer, 700);
    delay(300);

    noTone(buzzer);
  }

  // Encender el buzzer cuando se acerca
  if (distancia < 100)
  {
    digitalWrite(rojo, HIGH);

    tone(buzzer, 1200);
    delay(200);

    noTone(buzzer);
    delay(200);

    tone(buzzer, 1200);
    delay(200);

    noTone(buzzer);
  }

  // Noche mas con la alarma
  if (noche && (movimiento == HIGH || temperatura > 39))
  {
    digitalWrite(rojo, HIGH);

    tone(buzzer, 1500);
    delay(500);

    noTone(buzzer);
  }

  delay(200);
}