#define ds 0
#define st 1
#define sh 2
#define BF 7
#define BB 8
#define BL 9
#define BR 10
#define BD 11
#define BU 12
#define BA 13

void setup() {
  //Shift register pins
  for (int i = 0; i < 3; i++) {
    pinMode(i, OUTPUT);
  }

  //Niveles y apagados
  for (int i = 3; i < 7; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  //Botones
  for (int i = 7; i < 14; i++) {
    pinMode(i, INPUT);
  }

  randomSeed(millis());
  //Serial.begin(9600);
}

int cubo[4][4][4] = {
  { {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },

  { {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },

  { {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },

  { {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  }
};

//Arreglo de Shift register
int arreglo[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int a = 0;

//Variables para movimiento aleatorio
int posX = 600;
int posY = 600;
int posZ = 600;
int direccion = 0;
int tiempo = 0;

void loop() {

  // barrido
  for (int nivel = 3; nivel < 7; nivel++) {

    //Pasar nivel a Shift register
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        arreglo[a] = cubo[nivel - 3][j][k];
        a++;
      }
    }

    a = 0;

    //Pasar a shift register
    for (int i = 15; i >= 0; i--) {
      digitalWrite(ds, arreglo[i]);
      shift();
    }

    store();

    digitalWrite(nivel, LOW);
    limpiar();
    digitalWrite(nivel, HIGH);

  }
  
  moverRand();
  generarMov();
  
}

void shift() {
  digitalWrite(sh, HIGH);
  digitalWrite(sh, LOW);
}

void store() {
  digitalWrite(st, HIGH);
  digitalWrite(st, LOW);
}

void limpiar() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(ds, LOW);
    shift();
  }
  store();
}

void generarMov() {
  if (tiempo == 500) {
    
    direccion = random(1, 7);
    
    tiempo = 0;
  }
  else {
    tiempo++;
  }
}

void moverRand() {  
    
    if (direccion == 1) {
      posY--;
      posY = constrain(posY, 0, 600);
    }
  
    if (direccion == 2) {
      posY++;
      posY = constrain(posY, 0, 600);
    }
  
    if (direccion == 3) {
      posX--;
      posX = constrain(posX, 0, 600);
    }
  
    if (direccion == 4) {
      posX++;
      posX = constrain(posX, 0, 600);
    }
  
    if (direccion == 5) {
      posZ--;
      posZ = constrain(posZ, 0, 600);
    }
  
    if (direccion == 6) {
      posZ++;
      posZ = constrain(posZ, 0, 600);
    }

    int x = posX/200;
    int y = posY/200;
    int z = posZ/200;
  
  limpiarCubo();
  escribirCubo(x, y, z, 1);

}

void limpiarCubo() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cubo[i][j][k] = 0;
      }
    }
  }
}

void escribirCubo(int x, int y, int z, int val) {
  cubo[z][y][x] = val;
}

