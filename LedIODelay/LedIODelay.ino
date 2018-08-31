//Jorge Azzulito Franco
//Prueba de escritura analoga
//Anodo pin 3
//Catodo resistencia 330 Ohms - GND

void setup() {
  pinMode(3,OUTPUT);
}

void loop() {
  
  for(int brillo = 0; brillo < 256; brillo++){
      analogWrite(3,brillo);
      delay(10);
    }
  
    for(int brillo = 255; brillo >= 0 ; brillo--){
      analogWrite(3,brillo);
      delay(10);
    }
}
