#define PULSADOR_ROJO 2               // Constante que asigna el pulsador del equipo rojo
#define PULSADOR_VERDE 3              // Constante que asigna el pulsador del equipo verde
#define PULSADOR_PRESENTADOR 4        // Constante que asigna el pulsador del presentador
#define LED_ROJO 8                    // Constante que asigna el LED rojo a su equipo 
#define LED_VERDE 9                   // Constante que asigna el LED verde a su equipo

void setup(){
  pinMode(PULSADOR_ROJO, INPUT);                // Establece el pin 2 como ENTRADA
  pinMode(PULSADOR_VERDE, INPUT);               // Establece el pin 3 como ENTRADA
  pinMode(PULSADOR_PRESENTADOR, INPUT);         // Establece el pin 4 como ENTRADA
  pinMode(LED_ROJO, OUTPUT);                    // Establece el pin 8 como SALIDA
  pinMode(LED_VERDE, OUTPUT);                   // Establece el pin 9 como SALIDA

}

void loop(){
  
  // Mantenemos a la espera hasta que el presentador pulse el pulsador y lo suelte
  while( digitalRead(PULSADOR_PRESENTADOR) == LOW ){}
  while( digitalRead(PULSADOR_PRESENTADOR) == HIGH){}
  
  // Esperamos a que deje de pulsar 
  delay(200);
  
  // Mantenemos la espera hasta que uno de los dos equipos apriete el boton.
  while( (digitalRead(PULSADOR_ROJO) == LOW) && (digitalRead(PULSADOR_VERDE) == LOW) ) {}
 
  // Encendemos el LED del equipo que antes haya pulsado el boton.
  if( digitalRead(PULSADOR_ROJO) == HIGH) {
    digitalWrite( LED_ROJO, HIGH);
  }
  else {
    digitalWrite( LED_VERDE, HIGH);
  }
  
  // Mantenemos la espera hasta que el presentador vuelva a pulsar el boton y a la vez apagamos los LEDs de los equipos.
  while( digitalRead(PULSADOR_PRESENTADOR) == LOW ){}
  
  digitalWrite( LED_ROJO, LOW);
  digitalWrite( LED_VERDE, LOW);
  
  while( digitalRead(PULSADOR_PRESENTADOR) == HIGH){}
}
