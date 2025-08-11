
int subir=22;
int bajar=23;
int led1=24;
int led2=25;
int led3=26;
int led4=27;
int sw1=37;
int sw2=36;
int p1=35;
int p2=34;
int p3=33;
int p4=32;

void setup() {
  pinMode(subir,OUTPUT);
  pinMode(bajar,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(p4,INPUT);


  Serial.begin(9600); 
}

void loop() {
  /* Subir  */
  if ((digitalRead(p1)==1) && (digitalRead(sw1)==0)){
    digitalWrite(led3,0);
    digitalWrite(led2,0);
    digitalWrite(led1,1);
    digitalWrite(subir,1);
    digitalWrite(bajar,0);
    Serial.println("Motor subiendo");
  }

  /* Dejar de subir  */

  if (digitalRead(sw1)==1){
    digitalWrite(led3,1);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    digitalWrite(subir,0);
    digitalWrite(bajar,0);
    Serial.println("Motor detenido (arriba)");
  }
  
 /* Detener Mientras sube  */
 if((digitalRead(p2)==1) && (digitalRead(sw1)==0)){
    digitalWrite(led3,1);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    digitalWrite(subir,0);
    digitalWrite(bajar,0);
    Serial.println("Motor en pausa");
  }

  /* bajar */

  if ((digitalRead(p2)==1) && (digitalRead(sw2)==0)){
    digitalWrite(led3,0);
    digitalWrite(led2,1);
    digitalWrite(led1,0);
    digitalWrite(subir,0);
    digitalWrite(bajar,1);
    Serial.println("Motor bajando");
  }

  /* Motor detenido abajo   */

  if (digitalRead(sw2)==1){
    digitalWrite(led3,1);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    digitalWrite(subir,0);
    digitalWrite(bajar,0);
    Serial.println("Motor detenido (abajo)");
  }

  /* Detener Mientras baja  */
 if (digitalRead(p3)==1){ 
    digitalWrite(led3,1);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    digitalWrite(subir,0);
    digitalWrite(bajar,0);
    Serial.println("Motor en pausa");
  }



}

 



