

// Inicializamos los pines ~6
void setup(){
  pinMode(6, OUTPUT);
}


void loop(){
  analogWrite(6, map(analogRead(A0), 0, 1023, 0, 255));
}
