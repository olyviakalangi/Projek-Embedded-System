#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor = A0; 
int pompa = 2;

void setup() {
  lcd.init();                         //inisialisasi LCD
  lcd.backlight();                    //menampilkan ke LCD
  pinMode(pompa,OUTPUT);              //pin 2  sebagai OUTPUT
  pinMode(sensor, INPUT_PULLUP);      //pin A0 sebagai INPUT PULLUP
}

void loop() 
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Kelompok 4");
  lcd.setCursor(0,1);
  lcd.println("Embedded System ");
  delay(1000);
 
  //lcd.setCursor(2,0);
  //lcd.print("Status Media");
  
  if(digitalRead(sensor)==1)          //Relay Digital (2 output: ON/OFF; Indikator 0 = Basah dan 1 = Kering
  {
    lcd.setCursor(0,1);
    lcd.print(" Media Kering  ");
    digitalWrite(pompa,1);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("   Media basah  ");
    digitalWrite(pompa,0);
  }
  delay(5000);
}
