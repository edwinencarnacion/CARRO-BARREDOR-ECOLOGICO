// salidas para motor 1
//int velmotor1=7;
int control1 = 4;
int control2 = 5;

//salidas para motor2
//int velmotor2 = 10;
int control3 = 7;
int control4 = 6;

const int trig = 2;
const int echo = 3;

int distancia = 0;
int tiempo = 0;

void setup() {
  // pinMode(velmotor1,OUTPUT);
  pinMode(control1, OUTPUT);
  pinMode(control2, OUTPUT);

  //  pinMode(velmotor2,OUTPUT);
  pinMode(control3, OUTPUT);
  pinMode(control4, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() {

  distancia = medirDistancia();

  Serial.println(distancia);
  //delay(10);

  if (distancia < 20) {
    parar();
    delay(300);
    atras();
    delay(600);
    giro();
    delay(600);
  } else {
    adelante();
  }
}
void adelante() {
  //analogWrite (velmotor1, 180);
  digitalWrite(control1, LOW);
  digitalWrite(control2, HIGH);
  //  analogWrite (velmotor2, 180);
  digitalWrite(control3, LOW);
  digitalWrite(control4, HIGH);
}
void atras() {
  digitalWrite(control1, HIGH);
  digitalWrite(control2, LOW);
  digitalWrite(control3, HIGH);
  digitalWrite(control4, LOW);
}

void giro() {
  //analogWrite (velmotor1, 180);
  digitalWrite(control1, HIGH);
  digitalWrite(control2, LOW);
  digitalWrite(control3, LOW);
  digitalWrite(control4, HIGH);
}

void parar() {
  //analogWrite (velmotor1, 180);
  digitalWrite(control1, LOW);
  digitalWrite(control2, LOW);
  digitalWrite(control3, LOW);
  digitalWrite(control4, LOW);
}

int medirDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duracion = pulseIn(echo, HIGH);
  int distancia = duracion * 0.034 / 2;

  return distancia;
}
