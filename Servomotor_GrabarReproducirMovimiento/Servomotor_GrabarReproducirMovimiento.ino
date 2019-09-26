#include <Servo.h>

#define srv 2
#define bRec 3
#define ledR 4
#define bRep 5
#define ledV 6
#define lon 150

Servo servo;

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
int angulos[lon];

void setup() {

  pinMode(bRec, INPUT);
  pinMode(ledR, OUTPUT);
  servo.attach(srv);
  servo.write(0);
  Serial.begin(9600);

}

void loop() {

  botonRecord();
  botonReproducir();
  record();
  play();

//  Serial.print('[');
//  for(int i = 0; i < lon; i++){
//    Serial.print(angulos[i]);
//    Serial.print(',');
//  }
//  Serial.print(']');
//  Serial.print(' ');
  
}

void botonRecord(){
  
  if(digitalRead(bRec) == 1 and btnRec == 0){
    btnRec = 1;
    rec = 1;
    digitalWrite(ledR, rec);
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
  }

  if(digitalRead(bRep) == 0 and btnRep == 1){
    btnRep = 0;
  }
}

void record(){

  Serial.print(tiempo);
  Serial.print(' ');
  Serial.print(paso);
  Serial.print(' ');
  Serial.println(map(analogRead(A0), 0, 1023, 0, 180));

  angulo = map(analogRead(A0), 0, 1023, 0, 180);
  servo.write(angulo);
  
  if(rec == 1){
    if(tiempo == 5){
      angulos[paso] = angulo;
      paso++;
      tiempo = 0;
    }
    else{
      tiempo++;
    }
  }

  if(paso == lon){
    paso = 0;
    rec = 0;
    digitalWrite(ledR, rec);
  }
}

void play(){

  int i = 0;
  if(rep == 1){
    for(i = 0; i < lon; i++){
      servo.write(angulos[i]);
      Serial.println(i);
      delay(50);
    }
  
    servo.write(0);
  }

  if(i = lon){
    rep = 0;
    digitalWrite(ledV, rep);
  }
}

