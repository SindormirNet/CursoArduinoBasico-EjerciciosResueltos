#define LED 3                   // Constante que asigna a 
                                // LED el numero 3
#define PULSADOR 7              // Constante que asigna a
                                // PULSADOR el numero 7
                                
void setup(){
  pinMode( LED, OUTPUT);        // Establece el pin 3 como SALIDA
  pinMode( PULSADOR, INPUT);    // Establece el pin 7 como ENTRADA
}

void loop() {
    
    //Parpadea mientras el pulsador este activado
    while(digitalRead(PULSADOR) == HIGH) {
    
      digitalWrite( LED, HIGH);
      delay(100);
      digitalWrite( LED, LOW);
      delay(100);
      
    }

}
