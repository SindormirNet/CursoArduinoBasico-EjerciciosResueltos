#define PULSADOR_1 2            // Constante que asigna a
                                // PULSADOR el numero 2
#define PULSADOR_2 3            // Constante que asigna a
                                // PULSADOR el numero 3
#define LED 13                  // Constante que asigna a 
                                // LED el numero 13

int lectura_pulsador_1;         // Variable que almacena 
                                // el estado del pulsador_1
int lectura_pulsador_2;         // Variable que almacena 
                                // el estado del pulsador_2


void setup(){
  pinMode(LED, OUTPUT);            // Establece el pin 13 como SALIDA
  pinMode(PULSADOR_1, INPUT);      // Establece el pin 2 como ENTRADA
  pinMode(PULSADOR_2, INPUT);      // Establece el pin 3 como ENTRADA
}


void loop(){
  
  lectura_pulsador_1 = digitalRead(PULSADOR_1);     // Asigna el valor del pulsador
                                                  // a la variable lectura_pulsador
  lectura_pulsador_2 = digitalRead(PULSADOR_2);     // Asigna el valor del pulsador
                                                  // a la variable lectura_pulsador
  
  // ¿Estan presionados los dos pulsadores?
  if ( (lectura_pulsador_1 == HIGH) && (lectura_pulsador_2 == HIGH) ){ 
    
    // Activa el LED en caso de cierto 
    digitalWrite(LED, HIGH);   
    
  }
  else {
    
    // Desctiva el LED en caso de falso
    digitalWrite(LED, LOW); 
    
  }
  
}
