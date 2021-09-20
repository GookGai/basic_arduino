int tualek[8]={183,194,146,180,152,136};
int soom [8]={223,191,247,251,253,239,254};
int ledpin[8]= {6,7,8,9,10,11,12,13};
int j =0 , k =0; 
long randNumber ;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  
  pinMode(1,OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  sadang(tualek[0]);
}

void loop() {
 if(digitalRead(5)== LOW)
 kodpoom1();
 if(digitalRead(4)== LOW)
 kodpoom2();
 
}
void sadang(int a)
{
  for(int i=0;i<8;i++)
  {digitalWrite(ledpin[i],bitRead(a,7-i));
  }
}
void kodpoom1()
{
  if(digitalRead(5) == LOW)
  {delay(200);
    j += 1;}
    if(j>5)
  j=0;
  sadang(tualek[j]);
}
void kodpoom2()
{
  if(digitalRead(4) == LOW)
  {
    delay(200);
  randNumber = random(0,6);
  k=0;
  som();
  Serial.println(randNumber);
  sadang(tualek[randNumber]);
  torjaknun();
  }
}
void som()
{
  for(k;k<=8;k++)
  {sadang(soom[k]);
  delay(100);
  }
}
void torjaknun()
{
  if(randNumber != j)
  {digitalWrite(3,HIGH);
  delay(2000);
  digitalWrite(3,LOW);
  j=0;
  sadang(tualek[j]);
  }
  else 
  {digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(2,LOW);
  j=0;
  sadang(tualek[j]);
  }
  
}
 
