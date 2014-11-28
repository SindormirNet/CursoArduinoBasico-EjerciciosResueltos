#define LED 3                  // Constante que asigna a 
                                // LED el numero 3
#define PULSADOR_1 7              // Constante que asigna a
                                // PULSADOR el numero 7
#define PULSADOR_2 6              // Constante que asigna a
                                // PULSADOR el numero 6
                                
void setup(){
  pinMode( LED, OUTPUT);        // Establece el pin 3 como SALIDA
  pinMode( PULSADOR_1, INPUT);    // Establece el pin 7 como ENTRADA
  pinMode( PULSADOR_2, INPUT);    // Establece el pin 6 como ENTRADA
}

void loop() {
    
    //Permanece en el bucle sin hacer nada hasta que se pulsen los dos pulsadores simultaneamente
    do{
    }while( !((digitalRead(PULSADOR_1) == HIGH) && (digitalRead(PULSADOR_2) == HIGH)) );
    
      //Enciende y apaga el LED 50 veces
      for ( int i=0; i < 50; i++){
        digitalWrite( LED, HIGH);
        delay(100);
        digitalWrite( LED, LOW);
        delay(100);
      }

}
