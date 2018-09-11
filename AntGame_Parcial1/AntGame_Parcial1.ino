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

int matVirt[dpi][dpi] =
  //Matriz virtual
{ //Columna
  {0, 0, 0, 0, 0, 0}, //fila 0
  {0, 0, 0, 0, 0, 0}, //fila 1
  {0, 0, 0, 0, 0, 0}, //fila 2
  {0, 0, 0, 0, 0, 0}, //fila 3
  {0, 0, 0, 0, 0, 0}, //fila 4
  {0, 0, 0, 0, 0, 0}  //fila 5
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

  posX = map(analogRead(A1), 0, 1023, 0, 5);
  posY = map(analogRead(A0), 0, 1023, 0, 5);

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

void validarGanador(){
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

void showGanador(){
  int tiempo = 0;
  while(tiempo < 1000){
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
}

void printMatriz() {
  for (int repeticion = 0; repeticion < 50; repeticion++) {
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
