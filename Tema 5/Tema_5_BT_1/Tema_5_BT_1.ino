#define LED 13                  // Constante que asigna a 
// LED el numero 3
#define PULSADOR 7              // Constante que asigna a
// PULSADOR el numero 7
#define TIEMPO 10000            // Constante que asigna a 
// TIEMPO el tiempo de permanencia del concuros

//Creamos la variable que va a almacenar el tiempo
unsigned long time;





void setup(){
  pinMode( LED, OUTPUT);        // Establece el pin 3 como SALIDA
  pinMode( PULSADOR, INPUT);    // Establece el pin 7 como ENTRADA
}


void loop() {
  
  //Creamos la variable que va a almacenar el numero de pulsaciones dadas.
  int pulsaciones=0;

  // Mantenemos el LED apagado hasta que no se pulse el pulsador
  digitalWrite( LED, LOW);
  while(digitalRead(PULSADOR) == LOW);
  
  // Encendemos el LED para marcar el comienzo de los 10 segundos y guardamos el tiempo.
  digitalWrite( LED, HIGH); 
  time = millis();

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

