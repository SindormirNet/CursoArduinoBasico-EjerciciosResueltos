void setup(){
  pinMode(13, OUTPUT);        // Establece el pin 13 como SALIDA
}

void loop(){
  digitalWrite(13, HIGH);     // Activa el LED
  delay(50);                  // Espera 50 milisegundos
  digitalWrite(13, LOW);      // Desactiva el LED
  delay(50);                  // Espera 50 milisegundos
}
