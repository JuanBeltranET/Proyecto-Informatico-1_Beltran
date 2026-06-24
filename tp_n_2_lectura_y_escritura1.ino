int ledR = 3;
int ledG = 5;
int ledB = 6;

int buzzer = 8;
int boton = 7;

int potTiempo = A0;
int potR = A1;
int potG = A2;
int potB = A3;

bool secuenciaActiva = true;
bool estadoAnteriorBoton = HIGH;

void setup()
{
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);

    pinMode(buzzer, OUTPUT);
    pinMode(boton, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop()
{
    controlarBoton();

    int lecturaTiempo = analogRead(potTiempo);
    int lecturaR = analogRead(potR);
    int lecturaG = analogRead(potG);
    int lecturaB = analogRead(potB);

    int tiempo = (lecturaTiempo * 3000L) / 1023;

    int valorR = (lecturaR * 255L) / 1023;
    int valorG = (lecturaG * 255L) / 1023;
    int valorB = (lecturaB * 255L) / 1023;

    Serial.print("Tiempo: ");
    Serial.println(tiempo / 1000.0);

    Serial.print("R:");
    Serial.println(valorR);

    Serial.print("G:");
    Serial.println(valorG);

    Serial.print("B:");
    Serial.println(valorB);

    Serial.println("----------------");

    if (secuenciaActiva)
    {
        analogWrite(ledR, valorR);
        analogWrite(ledG, valorG);
        analogWrite(ledB, valorB);

        delay(tiempo);

        zumbido();

        parpadeo(valorR, valorG, valorB);
    }
    else
    {
        apagarLed();
    }
}

void controlarBoton()
{
    bool estadoActual = digitalRead(boton);

    if (estadoActual == LOW && estadoAnteriorBoton == HIGH)
    {
        secuenciaActiva = !secuenciaActiva;
        delay(50);
    }

    estadoAnteriorBoton = estadoActual;
}

void zumbido()
{
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
}

void apagarLed()
{
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
}

void parpadeo(int r, int g, int b)
{
    for (int i = 0; i < 4; i++)
    {
        analogWrite(ledR, r);
        analogWrite(ledG, g);
        analogWrite(ledB, b);

        delay(100);

        apagarLed();

        delay(100);
    }
}