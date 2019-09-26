#include <CapacitiveSensor.h>

#define speaker 11

#define DO 131
#define RE 147
#define MI 165
#define FA 175
#define SOL 196
#define LA 220
#define SI 247
#define DOs 262
#define ntonos 6

//Pitch
int pitch = 2;

//Variables de boton
int up = 0;
int down = 0;
int sus = 0;

//Matriz de tonos
int tonos[ntonos][8] =
{
  /*0 Tono bajo*/ {65, 73, 82, 87, 98, 110, 123, 131},
  /*TonobajoS*/ {69, 78, 0, 93, 104, 117, 0, 139},
  /*2 Natural*/   {131, 147, 165, 175, 196, 220, 247, 262},
  /*NaturalS*/  {139, 156, 0, 185, 208, 233, 0, 277},
  /*4 Tono alto*/ {262, 294, 330, 349, 392, 440, 494, 523},
  /*TonoaltoS*/ {277, 311, 0, 370, 415, 466, 0, 554}
};

//Pin de envio y de recibido
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2, 4);
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2, 5);
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2, 6);
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2, 7);
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2, 8);
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2, 9);
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2, 10);


void setup(){
  cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop(){
  
  long start = millis();

  long total1 =  cs_2_3.capacitiveSensor(100);
  long total2 =  cs_2_4.capacitiveSensor(100);
  long total3 =  cs_2_5.capacitiveSensor(100);
  long total4 =  cs_2_6.capacitiveSensor(100);
  long total5 =  cs_2_7.capacitiveSensor(100);
  long total6 =  cs_2_8.capacitiveSensor(100);
  long total7 =  cs_2_9.capacitiveSensor(100);
  long total8 =  cs_2_10.capacitiveSensor(100);

  if (total1 > 500) tone(speaker, tonos[pitch][0]);
  if (total2 > 500) tone(speaker, tonos[pitch][1]);
  if (total3 > 500 and pitch != 1 and pitch != 3 and pitch != 5) tone(speaker, tonos[pitch][2]);
  if (total4 > 500) tone(speaker, tonos[pitch][3]);
  if (total5 > 500) tone(speaker, tonos[pitch][4]);
  if (total6 > 500) tone(speaker, tonos[pitch][5]);
  if (total7 > 500 and pitch != 1 and pitch != 3 and pitch != 5) tone(speaker, tonos[pitch][6]);
  if (total8 > 500) tone(speaker, tonos[pitch][7]);

  toneUp();
  toneDown();
  

  if (total1 <= 500 and total2 <= 500 and total3 <= 500 and total4 <= 500
      and  total5 <= 500 and total6 <= 500 and total7 <= 500 and total8 <= 500)
    noTone(speaker);

  delay(10);
}

void toneUp(){
  if(digitalRead(A0) == 1 and up == 0){
    up = 1;
    pitch = pitch + 2;
    pitch = constrain(pitch, 0, 5);
  }

  if(analogRead(A0) == 0 and up == 1){
    up = 0;
  }
}

void toneDown(){
  if(digitalRead(12) == 1 and down == 0){
    down = 1;
    pitch = pitch - 2;
    pitch = constrain(pitch, 0, 5);
  }

  if(digitalRead(12) == 0 and down == 1){
    down = 0;
  }
}

