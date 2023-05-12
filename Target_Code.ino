#include <IRremote.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);
int a = 0;

void setup () {
  IrReceiver.begin(8, ENABLE_LED_FEEDBACK);
  lcd.begin(16,2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop () {
  if (IrReceiver.decode()) {
    lcd.print("Target Hit!!!");
   while(a < 15) {
   digitalWrite(13, HIGH);
   delay(150);
   digitalWrite(13, LOW);

   digitalWrite(12, HIGH);
   delay(150);
   digitalWrite(12, LOW);

   digitalWrite(11, HIGH);
   delay(150);
    digitalWrite(11, LOW);

    digitalWrite(10, HIGH);
    delay(150);
    digitalWrite(10, LOW);
    a = a+1;
    }
    lcd.clear();
    IrReceiver.resume();
  }
  else {
    IrReceiver.resume();
  }
}
