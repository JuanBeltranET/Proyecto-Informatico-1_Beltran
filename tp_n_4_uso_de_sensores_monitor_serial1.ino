#define TMP A0
#define LDR A1
#define pinRojo 9
#define pinVerde 10
#define pinAzul 11

void setup()
{
  Serial.begin(9600);
  
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop()
{
  int lecturaTMP = analogRead(TMP);
  int lecturaLDR = analogRead(LDR);
  
  float temperatura = (analogRead(TMP)*5.0/1024)*100-50;
  
  int porcentajeLuz = map(lecturaLDR, 1, 310, 100, 0);

  Serial.print("El nivel de luz actual es: ");
  Serial.print(porcentajeLuz);
  Serial.print(" y la temperatura actual: ");
  Serial.print(temperatura);
  Serial.println(" C");
  
  if (porcentajeLuz >= 30 && porcentajeLuz <= 70) 
  {
    
    // Condicionales compuestos para el color del LED según la temperatura
    if (temperatura > 90.0) 
    {
      digitalWrite(pinRojo, HIGH);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAzul, LOW);
    } 
    else if (temperatura < 18.0) 
    {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAzul, HIGH);
    } 
    else if (temperatura >= 18.0 && temperatura <= 90.0) 
    {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, HIGH);
      digitalWrite(pinAzul, LOW);
    }
    
  } 
  else 
  {
    // Si la luz no está entre el 30% y 70%, el LED se apaga por completo
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
  }

  delay(1000);
}