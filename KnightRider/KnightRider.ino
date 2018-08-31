//Jorge Azzulito Franco
//Enciende una fila de 6 LEDs de izquierda a derecha,
//apaga los anteriores y de derecha a izquierda y 
//apaga los anteriores
//Pines 0 - 6

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 6; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  
  for(int i = 0; i < 6; i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
  
  for(int i = 6; i > 0; i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
}

