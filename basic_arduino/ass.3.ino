#define C5 523.25
#define D5 587.33
#define E5 659.26
#define F5 698.46
#define G5 783.99
#define A5 880.00
#define B5 987.77
#define button1 11
#define button2 10
#define button3 9
#define button4 8
#define button5 7
#define button6 6
#define pressed HIGH
#define Speak 5

float a[8]={0,C5,D5,E5,F5,G5,A5,B5};
float b[250];
int i=0,st=0,bt=0;

void setup() {
   pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sw1,sw2,sw3,sw4,sw5,sw6,sw7,rec;
  
  sw1 =digitalRead(button1);
  sw2 =digitalRead(button2);
  sw3 =digitalRead(button3);
  sw4 =digitalRead(button4);
  sw5 =digitalRead(button5);
  rec =digitalRead(button6);

    if(sw1==pressed){
      bt=1;
      delay(80);
      tone(Speak,a[1],200);
      b[i]=523.25;
      i++;
      Serial.println(i);
      }
      else if(sw2==pressed){
      bt=1;
      delay(80);
      b[i]=587.33;
      tone(Speak,a[2],200);
      i++;
      Serial.println(i);
      }
      else if(sw3==pressed){
      bt=1;
      delay(80);  
      b[i]=659.26;
      tone(Speak,a[3],200);
      i++;
      Serial.println(i);
      }
      else if(sw4==pressed){
      bt=1;
      delay(80);
      b[i]=698.46;
      tone(Speak,a[4],200);
      i++;
      Serial.println(i);
      }
      else if(sw5==pressed){
      bt=1;
      delay(80);
      b[i]=783.99;
      tone(Speak,a[5],200);
      i++;
      Serial.println(i);
      }
      else{
        if (bt == 1){
          b[i] = 0;
          delay(150);
          noTone(Speak);
          i++;}
      }
  if(rec==pressed && st==0){
          st=1;bt=0;}
          if(st==1){
    for(int j=1; j<i; j++){
    delay(100);
    if(b[j]==0){
       noTone(Speak);
       Serial.println(j);
    }
    else
    tone(Speak,b[j],200);
    Serial.println(j);
    }
    i=0;
    st=0;
          }
  
}
