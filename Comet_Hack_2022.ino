#include <LiquidCrystal.h>
#include <Servo.h> 

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
int Clocation = 7;
int button = 8;
byte block[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
int angle = 360;

void setup() {
  Servo1.attach(servoPin);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Fishy!!!");
  lcd.setCursor(0, 1);
  lcd.print("Hunger:");

  lcd.createChar(0, block);
  
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  int buttonState = digitalRead(button);
  int hunger = Clocation - 7;
  if(buttonState == LOW){
    for (int i = 7; i < 16; i++){
      lcd.setCursor(i, 1);
      lcd.print(" ");
      Clocation = 7;
      }
      Servo1.write((90+(5*hunger))); 
      delay(1000);
      Servo1.write((0));
      hunger = 0;
    }
  
  if((millis()%5000) == 1){
    if(Clocation >= 16){
      lcd.setCursor(7, 1);
      lcd.print(" STARVING");
      }
    else{
      lcd.setCursor(Clocation, 1);
       lcd.write(byte(0));
      Clocation = Clocation+1;
      }
    delay(100);
    
    }  
}
