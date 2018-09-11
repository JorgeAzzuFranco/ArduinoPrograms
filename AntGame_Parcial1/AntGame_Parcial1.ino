//Jorge Azzulito Franco
//Juego de la hormiga come cesped con velocidad variada
//Pines (matriz) anodos 0-5, (matriz) catodos 6-11, (boton) 13


const int boton = 13;

void setup() {

  for (int i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(boton, INPUT);


}

//Variables
const int dpi = 6; //densidad de pantalla
int posX;
int posY;
int positionX;
int positionY;
int PosicionX=0;
int PosicionY=0;
int contador = 0;
int lectura = 0;

int matriz[dpi][dpi] =
  //Matriz fisica
{ //Columna
  {1, 1, 1, 1, 1, 1}, //fila 0
  {1, 1, 1, 1, 1, 1}, //fila 1
  {1, 1, 1, 1, 1, 1}, //fila 2
  {1, 1, 1, 1, 1, 1}, //fila 3
  {1, 1, 1, 1, 1, 1}, //fila 4
  {1, 1, 1, 1, 1, 1}  //fila 5
};

int ganador[dpi][dpi] =
{ //Columna
  {0, 1, 1, 1, 1, 0}, //fila 0
  {0, 1, 1, 1, 1, 0}, //fila 1
  {0, 0, 1, 1, 0, 0}, //fila 2
  {0, 0, 1, 1, 0, 0}, //fila 3
  {0, 0, 1, 1, 0, 0}, //fila 4
  {0, 1, 0, 0, 1, 0}  //fila 5
};

void loop() {

  botonReinicio();
  validarGanador();

  positionX = map(analogRead(A1), 0, 1023, 0, 5);
  positionY = map(analogRead(A0), 0, 1023, 0, 5);

  //Joystick
  if (positionX == 0) //Rápido X izquierda
  {
    PosicionX = PosicionX - 5;
    PosicionX = constrain(PosicionX, 0, 50); //En el físico usar 5000
  }
  if (positionX == 1) //Lento X izquierda
  {
    PosicionX = PosicionX - 1;
    PosicionX = constrain(PosicionX, 0, 50);
  }
  if (positionX == 3) //Lento X derecha
  {
    PosicionX = PosicionX + 1;
    PosicionX = constrain(PosicionX, 0, 50);
  }
  if (positionX == 4) //Rápido X derecha
  {
    PosicionX = PosicionX + 5;
    PosicionX = constrain(PosicionX, 0, 50);
  }
  if (positionY == 0) //Rápido Y izquierda
  {
    PosicionY = PosicionY - 5;
    PosicionY = constrain(PosicionY, 0, 50);
  }
  if (positionY == 1) //Lento Y izquierda
  {
    PosicionY = PosicionY - 1;
    PosicionY = constrain(PosicionY, 0, 50);
  }
  if (positionY == 3) //Lento Y derecha
  {
    PosicionY = PosicionY + 1;
    PosicionY = constrain(PosicionY, 0, 50);
  }
  if (positionY == 4) //Rápido Y derecha
  {
    PosicionY = PosicionY + 5;
    PosicionY = constrain(PosicionY, 0, 50);
  }
  //Fin Joystick

  posX = PosicionX/10;
  posY = PosicionY/10;

  if (matriz[posX][posY] == 0) {
    digitalWrite(posX, HIGH);
    digitalWrite(posY + 6, LOW);
  }

  if (matriz[posX][posY] == 1) {
    matriz[posX][posY] = 0;
  }

  printMatriz();
}

void limpiarMatriz() {
  //Llena la matriz de unos
  for (int j = 0; j < dpi; j++) {
    for (int k = 0; k < dpi; k++) {
      matriz[j][k] = 1;
    }
  }
}

void botonReinicio() {
  //Boton, Reiniciará el juego
  if (digitalRead(boton) == HIGH and lectura == 0) {
    lectura = !lectura;
    limpiarMatriz();
  }

  if (digitalRead(boton) == LOW and lectura == 1) {
    lectura = !lectura;
  }

}

void validarGanador() {
  contador = 0;
  for (int i = 0; i < dpi; i++) { //Columnas
    for (int j = 0; j < dpi; j++) { //Filas
      if (matriz[i][j] == 0) {
        contador++;
      }
    }
  }

  if (contador > 35) {
    showGanador();
  }
}

void showGanador() {
  int tiempo = 0;
  while (tiempo < 1000) {
    for (int i = 0; i < dpi; i++) { //Columnas
      for (int j = 0; j < dpi; j++) { //Filas
        if (ganador[i][j] == 1) {
          digitalWrite(i, HIGH);
          digitalWrite(j + 6, LOW);
        }
        limpiar();
      }
    }
    tiempo++;
  }
  limpiarMatriz();
  posX = 0;
  posY = 0;
  positionX = 0;
  positionY = 0;
  PosicionX = 0;
  PosicionY = 0;  
}

void printMatriz() {
  for (int repeticion = 0; repeticion < 20; repeticion++) {
    for (int i = 0; i < dpi; i++) { //Columnas
      for (int j = 0; j < dpi; j++) { //Filas
        if (matriz[i][j] == 1) {
          digitalWrite(i, HIGH);
          digitalWrite(j + 6, LOW);
        }
        limpiar();
      }
    }
  }
}

void limpiar() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(i, LOW);
  }
  for (int i = 6; i < 12; i++) {
    digitalWrite(i, HIGH);
  }
}
