#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
RF24 radio(9, 10); 
int msg[2];
Servo motor;
unsigned long time;
void setup(){
  motor.attach(2,800,2200); 
  delay(50);
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(5); 
  radio.setDataRate(RF24_250KBPS); 
  radio.setPALevel(RF24_PA_HIGH); 
  radio.openReadingPipe (1, 0x1488133766LL);
  radio.startListening(); }
void loop() { 
  if (radio.available()){ 
    time = millis();
    radio.read(&msg, sizeof(msg));} 
    if (millis() - time > 1000){
      msg[0]=0;} 
    //Serial.println(msg[0]);
    motor.write(msg[0]);
}
