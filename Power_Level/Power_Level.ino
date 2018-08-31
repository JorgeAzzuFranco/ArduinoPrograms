//Jorge Azzulito Franco
//Prueba de lectura analoga, simulacion de power level
//Anodo pin 3 - 5
//Catodo resistencia 330 Ohms - GND

void setup() {
  for(int i=2;i<5;i++){
      pinMode(i,OUTPUT);
    }
    
}

void loop() {
  for(int i=2;i<5;i++){
      digitalWrite(i,LOW);
  }
    
  int divi= 1023/4;
  int foco = analogRead(A0);
  
  digitalWrite((foco/divi)+1,HIGH);
  
  for(int i=1;i<(foco/divi)+1;i++){
      digitalWrite(i,HIGH);
  }
}
