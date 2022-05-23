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
  int dataAnalog = analogRead (A0);  //inisialisasi dataAnalog sebagai baca sensor pada pin analog A0
  long nilaiTerendah  = 0;          
  long nilaiTertinggi = 1023;        
  long persentase;
  
  Serial.println(dataAnalog);       //Jika ingin melihat melalui serial monitor
  persentase = map(dataAnalog, nilaiTerendah, nilaiTertinggi, 0, 100);  //Membuat nilai analog menjadi digital
  Serial.println(persentase);
 
  if(dataAnalog>=870)               //Relay Digital (2 output: ON/OFF; Indikator 0 = Basah dan 1 = Kering
  {
    lcd.setCursor(0,0);
    lcd.print("Kekeringan: ");
    lcd.print(persentase);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("= Media Kering =");
    digitalWrite(pompa,1);
  }
  else if(dataAnalog>=500 && dataAnalog<=850)          //Relay Digital (2 output: ON/OFF; Indikator 0 = Basah dan 1 = Kering
  {
    lcd.setCursor(0,0);
    lcd.print("Kekeringan: ");
    lcd.print(persentase);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("= Media Medium =");
    digitalWrite(pompa,0);
  }
  else if(dataAnalog<=450)
  {
    lcd.setCursor(0,0);
    lcd.print("Kekeringan: ");
    lcd.print(persentase);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("= Media  Basah =");
    digitalWrite(pompa,0);
  }
  delay(5000);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Kelompok 4");
  lcd.setCursor(0,1);
  lcd.print("Embedded System ");
  delay(1000);
}
