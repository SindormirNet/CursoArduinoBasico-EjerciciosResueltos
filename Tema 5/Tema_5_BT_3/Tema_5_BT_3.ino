#define PULSADOR 2           // Constante para el pulsador 


void setup(){
  for ( int i=3; i < 13; i++){
    pinMode( i, OUTPUT);               // Establece los pines del 3 al 12 como SALIDA
  }
  pinMode( PULSADOR, INPUT);         // Establece el pin 2 como ENTRADA
}


void loop() {
  
  //Creamos las variables que almacena el tiempo y la que matiene el tiempo de pulsaciones
  unsigned long pulsaciones = 0;
  unsigned long time;

  // Mantenemos los LEDs apagados hasta que no se pulse el pulsador
  for ( int i=3; i < 13; i++){
    digitalWrite( i, LOW);
  }
  
  // Mientras no se pulsa el pulsador, vamos guardando el tiempo actual
  while( digitalRead(PULSADOR) == LOW)
    time = millis();
   
  // Mientras esta pulsado, vamos guardando el tiempo que se pulsa y transformandolo en segundos
  while( (digitalRead(PULSADOR) == HIGH ) ){
    pulsaciones = (millis() - time)/1000;
  }
  
  delay(1000);
  
  // Encendemos los LEDs uno a uno hasta completar los segundos antes obtenidos
  for( int i=0; i < pulsaciones; i++){
    digitalWrite( i+3, HIGH);
    delay(1000);
  }

}

