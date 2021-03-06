//Jorge Azzulito Franco
//Cubo led con shift register. Utilización de un
//control que mueve un led encendido adelante, 
//atras, izquierda, derecha, arriba, abajo y un
//boton de acción
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

void setup() {
  //Pines de ShiftReg
  for(int i = 0; i < 3; i++){
    pinMode(i, OUTPUT);
  }

  //Pines de Ground para niveles
  for(int i = 3; i < 7; i++){
    pinMode(i, OUTPUT);
  }

  //Poniendo en alto los niveles
  for(int i = 3; i < 7; i++){
    digitalWrite(i, HIGH);
  }
  
  //Pines para botones
  for(int i = 7; i < 13; i++){
    pinMode(i, INPUT);
  }

  randomSeed(millis());
}

int cubo[4][4][4] = {
  {
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  },
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  },
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  },
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  }
};

int contador = 0;

int arreglo[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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

//Tiempo de random
int timer = 0;

void loop() {

  //Barrido Al Fin!!!!
  for(int nivel = 3; nivel < 7; nivel++){

    //Pasando el cubo a arreglo
    for(int y = 0; y < 4; y++){
      for(int x = 0; x < 4; x++){
        arreglo[contador] = cubo[nivel-3][y][x];
        contador++; 
      }
    }

    contador = 0;
    
    //Pasando el arreglo a ShiftR
    for(int i = 15; i >= 0; i--){
      digitalWrite(ds, arreglo[i]);
      shift();
    }

    store();

    digitalWrite(nivel, 0);
    limpiar();
    digitalWrite(nivel, 1);

  }
  mover();
}

void shift(){
  digitalWrite(sh, HIGH);
  digitalWrite(sh, LOW);
}

void store(){
  digitalWrite(st, HIGH);
  digitalWrite(st, LOW);
}

void limpiar(){
  for(int i = 0; i < 16; i++){
      digitalWrite(ds, 0);
      shift();
    }

    store();
}

void mover(){
  //Front
  if(digitalRead(BF) == 1 and bf == 0){
    bf = 1;
    direccion = 1;  
  }
  
  if(digitalRead(BF) == 0 and bf == 1){
    bf = 0;
  }

  //Back
  if(digitalRead(BB) == 1 and bb == 0){
    bb = 1;
    direccion = 2;
  }

  if(digitalRead(BB) == 0 and bb == 1){
    bb = 0;
  }

  //Left
  if(digitalRead(BL) == 1 and bl == 0){
    bl = 1;
    direccion = 3;
  }

  if(digitalRead(BL) == 0 and bl == 1){
    bl = 0;
  }

  //Right
  if(digitalRead(BR) == 1 and br == 0){
    br = 1;
    direccion = 4;
  }

  if(digitalRead(BR) == 0 and br == 1){
    br = 0;
  }

  //Up
  if(digitalRead(BU) == 1 and bu == 0){
    bu = 1;
    direccion = 5;
  }

  if(digitalRead(BU) == 0 and bu == 1){
    bu = 0;
  }

  //Down
 if(digitalRead(BD) == 1 and bd == 0){
    bd = 1;
    direccion = 6;
  }

  if(digitalRead(BD) == 0 and bd == 1){
    bd = 0;
  }

  if(digitalRead(BA) == 1 and ba == 0){
    ba = 1;
    direccion = 0;
    //ACCION
  }

  if(digitalRead(BA) == 0 and ba == 1){
    ba = 0;
  }

  if(direccion == 1){posY--; posY = constrain(posY,0,vel);}
  if(direccion == 2){posY++; posY = constrain(posY,0,vel);}
  if(direccion == 3){posX--; posX = constrain(posX,0,vel);}
  if(direccion == 4){posX++; posX = constrain(posX,0,vel);}
  if(direccion == 5){posZ--; posZ = constrain(posZ,0,vel);}
  if(direccion == 6){posZ++; posZ = constrain(posZ,0,vel);}
  
  int x = posX/division;
  int y = posY/division;
  int z = posZ/division;

  limpiarCubo();
  escribirCubo(x,y,z,1);

}

void escribirCubo(int x, int y, int z, int valor){
  cubo[z][y][x] = valor;
}

void limpiarCubo(){
  for(int z = 0; z < 4; z++){
    for(int y = 0; y < 4; y++){
      for(int x = 0; x < 4; x++){
       cubo[z][y][x] = 0;
      }
    }
  }
}

