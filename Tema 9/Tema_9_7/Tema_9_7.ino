// Constantes que asignan un segmento del display a un PIN de Arduino
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_DP 9

void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
  Serial.print( "Introduce numeros del 0 al 9: ");
  for (int i=2; i<11; i++)                                  // Inicializamos los pines del 2 al 10 como SALIDAS, para el Display
    pinMode(i, OUTPUT);
}


void loop(){
  // Variables para guardar el dato leido y la conversion a entero.
  byte dato;
  int numero;
   
  if( Serial.available() > 0) {                             // ¿Ha enviado algun dato el PC?
    dato = Serial.read();                                   // Guardamos el dato enviado en la variable dato
    numero = map(dato, 0x30, 0x39, 0, 9);
    if( numero >= 0 && numero <= 9){                        // Si el numero esta entre el 0 y el 9 encendemos, sino apagamos.
      digitalWrite(10, HIGH);
      imprime_7_segmentos(numero);
    }
    else
      digitalWrite( 10, LOW);
  }

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
