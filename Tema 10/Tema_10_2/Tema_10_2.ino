#define PULSADOR 2
#define LED 13

void setup(){
  pinMode( LED, OUTPUT);
  pinMode( PULSADOR, INPUT_PULLUP);
}

void loop(){
  if( digitalRead( PULSADOR) == LOW) {
    digitalWrite( LED, HIGH);
  }
  else{
    digitalWrite( LED, LOW);
  }
}
