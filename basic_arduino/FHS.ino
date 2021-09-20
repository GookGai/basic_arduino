#define LED_W_R 4
#define LED_W_Y 5
#define LED_W_G 6
#define WEST_BUTTON_PIN 2
#define WALK_BUTTON_PIN 13
#define LED_S_R 8
#define LED_S_Y 9
#define LED_S_G 10
#define SOUTH_BUTTON_PIN 3
#define goE 2
#define waitE 3
#define goN 0
#define waitN 1
#define gowalk 4
#define waitwalk 5
#define greenwalk 12
#define redwalk 11

struct State {
  unsigned long ST_Out; // 6-bit pattern to street output
  unsigned long Time; // delay in ms units
  unsigned long Next[8];
}; // next state for inputs 0,1,2,3
typedef const struct State SType;
SType FSM[6] = {
  {B01100001, 2000, {goN, waitN, goN, waitN, waitN, waitN, waitN, waitN}},
  {B01100111, 500, {goE, goE, goE, goE, gowalk, gowalk, gowalk, gowalk}},
  {B01001100, 2000, {goE, goE, waitE, waitE, waitE, waitE, waitE, waitE}},
  {B01111100, 500, {goN, goN, goN, goN , gowalk, gowalk, gowalk, goN}},
  {B10100100, 2000, {gowalk, goE, goN, goE, gowalk, goE, goN, goE}},
  {B01100100, 0, {gowalk, goE, goN, goE, gowalk, goE, goN, goE}}

};
unsigned short S = 4 ; // index to the current state
int timer1_counter = 0;
int  p1 = 0;
int  t1 = 0;

void setup() {
  pinMode(LED_W_R, OUTPUT);
  pinMode(LED_W_Y, OUTPUT);
  pinMode(LED_W_G, OUTPUT);
  pinMode(WEST_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_S_R, OUTPUT);
  pinMode(LED_S_Y, OUTPUT);
  pinMode(LED_S_G, OUTPUT);
  pinMode(SOUTH_BUTTON_PIN, INPUT_PULLUP);
  pinMode(redwalk, OUTPUT);
  pinMode(greenwalk, OUTPUT);
  pinMode(WALK_BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  timer1_counter = 3036;
  TCNT1 = timer1_counter; TCCR1B |= (1 << CS12); TIMSK1 |= (1 << TOIE1);
  interrupts();
}

int input, input1, input2, input3;
ISR(TIMER1_OVF_vect) // interrupt service routine
{
  TCNT1 = timer1_counter; // preload timer
  Serial.println(t1++);
}

void loop() {
  digitalWrite(LED_W_R, FSM[S].ST_Out & B00000001);
  digitalWrite(LED_W_Y, !(FSM[S].ST_Out & B00000010));
  digitalWrite(LED_W_G, FSM[S].ST_Out & B00000100);
  digitalWrite(LED_S_R, FSM[S].ST_Out & B00001000);
  digitalWrite(LED_S_Y, !(FSM[S].ST_Out & B00010000));
  digitalWrite(LED_S_G, FSM[S].ST_Out & B00100000);
  digitalWrite(greenwalk, FSM[S].ST_Out & B01000000);
  digitalWrite(redwalk, FSM[S].ST_Out & B10000000);
  delay(FSM[S].Time);
  if(S != waitN && S != waitE)
  {
  input = 0;
  input1 = !digitalRead(WEST_BUTTON_PIN);
  input2 = !digitalRead(SOUTH_BUTTON_PIN);
  input3 = !digitalRead(WALK_BUTTON_PIN);
  input = input3 * 4 + input2 * 2 + input1;
  }
  if (S == 4 && (input != 0 && input != 4 )) {
    int kapip = t1 + 1;
    int p = 1 ;
    Serial.println("BT : " + (String)kapip);
    while (t1 <= kapip ) {
      p++;
      if (p % 35 == 0) {
        Serial.print("tidloop");
        digitalWrite(greenwalk , !digitalRead(greenwalk));
        Serial.println("counter : " + (String)p);
      }
    }

  }
  S = FSM[S].Next[input];
  Serial.print(" 1 ");
  Serial.print(input1);

  Serial.print(" 2 ");
  Serial.print(input2);

  Serial.print(" 3 ");
  Serial.print(input3);
  Serial.println("");



}
