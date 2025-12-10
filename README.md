# EcoMind AI Station

An autonomous edge AI environmental sensing station that captures fine particulates (PM1.0, PM2.5, PM10), harmful gases (CO, NOx, VOCs), temperature, and barometric pressure. Uses local trend estimation to forecast Air Quality Index (AQI) spikes up to 4 hours in advance.

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
