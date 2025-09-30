/*  Temperature humidity sensor */
#include <DHT.h>
#define datapin 7     // Digital  pin we're connected to
#define DHTTYPE DHT22
DHT dht(datapin, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Find Temperature & Humidity */
  float air_temp = dht.readTemperature();
  float humidity = dht.readHumidity();

/* //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Temp: ");
  Serial.print(air_temp);
  Serial.println(" Celsius");
*/
 
 // Print for graphing
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(air_temp);
  Serial.println();
  delay(2000);
}
