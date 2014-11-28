void setup(){
  pinMode(6, OUTPUT);
}

void loop(){
  int potenciometro;
  int intensidad_led;
  
  potenciometro = analogRead(A0);
  
  intensidad_led = map( potenciometro, 0, 1023, 0, 255);
  
  analogWrite(6, intensidad_led);

}
