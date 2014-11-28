#define PULSADOR_ROJO A0               // Constante que asigna el pulsador del equipo rojo
#define PULSADOR_VERDE A1              // Constante que asigna el pulsador del equipo verde
#define LED_ROJO 12                    // Constante que asigna el LED rojo a su equipo 
#define LED_VERDE 13                   // Constante que asigna el LED verde a su equipo
#define ALTAVOZ 11                     // Constante que asigna el altavoz
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
  Serial.begin(9600);
  pinMode(PULSADOR_ROJO, INPUT);                // Establece el pin A0 como ENTRADA
  pinMode(PULSADOR_VERDE, INPUT);               // Establece el pin A1 como ENTRADA
  pinMode(LED_ROJO, OUTPUT);                    // Establece el pin 12 como SALIDA
  pinMode(LED_VERDE, OUTPUT);                   // Establece el pin 13 como SALIDA
  pinMode(ALTAVOZ, OUTPUT);                     // Establece el pin 11 como SALIDA
  
  for (int i=2; i<11; i++)
    pinMode(i, OUTPUT);                         // Establece los pines como SALIDA para el DISPLAY

}

void loop(){
  
  // Estados de la puntuacion y el turno
  static byte puntuacion_rojo = 0, puntuacion_verde = 0;
  boolean turno_rojo = 0, turno_verde = 0;
  boolean go = 0, acierto = 0, fallo = 0;
  String mensaje = "";
  char leido = ' ';
  
  
  Serial.println(" Los jugadores esperando para contestar a que se realice la pregunta");
  Serial.println( "(Escriba 'go' cuando termine de hacerla o 'status' para ver las puntuaciones)");
  
  
  // Mantenemos a la espera hasta que el presentador escriba go
  do{
    
    // Inicializamos la variable y si hay disponible algun dato entramos.
    leido = ' ';
    if( Serial.available() > 0){
      
      // Leemos y si no es fin de linea, asignamos al string mensaje.
      leido = Serial.read();
      if( leido != '\n')
        mensaje += leido;
        
      // Si mensaje es igual a status, mostramos la puntuacion y encendemos los LEDs y DISPLAY
      if( mensaje == "status"){
        Serial.print("La puntuacion del equipo rojo es: ");
        Serial.print( puntuacion_rojo);
        Serial.println( ".");
          digitalWrite( 10, HIGH);
          digitalWrite( LED_ROJO, HIGH);
          imprime_7_segmentos(puntuacion_rojo);
          delay (3000);
          digitalWrite( LED_ROJO, LOW);
        Serial.print("La puntuacion del equipo verde es: ");
        Serial.print( puntuacion_verde);
        Serial.println( ".");
          digitalWrite( LED_VERDE, HIGH);
          imprime_7_segmentos(puntuacion_verde);
          delay (3000);
          digitalWrite( LED_VERDE, LOW);
          digitalWrite( 10, LOW);  
          mensaje = "";
      }
      
      // Si el mensaje es go, cambiamos el estado para poder salir del bucle.
      else if( mensaje == "go"){
        go = 1;
      }  
    
    }
  }while( go == LOW );
  
  
  // Inicializamos mensaje.
  mensaje = "";
  
  
  // Esperamos a que deje de pulsar y emitimos un tono de confirmacion
  tone( ALTAVOZ, 239, PITIDO_CORTO);
  delay( PITIDO_CORTO);
  
  
  // Mantenemos la espera hasta que uno de los dos equipos apriete el boton.
  Serial.println("Esperando a que los jugadores presionen el pulsador");
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
  
  
  Serial.println("Es la respuesta correcta? ('ok' acierto, 'ko' fallo)");
  
  
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
    
    // Inicializamos la variable y si hay disponible algun dato entramos.
    leido = ' ';
    if( Serial.available() > 0){
      leido = Serial.read();
        if( leido != '\n')
          mensaje += leido;
      
      // Si el mensaje es ok, guardamos el estado acierto, inicializamos el string mensaje
      if( mensaje == "ok"){
        acierto = 1;
        mensaje = "";
      }
      // Si el mensaje es ok, guardamos el estado fallo, inicializamos el string mensaje
      else if( mensaje == "ko"){
        fallo = 1;
        mensaje = "";
      }
      
    }
  }while( acierto == LOW  && fallo == LOW );
  
  
  // Si se ha pulsado el boton de acierto, emitimos una musica de acierto, sino una de fallo, reiniciamos el estado del turno
  if ( acierto == HIGH ){
    
    tone( ALTAVOZ, 239, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 259, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 279, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    tone( ALTAVOZ, 299, PITIDO_CORTO);
    delay( PITIDO_CORTO);
    
    // Actualizamos las puntuaciones y los estados de turno.
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

