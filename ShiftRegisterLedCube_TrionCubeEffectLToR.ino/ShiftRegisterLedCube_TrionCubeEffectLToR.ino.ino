//Jorge Azzulito Franco
//Animación de cubo led de izquierda a derecha con
//shift register.
//Pines 0-2 para shift register y 4-7 para GND 
//de niveles

#define ds 0
#define st 1
#define sh 2

int izder[4][16] =  
{
  {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}
};

void setup() {
  // put your setup code here, to run once:
  pinMode(ds,OUTPUT);
  pinMode(st,OUTPUT);
  pinMode(sh,OUTPUT);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  for(int i = 0; i < 4; i++){
    //Para que sea de derecha a izquierda cambia
    //(int j = 16; j >= 0; j++)
    for(int j = 0; j < 16; j++){
      if(izder[i][j] == 1){
        digitalWrite(ds, 1);
        shift();
      }
      else{
        digitalWrite(ds, 0);
        shift();
      }
    }
    store();
    efecto();
  }  
}

void shift(){
  digitalWrite(sh, 1);
  digitalWrite(sh, 0);
}

void store(){
  digitalWrite(st, 1);
  digitalWrite(st, 0);
}

void efecto(){
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(100);  
}

