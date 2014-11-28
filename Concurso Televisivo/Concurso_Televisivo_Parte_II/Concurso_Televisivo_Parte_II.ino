#define PULSADOR_ROJO 2               // Constante que asigna el pulsador del equipo rojo
#define PULSADOR_VERDE 3              // Constante que asigna el pulsador del equipo verde
#define PULSADOR_PRESENTADOR 4        // Constante que asigna el pulsador del presentador
#define PULSADOR_ACIERTO 5
#define PULSADOR_FALLO 6
#define LED_ROJO 8                    // Constante que asigna el LED rojo a su equipo 
#define LED_VERDE 9                   // Constante que asigna el LED verde a su equipo
#define ZUMBADOR 10
#define PITIDO_CORTO 200

void setup(){
  pinMode(PULSADOR_ROJO, INPUT);                // Establece el pin 2 como ENTRADA
  pinMode(PULSADOR_VERDE, INPUT);               // Establece el pin 3 como ENTRADA
  pinMode(PULSADOR_PRESENTADOR, INPUT);         // Establece el pin 4 como ENTRADA
  pinMode(PULSADOR_ACIERTO, INPUT);             // Establece el pin 5 como ENTRADA
  pinMode(PULSADOR_FALLO, INPUT);               // Establece el pin 6 como ENTRADA
  pinMode(LED_ROJO, OUTPUT);                    // Establece el pin 8 como SALIDA
  pinMode(LED_VERDE, OUTPUT);                   // Establece el pin 9 como SALIDA
  pinMode(ZUMBADOR, OUTPUT);                    // Establece el pin 10 como SALIDA

}

void loop(){
  
  // Mantenemos a la espera hasta que el presentador pulse el pulsador y lo suelte
  while( digitalRead(PULSADOR_PRESENTADOR) == LOW ){}
  while( digitalRead(PULSADOR_PRESENTADOR) == HIGH){}
  
  // Esperamos a que deje de pulsar 
  digitalWrite( ZUMBADOR, HIGH);
  delay(PITIDO_CORTO);
  digitalWrite( ZUMBADOR, LOW);
  
  // Mantenemos la espera hasta que uno de los dos equipos apriete el boton.
  while( (digitalRead(PULSADOR_ROJO) == LOW) && (digitalRead(PULSADOR_VERDE) == LOW) ) {}
 
  // Encendemos el LED del equipo que antes haya pulsado el boton.
  if( digitalRead(PULSADOR_ROJO) == HIGH) {
    digitalWrite( LED_ROJO, HIGH);
  }
  else {
    digitalWrite( LED_VERDE, HIGH);
  }
  
  // Mantenemos la espera hasta que el presentador vuelva a pulsar el boton.
  while( digitalRead(PULSADOR_ACIERTO) == LOW  && digitalRead(PULSADOR_FALLO) == LOW ){}
  
  // Si se ha pulsado el boton de acierto, emitimos dos pitidos, sino uno largo
  if ( digitalRead(PULSADOR_ACIERTO) == LOW ){
    for( int i = 0; i < 2; i++){
      digitalWrite( ZUMBADOR, HIGH);
      delay(PITIDO_CORTO);
      digitalWrite( ZUMBADOR, LOW);
      delay(PITIDO_CORTO);
    }
  }
  else{
    digitalWrite( ZUMBADOR, HIGH);
    delay(PITIDO_CORTO*2);
    digitalWrite( ZUMBADOR, LOW);
    delay(PITIDO_CORTO);
  }
    
  // Apagamos los LEDs de los concursanter
  digitalWrite( LED_ROJO, LOW);
  digitalWrite( LED_VERDE, LOW);
  
}
