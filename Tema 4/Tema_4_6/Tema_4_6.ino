#define PULSADOR 2              // Constante que asigna a
                                // PULSADOR el numero 2
                                
// Variable que designara a cada uno de los 4 LEDS
byte pin;

// Variable que almacenar el estado del pulsador
int lectura_pulsador;


void setup(){
  // Utilizamos un bucle for para activar los pines del 2 al 5
  for ( pin = 2 ; pin < 6; pin++) {
    pinMode( pin, OUTPUT);
  }
  
}


void loop(){
  // Asigna el valor del pulsador a la variable lectura_pulsador
  lectura_pulsador = digitalRead(PULSADOR);  

  // ¿Esta presionado el pulsador?  
  if ( lectura_pulsador == HIGH ){
    
      // Activamos y desactivamos los LEDS de forma creciente 
      // durante 100 milisegundos en caso de cierto
      for ( pin = 2; pin < 6; pin++) {
          digitalWrite(pin, HIGH);
          delay(100);
          digitalWrite(pin, LOW);
      }
      
  }
  else{
    
      // Activamos y desactivamos los LEDS de forma decreciente 
      // durante 100 milisegundos  en caso de falso
      for ( pin = 5; pin >= 2; pin--) {
          digitalWrite(pin, HIGH);
          delay(100);
          digitalWrite(pin, LOW); 
      }
      
  }
  
}
