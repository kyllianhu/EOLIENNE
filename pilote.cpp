#define borneENA 10
#define borneIN1 9
#define borneIN2 8

#define borneX1 2
#define borneX2 3
#define borneX3 4

#define led1 A0
#define led2 A1

const int lent = 1500;
const int moyen = 1000;
const int rapide = 750;

void setup() {
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);

  pinMode(borneX1, INPUT_PULLUP);
  pinMode(borneX2, INPUT_PULLUP);
  pinMode(borneX3, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  digitalWrite(borneIN1, LOW);
  digitalWrite(borneIN2, LOW);
  analogWrite(borneENA, 0);
}

void loop() {
  int vitesse = 0;
  bool actif = false;
  int periodeLed = 0;
  
  bool x1 = !digitalRead(borneX1);
  bool x2 = !digitalRead(borneX2);
  bool x3 = !digitalRead(borneX3);
  
  if (x1 && !x2 && !x3) {
    vitesse = 150;
    actif = true;
    periodeLed = lent;
  }
  else if (x1 && x2 && !x3) {
    vitesse = 200;
    actif = true;
    periodeLed = moyen;
  }
  else if (x1 && x2 && x3) {
    vitesse = 255;
    actif = true;
    periodeLed = rapide;
  }
  
  if (actif) {
    digitalWrite(borneIN1, HIGH);
    digitalWrite(borneIN2, LOW);
    analogWrite(borneENA, vitesse);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(periodeLed);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(periodeLed);
  } else {
    digitalWrite(borneIN1, LOW);
    digitalWrite(borneIN2, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    analogWrite(borneENA, 0);
  }
}