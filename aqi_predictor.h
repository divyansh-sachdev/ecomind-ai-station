#ifndef AQI_PREDICTOR_H
#define AQI_PREDICTOR_H

#include <Arduino.h>

struct EcoData {
    int pm2_5;
    int pm10;
    float gasVocPpm;
    float tempC;
    float humidity;
};

inline int calculateAQI(int pm2_5) {
    if (pm2_5 <= 30) return map(pm2_5, 0, 30, 0, 50);
    if (pm2_5 <= 60) return map(pm2_5, 31, 60, 51, 100);
    if (pm2_5 <= 90) return map(pm2_5, 61, 90, 101, 200);
    if (pm2_5 <= 120) return map(pm2_5, 91, 120, 201, 300);
    return 300 + (pm2_5 - 120);
}

#endif
