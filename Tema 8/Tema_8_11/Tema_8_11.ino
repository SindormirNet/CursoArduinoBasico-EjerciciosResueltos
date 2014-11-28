#define ALTAVOZ 6
#define B 466
#define C 261
#define E 329
#define G 391

// Inicializamos el pin ~6
void setup() {
  pinMode(ZUMBADOR, OUTPUT);

}

void loop() {
  // Tocamos la nota correspontiente el tiempo determinado.
  tone(ALTAVOZ, E, 500);
  // Esperamos ese tiempo hasta tocar la poxima nota.
  delay (500);
  tone (ALTAVOZ, E, 500);
  delay (500);
  tone(ALTAVOZ, E, 500);
  delay (500);
  tone(ALTAVOZ, C, 350);
  delay (350);
  tone (ALTAVOZ, G, 150);
  delay (150);
  tone (ALTAVOZ, E, 500);
  delay (500);
  tone (ALTAVOZ, C, 350);
  delay (350);
  tone (ALTAVOZ, G , 150);
  delay (150);
  tone (ALTAVOZ, E , 650);

  delay (4000);

}
