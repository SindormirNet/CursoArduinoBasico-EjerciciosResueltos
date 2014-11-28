

void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
  for( int i=2; i < 6; i++)
    pinMode(i, OUTPUT);
  Serial.print("Indique que LED quiere encender o apagar (A,B,C,D encender o a,b,c,d apagar): ");
}


void loop(){
  // Incializamos las variables para guardar el dato leido.
  byte dato;
  byte led_encendido;
  byte led_apagado;
  
  if( Serial.available() > 0){
    dato = Serial.read();
    
    // Una vez leido el dato, si es uno de las opciones, apagamos o encendemos el LED
    if ( dato >= 0x41 && dato <= 0x44){
      led_encendido = map( dato, 0x41, 0x44, 2, 5);
      digitalWrite( led_encendido , HIGH);
    }
    else if ( dato >= 0x61 && dato <= 0x64){
      led_apagado = map( dato, 0x61, 0x64, 2, 5);
      digitalWrite( led_apagado , LOW);
    }

  }

}
