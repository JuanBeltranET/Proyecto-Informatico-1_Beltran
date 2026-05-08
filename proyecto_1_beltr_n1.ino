int led1R = 3;
int led1G = 5;
int led1B = 6;
int led2R = 9;
int led2G = 10;
int led2B = 11;
int led3R = A0;
int led3G = A1;
int led3B = A2;
int buzzer = 8;

void setup()
{
  pinMode(led1R, OUTPUT);
  pinMode(led1G, OUTPUT);
  pinMode(led1B, OUTPUT);
  pinMode(led2R, OUTPUT);
  pinMode(led2G, OUTPUT);
  pinMode(led2B, OUTPUT);
  pinMode(led3R, OUTPUT);
  pinMode(led3G, OUTPUT);
  pinMode(led3B, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  apagarTodos();
  analogWrite(led1R, 255);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  delay(1000);
  zumbido();
  Parpadeo();
  apagarTodos();
  digitalWrite(led2R, HIGH);
  digitalWrite(led2G, LOW);
  digitalWrite(led2B, HIGH);
  delay(1000);
  zumbido();
  Parpadeo();
  apagarTodos();
  analogWrite(led3R, 0);
  analogWrite(led3G, 80);
  analogWrite(led3B, 80);
  delay(1000);
  zumbido();
  Parpadeo();
}

void zumbido()
{
  analogWrite(buzzer, 120);
  delay(100);
  analogWrite(buzzer, 0);
}

void apagarTodos()
{
  analogWrite(led1R, 0);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  digitalWrite(led2R, LOW);
  digitalWrite(led2G, LOW);
  digitalWrite(led2B, LOW);
  analogWrite(led3R, 0);
  analogWrite(led3G, 0);
  analogWrite(led3B, 0);
}

void Parpadeo()
{
  for (int i = 0; i < 4; i++)
  {
    encenderNaranja();
    delay(100);
    apagarTodos();
    delay(100);
  }
}

void encenderNaranja()
{
  analogWrite(led1R, 255);
  analogWrite(led1G, 80);
  analogWrite(led1B, 0);
  digitalWrite(led2R, HIGH);
  digitalWrite(led2G, HIGH);
  digitalWrite(led2B, LOW);
  analogWrite(led3R, 255);
  analogWrite(led3G, 80);
  analogWrite(led3B, 0);
}
