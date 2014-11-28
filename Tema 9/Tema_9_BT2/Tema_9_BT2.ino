#define DURACION_PUNTO 64
#define ZUMBADOR 2

const int duracion_punto = DURACION_PUNTO;             // Numero de periodos por punto
const int pausa_punto = DURACION_PUNTO;                // Pausa despues de un punto
const int duracion_raya = 3*DURACION_PUNTO;            // Numero de periodos por raya
const int pausa_raya = DURACION_PUNTO;                 // Pausa despues de una raya


char *letras[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char *numeros[]={"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

void setup(){
  Serial.begin(9600);                                       // Indicamos la velocidad del puerto serie
  Serial.print("Escriba lo que quiere transmitir: ");
  pinMode( ZUMBADOR, OUTPUT);
}


void loop(){
  char mensaje[32];
  
  if (Serial.available()){
    int i = 0;
    
    while( Serial.available()){
      mensaje[i] = Serial.read();
      if ( mensaje[i] >= 'A' && mensaje[i] <= 'Z'){
        int posicion = map ( mensaje[i], 0x41, 0x5A, 0, 25);
        sonar( letras [posicion]);
      
      }
      else if ( mensaje[i] >= '0' && mensaje[i] <= '9'){
        int posicion = map ( mensaje[i], 0x30, 0x39, 0, 9);
        sonar( numeros [posicion]);
      }
      else if ( mensaje[i] == ' '){
         delay(pausa_punto*7);
      }
      
    i++;
    }
  }
  
  delay(2000);
}


void sonar(char *secuencia){
  
  int i = 0;
  
  while (secuencia[i] != NULL){
    
    if (secuencia[i] == '.'){
      digitalWrite( ZUMBADOR, HIGH);
      delay(duracion_punto);
      digitalWrite( ZUMBADOR, LOW);
    }
    
    else{
      digitalWrite( ZUMBADOR, HIGH);
      delay(duracion_raya);
      digitalWrite( ZUMBADOR, LOW);
    }
    
    delay(pausa_punto);
    i++;
  }
  
  delay(pausa_punto*3);
}


