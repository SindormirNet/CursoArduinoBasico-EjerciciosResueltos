// Inicializamos el pin ~6
void setup(){
  pinMode(6, OUTPUT);
}


void loop(){
  // Creamos una variable para almacenar la frecuencia.
  int frecuencia;
  
  // Guardamos la conversion del potenciometro a una escala de 15MHz a 50Hz
  frecuencia = map( analogRead(A0), 0, 1023, 50, 15000);
 
  // Aplicamos la frecuancia haya al zumbador 
  tone( 6, frecuencia); 
}
