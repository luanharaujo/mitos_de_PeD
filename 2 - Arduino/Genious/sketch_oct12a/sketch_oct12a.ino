*int GerarAleatorio(int);

int ledY=3, ledB=2, ledR=4, ledG=5;
int buttonG=8, buttonR=10, buttonB=11, buttonY=12;
int contadora=0, sequencia[100], aleatorios[100], portaAnalogica=A0;

void setup()
{
  //Declaracao das portas ligadas aos leds como saidas
  pinMode(ledY, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  //Declaracao das portas ligadas aos botoes como entradas
  pinMode(buttonY, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonR, INPUT);
  pinMode(buttonG, INPUT);
  
  pinMode(portaAnalogica, INPUT);
}

void loop()
{
  aleatorio=GerarAleatorio(contadora);
  contadora++;
  switch(aleatorio(contadora))
  {
  case 0:
    digitalWrite(ledY, 1);
  case 1:
    digitalWrite(ledB, 1);
  case 2:
    digitalWrite(ledR, 1);
  case 3:
    digitalWrite(ledG, 1);
  }
}

*int GerarAleatorio(int contadora)
{
  aleatorio[contadora]=analogRead(portaAnalogica)%4;
  return aleatorio;
}

