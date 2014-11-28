
// Inicializamos los pines del 2 al 8 para los LEDs (Puede ser los mismo del display del tema anterior)
void setup(){
  for ( int i=2; i<9; i++)
    pinMode(i, OUTPUT);
}



void loop(){
  // Inicializamos las dos variables que vamos a usar, una para guardar el valor del potenciometro,
  // y la otra para la conversion a los pines del potenciometro.
  int valor_potenciometro;
  byte valor_mapeado;
  
  // Leemos el valor del potenciometro y lo guardamos
  valor_potenciometro = analogRead(A0);
  
  // Realizamos la conversion para el pin adecuado
  valor_mapeado = map(valor_potenciometro, 0, 1023, 2, 8);
  
  /* Encendemos y apagamos el LED marcado. Como el loop no para de ejecutarse y hay 10 milisegundos 
     de espera con el LED encendido, nuestro ojo lo percibe completamente encendido. No es la solucion
     mas optima. */
  digitalWrite(valor_mapeado, HIGH);
  delay(10);
  digitalWrite(valor_mapeado, LOW);

}
