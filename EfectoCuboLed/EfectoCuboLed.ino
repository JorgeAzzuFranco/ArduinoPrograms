//Jorge Azzulito Franco
//Animación de cubo led de abajo hacia arriba con
//shift register. va desactivando un led por cada 
//ciclo.
//Pines 0-2 para shift register y 4-7 para GND 
//de niveles

#define ds 0
#define st 1
#define sh 2

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
  
  for(int i = 0; i < 16; i++){
    digitalWrite(ds, 0);
    shift();
    store();
    efecto();
  }

  for(int i = 0; i < 16; i++){
    digitalWrite(ds, 1);
    shift();
    store();
  }

  store();
  
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
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(200);

  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(200);

  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(200);
  
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(200);
  
}

