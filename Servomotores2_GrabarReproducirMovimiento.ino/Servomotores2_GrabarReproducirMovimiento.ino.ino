#include <Servo.h>

#define srv 2
#define srvd 3
#define laser 4

#define ledR 8
#define ledV 9
#define bRec 10
#define bRep 11

#define lon 400

Servo servo;
Servo servod;

//Boton grabar
int btnRec = 0;
int rec = 0;

//Boton reproducir
int btnRep = 0;
int rep = 0;

//Control de tiempo
int tiempo = 0;

//Paso del arreglo
int paso = 0;

//Angulos guardados y lector de angulo
int angulo;
int angulod;
int angulos[lon];
int angulosd[lon];


void setup() {

  pinMode(bRec, INPUT);
  pinMode(bRep, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(laser, OUTPUT);
  
  servo.attach(srv);
  servo.write(0);
  servod.attach(srvd);
  servod.write(0);

}

void loop() {

  botonRecord();
  botonReproducir();
  record();
  play();
  
}

void botonRecord(){
  
  if(digitalRead(bRec) == 1 and btnRec == 0){
    btnRec = 1;
    rec = 1;
    digitalWrite(ledR, rec);
    digitalWrite(laser, rec);

  }

  if(digitalRead(bRec) == 0 and btnRec == 1){
    btnRec = 0;
  }

}

void botonReproducir(){
  if(digitalRead(bRep) == 1 and btnRep == 0){
    btnRep = 1;
    rep = 1;
    digitalWrite(ledV, rep);
    digitalWrite(laser, rep);
  }

  if(digitalRead(bRep) == 0 and btnRep == 1){
    btnRep = 0;
  }
}

void record(){

  angulo = map(analogRead(A0), 0, 1023, 60, 100);
  angulod = map(analogRead(A1), 0, 1023, 30, 0);
  
  servo.write(angulo);
  servod.write(angulod);

  if(rec == 1){
    if(tiempo == 5){
      angulos[paso] = angulo;
      angulosd[paso] = angulod;
      paso++;
      tiempo = 0;
    }
    else{
      tiempo++;
    }

    if(paso == lon){
      paso = 0;
      rec = 0;
      digitalWrite(ledR, rec);
      digitalWrite(laser, rec);
    }
    
  }

  
}

void play(){

  int i = 0;
  if(rep == 1){
    for(i = 0; i < lon; i++){
      servo.write(angulos[i]);
      servod.write(angulosd[i]);
      delay(50);
    }
  
    servo.write(0);

    if(i == lon){
      rep = 0;
      digitalWrite(ledV, rep);
      digitalWrite(laser, rep);
    }
  }

  
}
