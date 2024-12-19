#include <NewPing.h>
#include <Servo.h>
Servo serv;

int range;

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

void setup(){
  Serial.begin(115200);
  serv.attach(9);
}

void loop(){
  delay(100);
  unsigned int uS = sonar.ping();
  range = uS / US_ROUNDTRIP_CM;

  if (range <= 60 ){
    serv.write(0);
  }else if (range > 60){
    serv.write(180);
  }
  Serial.print("Jarak: ");              // Tampilkan jarak di serial monitor
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println(" cm");
  delay(500);

}