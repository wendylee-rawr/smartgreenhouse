/* Servo */
#include <Servo.h>
Servo myservodoor;
Servo myservoflap;

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
  myservodoor.attach(A0);  // attaches the servo on pin A0 to the servo object
  myservoflap.attach(A1);  // attaches the servo on pin A1 to the servo object
}

void loop() {

  /* Find Temperature & Humidity */
  float air_temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  /* Check if reading failed */
  if (isnan(air_temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  /* Print Output on LCD Screen  */
  lcd.setCursor(0,0);
  lcd.print(String("Temp. ") + String(air_temp));
  lcd.setCursor(0,1);
  lcd.print(String("Humidity ") + String(humidity) + String("%"));
/*
myservoflap.write(100); // close
myservodoor.write(0); //open
delay(2000);
myservoflap.write(0);
myservodoor.write(100);
*/
  // Servo control based on temperature
/*
  if (air_temp >= 23) {
    myservodoor.write(0); // Move to 100 degrees open
    myservoflap.write(100); // Move to 100 degrees open
  } else if (air_temp <= 22) {
    myservodoor.write(100); // Move to 0 degrees close
    myservoflap.write(0); // Move to 0 degrees close
  } 
*/

// Servo control based on  humidity (easier to test)

  if (humidity >= 51) {
    myservodoor.write(0); // too humid open
    myservoflap.write(100); // 
  } else if (humidity <= 50) {
    myservodoor.write(100); // too dry close
    myservoflap.write(0); // 
  }

  delay(2000); // Wait a few seconds between readings


}
