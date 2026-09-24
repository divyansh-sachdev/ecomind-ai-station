<div align="center">

# EcoMind AI Station

**Autonomous environmental sensing station with standards-compliant AQI computation**

![Domain](https://img.shields.io/badge/Domain-Environmental_Sensing-00F3FF?style=for-the-badge) ![Platform](https://img.shields.io/badge/Platform-ESP32_Edge-9D00FF?style=for-the-badge) ![Index](https://img.shields.io/badge/Index-CPCB_AQI-0066FF?style=for-the-badge)

![ESP32](https://img.shields.io/badge/ESP32-0D1117?style=flat-square&logo=espressif&logoColor=white) ![Arduino](https://img.shields.io/badge/Arduino-0D1117?style=flat-square&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C++-0D1117?style=flat-square&logo=cplusplus&logoColor=white) ![PMS5003](https://img.shields.io/badge/PMS5003-0D1117?style=flat-square) ![BME280](https://img.shields.io/badge/BME280-0D1117?style=flat-square) ![MQ--135](https://img.shields.io/badge/MQ--135-0D1117?style=flat-square)

</div>

---

## Overview

A self-contained air-quality station that measures fine particulates, gas contaminants, temperature,
humidity and barometric pressure, then converts the raw particulate reading into a published Air
Quality Index on the device itself.

The conversion is the substantive part: raw &micro;g/m&sup3; means nothing to a non-specialist, while
an AQI band maps directly onto public-health guidance. The station implements the piecewise-linear
breakpoint mapping from the standard AQI scale so its output is directly comparable with official
monitoring stations rather than being an arbitrary internal score.

## Domain &amp; Techniques

| Layer | Implementation |
| :--- | :--- |
| **Particulate Sensing** | Plantower PMS5003 laser-scattering counter over hardware UART2, reporting PM1.0 / PM2.5 / PM10 |
| **Gas Sensing** | MQ-135 broad-spectrum contaminant sensor on ADC1 for CO, NO&#8339; and VOC presence |
| **Atmospheric Context** | Bosch BME280 for temperature, relative humidity and barometric pressure over I2C |
| **AQI Computation** | Piecewise-linear interpolation across the standard PM2.5 breakpoint table (0&ndash;30, 31&ndash;60, 61&ndash;90, 91&ndash;120, 120+) into the 0&ndash;500 AQI scale |
| **Autonomy** | All computation is local — the station produces a usable index with no network connection |

## Pipeline

```
PMS5003 --UART2--> PM1.0 / PM2.5 / PM10 --+
                                          |
MQ-135  --ADC---->  gas / VOC ------------+--> EcoData record
                                          |
BME280  --I2C---->  temp / RH / pressure -+
                                          |
                                          v
                        [ PM2.5 breakpoint interpolation ]
                                          |
                                          v
                             AQI 0-500 + health band
```

## Sensor Suite

- **Plantower PMS5003**: Precision laser scattering particle counter.
- **Bosch BME280**: Temperature, relative humidity, and barometric pressure.
- **MQ-135 Gas Sensor**: Broad-spectrum air contaminant detection.

## Hardware Wiring

| Device | Interface | ESP32 Pins |
| --- | --- | --- |
| PMS5003 | Hardware UART2 | GPIO 16 (RX), GPIO 17 (TX) |
| BME280  | I2C            | GPIO 21 (SDA), GPIO 22 (SCL) |
| MQ-135  | Analog In      | GPIO 34 (ADC1) |

## Repository Layout

| Path | Purpose |
| :--- | :--- |
| `EcoMindStation.ino` | Main firmware — multi-sensor polling and reporting |
| `aqi_predictor.h` | `EcoData` record and `calculateAQI()` breakpoint interpolation |
| `config.example.h` | Calibration constants — copy to `config.h` |

## Project Status

**Implemented:** multi-sensor acquisition across UART / I2C / analog, and standards-compliant AQI
computation from PM2.5.

**Roadmap:** the station currently reports the *present* AQI rather than forecasting it. Forecasting
is the intended next stage and needs two things this build does not yet have: a rolling history buffer
in flash, and a trend model over that history. A linear or exponential-smoothing extrapolation over a
few hours of retained samples is the realistic first version; the humidity and pressure channels are
already captured because they are the useful covariates for that model.

---

<div align="center">
  <sub>
    Part of the <b>AI + Robotics</b> engineering portfolio of
    <a href="https://github.com/divyansh-sachdev">Divyansh Sachdev</a><br>
    90+ national &amp; international competition wins &middot; IIT / NIT / IIIT podiums
  </sub>
</div>
