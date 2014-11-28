#define LED 13                  // Constante que asigna a 
                                // LED el numero 13
#define LED_ROJO 12             // Constante que asigna a
                                // LED_ROJO el numero 12
#define LED_VERDE 11            // Constante que asigna a 
                                // LED_VERDE el numero 11
#define LED_AZUL 10             // Constante que asigna a
                                // LED_AZUL el numero 10

void setup(){
  pinMode(LED, OUTPUT);          // Establece el pin 13 como SALIDA
  pinMode(LED_ROJO, OUTPUT);     // Establece el pin 12 como SALIDA
  pinMode(LED_VERDE, OUTPUT);    // Establece el pin 11 como SALIDA
  pinMode(LED_AZUL, OUTPUT);     // Establece el pin 10 como SALIDA
}

void loop(){
  digitalWrite(LED_ROJO, LOW);   // Desactiva el LED ROJO
  digitalWrite(LED, HIGH);       // Activa el LED
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED, LOW);        // Desactiva el LED
  digitalWrite(LED_ROJO, HIGH);  // Activa el LED ROJO
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED_ROJO, LOW);   // Desactiva el LED ROJO
  digitalWrite(LED_VERDE, HIGH); // Activa el LED VERDE
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED_VERDE, LOW);  // Desactiva el LED VERDE
  digitalWrite(LED_AZUL, HIGH);  // Activa el LED AZUL
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED_AZUL, LOW);   // Desactiva el LED AZUL
  digitalWrite(LED_VERDE, HIGH); // Activa el LED VERDE
  delay(50);                     // Espera 50 milisegundos
  digitalWrite(LED_VERDE, LOW);  // Desactiva el LED VERDE
  digitalWrite(LED_ROJO, HIGH);  // Activa el LED ROJO
  delay(50);                     // Espera 50 milisegundos
}
