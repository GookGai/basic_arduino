//We always have to include the library
#include "LedControl.h"
int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int joystick_button = 8;
int joystick_axis_x = A0;
int joystick_axis_y = A1;
int x = 3, y = 7;
int bullet[6];
int bux[6], buy[6];
int enermy[10];
int enx[10], eny[10];
int check[8][8];
/*
  Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
*/
LedControl lc = LedControl(11, 13, 10, 1);
/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;
                /////////////////////function////////////////////////////
void drawsh() {
  lc.setLed(0, x, y, true);
  lc.setLed(0, x + 1, y, true);
  lc.setLed(0, x - 1, y, true);
  lc.setLed(0, x, y - 1, true);
}
void erassh() {
  lc.setLed(0, x, y, false);
  lc.setLed(0, x + 1, y, false);
  lc.setLed(0, x - 1, y, false);
  lc.setLed(0, x, y - 1, false);
}
void shot() {
  if (digitalRead(right_button) == LOW)
  { 
    for (short i = 0 ; i < 5; i++) {
      if (!bullet[i]) {
        bullet[i] = 1;
        bux[i] = x;
        buy[i] = y - 2;
        lc.setLed(0, bux[i], buy[i] , true);
        break ;
      }
    }
  }
}
void bumove() {
  for (short i = 0 ; i < 5; i++) {
    if (bullet[i]==1) {
      lc.setLed(0, bux[i], buy[i], false);
      buy[i]--;
     lc.setLed(0, bux[i], buy[i], true);
     if(buy[i]<0)
     bullet[i] = 0;
    }
  }
}
void movment() {
  if ((map(analogRead(joystick_axis_x), 0, 1000, -1, 1)) == -1) {
    erassh();
    ++x;
    drawsh();
  }
  if ((map(analogRead(joystick_axis_x), 0, 1000, -1, 1)) == 1) {
    erassh();
    --x;
    drawsh();
  }
}
void ene(){
  for (short i = 0 ; i < 7; i++) {
      if (!enermy[i]) {
        enermy[i] = 1;
        enx[i] = random(0,9);
        eny[i] = 0;
        lc.setLed(0, enx[i], eny[i] , true);
      }
    }
  }
void enmove() {
  for (short i = 0 ; i < 7; i++) {
    if (enermy[i]==1) {
      lc.setLed(0, enx[i], eny[i], false);
      eny[i]++;
     lc.setLed(0, enx[i], eny[i], true);
     if(buy[i]>8)
     enermy[i] = 0;
    }
  }
}

void setup() {
  randomSeed(analogRead(0));
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
  drawsh();
  ene();
}
void loop() {
  movment();
  shot();
  bumove();
  enmove();
  delay(200);
}
