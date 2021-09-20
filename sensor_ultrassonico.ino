#define echo 12
#define trig 13

unsigned long tempo;
double distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  digitalWrite(trig, LOW);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tempo = pulseIn(echo,HIGH);

  distancia = tempo/58;

  Serial.println(distancia);

  if (Serial.read() < 1000) {
    digitalWrite(0, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(0, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  else{
    digitalWrite(1, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(1, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }

  delay(500);
}
