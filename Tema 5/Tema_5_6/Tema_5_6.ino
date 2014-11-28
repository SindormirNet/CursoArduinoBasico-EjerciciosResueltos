#define LED 3                  // Constante que asigna a 
                                // LED el numero 3
#define PULSADOR 7              // Constante que asigna a
                                // PULSADOR el numero 7
                                
void setup(){
  pinMode( LED, OUTPUT);        // Establece el pin 3 como SALIDA
  pinMode( PULSADOR, INPUT);    // Establece el pin 7 como ENTRADA
}

void loop() {
    
    //Permanece en el bucle sin hacer 
    //nada hasta que se pulse el pulsador
    do{
    }while(digitalRead(PULSADOR) == LOW);
    
      //Enciende y apaga el LED indefinidamente
      do {
        digitalWrite( LED, HIGH);
        delay(100);
        digitalWrite( LED, LOW);
        delay(100);
      } while(1);

}
