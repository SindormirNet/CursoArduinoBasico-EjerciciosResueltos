#define LED 13                // Constante que asigna a 
                              // LED el numero 13

void setup(){
  pinMode(LED, OUTPUT);        // Establece el pin 13 como SALIDA
}

void loop(){
  digitalWrite(LED, HIGH);     // Activa el LED
  delay(50);                  // Espera 50 milisegundos
  digitalWrite(LED, LOW);      // Desactiva el LED
  delay(50);                  // Espera 50 milisegundos
}
