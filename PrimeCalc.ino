#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long start = 3;
unsigned long finish = 4294967295;
unsigned long primes = 1; //skips 2

unsigned long n = start;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Total: ");
  lcd.setCursor(0,1);
  lcd.print("Last# ");
}

void writeDisplay(unsigned long value, unsigned long primeCount) {
  lcd.setCursor(7,0);
  lcd.print(primeCount);

  lcd.setCursor(6,1);
  lcd.print(value);
    
  return;
}

void loop() {
  while(n < finish){
    for(unsigned long i = 2;
        i <= n/2+1;
        i++) {
      if(n % i == 0) {
        break;
      }
      else if(i >= n/2) {
        primes++;
        writeDisplay(n, primes);
        break;
      }
    }
    n++;
  }

  //watchdog timer feeder
  while(true){
    char timer = 0;
    for(char i; i <= 5; i++){
      timer++;
      delay(100);
    }
    delay(1000);
  }
}
