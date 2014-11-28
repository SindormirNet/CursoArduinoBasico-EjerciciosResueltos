
// Habilitamos el pines ~6
void setup(){
  pinMode(6, OUTPUT);
}



void loop(){
  // Inicializamos las variables para almacenar los valores.
  int potenciometro;
  unsigned int tiempo_ciclo;
  
  // Incrementamos la intensidad del LED segun el tiempo leido
  for( int intensidad = 0; intensidad <=255; intensidad++){ 
    analogWrite(6, intensidad);
   
    // Asignamos el valor leido de los potenciometros y lo mapeamos
    potenciometro = analogRead(A0);
    tiempo_ciclo = map( potenciometro, 0, 1023, 1, 50);
    
    // Esperamos el tiempo mapeado por el potenciometro.
    delay(tiempo_ciclo);
  }
  
  // Decrementamos la intensidad del LED segun el tiempo leido
  for( int intensidad = 255; intensidad >=0; intensidad--){
    analogWrite(6, intensidad);
    
    // Asignamos el valor leido de los potenciometros y lo mapeamos
    potenciometro = analogRead(A0);
    tiempo_ciclo = map( potenciometro, 0, 1023, 1, 50);
    
    // Esperamos el tiempo mapeado por el potenciometro.
    delay(tiempo_ciclo);
  }

}
