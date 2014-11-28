// Guardamos de forma global el LED anterior para poder apagarlo
byte valor_mapeado_anterior = 0;



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
  
  // Si cambiamos de LED, encendemos el nuevo y apagamos el viejo. Memorizamos el estado actual.
  if (valor_mapeado != valor_mapeado_anterior){
    digitalWrite(valor_mapeado, HIGH);
    digitalWrite(valor_mapeado_anterior, LOW);
    valor_mapeado_anterior = valor_mapeado;
  }
}
