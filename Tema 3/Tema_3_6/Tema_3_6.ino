#define PULSADOR 2              // Constante que asigna a
                                // PULSADOR el numero 2
#define LED 13                  // Constante que asigna a 
                                // LED el numero 13

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
     digitalWrite(LED, LOW);             // Desactiva el LED en caso de cierto
  }
  else {
    digitalWrite(LED, HIGH);             // Activa el LED en caso de falso
  }
}
