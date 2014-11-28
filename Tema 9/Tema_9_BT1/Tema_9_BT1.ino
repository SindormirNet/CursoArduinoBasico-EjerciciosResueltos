
void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
}


// Para el montaje. Conectamos 5V - Resitencia 1000 Ohm - Pin A0 - Resistencia a conocer - 0V
// Hemos dedicido el metodo calculando la Intensidad para toda la rama siendo            I = Vtotal / (Rtotal) = V / ( 1000 Ohm + Resistencia a conocer)
// por otra parte tenemos que tambien la Intensidad para la resisntecia a conocer es     I = Vmedido / (Resistencia a conocer)
// al igualar estas Intensidades y despejar la resistencia a conococer nos queda:        Resistencia a conocer = ( Vmedido * 1000 Ohm ) / ( Vtotal - Vmedido)

void loop(){
  // Variables para guardar el dato leido y la conversion a entero.
  float voltaje = map ( analogRead(A0), 0, 1023, 0, 5000);
  voltaje = voltaje/1000;
  float resistencia = voltaje*1000/(5-voltaje);
  
  // Expresamos por pantalla los valores obtenidos por el potenciometro.
  Serial.print( "La resistencia obtenida es: ");
  Serial.print( resistencia);
  Serial.println( " Ohmios");
  delay(2000);

}
