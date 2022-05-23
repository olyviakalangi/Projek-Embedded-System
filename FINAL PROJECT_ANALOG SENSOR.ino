#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pompa = 2;

void setup() {
  Serial.begin(9600);
  lcd.init();                         //inisialisasi LCD
  lcd.backlight();                    //menampilkan ke LCD
  pinMode(pompa,OUTPUT);              //pin 2  sebagai OUTPUT
}

void loop() 
{
  int dataAnalog = analogRead (A0);  //inisialisasi dataAnalog sebagai baca sensor pada pin analog
  Serial.println(dataAnalog);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Kelompok 4");
  lcd.setCursor(0,1);
  lcd.println("Embedded System ");
  delay(1000);
 
  //lcd.setCursor(2,0);
  //lcd.print("Status Media");
  
  if(dataAnalog>=900)          //Relay Digital (2 output: ON/OFF; Indikator 0 = Basah dan 1 = Kering
  {
    lcd.setCursor(0,1);
    lcd.print(" Media Kering  ");
    digitalWrite(pompa,1);
  }
  if(dataAnalog>=500 && dataAnalog<=850)          //Relay Digital (2 output: ON/OFF; Indikator 0 = Basah dan 1 = Kering
  {
    lcd.setCursor(0,1);
    lcd.print(" Media Medium  ");
    digitalWrite(pompa,0);
  }
  if(dataAnalog<=450)
  {
    lcd.setCursor(0,1);
    lcd.print("   Media basah  ");
    digitalWrite(pompa,0);
  }
  delay(5000);
}
