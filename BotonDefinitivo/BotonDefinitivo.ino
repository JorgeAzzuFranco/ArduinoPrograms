void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(2,OUTPUT);
}

estado = 0;
lectura = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13) == HIGH && lectura == 0){
    lectura = !lectura;
    estado = !estado;
    digitalWrite(2,estado);
  }
  if (digitalRead(13) == LOW && lectura == 1){
    lectura = !lectura;
  }
}
