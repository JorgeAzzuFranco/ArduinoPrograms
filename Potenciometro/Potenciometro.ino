//Jorge Azzulito Franco
//Uso de potenciometro, lectura y escritura analoga
//Anodo pin 3
//Catodo resistencia 330 Ohms - GND

void setup() {
  
  pinMode(3,OUTPUT);
  //Los pines analogicos estan como entrada por default
}

void loop() {
  
  int brillo = analogRead(A0);
  int pot = map(brillo, 0, 1023, 0, 255);
  analogWrite(3, pot);
}

