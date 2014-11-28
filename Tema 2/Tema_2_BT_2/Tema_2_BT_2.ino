#define LED 13                  // Constante que asigna a 
                                // LED el numero 13
#define FRECUENCIA 10           // Constante que asigna a 
                                // FRECUENCIA el valor en Hz
#define T (2000/FRECUENCIA)     // Constante que asigna a T
                                // la mitad del periodo a partir
                                // de una frecuencia. (En milisegundos)


void setup(){
  pinMode(LED, OUTPUT);          // Establece el pin 13 como SALIDA
}

void loop(){
  digitalWrite(LED, HIGH);       // Activa el LED
  delay(T);                      // Espera T milisegundos
  digitalWrite(LED, LOW);        // Desactiva el LED
  delay(T);                      // Espera T milisegundos
}
