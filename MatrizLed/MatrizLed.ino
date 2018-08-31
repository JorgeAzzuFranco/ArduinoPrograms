//Jorge Azzulito Franco
//Enciende completamente una matriz LED 6x6
//Anodos en pines 0 - 5
//Catodos con resistencia 330 Ohms 6 - 11

void setup() {
  for(int i = 0; i < 12; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){

  for(int i = 0; i < 6; i++){
    digitalWrite(i, HIGH);
  }

  for(int i = 6; i < 12; i++){
    digitalWrite(i, LOW);
  }

  delay(100);
}
