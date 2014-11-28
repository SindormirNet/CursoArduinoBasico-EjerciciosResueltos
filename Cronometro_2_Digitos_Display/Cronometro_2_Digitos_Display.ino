// Constantes que asignan un segmento del display a un PIN de Arduino
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_DP 9

// Configuramos todos los pines para el display y los pulsadores
void setup() {
  for (int i=11; i<13; i++)
    pinMode(i, OUTPUT);
  for (int i=2; i<10; i++)
    pinMode(i, OUTPUT);
}




void loop() {  

  static byte unidades_segundos = 2;
  static byte decenas_segundos = 1;
  
  decenas_segundos = actualiza_decenas_segundos(unidades_segundos, decenas_segundos);
  unidades_segundos = actualiza_segundos(unidades_segundos);

  
  
  
  digitalWrite(12, HIGH);
  imprime_7_segmentos( decenas_segundos);
  delay(8);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  imprime_7_segmentos( unidades_segundos);
  delay(8);
  digitalWrite(11, LOW);
  digitalWrite(9,HIGH);

}


byte actualiza_segundos(byte unidades_segundos){
    static unsigned long tiempo = 0;
    if (millis() - tiempo >= 1000){
      if ( unidades_segundos != 0){
        unidades_segundos--;
        tiempo = millis();
      }
      else if ( unidades_segundos == 0){
        unidades_segundos = 9;
        tiempo = millis();
      }
    }
    return unidades_segundos;
}



byte actualiza_decenas_segundos(byte unidades_segundos, byte decenas_segundos){
    static unsigned long tiempo = 0;
    if (millis() - tiempo >= 1000){
      if( unidades_segundos == 9 && decenas_segundos != 0 ){
        decenas_segundos--;
        tiempo = millis();
      }
      else if( unidades_segundos == 9 && decenas_segundos == 0){
        decenas_segundos = 5;
        tiempo = millis();
      }
    }
    return decenas_segundos;
}



// Funcion que indica los numeros del 1 al 9 y las letras de la A hasta la F
void imprime_7_segmentos(int num) {
  
  switch (num) {
    
    case 0:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, LOW);
      break;
      
    case 1:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
      
    case 2:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;

    case 3:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;

    case 4:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 5:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 6:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 7:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;

    case 8:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 9:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    default:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    }
}

