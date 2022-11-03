//Declaro las constantes de los pines donde iran conectados los pines del sensor con los pines del arduino
const int s0 = 9;  
const int s1 = 10;  
const int s2 = 11;  
const int s3 = 12;  
const int out = 13;  

// Variables globales donde se guarda el valor de la intensidad del color detectado
int rojo = 0;  
int verde = 0;  
int azul = 0; 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}

void loop() {
  // put your main code here, to run repeatedly:

//detecta plateado
  if(rojo > 188 && rojo <= 208){
      if(verde > 188 && verde <= 208){
        if(azul > 188 && azul <= 208){
 Serial.println("Detectando color: Plata");  
        }}}

         //detecta negro 
          if(rojo > 0 && rojo <= 20){
      if(verde > 0 && verde <= 20){
        if(azul > 0 && azul <= 20){
 Serial.println("Detectando color: Negro");  
        }}}

// detecta color azul
 if(azul >= 50){
      if(verde <= 20){
        if(rojo <= 20){
 Serial.println("Detectando color: Azul");  
        }}}
}

void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
