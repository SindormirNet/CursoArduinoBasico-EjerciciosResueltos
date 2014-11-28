// Habilitamos los pines ~3 y ~6
void setup(){
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
}



void loop(){
  // Creamos todas las variables que vamos a necesitar
  int potenciometro_1;
  int potenciometro_2;  
  int intensidad_led_1;
  int intensidad_led_2;
  
  // Asignamos el valor leido de los potenciometros
  potenciometro_1 = analogRead(A0);
  potenciometro_2 = analogRead(A1);
  
  // Conversionamos para poder crear entradas analogicas
  intensidad_led_1 = map( potenciometro_1, 0, 1023, 0, 255);
  intensidad_led_2 = map( potenciometro_2, 0, 1023, 0, 255);
  
  // Encendemos los Leds segun la intensidad analogicamente
  analogWrite(6, intensidad_led_1);
  analogWrite(3, intensidad_led_2);

}
