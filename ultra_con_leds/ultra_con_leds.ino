#include <NewPing.h>

#define TRIGGER_PIN_1 5
#define ECHO_PIN_1 6

#define TRIGGER_PIN_2 7
#define ECHO_PIN_2 8

#define MAX_DISTANCE 200

NewPing sensor_1(TRIGGER_PIN_1,ECHO_PIN_1,MAX_DISTANCE);
NewPing sensor_2(TRIGGER_PIN_2,ECHO_PIN_2,MAX_DISTANCE);

int led1 = 9;  //derecho abajo
int led2 = 10; //derecha arriba
int led3 = 11; //izquierda arriba
int led4 = 12; //izquierda abajo

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.write(12);

}

void loop() {

  //Conversión a integer de cm's 

int val_sen_1 = sensor_1.ping_cm();

int val_sen_2 = sensor_2.ping_cm();
  
  // put your main code here, to run repeatedly:
delay(2000);
Serial.print("distancia del sensor 1  ");
Serial.print(sensor_1.ping_cm());
Serial.println("cm");

delay(2000);
Serial.print("distancia del sensor 2  ");
Serial.print(sensor_2.ping_cm());
Serial.println("cm");

if (val_sen_1 > 7){
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
}
else{
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
}
if (val_sen_2 > 7){
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
}
else{
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led1,HIGH);
}
}
