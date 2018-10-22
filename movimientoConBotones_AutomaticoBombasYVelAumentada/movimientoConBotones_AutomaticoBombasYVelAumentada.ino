//Jorge Azzulito Franco
//Cubo led con shift register. Utilización de un
//control que mueve un led encendido adelante,
//atras, izquierda, derecha, arriba, abajo y un
//boton de acción. Ademas se adiciona un led
//que enciende aleatoriamente y sigue una direccion
//especifica
//Pines 0-2 para shift register, 3-6 para GND
//de niveles y de 7-13 para los botones

#define ds 0
#define st 1
#define sh 2
#define BF 7
#define BB 8
#define BL 9
#define BR 10
#define BD 12
#define BU 11
#define BA 13

int cubo[3][4][4][4] = {
  {
    {
      {1, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    }
  },

  {
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    }
  },

  {
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    },
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
    }
  }
};

int contador = 0;

int arreglo[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//Posicion
int posX = 0;
int posY = 0;
int posZ = 0;

//Variable de control de boton
int bf = 0;
int bb = 0;
int bl = 0;
int br = 0;
int bu = 0;
int bd = 0;
int ba = 0;

//Direccion
int direccion = 0;
int vel = 600;
int division = 200;

//Variables para movimiento aleatorio
int posRx = 600;
int posRy = 600;
int posRz = 600;
int direccionR = 0;
int velR = 1800;
int divR = 600;
int tiempo = 0;

//Bombas
int nbombas = 0;
int bombas[3][3] = 
{/* z, y, x */
 /*1*/ {-1,-1,-1},
 /*2*/ {-1,-1,-1},
 /*3*/ {-1,-1,-1}
};

void setup() {
  //Pines de ShiftReg
  for (int i = 0; i < 3; i++) {
    pinMode(i, OUTPUT);
  }

  //Pines de Ground para niveles
  for (int i = 3; i < 7; i++) {
    pinMode(i, OUTPUT);
  }

  //Poniendo en alto los niveles
  for (int i = 3; i < 7; i++) {
    digitalWrite(i, HIGH);
  }

  //Pines para botones
  for (int i = 7; i < 13; i++) {
    pinMode(i, INPUT);
  }

  randomSeed(millis());
//  Serial.begin(9600);
}

void loop() {

  //Barrido Al Fin!!!!
  for (int plan = 0; plan < 3; plan++) {
    for (int nivel = 3; nivel < 7; nivel++) {

      //Pasando el cubo a arreglo
      for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
          arreglo[contador] = cubo[plan][nivel - 3][y][x];
          contador++;
        }
      }

      contador = 0;

      //Pasando el arreglo a ShiftR
      for (int i = 15; i >= 0; i--) {
        digitalWrite(ds, arreglo[i]);
        shift();
      }

      store();

      digitalWrite(nivel, 0);
      limpiar();
      digitalWrite(nivel, 1);

    }
  }

  mover();
  moverRand();
  colision();
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
    digitalWrite(ds, 0);
    shift();
  }

  store();
}

void mover() {
  //Front
  if (digitalRead(BF) == 1 and bf == 0) {
    bf = 1;
    direccion = 1;
  }

  if (digitalRead(BF) == 0 and bf == 1) {
    bf = 0;
  }

  //Back
  if (digitalRead(BB) == 1 and bb == 0) {
    bb = 1;
    direccion = 2;
  }

  if (digitalRead(BB) == 0 and bb == 1) {
    bb = 0;
  }

  //Left
  if (digitalRead(BL) == 1 and bl == 0) {
    bl = 1;
    direccion = 3;
  }

  if (digitalRead(BL) == 0 and bl == 1) {
    bl = 0;
  }

  //Right
  if (digitalRead(BR) == 1 and br == 0) {
    br = 1;
    direccion = 4;
  }

  if (digitalRead(BR) == 0 and br == 1) {
    br = 0;
  }

  //Up
  if (digitalRead(BU) == 1 and bu == 0) {
    bu = 1;
    direccion = 5;
  }

  if (digitalRead(BU) == 0 and bu == 1) {
    bu = 0;
  }

  //Down
  if (digitalRead(BD) == 1 and bd == 0) {
    bd = 1;
    direccion = 6;
  }

  if (digitalRead(BD) == 0 and bd == 1) {
    bd = 0;
  }

  if (digitalRead(BA) == 1 and ba == 0) {
    ba = 1;
    escribirBombas(posX/division, posY/division, posZ/division);
}

  if (digitalRead(BA) == 0 and ba == 1) {
    ba = 0;
  }

  if (direccion == 1) {posY--;posY = constrain(posY, 0, vel);}
  if (direccion == 2) {posY++;posY = constrain(posY, 0, vel);}
  if (direccion == 3) {posX--;posX = constrain(posX, 0, vel);}
  if (direccion == 4) {posX++;posX = constrain(posX, 0, vel);}
  if (direccion == 5) {posZ--;posZ = constrain(posZ, 0, vel);}
  if (direccion == 6) {posZ++;posZ = constrain(posZ, 0, vel);}

  int x = posX / division;
  int y = posY / division;
  int z = posZ / division;

  limpiarCubo(0);
  escribirCubo(0, x, y, z, 1);
}

void escribirCubo(int plano, int x, int y, int z, int valor) {
  cubo[plano][z][y][x] = valor;
}

void limpiarCubo(int plano) {
  for (int z = 0; z < 4; z++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cubo[plano][z][y][x] = 0;
      }
    }
  }
}

//Funciones para el led random
void moverRand() {

  if (posY < map(posRy, 0, velR, 0, 600)) {
    posRy--;
    posRy = constrain(posRy, 0, velR);
  }

  if (posY > map(posRy, 0, velR, 0, 600)) {
    posRy++;
    posRy = constrain(posRy, 0, velR);
  }

  if (posX < map(posRx, 0, velR, 0, 600)) {
    posRx--;
    posRx = constrain(posRx, 0, velR);
  }

  if (posX > map(posRx, 0, velR, 0, 600)) {
    posRx++;
    posRx = constrain(posRx, 0, velR);
  }

  if (posZ < map(posRz, 0, velR, 0, 600)) {
    posRz--;
    posRz = constrain(posRz, 0, velR);
  }

  if (posZ > map(posRz, 0, velR, 0, 600)) {
    posRz++;
    posRz = constrain(posRz, 0, velR);
  }

  int Rx = posRx / divR;
  int Ry = posRy / divR;
  int Rz = posRz / divR;

  limpiarCubo(1);
  escribirCubo(1, Rx, Ry, Rz, 1);
}

void colision() {

  //Cuando choca con las bombas
  if (cubo[1][map(posRz, 0, velR, 0, 3)][map(posRy, 0, velR, 0, 3)][map(posRx, 0, velR, 0, 3)] == 1
  and cubo[2][map(posRz, 0, velR, 0, 3)][map(posRy, 0, velR, 0, 3)][map(posRx, 0, velR, 0, 3)] == 1) {
    
    if (tiempo < 50) { //Tiempo en el que tarda en reaccionar
      
      direccion = 0;
      for (int i = -1; i < 3; i++) {
        for (int j = -1; j < 3; j++) {
          for (int k = -1; k < 3; k++) {
            
            escribirCubo(1,
                         constrain(map(posRx, 0, velR, 0, 3) + k, 0, 3),
                         constrain(map(posRy, 0, velR, 0, 3) + j, 0, 3),
                         constrain(map(posRz, 0, velR, 0, 3) + i, 0, 3),
                         1);
          }
        }
      }

      tiempo++;
    }
    else {
      limpiarCubo(2);
      posX = 0;
      posY = 0;
      posZ = 0;
      posRx = 1800;
      posRy = 1800;
      posRz = 1800;
      tiempo = 0;
      velR = velR - 300;
      divR = divR - 100;
    }
  }

  //Cuando choca con el jugador
  if (cubo[0][map(posZ, 0, vel, 0, 3)][map(posY, 0, vel, 0, 3)][map(posX, 0, vel, 0, 3)] == 1
  and cubo[1][map(posZ, 0, vel, 0, 3)][map(posY, 0, vel, 0, 3)][map(posX, 0, vel, 0, 3)] == 1) {
    //Serial.println("Choca con el player");
    if (tiempo < 50) { //Tiempo en el que tarda en reaccionar
      direccion = 0;
      for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
          for (int k = -1; k < 2; k++) {

            escribirCubo(1,
                         constrain(map(posX, 0, 600, 0, 3) + k, 0, 3),
                         constrain(map(posY, 0, 600, 0, 3) + j, 0, 3),
                         constrain(map(posZ, 0, 600, 0, 3) + i, 0, 3),
                         1);
          }
        }
      }

      tiempo++;
    }
    else {
      limpiarCubo(2);
      posX = 0;
      posY = 0;
      posZ = 0;
      posRx = 1800;
      posRy = 1800;
      posRz = 1800;
      tiempo = 0;
      velR = 1800;
      divR = 600;
    }
  }

  }

void escribirBombas(int x, int y, int z){

  if(nbombas == 3){
    
    nbombas = 3;
    cubo[2][(bombas[0][0])][(bombas[0][1])][(bombas[0][2])] = 0;
    
    bombas[0][0] = bombas[1][0];
    bombas[0][1] = bombas[1][1];
    bombas[0][2] = bombas[1][2];
    
    bombas[1][0] = bombas[2][0];
    bombas[1][1] = bombas[2][1];
    bombas[1][2] = bombas[2][2];
    
    bombas[2][0] = z;
    bombas[2][1] = y;
    bombas[2][2] = x;
    
  }
  else{
    bombas[nbombas][0] = z;
    bombas[nbombas][1] = y;
    bombas[nbombas][2] = x;
    nbombas++;
  }
  
  escribirCubo(2, x, y, z, 1);
  
}
 
