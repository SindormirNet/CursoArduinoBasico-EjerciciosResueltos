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
  static boolean estado_0 = 1;
  static boolean estado_1 = 0;
  static boolean estado_2 = 0;
  static boolean estado_3 = 0;
  static boolean estado_acierto = 0;
  

  // Mantenemos los LEDs apagados hasta que no se pulse ningun pulsador
  digitalWrite( LED_ROJO, LOW);
  digitalWrite( LED_VERDE, LOW);
  
  

      
  if ( estado_0 == 1){
    if( digitalRead( PULSADOR_1) == HIGH || digitalRead( PULSADOR_2) == HIGH || digitalRead( PULSADOR_3) == HIGH || digitalRead( PULSADOR_4) == HIGH ){
      estado_1 = 1;
      estado_0 = 0;
      if( digitalRead( PULSADOR_1) == HIGH){
        estado_acierto = 1;
      }
      else {
        estado_acierto = 0;
      }
      delay( 300);
    }
  }
  
  
  else  if ( estado_1 == 1){
    if( digitalRead( PULSADOR_1) == HIGH || digitalRead( PULSADOR_2) == HIGH || digitalRead( PULSADOR_3) == HIGH || digitalRead( PULSADOR_4) == HIGH ){
      estado_2 = 1;
      estado_1 = 0;
      if( digitalRead( PULSADOR_2) == HIGH && estado_acierto == 1){
        estado_acierto = 1;
      }
      else{
        estado_acierto = 0;
      }
      delay( 300);
    }
  }
  
  
  else  if ( estado_2 == 1){
    if( digitalRead( PULSADOR_1) == HIGH || digitalRead( PULSADOR_2) == HIGH || digitalRead( PULSADOR_3) == HIGH || digitalRead( PULSADOR_4) == HIGH ){
      estado_3 = 1;
      estado_2 = 0;
      if( digitalRead( PULSADOR_3) == HIGH && estado_acierto == 1){
        estado_acierto = 1;
      }
      else{
        estado_acierto = 0;
      }
      delay( 300);
    }
  }
  
  
  else  if ( estado_3 == 1){
    if( digitalRead( PULSADOR_1) == HIGH || digitalRead( PULSADOR_2) == HIGH || digitalRead( PULSADOR_3) == HIGH || digitalRead( PULSADOR_4) == HIGH ){
      estado_0 = 1;
      estado_3 = 0;
      if( digitalRead( PULSADOR_4) == HIGH && estado_acierto == 1){
        digitalWrite( LED_VERDE, HIGH);
        delay( 2000);
        digitalWrite( LED_VERDE, LOW);
        estado_acierto = 0;
      }
      else{
        digitalWrite( LED_ROJO, HIGH);
        delay( 5000);
        digitalWrite( LED_ROJO, LOW);
        estado_acierto = 0;
      }
      delay( 300);
    }
  }


}

