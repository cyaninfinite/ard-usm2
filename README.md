# ard-usm2
<a href="LICENSE" ><img src="https://img.shields.io/github/license/1487quantum/ard-usm2?style=flat-square"/></a>
<a href="https://github.com/1487quantum/ard-ultrasonic-pong/actions/workflows/ard-ci.yml" ><img src="https://img.shields.io/github/workflow/status/1487quantum/ard-usm2/Arduino-CI?label=Build&logo=arduino&style=flat-square"/></a>

<a href="https://cyaninfinite.com/ultrasonic-sensor-projects/" ><img src="https://img.shields.io/badge/Documentation-@Cyaninfinite-blue?style=for-the-badge"/></a>


Arduino Ultrasonic Musical Keyboard (Version 2), powered by Maker Uno. Uses the ssd1306 0.96" OLED Display (I2C) and u8g2 library for display.


## Components

- Maker Uno (Arduino Uno can also be used, just update the pin constants accordingly)
- SSD1306 0.96" OLED Display (I2C)
- Ultrasonic Sensor [PING))) Ultrasonic Distance Sensor]

## Schematics
```

                            (Toggle Buzzer mode)

                              ----_|__--------------
                              |                 SCL|  <--> Display (SCL)
                              |     Maker       SDA|  <--> Display (SDA)
                              |      UNO       AREF|
                              |                 GND|
                              |reserved          13|
                              |IOREF             12|                              
                              |RESET           ~ 11|
          Display (VCC) <-->  |3.3V            ~ 10|                        
 Ultrasonic Sensor (5V) <-->  |5.0V            ~  9|  <--> Ultrasonic Sensor (SIG)
Ultrasonic Sensor (GND) <-->  |GND                8|  <--> Piezo Speaker (Onboard)
          Display (GND) <-->  |GND                 |
                              |Vin                7|
                              |                ~  6|
                              |A0              ~  5|                                
                              |A1                 4|
                              |A2              ~  3|
                              |A3                 2|
                              |A4 SDA          TX 1|   
                              |A5 SCL  ICSP    RX 0|   
                              ----------------------   

```
## Libraries
The `u8g2` graphics library is required, ensure that it is installed before running the code. (The library could be install via the Library Manager.)

More info on the library: https://github.com/olikraus/u8g2

# License
Licensed under the [MIT License](./LICENSE).
