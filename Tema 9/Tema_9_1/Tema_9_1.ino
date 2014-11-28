void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
  pinMode( 9, OUTPUT);                                      // Establecemos el pin 9 como SALIDA
  Serial.print( "Introduce numeros del 0 al 9: ");
}


void loop(){
  byte dato;
  byte brillo;
   
  if( Serial.available() > 0) {                             // ¿Ha enviado algun dato el PC?
    dato= Serial.read();                                    // Guardamos el dato enviado en la variable dato
    brillo = map( dato, 0x30, 0x39, 0, 255);                // Escalamos el valor
    analogWrite( 9, brillo);                                // Modificamos la intensidad del LED
    Serial.print( "Cambia brillo a: ");                     // Escribimos de vuelta al PC
    Serial.println( dato - 0x30);
  }

}
