#include <Adafruit_NeoPixel.h>

#define PIN_NEOPIXEL 6
#define NUM_LEDS      12
#define PIN_POT       A0
#define PIN_BOTON     2

Adafruit_NeoPixel anillo(NUM_LEDS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

int efectoActivo = 1;
bool ultimoEstadoBoton = HIGH; 
int tiempoEspera = 500; 

void setup() 
{
  anillo.begin();
  anillo.show(); 
  
  pinMode(PIN_BOTON, INPUT_PULLUP); 
  randomSeed(analogRead(A5)); 
}

void loop() 
{
  actualizarPotenciometro(); 
  revisarBoton();            

  if (efectoActivo == 1) 
  {
    ejecutarEfecto1();
  } 
  else if (efectoActivo == 2) 
  {
    ejecutarEfecto2();
  } 
  else if (efectoActivo == 3) 
  {
    ejecutarEfecto3();
  }
}

void actualizarPotenciometro() 
{
  int lectura = analogRead(PIN_POT);
  tiempoEspera = map(lectura, 0, 1023, 50, 600); 
}

void revisarBoton() 
{
  bool estadoBoton = digitalRead(PIN_BOTON);
  
  if (estadoBoton == LOW && ultimoEstadoBoton == HIGH) 
  {
    delay(50); 
    efectoActivo++;
    if (efectoActivo > 3) 
    {
      efectoActivo = 1; 
    }
    anillo.clear();
    anillo.show();
  }
  ultimoEstadoBoton = estadoBoton;
}

void esperarYRevisar() 
{
  unsigned long tiempoInicio = millis();
  while (millis() - tiempoInicio < tiempoEspera) 
  {
    revisarBoton();
    actualizarPotenciometro(); 
  }
}

void ejecutarEfecto1() 
{
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    anillo.clear();
    
    if (i % 3 == 0) 
    {
      anillo.setPixelColor(i, anillo.Color(255, 0, 0)); 
    } 
    else if (i % 3 == 1) 
    {
      anillo.setPixelColor(i, anillo.Color(0, 255, 0)); 
    } 
    else 
    {
      anillo.setPixelColor(i, anillo.Color(0, 0, 255)); 
    }
    
    anillo.show();
    esperarYRevisar();
    if (efectoActivo != 1) 
    {
      return; 
    }
  }
}

void ejecutarEfecto2() 
{
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    anillo.clear();
    anillo.setPixelColor(i, anillo.Color(255, 255, 0)); 
    anillo.show();
    esperarYRevisar();
    if (efectoActivo != 2) 
    {
      return;
    }
  }
  
  for (int i = NUM_LEDS - 1; i >= 0; i--) 
  {
    anillo.clear();
    anillo.setPixelColor(i, anillo.Color(255, 255, 0)); 
    anillo.show();
    esperarYRevisar();
    if (efectoActivo != 2) 
    {
      return;
    }
  }
}

void ejecutarEfecto3() 
{
  anillo.clear();
  
  long colorPares = anillo.Color(random(0, 256), random(0, 256), random(0, 256));
  long colorImpares = anillo.Color(random(0, 256), random(0, 256), random(0, 256));

  for (int i = 0; i < NUM_LEDS; i++) 
  {
    if (i % 2 == 0) 
    {
      anillo.setPixelColor(i, colorPares);
    } 
    else 
    {
      anillo.setPixelColor(i, anillo.Color(0, 0, 0));
    }
  }
  anillo.show();
  esperarYRevisar();
  if (efectoActivo != 3) 
  {
    return;
  }

  for (int i = 0; i < NUM_LEDS; i++) 
  {
    if (i % 2 != 0) 
    {
      anillo.setPixelColor(i, colorImpares);
    } 
    else 
    {
      anillo.setPixelColor(i, anillo.Color(0, 0, 0));
    }
  }
  anillo.show();
  esperarYRevisar();
}