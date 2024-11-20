#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 23     // Pin yang terhubung ke sensor DHT
#define DHTTYPE DHT22   // Jenis sensor yang Anda gunakan (DHT11/DHT22/DS18B20)

// Alamat I2C LCD
const int lcdAddress = 0x27; // Sesuaikan dengan alamat LCD I2C Anda

// Jumlah kolom dan baris pada LCD
const int lcdColumns = 16;
const int lcdRows = 2;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

void setup() {
  Serial.begin(115200);
  dht.begin();
    // Inisialisasi LCD
  lcd.init();

  // Hidupkan backlight (opsional)
  lcd.backlight();

}

void loop() {
  delay(2000);  // Tunggu 2 detik sebelum membaca suhu lagi

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.setCursor(0, 0);             // Pindah ke baris kedua
  lcd.print("  ");                  // Menghapus nilai sebelumnya
  lcd.setCursor(0, 0);             // Kembali ke baris kedua
  lcd.print("Suhu: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);             // Pindah ke posisi ke-9 pada baris kedua
  lcd.print("  ");                  // Menghapus nilai sebelumnya
  lcd.setCursor(0, 1);             // Kembali ke posisi ke-9 pada baris kedua
  lcd.print("Lembab: ");
  lcd.print(humidity);
  lcd.print("%");
}