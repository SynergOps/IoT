// SOS Morse Code: ... --- ... (3 κοντά, 3 μακριά, 3 κοντά)
// Διεθνές σήμα κινδύνου

const int LED = LED_BUILTIN;  // Pin 13 (ενσωματωμένο LED)

// Χρονισμοί Morse (σε milliseconds)
int DOT_DURATION = 200;        // Τελεία: 200ms
int DASH_DURATION = 600;       // Παύλα: 600ms (3× τελεία)
int SYMBOL_SPACE = 200;        // Διάστημα μεταξύ . και -
int LETTER_SPACE = 600;        // Διάστημα μεταξύ S-O-S
int WORD_SPACE = 1400;         // Παύση πριν επαναλάβει

void setup() {
  pinMode(LED, OUTPUT);
  // Μικρή αρχική καθυστέρηση
  delay(1000);
}

// Συνάρτηση για τελεία (.)
void dot() {
  digitalWrite(LED, HIGH);
  delay(DOT_DURATION);
  digitalWrite(LED, LOW);
  delay(SYMBOL_SPACE);
}

// Συνάρτηση για παύλα (-)
void dash() {
  digitalWrite(LED, HIGH);
  delay(DASH_DURATION);
  digitalWrite(LED, LOW);
  delay(SYMBOL_SPACE);
}


void loop() {
  // S: ... (3 τελείες)
  dot();
  dot();
  dot();
  delay(LETTER_SPACE);
  
  // O: --- (3 παύλες)
  dash();
  dash();
  dash();
  delay(LETTER_SPACE);
  
  // S: ... (3 τελείες)
  dot();
  dot();
  dot();
  
  // Παύση πριν επαναλάβει το SOS
  delay(WORD_SPACE);
}

