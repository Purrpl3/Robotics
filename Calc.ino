#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define buttonScroll 2
#define buttonSelect 3

const int maxModeSel = 4;

//Calculator Function, number when reached will return to 0
const int maxCalcSel = 4;
const int maxCalcNumSel = 10;

/*
Numbers 0
Operations 1
Trigonometric 2
Other 3
*/

//Global Selection Scroll
int selection = 0;

/* Selection number
Calculator 0
Complex 1
Inequality 2
Polynomial 3
*/

// SDA = A4, SCL = A5
LiquidCrystal_I2C lcd(0x27, 16, 2);

void funcDispMode() {
lcd.setCursor(0, 0);
  switch(selection) {
    case(0):
      lcd.print("Calculator");
      lcd.setCursor(0, 1);
      lcd.print("Complex");
      break;
    case(1):
      lcd.print("Complex");
      lcd.setCursor(0, 1);
      lcd.print("Inequality");
      break;
    case(2):
      lcd.print("Inequality");
      lcd.setCursor(0, 1);
      lcd.print("Polynomial");
      break;
    case(3):
      lcd.print("Polynomial");
      lcd.setCursor(0, 1);
      lcd.print("Calculator");
      break;
  }
}

void funcSelect() {
  switch(selection) {
    case(0):
      funcCalc();
      break;
    case(1):
      break;
    case(2):
      break;
    case(3):
      break;
  }
}

void funcCalc() {
  if (digitalRead(buttonScroll)) {
    funcCalcMenu();
  }
}
void funcCalcMenu() {
  if (digitalRead(buttonScroll)) {
    selection++;
  }
  if (digitalRead(buttonSelect)) {
    if (selection == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Number:");
      lcd.setCursor(0, 1);
      int n = 0;
      lcd.print(n);
      if (digitalRead(buttonScroll)) {
        n++;
      } else if (digitalRead(buttonSelect)) {
        //Add n to main array
      }
    }
  }
}

void setup() {
  pinMode(buttonScroll, INPUT);
  pinMode(buttonSelect, INPUT);

  lcd.init();
  lcd.backlight();

  funcDispMode();
  if (digitalRead(buttonScroll)) {
    selection++;

    if (selection == maxModeSel) { //Change as necessary
      selection = 0;
    }
  }
  if (digitalRead(buttonSelect)) {
    funcSelect();
  }
}

void loop() {
}
