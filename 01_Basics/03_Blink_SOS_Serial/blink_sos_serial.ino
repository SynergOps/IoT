// SOS Morse Code με Serial Output
// Εκπέμπει ... --- ... και ταυτόχρονα γράφει την ακολουθία στο Serial Monitor.

const int LED = LED_BUILTIN;

// Χρονισμοί (ms)
const int DOT_DURATION = 200;
const int DASH_DURATION = 600;      // 3 × DOT
const int SYMBOL_SPACE = 200;       // Μεταξύ dot/dash
const int LETTER_SPACE = 600;       // Μεταξύ γραμμάτων
const int WORD_SPACE = 1400;        // Μεταξύ επαναλήψεων SOS

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("[START] SOS Morse Transmitter");
  delay(500);
}
// Βοηθητική για κοινή λειτουργία ενεργοποίησης/σβησίματος LED
void flash(int duration) {
  digitalWrite(LED, HIGH);
  delay(duration);
  digitalWrite(LED, LOW);
  delay(SYMBOL_SPACE);
}

void dot() {
  Serial.print('.');
  flash(DOT_DURATION);
}

void dash() {
  Serial.print('-');
  flash(DASH_DURATION);
}

// Εκκίνηση του προγράμματος
void loop() {
  Serial.print("S:");
  dot(); dot(); dot();
  delay(LETTER_SPACE);

  Serial.print(" O:");
  dash(); dash(); dash();
  delay(LETTER_SPACE);

  Serial.print(" S:");
  dot(); dot(); dot();

  Serial.println("  | Cycle complete");
  delay(WORD_SPACE);
}