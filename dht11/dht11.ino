#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  float temperatureC = dht.readTemperature();
  float humidity = dht.readHumidity();
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1); 
  lcd.print("C");
  lcd.setCursor(0, 1); 
  lcd.print("Humidity: ");
  lcd.print(humidity, 1); 
  lcd.print("%");
  delay(2000);
}
