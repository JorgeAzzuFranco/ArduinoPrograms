//Jorge Azzulito Franco
//Enciende LED con un botón físico
//Boton conectado a pin 8
//Led conectado a pin 0

void setup() {
  pinMode(0, OUTPUT);
  pinMode(8, INPUT);
}

const int boton = 8;
const int led =  0;
int estadoBoton = 0;

void loop() {
  
  estadoBoton = digitalRead(boton);

  if (estadoBoton == HIGH) {
    // Enciende LED
    digitalWrite(led, HIGH);
  } else {
    // Apaga LED
    digitalWrite(led, LOW);
  }
}
