#define LED_ROJO 3
#define LED_VERDE 5
#define LED_AMARILLO 6
#define PULSADOR_1 11
#define PULSADOR_2 12
#define PULSADOR_3 13

// Inicializamos los pines ~3, ~5 y ~6
void setup(){
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(PULSADOR_1, INPUT);
  pinMode(PULSADOR_2, INPUT);
  pinMode(PULSADOR_3, INPUT);
}

unsigned int pulsador_1 = 0, pulsador_2 = 0, pulsador_3 = 0;

void loop(){
  if( (digitalRead(PULSADOR_1) == HIGH) && (pulsador_1 <= 255) ) 
    pulsador_1++;
  else if ( (digitalRead(PULSADOR_1) == HIGH) && (pulsador_1 >= 0) )
    pulsador_1--;
  else if( (digitalRead(PULSADOR_2) == HIGH) && (pulsador_2 <= 255) )
    pulsador_2++;
  else if ( (digitalRead(PULSADOR_2) == HIGH) && (pulsador_2 >= 0) )
    pulsador_2--;
  else if( (digitalRead(PULSADOR_3) == HIGH) && (pulsador_3 <= 255) )
    pulsador_3++;
  else if ( (digitalRead(PULSADOR_3) == HIGH) && (pulsador_3 >= 0) )
    pulsador_3--;
    
  analogWrite(LED_ROJO, pulsador_1);
  analogWrite(LED_VERDE, pulsador_2);
  analogWrite(LED_AMARILLO, pulsador_3);
  delay(20);



}
