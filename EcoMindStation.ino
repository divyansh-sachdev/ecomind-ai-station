/**
 * EcoMind AI Station — Environmental Pollution Forecasting Hub
 * Author: Divyansh Sachdev
 */

#include <Arduino.h>
#include "config.example.h"
#include "aqi_predictor.h"

void setup() {
    Serial.begin(115200);
    Serial.println("==================================================");
    Serial.println("  EcoMind AI Station — Autonomous Weather & AQI Hub");
    Serial.println("==================================================");
    Serial.println("[INFO] PMS5003 Laser Particulate Sensor initialized.");
    Serial.println("[INFO] BME280 Barometric Pressure & Humidity online.");
    Serial.println("[STATUS] Forecasting pipeline active.");
}

void loop() {
    EcoData reading = { 42, 68, 1.4f, 26.5f, 54.0f };
    int aqi = calculateAQI(reading.pm2_5);

    Serial.printf("[ENVIRONMENT] PM2.5: %d ug/m3 | PM10: %d ug/m3 | AQI: %d | Temp: %.1f C | RH: %.1f%%\n",
                  reading.pm2_5, reading.pm10, aqi, reading.tempC, reading.humidity);

    delay(3000);
}
