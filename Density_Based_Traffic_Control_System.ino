#define ledA1 10
#define ledA2 9
#define ledA3 8

#define ledB1 11
#define ledB2 12
#define ledB3 13

#define ledC1 27
#define ledC2 25
#define ledC3 23

#define ledD1 50
#define ledD2 48
#define ledD3 46 
int sensorPin = A9;
int sensorValue = 0;
int a1, a2, b1, b2, c1, c2, d1, d2; 
int led = 35;


void setup() {

  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);



}

void loop() {

  readSensor();

  if (b1 == 1 && b2 == 1)
  {
    roadBopen();
  }
  else if (d1 == 1 && d2 == 1 && (b1 == 0 || b2 == 0))
  {
    roadDopen();
    if (b1 == 1 && b2 == 1)
    {
      roadBopen();
    }
  }
  else if (a1 == 1 && a2 == 1 && ((d2 == 0 || b2 == 0) || (d1 == 0 || b1 == 0)))
  {
    roadAopen();
    if (b1 == 1 && b2 == 1)
    {
      roadBopen();
    }
    else if (d1 == 1 && d2 == 1 && (b1 == 0 || b2 == 0))
    {
      roadDopen();
    }
  }
  else if (c1 == 1 && c2 == 1 && ((d2 == 0 || b2 == 0 || a2 == 0) || (d1 == 0 || b1 == 0 || a1 == 0)))
  {
    roadCopen();
    if (b1 == 1 && b2 == 1)
    {
      roadBopen();
    }
    else if (d1 == 1 && d2 == 1 && (b1 == 0 || b2 == 0))
    {
      roadDopen();
    }
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((b1 == 1 && b2 == 0) && (c1 == 1 || d1 == 1 || b1 == 1) && (c2 == 1 && d2 == 1 && b2 == 1))
  {
    roadBopen();
  }
  else if ((d1 == 1 && d2 == 0) && (c1 == 1 || a1 == 1) && (b1 == 0 && b2 == 0) && (c2 == 0 && a2 == 0))
  {
    roadDopen();
  }
  else if ((a1 == 1 && a2 == 0) && (c1 == 1 && c2 == 0) && (d1 == 0 && d2 == 0) && (b1 == 0 && b2 == 0))
  {
    roadAopen();
  }
  else if ((c1 == 1 && c2 == 0) && (b1 == 0 || b2 == 0) && (d1 == 0 || d2 == 0) && (a1 == 0 || a2 == 0))
  {
    roadCopen();
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((b1 == 1 && b2 == 0) && (c1 == 0 || c2 == 0) && (d1 == 0 || d2 == 0) && (a1 == 0 || a2 == 0))
  {
    roadBopen();
  }
  else if ((d1 == 1 && d2 == 0) && (c1 == 0 || c2 == 0) && (b1 == 0 || b2 == 0) && (a1 == 0 || a2 == 0))
  {
    roadDopen();
  }

  else if ((a1 == 1 && a2 == 0) && (c1 == 0 || c2 == 0) && (d1 == 0 || d2 == 0) && (b1 == 0 || b2 == 0))
  {
    roadAopen();
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
  {
    roadBopen();
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadDopen();
    }
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadAopen();
    }
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadCopen();
    }
  }
}
void readSoundSensor(){
sensorValue = analogRead(sensorPin); //reading value of sound sensor
if(sensorValue > 800){
//if detected sound is greater than 800 then road A will be opened.
digitalWrite(led, HIGH);
roadAopen();
}
digitalWrite(led, LOW);
}
void readSensor()
{
  a1 = analogRead(A7);
  a2 = analogRead(A6);
  b1 = analogRead(A4);
  b2 = analogRead(A5);
  c1 = analogRead(A1);
  c2 = analogRead(A0);
  d1 = analogRead(A3);
  d2 = analogRead(A2);

  if (a1 < 200) a1 = 1; else a1 = 0; if (a2 < 200) a2 = 1; else a2 = 0;
if (b1 < 200) b1 = 1; else b1 = 0; if (b2 < 200) b2 = 1; else b2 = 0;
if (c1 < 200) c1 = 1; else c1 = 0; if (c2 < 200) c2 = 1; else c2 = 0;
if (d1 < 200) d1 = 1; else d1 = 0; if (d2 < 200) d2 = 1; else d2 = 0;

Serial.print(a1);
Serial.print("\t");
Serial.print(a2);
Serial.print("\t");
Serial.print(b1);
Serial.print("\t");
Serial.print(b2);
Serial.print("\t");
Serial.print(c1);
Serial.print("\t");
Serial.print(c2);
Serial.print("\t");
Serial.print(d1);
Serial.print("\t");
Serial.print(d2);
Serial.println("\t");

}

void roadAopen()
{
  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledA2, HIGH);
  delay(1000);
  digitalWrite(ledA2, LOW);
  readSensor();
}

void roadBopen()
{
  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopen()
{
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopen()
{
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  delay(10000);
  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  delay(1000);
  digitalWrite(ledD2, LOW);
  readSensor();
}
