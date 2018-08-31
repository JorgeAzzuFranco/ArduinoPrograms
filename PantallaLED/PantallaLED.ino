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
const int frames = 6;

int matriz[frames][dpi][dpi] =
{
  { //EDO1
    {1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0}
  },
  { //EDO2
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO3
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO4
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO5
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
  },
  { //EDO6
    {1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 1}
  }
};

void loop() {

  limpiar();
  delay(500);

  for (int frame = 0; frame < dpi; frame++) {

    for (int repeat = 0; repeat < 600; repeat++) {

      for (int i = 0; i < dpi; i++) {

        for (int j = 0; j < dpi; j++)

          if (matriz[frame][i][j] == 1) {
            digitalWrite(i, HIGH);
            digitalWrite(j + dpi, LOW);
            limpiar();
          }

      }

    }

  }

}

void limpiar() {
  for (int i = 0; i < dpi; i++) {
    digitalWrite(i, LOW);
  }
  for (int i = dpi; i < dpi*2; i++) {
    digitalWrite(i, HIGH);
  }
}

