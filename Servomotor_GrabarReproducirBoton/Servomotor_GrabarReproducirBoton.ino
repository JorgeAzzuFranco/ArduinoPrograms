#include <Servo.h>

#define srv1 2
#define srv2 3
#define bRec 4
#define bRep1 5
#define ledR 6
#define ledV 7

//Servos
Servo servo1;
Servo servo2;

//Angulos para cada servo
int grados1;
int grados2;

//Variables de control de botones
//Boton record
int btnRec = 0;
int rec = 0;

//Boton reproducir
int btnRep1 = 0;


int arreglo1[2] = {0,0};

void setup() {

  //Servos
  servo1.attach(srv1);
  servo1.write(0);

  servo2.attach(srv2);
  servo2.write(0);

  //Botones
  pinMode(bRec, INPUT);
  pinMode(bRep1, INPUT);

  //LEDs
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);

}

void loop() {

  botonRecord();
  botonGrabado1();

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

void botonGrabado1(){

  grados1 = map(analogRead(A0), 0, 1023, 0, 180);
  grados2 = map(analogRead(A5), 0, 1023, 0, 180);

  servo1.write(grados1);
  servo2.write(grados2);
  
  if(rec == 1){

    if(digitalRead(bRep1) == 1 and btnRep1 == 0){
      btnRep1 = 1;
      arreglo1[0] = grados1;
      arreglo1[1] = grados2;
      rec = 0;
      digitalWrite(ledR, rec);
      
    }

    if(digitalRead(bRep1) == 0 and btnRep1 == 1){
      btnRep1 = 0;
    }
  
  }

  if(rec == 0){
    
    if(digitalRead(bRep1) == 1 and btnRep1 == 0){
      digitalWrite(ledV, 1);
      servo1.write(arreglo1[0]);
      servo2.write(arreglo1[1]);
      delay(50);
      digitalWrite(ledV, 0);
    }

    if(digitalRead(bRep1) == 0 and btnRep1 == 1){
      btnRep1 = 0;
    }
    
  }
  
}

