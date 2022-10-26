#include <NewPing.h>
#include <ezButton.h>

#define TRIGGER_PIN_1 5
#define ECHO_PIN_1 6

#define TRIGGER_PIN_2 7
#define ECHO_PIN_2 8

#define MAX_DISTANCE 200

ezButton limitSwitch(7);

NewPing sensor_1(TRIGGER_PIN_1,ECHO_PIN_1,MAX_DISTANCE);
NewPing sensor_2(TRIGGER_PIN_2,ECHO_PIN_2,MAX_DISTANCE);

int led1 = 9;  //derecha arriba
int led2 = 10; //izquierda arriba
int led3 = 11; //derecha abajo
int led4 = 12; //izquierda abajo
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.write(12);

Serial.begin(9600);
limitSwitch.setDebounceTime(50);
}

void loop() {
  // put your main code here, to run repeatedly:
limitSwitch.loop();


  //Conversión a integer de cm's 

int val_sen_1 = sensor_1.ping_cm();

int val_sen_2 = sensor_2.ping_cm();
  

delay(2000);
Serial.print("distancia del sensor 1  ");
Serial.print(sensor_1.ping_cm());
Serial.println("cm");

delay(2000);
Serial.print("distancia del sensor 2  ");
Serial.print(sensor_2.ping_cm());
Serial.println("cm");

if(limitSwitch.isPressed())
    Serial.println("The limit switch: UNTOUCHED -> TOUCHED");  //este pedo es cuando se presiona
  digitalWrite(led4,HIGH); // gira pa tras
  digitalWrite(led3,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);

if(limitSwitch.isReleased())
    Serial.println("The limit switch: TOUCHED -> UNTOUCHED"); //cuando se queda despues de la presionada

int state = limitSwitch.getState();

if(state == HIGH)
    Serial.println("The limit switch: UNTOUCHED");
    
else
    Serial.println("The limit switch: TOUCHED");
    


if (val_sen_1 > 7){
  digitalWrite(led4,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led1,HIGH);
}
else{
  digitalWrite(led4,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
}
if (val_sen_2 > 7){
  digitalWrite(led4,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led1,HIGH);
}
else{
  digitalWrite(led4,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led1,HIGH);
}
}
