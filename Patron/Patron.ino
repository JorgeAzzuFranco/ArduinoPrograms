//Jorge Azzulito Franco
//Matríz LED 6x6 simulando pantalla.
//Escribe tu mensaje en la matríz
//Anodos en pines 0 - 5
//Catodos 6 - 11

void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
}

const int dpi = 6;
const int cambios = 5;

int matriz[cambios][dpi][dpi] =
{
  { //EDO1
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
  },
  { //EDO2
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO3
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO4
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO5
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
  }
};

void loop() {

  limpiar();

  for (int frame = 0; frame < cambios; frame++) { //Controla que arreglo se muestra

    for (int repeat = 0; repeat < 200; repeat++) { //Controla la velocidad con la que hace el patron

      for (int i = 0; i < 6; i++) { //Controla eje Y

        for (int j = 0; j < 6; j++){ //Controla eje X

          if (matriz[frame][i][j] == 1) {
            digitalWrite(i, HIGH);
            digitalWrite(j + 6, LOW);
            limpiar();
          }
          
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

