#include <Wire.h>
/* LCD Screen */
#include <LiquidCrystal_I2C.h>
/*  Temperature humidity sensor */
#include <DHT.h>
#define datapin 7     // Digital  pin we're connected to
#define DHTTYPE DHT22
DHT dht(datapin, DHTTYPE);
// Set the LCD I2C address (commonly 0x27 or 0x3F)
// If unsure, run an I2C scanner sketch first
LiquidCrystal_I2C lcd(0x27, 16, 2);

void  setup() {
  Serial.begin(9600);
  dht.begin(); 
  lcd.init();               // Initialize the LCD
  lcd.backlight();          // Turn on the backlight
}

void loop() {

  /* Find Temperature & Humidity */
  float air_temp = dht.readTemperature();
  float humidity = dht.readHumidity();
      
  /* Print Output on LCD Screen  */
  // Display temperature on first line
  lcd.setCursor(0, 0);  // (column, row)
  lcd.print("Temp: ");
  lcd.print(air_temp, 1); // one decimal place
  lcd.print((char)223);   // degree symbol
  lcd.print("C   ");      // spaces to clear leftovers

  // Display humidity on second line
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity, 1);
  lcd.print("%   ");
  delay(1000); // Update every second
}
