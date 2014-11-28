#define PULSADOR_ROJO A0               // Constante que asigna el pulsador del equipo rojo
#define PULSADOR_VERDE A1              // Constante que asigna el pulsador del equipo verde
#define PULSADOR_PRESENTADOR A2        // Constante que asigna el pulsador del presentador
#define PULSADOR_ACIERTO A3            // Constante que asigna el pulsador de acierto
#define PULSADOR_FALLO A4              // Constante que asigna el pulsador de fallo
#define PULSADOR_PUNTUACION A5         // Constante que asigna el pulsador de la puntuacion
#define LED_ROJO 12                    // Constante que asigna el LED rojo a su equipo 
#define LED_VERDE 13                   // Constante que asigna el LED verde a su equipo
#define ALTAVOZ 11                     // Constante que asigna el altavox
#define PITIDO_CORTO 250               // Constante que asigna la duracion de un pitido corto

// Constantes que asignan un segmento del display a un PIN de Arduino
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_DP 9


void setup(){
  pinMode(PULSADOR_ROJO, INPUT);                // Establece el pin A0 como ENTRADA
  pinMode(PULSADOR_VERDE, INPUT);               // Establece el pin A1 como ENTRADA
  pinMode(PULSADOR_PRESENTADOR, INPUT);         // Establece el pin A2 como ENTRADA
  pinMode(PULSADOR_ACIERTO, INPUT);             // Establece el pin A3 como ENTRADA
  pinMode(PULSADOR_FALLO, INPUT);               // Establece el pin A4 como ENTRADA
  pinMode(PULSADOR_PUNTUACION, INPUT);          // Establece el pin A5 como ENTRADA
  pinMode(LED_ROJO, OUTPUT);                    // Establece el pin 12 como SALIDA
  pinMode(LED_VERDE, OUTPUT);                   // Establece el pin 13 como SALIDA
  pinMode(ALTAVOZ, OUTPUT);                     // Establece el pin 11 como SALIDA
  pinMode(DISPLAY, OUTPUT);                     // Establece el pin 10 como SALIDA
  
  for (int i=2; i<10; i++)
    pinMode(i, OUTPUT);

}

void loop(){
  
  // Estados de la puntuacion y el turno
  static byte puntuacion_rojo = 0, puntuacion_verde = 0;
  boolean turno_rojo = 0, turno_verde = 0;
  
  
  // Mantenemos a la espera hasta que el presentador pulse el pulsador y lo suelte
  do{
    if( digitalRead(PULSADOR_PUNTUACION) == HIGH){
      digitalWrite( 10, HIGH);
      digitalWrite( LED_ROJO, HIGH);
      imprime_7_segmentos(puntuacion_rojo);
      delay (3000);
      digitalWrite( LED_ROJO, LOW);
      digitalWrite( LED_VERDE, HIGH);
      imprime_7_segmentos(puntuacion_verde);
      delay (3000);
      digitalWrite( LED_VERDE, LOW);
      digitalWrite( 10, LOW);
    }
  }while( digitalRead(PULSADOR_PRESENTADOR) == LOW );
  while( digitalRead(PULSADOR_PRESENTADOR) == HIGH){}
  
  
  // Esperamos a que deje de pulsar y emitimos un tono de confirmacion
  tone( ALTAVOZ, 239, PITIDO_CORTO);
  delay( PITIDO_CORTO);
  
  
  // Mantenemos la espera hasta que uno de los dos equipos apriete el boton.
  while( (digitalRead(PULSADOR_ROJO) == LOW) && (digitalRead(PULSADOR_VERDE) == LOW) ) {}
 
 
  // Encendemos el LED del equipo que antes haya pulsado el boton y cambiamos su estado de turno
  if( digitalRead(PULSADOR_ROJO) == HIGH) {
    digitalWrite( LED_ROJO, HIGH);
    turno_rojo = 1;
  }
  else {
    digitalWrite( LED_VERDE, HIGH);
    turno_verde = 1;
  }
  
  
  // Mantenemos la espera hasta que el presentador de como valido la respuesta, mientras encendemos el
  // LED y la puntuacion del equipo que este esperando para responder
  do{
    if (turno_rojo == 1){
      digitalWrite( 10, HIGH);
      digitalWrite( LED_ROJO, HIGH);
      imprime_7_segmentos(puntuacion_rojo);
      digitalWrite( LED_ROJO, LOW);
      digitalWrite( 10, LOW);
    }else if (turno_verde == 1){
      digitalWrite( 10, HIGH);
      digitalWrite( LED_VERDE, HIGH);
      imprime_7_segmentos(puntuacion_verde);
      digitalWrite( LED_VERDE, LOW);
      digitalWrite( 10, LOW);
    } 
  }while( digitalRead(PULSADOR_ACIERTO) == LOW  && digitalRead(PULSADOR_FALLO) == LOW );
  
  
  // Si se ha pulsado el boton de acierto, emitimos una musica de acierto, sino una de fallo, reiniciamos el estado del turno
  if ( digitalRead(PULSADOR_ACIERTO) == LOW ){
    
    
    tone( ALTAVOZ, 239, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 259, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 279, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 299, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    
    
    if (turno_rojo == 1){
      puntuacion_rojo++;
      turno_rojo = 0;
    }else if (turno_verde == 1){
      puntuacion_verde++;
      turno_verde = 0;
    }
    
  }
  else{
    
    tone( ALTAVOZ, 239, PITIDO_CORTO*2);
    delay( PITIDO_CORTO*2);
    tone( ALTAVOZ, 219, PITIDO_CORTO*2);
    delay( PITIDO_CORTO*2);
    tone( ALTAVOZ, 199, PITIDO_CORTO*2);
    delay( PITIDO_CORTO*2);
    tone( ALTAVOZ, 179, PITIDO_CORTO*4);
    delay( PITIDO_CORTO*4);
    
    turno_rojo = 0;
    turno_verde = 0;
  }
  
  
  // Apagamos los LEDs de los concursanter
  digitalWrite( LED_ROJO, LOW);
  digitalWrite( LED_VERDE, LOW);
  
}





// Funcion que indica los numeros del 1 al 9 y las letras de la A hasta la F
void imprime_7_segmentos(int num) {
  
  switch (num) {
    
    case 0:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, LOW);
      break;
      
    case 1:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
      
    case 2:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;

    case 3:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;

    case 4:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 5:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 6:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 7:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;

    case 8:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 9:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    default:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    }
}

