const int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  alleMeineEntchen();
}

void alleMeineEntchen() {
  char notes[] = "cdef gg aaaa g aaaa g ffff ee dddd c";
  int beats[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int tempo = 300;
  const int songLength = 37;

  int i, duration;
  for (i = 0; i < songLength; i++) {
    duration = beats[i] * tempo;
    if (notes[i] == ' ') {
      delay(duration);
    } else {
      tone(buzzerPin, frequency(notes[i]), duration);
    }
    delay(duration);
    delay(tempo / 10);
  }
}

int frequency(char note) {
  int i;
  const int numNotes = 8;

  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  int frequency[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++) {
    if (names[i] == note) {
      return frequency[i];
    }
  }
  return 0;
}
