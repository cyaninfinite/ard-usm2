# ard-usm2
Arduino Ultrasonic Musical Keyboard, powered by Maker Uno. Uses the ssd1306 0.96" OLED Display (I2C) and u8g2 library for display.

## Components
- Maker Uno
- SSD1306 0.96" OLED Display (I2C)
- Ultrasonic Sensor

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
- u8g2: https://github.com/olikraus/u8g2
