int b[] = {13, 12, 12, 10};
int L[] = {5, 6, 7, 8};
int buzzer = 3;
int D = 400;
int d = 200;
int f[] = {262, 294, 330, 349};

int seq[200];
int m;
int MAX;


void lol(void)
{
  tone(buzzer,523,100);
 delay(150);
  tone(buzzer,523,100);
  delay(150);
  tone(buzzer,523,100);
  delay(150);
  tone(buzzer,2*392,200);
  delay(300);
  tone(buzzer,523,100);
  delay(150);
  tone(buzzer,2*392,400);
   
}

int le(void)
{
  int i;
  int l;
  
  for(i=0; i<=m; i++)
  {
    while(((!digitalRead(b[0])) && (!digitalRead(b[1]))) && ((!digitalRead(b[2])) && (!digitalRead(b[3])))) {delay(5);}
    if(digitalRead(b[0]))
    {
      l = 0;
    }
    else if(digitalRead(b[1]))
    {
      l = 1;
    }
    else if(digitalRead(b[2]))
    {
      l = 2;
    }
    else
    {
      l = 3;
    }
    tone(buzzer, f[l]);
    digitalWrite(L[l], HIGH);
    while(digitalRead(b[l])) {delay(5);}
    digitalWrite(L[l], LOW);
    noTone(buzzer);
  
    
    if(l != seq[i])
    {
      return 0;
    }
  }
  return 1;
}

void fim(void)
{
  int i;
  
  for(i=0; i<3; i++)
  {
    tone(buzzer, 440);
    digitalWrite(L[0], HIGH);
    digitalWrite(L[1], HIGH);
    digitalWrite(L[2], HIGH);
    digitalWrite(L[3], HIGH);
    delay(400);
    digitalWrite(L[0], LOW);
    digitalWrite(L[1], LOW);
    digitalWrite(L[2], LOW);
    digitalWrite(L[3], LOW);
    noTone(buzzer);
    delay(200);
  }
}

void toca(void)
{
  int i;
  
  for(i=0; i<=m; i++)
  {
    tone(buzzer, f[seq[i]]);
    digitalWrite(L[seq[i]], HIGH);
    delay(analogRead(A0));
    digitalWrite(L[seq[i]], LOW);
    noTone(buzzer);
    delay(analogRead(A0)/2);
    
  }
}

void setup()
{
  pinMode(b[0], INPUT);
  pinMode(b[1], INPUT);
  pinMode(b[2], INPUT);
  pinMode(b[3], INPUT);
  pinMode(L[0], OUTPUT);
  pinMode(L[1], OUTPUT);
  pinMode(L[2], OUTPUT);
  pinMode(L[3], OUTPUT);
  pinMode(buzzer, OUTPUT);
  //Serial.begin(9600);
  MAX = -2;
}

void loop()
{
  int flag = 0;
  m = -1;
  do
  {
    if(m>MAX)
    {
      MAX = m;
      if(!flag)
      {
        flag++;
        lol();
      }
    }
    delay(D);
    m++;
    seq[m] = ((millis()+analogRead(A5))%4);
    toca();
  }
  while(le() == 1);
  fim();
 
  /*Serial.print(digitalRead(b[0]));
  Serial.print("-");
  Serial.print(digitalRead(b[1]));
  Serial.print("-");
  Serial.print(digitalRead(b[2]));
  Serial.print("-");
  Serial.print(digitalRead(b[3]));
  Serial.print("-");
  Serial.println(analogRead(A0));
  */
}