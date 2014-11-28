#define PULSADOR 2              // Constante que asigna a
                                // PULSADOR el numero 2
#define LED 13                  // Constante que asigna a 
                                // LED el numero 13
#define FRECUENCIA 20           // Constante que asigna a 
                                // FRECUENCIA el valor en Hz
#define T (2000/FRECUENCIA)     // Constante que asigna a T
                                // la mitad del periodo a partir
                                // de una frecuencia. (En milisegundos)


int lectura_pulsador;           // Variable que almacenar 
                                // el estado del pulsador


void setup(){
  pinMode(LED, OUTPUT);          // Establece el pin 13 como SALIDA
  pinMode(PULSADOR, INPUT);      // Establece el pin 2 como ENTRADA
}

void loop(){
  lectura_pulsador = digitalRead(PULSADOR);     // Asigna el valor del pulsador
                                                // a la variable lectura_pulsador
  
  if (lectura_pulsador == HIGH ){        // ¿Esta presionado el pulsador?
     digitalWrite(LED, HIGH);            // Activa y desactiva el LED 
     delay(T);                           // a la FRECUENCIA dada en caso de cierto
     digitalWrite(LED, LOW);
     delay(T);
  }
  else {
    digitalWrite(LED, LOW);              // Desactiva el LED en caso de falso
  }
}
