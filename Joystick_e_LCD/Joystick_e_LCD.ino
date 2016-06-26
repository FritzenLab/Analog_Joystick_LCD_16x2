/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
int eixoX = A0;
int eixoY = A1;
float valorX = 0;
float valorY = 0;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Mova o cursor");
  lcd.setCursor(0, 1);
  lcd.print("em qualquer eixo");
}

void loop() {

  delay(50);
  valorX = analogRead(eixoX);
  valorY = analogRead(eixoY);

  if ((valorY || valorX > 518) || (valorY || valorX < 506)){
    
  } else {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Centro");
  }
 
  if ((valorX > 518) && ((valorY > 506) && (valorY <518))) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sul");
    lcd.setCursor(2, 1);
    lcd.print(valorX*0.3519,0);
    lcd.setCursor(7, 1);
    lcd.print("graus");
  } 
  if ((valorX < 506) && ((valorY > 506) && (valorY <518))) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Norte");
    lcd.setCursor(2, 1);
    lcd.print(valorX*0.3519,0);
    lcd.setCursor(7, 1);
    lcd.print("graus");
  }
  if ((valorY > 518) && ((valorX > 506) && (valorX <518))) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Leste");
    lcd.setCursor(2, 1);
    lcd.print(valorY*0.3519,0);
    lcd.setCursor(7, 1);
    lcd.print("graus");
  } 
  if ((valorY < 506) && ((valorX > 506) && (valorX <518))){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Oeste");
    lcd.setCursor(2, 1);
    lcd.print(valorY*0.3519,0);
    lcd.setCursor(7, 1);
    lcd.print("graus");
  }

 
  
  
}

