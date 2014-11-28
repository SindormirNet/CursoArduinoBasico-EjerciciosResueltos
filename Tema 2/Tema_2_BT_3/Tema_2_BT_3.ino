#define LED 13                  // Constante que asigna a 
                                // LED el numero 13
#define VCC HIGH                // Constante que asigna a
                                // VCC el valor de HIGH
#define GND LOW                 // Constante que asigna a
                                // GND el valor de LOW


void setup(){
  pinMode(LED, OUTPUT);          // Establece el pin 13 como SALIDA
}

void loop(){
  digitalWrite(LED, VCC);        // Activa el LED
  delay(250);                    // Espera 250 milisegundos
  digitalWrite(LED, GND);        // Desactiva el LED
  delay(250);                    // Espera 250 milisegundos
}
