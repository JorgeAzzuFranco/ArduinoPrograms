const int boton = 13;

void setup() {

  for (int i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(boton, INPUT);

}

//Variables
const int dpi = 6; //densidad de pantalla
int contador = 35; //LEDs restantes
int posX;
int posY;
int lectura = 0;
int matriz[1][dpi][dpi] =
{ //Matriz fisica
  { //Columna
    {1, 1, 1, 1, 1, 1}, //fila 0
    {1, 1, 1, 1, 1, 1}, //fila 1
    {1, 1, 1, 1, 1, 1}, //fila 2
    {1, 1, 1, 1, 1, 1}, //fila 3
    {1, 1, 1, 1, 1, 1}, //fila 4
    {1, 1, 1, 1, 1, 1}  //fila 5
  }
};
int matrix[1][dpi][dpi] =
{ //Matriz virtual
  { //Columna
    {1, 1, 1, 1, 1, 1}, //fila 0
    {1, 1, 1, 1, 1, 1}, //fila 1
    {1, 1, 1, 1, 1, 1}, //fila 2
    {1, 1, 1, 1, 1, 1}, //fila 3
    {1, 1, 1, 1, 1, 1}, //fila 4
    {1, 1, 1, 1, 1, 1}  //fila 5
  }
};


void loop() {

  botonReinicio();

  posX = map(analogRead(A1), 0, 1023, 0, 5);
  posY = map(analogRead(A0), 0, 1023, 0, 5);

  if (matriz[0][posX][posY] == 1) {
    matriz[0][posX][posY] = 0;
  }

  printMatriz();



}

void limpiarMatriz() {
  //Llena la matriz de unos
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < dpi; j++) {
      for (int k = 0; k < dpi; k++) {
        matriz[i][j][k] = 1;
      }
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

  posX = 1;
  posY = 1;
}

void printMatriz() {
  for (int frame = 0; frame < 1; frame++) { //Frame
    for (int repeticion = 0; repeticion < 50; repeticion++) {
      for (int i = 0; i < dpi; i++) { //Columnas
        for (int j = 0; j < dpi; j++) { //Filas
          if (matriz[frame][i][j] == 1) {
            digitalWrite(i, HIGH);
            digitalWrite(j + 6, LOW);
          }
          limpiar();
        }
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
