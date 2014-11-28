#define LED 13                  // Constante que asigna a 
                                // LED el numero 13
#define LED_ROJO 12             // Constante que asigna a
                                // LED_ROJO el numero 12

void setup(){
  pinMode(LED, OUTPUT);          // Establece el pin 13 como SALIDA
  pinMode(LED_ROJO, OUTPUT);     // Establece el pin 12 como SALIDA
}

void loop(){
  digitalWrite(LED, HIGH);       // Activa el LED
  digitalWrite(LED_ROJO, LOW);   // Desactiva el LED ROJO
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED, LOW);        // Desactiva el LED
  digitalWrite(LED_ROJO, HIGH);  // Activa el LED ROJO
  delay(50);                     // Espera 50 milisegundos
}
