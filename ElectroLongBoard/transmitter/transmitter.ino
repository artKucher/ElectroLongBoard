

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#define pot A0

RF24 radio(9,10);

int forservo;

void setup(){
    Serial.begin(9600);
    radio.begin();
    delay(50);
    radio.setChannel(5);
    radio.setDataRate     (RF24_250KBPS);                   // Указываем скорость передачи данных (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS), RF24_1MBPS - 1Мбит/сек
    radio.setPALevel      (RF24_PA_HIGH);                 // Указываем мощность передатчика (RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm)
    radio.openWritingPipe (0x1488133766LL);
    pinMode(pot,INPUT);
}
void loop(){
    forservo = map(analogRead(pot),485,750,0,180);
    forservo = constrain(forservo,0,180);
    radio.write(&forservo, sizeof(forservo));
    delay(50);
}
