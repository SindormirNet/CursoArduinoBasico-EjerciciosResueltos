#define LED_ROJO 12            // Constante para el LED_ROJO
#define LED_VERDE 11           // Constante para el LED_VERDE
#define PULSADOR_1 7           // Constante para el pulsador 1
#define PULSADOR_2 6           // Constante para el pulsador 2
#define PULSADOR_3 5           // Constante para el pulsador 3
#define PULSADOR_4 4           // Constante para el pulsador 4
#define TIEMPO_PULSACION 300   // Constate para el tiempo de espera entre las pulsaciones

void setup(){
  pinMode( LED_ROJO, OUTPUT);          // Establece el pin 12 como SALIDA
  pinMode( LED_VERDE, OUTPUT);         // Establece el pin 11 como SALIDA
  pinMode( PULSADOR_1, INPUT);         // Establece el pin 7 como ENTRADA
  pinMode( PULSADOR_2, INPUT);         // Establece el pin 6 como ENTRADA
  pinMode( PULSADOR_3, INPUT);         // Establece el pin 5 como ENTRADA
  pinMode( PULSADOR_4, INPUT);         // Establece el pin 4 como ENTRADA
}


void loop() {

  //Creamos las variables que van a almacenar los estados y el codigo de seguridad
  static int estado = 0;
  byte lectura;
  static boolean estado_acierto = 1;
  const byte codigo_seguridad[4] = {1, 2, 3, 4 };


  // Bucle en el que vamos analizando una vez que haya habido pulsacion si ha sido la correcta, vamos
  // avanzando un estado cada vez que haya habido una pulsacion, tanto correcta como no.
  for( int i = 0; i < 4; i++){    
    if ( estado == i){
      lectura = pulsacion();
      delay(TIEMPO_PULSACION);
      if( lectura ){
        estado++;
        if( lectura != codigo_seguridad[i] )
          estado_acierto = 0;
      }
    }
  }

  // Una vez hayamos alcanzado el cuarto estado(a la cuarta pulsacion) inicializamos el estado
  // y emitimos con el LED correcto si el codigo de seguridad ha sido el correcto.
  if( estado == 4){
    estado = 0;
    if( estado_acierto == 1){
      digitalWrite( LED_VERDE, HIGH);
      delay( 2000);
      digitalWrite( LED_VERDE, LOW);

    }
    else{
      digitalWrite( LED_ROJO, HIGH);
      delay( 5000);
      digitalWrite( LED_ROJO, LOW);
      estado_acierto = 1;
    }
  }
}


// Funcion que devuelve en forma de byte que pulsador ha sido presionado
byte pulsacion(){
  if( digitalRead( PULSADOR_1))      return 1;
  else if( digitalRead( PULSADOR_2)) return 2;
  else if( digitalRead( PULSADOR_3)) return 3;
  else if( digitalRead( PULSADOR_4)) return 4;
  else                               return 0;
}

