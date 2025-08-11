// pines DERECHA, IZQUIERDA 
int der = 22;
int izq = 23;
int s1 = 30;
int s2 = 31;
int s3 = 32;
int s4 = 33;
int sw1 = 37;
int sw2 = 36;
int start = 35;
int st = 34;
int destino = 0;
int estado = 0;
int inicio = 0;

void setup() {
  Serial.begin(9600);
  pinMode(der, OUTPUT); 
  pinMode(izq, OUTPUT); 
  pinMode(s1, INPUT); 
  pinMode(s2, INPUT); 
  pinMode(s3, INPUT); 
  pinMode(s4, INPUT); 
  pinMode(st, INPUT); 
  pinMode(start, INPUT); 
  pinMode(sw2, INPUT); 
  pinMode(sw1, INPUT); 
}

void stopBanda() {
  digitalWrite(der, LOW);
  digitalWrite(izq, LOW);
}

void loop() {

  while (digitalRead(start) == LOW) {
    if (digitalRead(sw1) == LOW && digitalRead(sw2) == LOW) {
      destino = 1;
      Serial.println("s1");
    }
    if (digitalRead(sw1) == LOW && digitalRead(sw2) == HIGH) {
      destino = 2;
      Serial.println("s2");
    }
    if (digitalRead(sw1) == HIGH && digitalRead(sw2) == LOW) {
      destino = 3;
      Serial.println("s3");
    }
    if (digitalRead(sw1) == HIGH && digitalRead(sw2) == HIGH) {
      destino = 4;
      Serial.println("s4");
    }
  }
  while (destino == 1) {
    if (digitalRead(s1) == LOW) {
      digitalWrite(der, HIGH);
      digitalWrite(izq, LOW);
    }
    if (digitalRead(s1) == HIGH) {
      stopBanda();
      destino = 0;
    }
  }

 
  while (destino == 3) {
    if (digitalRead(s3) == LOW) {
      digitalWrite(der, LOW);
      digitalWrite(izq, HIGH);
    }
    if (digitalRead(s3) == HIGH) {
      stopBanda();
      destino = 0; 
    }
  }
}

