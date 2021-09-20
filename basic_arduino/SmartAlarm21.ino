#include "ST7735_TEE.h"
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
bool leftstate = false;
bool rightstate = true;
bool settime = false;
int Hour = 23;
int Min = 59;
int setMin = 1;
int setHour = 1;
int times;
char str[50] = "The Smart";
char str2[50] = "Alarm Clock";
char str3[50] = "The Smart";
char str4[50] = " Settime ";
uint8_t hour  = 00, minute = 00, second = 00;
//TEE_ST7735 lcd(0,13,12,14,2); //ESP8266 csk,sda,A0,rst,cs
TEE_ST7735 lcd(9, 10, 11, 12, 13); //Arduino  csk,sda,A0,rst,cs
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4);
void setup()
{
  //lcd.init(lcd.HORIZONTAL);
  lcd.init(lcd.VERTICAL);
  // lcd.fillScreen(BLACK);
  // delay(500);
  // lcd.fillScreen(GREEN);
  // delay(500);
  Serial.begin(4800);
  mySerial.begin(4800);
  lcd.fillScreen(BLUE);
  lcd.drawString(10, 20, str, WHITE, 2);
  lcd.drawString(1, 50, str2, WHITE, 2);
  lcd.drawChar( 60, 80, ':', WHITE, 2);
  lcd.fillRect(80, 100, 30, 5, RED);
  String c = (String)Min;
  for (int i = 0 ; i < c.length(); i++)
  {
    lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
    lcd.drawChar(80 + i * 15, 80, c[i], WHITE, 2);
  }
  String e = (String)Hour;
  for (int i = 0 ; i < e.length(); i++)
  {
    lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
    lcd.drawChar(20 + i * 15, 80, e[i], WHITE, 2);
  }
   noInterrupts();           /* disable all interrupts             */

  TCCR1A  = 0;

  TCCR1B  = 0;

  TCNT1   = 3036;           /* preload timer 65536-16MHz/256/1Hz  */

  TCCR1B |= (1 << CS12);    /* 256 prescaler                      */

  TIMSK1 |= (1 << TOIE1);   /* enable timer overflow interrupt    */

  interrupts();             /* enable all interrupts              */
}

void loop() {
  if (digitalRead(right_button) == LOW && leftstate == true && settime == false)
  {
    leftstate = false;
    rightstate = true;
    if (rightstate == true)
    {
      lcd.fillRect(80, 100, 30, 5, RED);
    }
    if (leftstate == false)
      lcd.fillRect(20, 100, 30, 5, BLUE);
  }
  if (digitalRead(left_button) == LOW && rightstate == true && settime == false)
  {
    leftstate = true;
    rightstate = false;
    if (leftstate == true)
    {
      lcd.fillRect(20, 100, 30, 5, RED);
    }
    if (rightstate == false)
      lcd.fillRect(80, 100, 30, 5, BLUE);
  }

  if (digitalRead(down_button) == LOW && Min > 1 && rightstate == true && settime == false)
  {
    Min--;
    String c = (String)Min;
    for (int i = 0 ; i < c.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, c[i], WHITE, 2);
    }
  }
  if (digitalRead(up_button) == LOW && Min < 59 && rightstate == true && settime == false)
  {
    Min++;
    String c = (String)Min;
    for (int i = 0 ; i < c.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, c[i], WHITE, 2);
    }
  }

  if (digitalRead(down_button) == LOW && Hour > 1 && leftstate == true && settime == false)
  {
    Hour--;
    String e = (String)Hour;
    for (int i = 0 ; i < e.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, e[i], WHITE, 2);
    }
  }
  if (digitalRead(up_button) == LOW && Hour < 23 && leftstate == true && settime == false)
  {
    Hour++;
    String e = (String)Hour;
    for (int i = 0 ; i < e.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, e[i], WHITE, 2);
    }
  }
  if (settime == false)
  {
    lcd.drawString(10, 20, str, WHITE, 2);
    lcd.drawString(1, 50, str2, WHITE, 2);
    lcd.drawChar( 60, 80, ':', WHITE, 2);
  }
  if (digitalRead(select_button) == LOW && settime == false)
  {
    times = Hour * 100 + Min + 10000;
    mySerial.print(times);
    Serial.println(times);
    delay(500);
  }
  if (digitalRead(start_button) == LOW && settime == false)
  {
    settime = true;
    lcd.fillScreen(BLUE);
    lcd.drawChar( 60, 80, ':', WHITE, 2);
    lcd.fillRect(80, 100, 30, 5, RED);
    String g = (String)setMin;
    for (int i = 0 ; i < g.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, g[i], WHITE, 2);
    }
    String h = (String)setHour;
    for (int i = 0 ; i < h.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, h[i], WHITE, 2);
    }
    
    
  }
  if (digitalRead(start_button) == LOW && settime == true)
  {
    lcd.fillScreen(BLUE);
    settime = false;
  }
  if (digitalRead(right_button) == LOW && leftstate == true && settime == true)
  {
    leftstate = false;
    rightstate = true;
    if (rightstate == true)
    {
      lcd.fillRect(80, 100, 30, 5, RED);
    }
    if (leftstate == false)
      lcd.fillRect(20, 100, 30, 5, BLUE);
  }
  if (digitalRead(left_button) == LOW && rightstate == true && settime == true)
  {
    leftstate = true;
    rightstate = false;
    if (leftstate == true)
    {
      lcd.fillRect(20, 100, 30, 5, RED);
    }
    if (rightstate == false)
      lcd.fillRect(80, 100, 30, 5, BLUE);
  }

  if (digitalRead(down_button) == LOW && setMin > 0 && rightstate == true && settime == true)
  {
    setMin--;
    String g = (String)setMin;
    for (int i = 0 ; i < g.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, g[i], WHITE, 2);
    }
  }
  if (digitalRead(up_button) == LOW && setMin < 59 && rightstate == true && settime == true)
  {
    setMin++;
    String g = (String)setMin;
    for (int i = 0 ; i < g.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, g[i], WHITE, 2);
    }
  }

  if (digitalRead(down_button) == LOW && setHour > 0 && leftstate == true && settime == true)
  {
    setHour--;
    String h = (String)setHour;
    for (int i = 0 ; i < h.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, h[i], WHITE, 2);
    }
  }
  if (digitalRead(up_button) == LOW && setHour < 23 && leftstate == true && settime == true)
  {
    setHour++;
    String h = (String)setHour;
    for (int i = 0 ; i < h.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, h[i], WHITE, 2);
    }
  }
  if (settime == true)
  {
    lcd.drawString(10, 20, str3, WHITE, 2);
    lcd.drawString(1, 50, str4, WHITE, 2);
    lcd.drawChar( 60, 80, ':', WHITE, 2);
    String a = (String)hour;
    for (int i = 0 ; i < a.length(); i++)
    {
      lcd.fillRect(10 + i * 15, 110, 25, 20, BLUE);
      lcd.drawChar(10 + i * 15, 110, a[i], WHITE, 2);
    }
    String b = (String)minute;
    for (int i = 0 ; i < a.length(); i++)
    {
      lcd.fillRect(50 + i * 15, 110, 25, 20, BLUE);
      lcd.drawChar(50 + i * 15, 110, b[i], WHITE, 2);
    }
    String s = (String)second;
    for (int i = 0 ; i < s.length(); i++)
    {
      lcd.fillRect(90 + i * 15, 110, 25, 20, BLUE);
      lcd.drawChar(90 + i * 15, 110, s[i], WHITE, 2);
    }
  }
  if (digitalRead(start_button) == LOW && settime == true)
  {
    settime = false;
    lcd.fillScreen(BLUE);
    lcd.drawChar( 60, 80, ':', WHITE, 2);
    lcd.fillRect(80, 100, 30, 5, RED);
    String c = (String)Min;
    for (int i = 0 ; i < c.length(); i++)
    {
      lcd.fillRect(80 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(80 + i * 15, 80, c[i], WHITE, 2);
    }
    String e = (String)Hour;
    for (int i = 0 ; i < e.length(); i++)
    {
      lcd.fillRect(20 + i * 15, 80, 25, 20, BLUE);
      lcd.drawChar(20 + i * 15, 80, e[i], WHITE, 2);
    }
  }
  if (digitalRead(select_button) == LOW && settime == true)
  {
     hour = setHour;
  minute = setMin;
    times = (setHour * 100 + setMin);
    mySerial.print(times);
    Serial.println(times);
    delay(500);
  }

}
void plot (uint8_t x, uint8_t y, bool value)

{

  uint8_t address;                                      /* select which matrix depending on the x coord  */

  if (x >= 0  && x <= 7)  {

    address = 3;

  }

  if (x >= 8  && x <= 15) {

    address = 2;

    x = x - 8;

  }

  if (x >= 16 && x <= 23) {

    address = 1;

    x = x - 16;

  }

  if (x >= 24 && x <= 31) {

    address = 0;

    x = x - 24;

  }
  

}
void clocks()

{
  if (second == 0)

  {

    plot(10, 2, 0);

    plot(10, 4, 0);

    plot(20, 2, 0);

    plot(20, 4, 0);

  }

  else

  {

    plot(10, 2, 1);

    plot(10, 4, 1);

    plot(20, 2, 1);

    plot(20, 4, 1);

  }
  // display second count line

  if (second < 30)

  {

    plot(second + 1, 7, 1);

  }

  else

  {

    plot(60 - second, 7, 0);

  }

}



ISR(TIMER1_OVF_vect)        // interrupt service routine

{

  TCNT1 = 3036;             /* preload timern */

  Serial.println(second++);

  if (second > 59) {

    second = 0; minute++;

  }

  if (minute > 59) {

    minute = 0; hour++;

  }

  if (hour > 23) {

    hour = 0;

  }
}
