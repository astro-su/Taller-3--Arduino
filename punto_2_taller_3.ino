int m1=31;
int m2=30;
int s1=33;
int s2=32;
int open=22;
int close=23;
int redl=24;
int grnl=25;

int contadorCarros = 0;

void setup() {
  pinMode(m1,INPUT);
  pinMode(m2,INPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(open,OUTPUT);
  pinMode(close,OUTPUT);
  pinMode(redl,OUTPUT);
  pinMode(grnl,OUTPUT);
  Serial.begin(9600);

  digitalWrite(open, LOW);
  digitalWrite(close, LOW);

}

void loop() {
  if (digitalRead(s1)==1){
    digitalWrite(close,0);
    digitalWrite(redl,1);
    digitalWrite(open,1);
    Serial.println("Subiendo");

    while (digitalRead(m2)==0){

    }
      digitalWrite(redl,0);
      digitalWrite(grnl,1);
      Serial.println("Detenida");
      digitalWrite(open,0);
      delay(5000);
      digitalWrite(grnl,0);

      while (digitalRead(s1)==1){

      }
      digitalWrite(redl,1);
      digitalWrite(close,1);
      Serial.println("Bajando");

      while(digitalRead(m1)==0){

      }  
      digitalWrite(redl,0);
      Serial.println("Detenida");
      digitalWrite(close,0);
      
      if( contadorCarros >= 0)contadorCarros++;
      Serial.println("Carros que han entrado: ");
      Serial.println(contadorCarros);
  }
  if(digitalRead(s2)==1){
    digitalWrite(close,0);
    digitalWrite(open,1);
    digitalWrite(redl,1);
    Serial.println("Subiendo");

    while(digitalRead(m2)==0){

    }
    digitalWrite(redl,0);
    Serial.println("Detenida");
    digitalWrite(grnl,1);
    digitalWrite(open,0);
    delay(5000);
    digitalWrite(grnl,0);
    

    if(digitalRead(s2)==0){
      digitalWrite(redl,1);
      digitalWrite(close,1);
      Serial.println("Bajando");

      while(digitalRead(m1)==0){

      }
      digitalWrite(redl,0);
      Serial.println("Detenida");
      digitalWrite(close,0);
      

      if( contadorCarros > 0)contadorCarros--;

      Serial.println("Carro salió");
      Serial.print("Carros en el parqueadero: ");
      Serial.println(contadorCarros);

    }
  }     
}
        




