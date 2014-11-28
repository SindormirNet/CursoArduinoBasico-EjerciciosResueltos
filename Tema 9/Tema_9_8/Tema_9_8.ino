void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
  
}


void loop(){
  // Variables para guardar el dato leido y la conversion a entero.
  float voltaje = map ( analogRead(A0), 0, 1023, 0, 5000);
  
  // Expresamos por pantalla los valores obtenidos por el potenciometro.
  Serial.print( "El voltaje obtenido es: ");
  Serial.print( voltaje/1000);
  Serial.println( "V");
  delay(200);

}

