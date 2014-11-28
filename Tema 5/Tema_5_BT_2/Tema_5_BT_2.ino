#define LED_ROJO 12            // Constante para el LED_ROJO
#define LED_VERDE 11           // Constante para el LED_VERDE
#define PULSADOR_1 7           // Constante para el pulsador 1
#define PULSADOR_2 6           // Constante para el pulsador 2
#define PULSADOR_3 5           // Constante para el pulsador 3
#define PULSADOR_4 4           // Constante para el pulsador 4



void setup(){
  pinMode( LED_ROJO, OUTPUT);          // Establece el pin 12 como SALIDA
  pinMode( LED_VERDE, OUTPUT);         // Establece el pin 11 como SALIDA
  pinMode( PULSADOR_1, INPUT);         // Establece el pin 7 como ENTRADA
  pinMode( PULSADOR_2, INPUT);         // Establece el pin 6 como ENTRADA
  pinMode( PULSADOR_3, INPUT);         // Establece el pin 5 como ENTRADA
  pinMode( PULSADOR_4, INPUT);         // Establece el pin 4 como ENTRADA
}


void loop() {
  
  //Creamos las variables que van a almacenar el numero de pulsaciones dadas.
  int pulsaciones_1 = 0;
  int pulsaciones_2 = 0;
  int pulsaciones_3 = 0;
  int pulsaciones_4 = 0;
  
  byte estado = TRUE;

  // Mantenemos los LEDs apagados hasta que no se pulse ningun pulsador
  digitalWrite( LED_ROJO, LOW);
  digitalWrite( LED_VERDE, LOW);
  
  
  while( (digitalRead(PULSADOR_1) == LOW) && (digitalRead(PULSADOR_2) == LOW) && (digitalRead(PULSADOR_3) == LOW) && (digitalRead(PULSADOR_4) == LOW) )
  
  while( estado ==
      
    if ( digitalRead(PULSADOR_1) == HIGH){
      while(digitalRead(PULSADOR));
      pulsaciones_1++;
      delay(50);
    }
    if ( digitalRead(PULSADOR_2) == HIGH){
      while(digitalRead(PULSADOR));
      pulsaciones_2++;
      delay(50);
    }
    if ( digitalRead(PULSADOR_3) == HIGH){
      while(digitalRead(PULSADOR));
      pulsaciones_3++;
      delay(50);
    }
    if ( digitalRead(PULSADOR_4) == HIGH){
      while(digitalRead(PULSADOR));
      pulsaciones_4++;
      delay(50);
    }

    if
  // Permanecemos 10 segundos contando las pulsaciones
  while ( (millis() - time) < TIEMPO){

    if ( digitalRead(PULSADOR) == HIGH){
      while(digitalRead(PULSADOR));
      pulsaciones++;
      delay(50);
    }
  }
  
  // Apagamos el LED y esperamos 1 segundo para poder ver la cuenta
  digitalWrite(LED, LOW);
  delay(1000);
  
  // Mostramos la cuenta parpadeando el LED ese numero de veces.
  for ( int i=0; i < pulsaciones; i++){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }

}

