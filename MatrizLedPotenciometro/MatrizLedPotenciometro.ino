//Jorge Azzulito Franco
//Simulacion de joystick en una matriz LED 6x6
//Necesitas 2 potenciometros
//Potenciometro Y en A0
//Potenciometro X en A1
//Anodos en pines 0 - 5
//Catodos con resistencia 330 Ohms 6 - 11

void setup() {
  
  for(int i = 0; i < 12; i++){
      pinMode(i, OUTPUT);
  }
}

void loop() {

  for(int i = 0; i < 6; i++){
    digitalWrite(i, LOW);
  }
 
  for(int i = 6; i < 12; i++){
    digitalWrite(i, HIGH);
  }
  
  int division = 1023/5;
  int ledY = analogRead(A0);
  int ledX = analogRead(A1);

  //Va de 0 a 5
  digitalWrite(ledY/division,HIGH);

   //Va de 6 a 11
  digitalWrite(ledX/division+6,LOW);
  
}
