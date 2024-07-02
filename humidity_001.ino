//ARDUINO HUMIDITY MEASURING SYSTEM - 6/23/2024 - GROUP 4
//CREATED BY: MANESHA FERNANDO


//LIBRARIES
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

//OBJECT NAME
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT11 manesha(6);

void setup() {

  pinMode(4, OUTPUT); // FILAMENT BULB CONTROL
  pinMode(5, OUTPUT); // MIST MAKER CONTROL
  

  //LCD INITIALIZATION
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);



  //WELCOME MESSAGE..
  lcd.setCursor(0,0);
  lcd.print("WELCOME !!");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("ARDUINO HUMIDITY");
  lcd.setCursor(0,1);
  lcd.print("CONTROL SYSTEM");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("GROUP 4");
  delay(3000);
  lcd.clear();

}

void loop() {

  int waterLvl = analogRead(A3);
  int humidity = manesha.readHumidity();


  //DISPLAY HUMIDITY MEASURMENT ON LCD SCREEN - ROW 1
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(humidity);
  lcd.print("%");

//DISPLAY WATER LEVEL MEASURMENT ON LCD SCREEN - ROW 2
  if (waterLvl < 530){
    lcd.setCursor(0,1);
    lcd.print("Water Lvl = LOW");
  }

  else if (waterLvl < 600 && waterLvl > 530){
    lcd.setCursor(0,1);
    lcd.print("Water Lvl = HALF");
  }

  else if (waterLvl > 600){
    lcd.setCursor(0,1);
    lcd.print("Water Lvl = FULL");
  }


//RELAY CONTROL MECHANISM - FOR FILAMENT AND MIST MAKER
//NEED CALIBRATION DEPENDING ON THE ENVIRONMENT
//THRESHOLD VALUE = 80% WITH +-2% TOLERANCE
  if (humidity < 79) {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }
  else if (humidity > 81){
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

}
