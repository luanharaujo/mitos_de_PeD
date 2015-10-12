int ledY=3, ledB=2, ledR=4, ledG=5;
int buttonG=8, buttonR=10, buttonB=11, buttonY=12;
int b0, b1, b2, b3;
int contadora=0, sequencia[100], aleatorio[100], portaAnalogica=A0, i;
int GerarAleatorio(int);
boolean recebendo=0, perdeu=0;

void setup()
{
  Serial.begin(9600);
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
  
 if(recebendo==0)
 { 
  for(i=0; i<contadora; i++)
  {
    delay(977);
    switch(aleatorio[i])
    {
    case 0:
      digitalWrite(ledY, 1);
      digitalWrite(ledB, 0);
      digitalWrite(ledR, 0);
      digitalWrite(ledG, 0);
      break;
    case 1:
      digitalWrite(ledB, 1);
      digitalWrite(ledY, 0);
      digitalWrite(ledR, 0);
      digitalWrite(ledG, 0);
      break;
    case 2:
      digitalWrite(ledR, 1);
      digitalWrite(ledB, 0);
      digitalWrite(ledY, 0);
      digitalWrite(ledG, 0);
      break;
    case 3:
      digitalWrite(ledG, 1);
      digitalWrite(ledB, 0);
      digitalWrite(ledR, 0);
      digitalWrite(ledY, 0);
      break;
    }
    delay(333);
    digitalWrite(ledY, 0);
    digitalWrite(ledB, 0);
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 0);
    Serial.println(aleatorio[i]);
  }

  recebendo=1;
 }
 else
 {
  for(i=0; i<contadora; i++)
  {
    b0=digitalRead(buttonY);
    b1=digitalRead(buttonB);
    b2=digitalRead(buttonR);
    b3=digitalRead(buttonG);
    while (b0==0 && b1==0 && b2==0 && b3==0)
    {
      
    }
    if (b0==1 && b1==0 && b2==0 && b3==0)
    {
      sequencia[i]=0;
    }
    else if (b0==0 && b1==1 && b2==0 && b3==0)
    {
      sequencia[i]=1;
    }
    else if (b0==0 && b1==0 && b2==1 && b3==0)
    {
      sequencia[i]=2;
    }
    else if (b0==0 && b1==0 && b2==0 && b3==1)
    {
      sequencia[i]=3;
    }
    if(sequencia[i]!=aleatorio[i])
    {
      i=contadora;
      perdeu=1;
    }
  }
 } 
 
  recebendo=0;
  aleatorio[contadora]=GerarAleatorio(contadora);
  contadora++;
}

int GerarAleatorio(int contadora)
{
  long int valor;
  valor=(analogRead(portaAnalogica)*millis())%4;
  return valor;
}

