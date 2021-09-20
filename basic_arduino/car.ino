int enA = 10;//ซ้าย
int in1 = 12;
int in2 = 8;
int enB = 11;
int in4 = 13;
int in3 =9;
void setup()
{
// set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
     pinMode(3,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
// this function will run the motors in both directions at a fixed speed
// turn on motor A
if(analogRead(A1)> 975 ){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(5 , HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(100);}
else{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(5 , LOW);
delay(70);}
if(analogRead(A5)> 900 ){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(4 , HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(150);}
else{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(4 , LOW);
delay(70);}
if(analogRead(A3)> 200 )
{
 digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
digitalWrite(6 , HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(150);}

else{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(6 , LOW);
delay(70);}
  
 if(analogRead(A4)> 900 )
{
 digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
digitalWrite(2 , HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(300);}

else{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(2 , LOW);
delay(70);}

if(analogRead(A0)> 800 )
{
 digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(3 , HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(300);}
else{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(3 , LOW);
delay(70);} 
///////////////////////////////
if(analogRead(A0)< 900&& analogRead(A4)< 980&&analogRead(A3)< 200&&analogRead(A5)< 900 &&analogRead(A1)< 975){
  {
 digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
// set speed to 200 out of possible range 0~255
analogWrite(enA, 253);
analogWrite(enB, 130);// Speed Control
delay(100);
}
}
else{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(3 , LOW);
delay(200);
} 
}
//analogWrite(enA, 200);
//analogWrite(enB, 120);// Speed Control
//delay(600);

//}
