//Jorge Azzulito Franco
//Usando shift register se creará un Knight Rider
// desplazando un led encendido de izquierda a 
//derecha
//Pines 0 - 2

#define ds 0
#define st 1
#define sh 2

void setup() {
  // put your setup code here, to run once:
  pinMode(ds, OUTPUT);
  pinMode(st, OUTPUT);
  pinMode(sh, OUTPUT);
}

int knight[8][8] = 
{
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite();

  for(int i = 0; i < 8; i++){
    ingresarReg(knight[i]);
    delay(100);
    limpiar();
  }

  for(int i = 7; i > -1; i--){
    ingresarReg(knight[i]);
    delay(100);
    limpiar();
  }
}

void shift(){
  digitalWrite(sh, HIGH);
  digitalWrite(sh,LOW);
}

void store(){
  digitalWrite(st,HIGH);
  digitalWrite(st,LOW);
}

void ingresarReg(int a[]){
  for(int i = 7; i > -1; i--){
    if(a[i] == 1){
      digitalWrite(ds,HIGH);
      shift();
    }
    else{
      digitalWrite(ds,LOW);
      shift();
    }
  }
  store();
}

void limpiar(){
  for(int i = 7; i > -1; i--){
      digitalWrite(ds,LOW);
      shift();
  }
  store();
}

