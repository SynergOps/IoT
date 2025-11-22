/*
  SOS Morse Code με Serial Output

  Εκπέμπει ... --- ... και ταυτόχρονα γράφει την ακολουθία στο Serial Monitor.

  Βασικές Έννοιες:
  1. **Serial Communication:** Επικοινωνία του Arduino με τον υπολογιστή μέσω USB.
  2. **Debugging:** Χρήση της `Serial.print()` για να βλέπουμε τι κάνει το πρόγραμμα σε πραγματικό χρόνο.
  3. **Συγχρονισμός:** Πώς να συνδυάσουμε φυσική έξοδο (LED) με ψηφιακή πληροφορία (Κείμενο).
*/

const int LED = LED_BUILTIN;

// Χρονισμοί (ms)
const int DOT_DURATION = 200;
const int DASH_DURATION = 600; // 3 × DOT
const int SYMBOL_SPACE = 200;  // Μεταξύ dot/dash
const int LETTER_SPACE = 600;  // Μεταξύ γραμμάτων
const int WORD_SPACE = 1400;   // Μεταξύ επαναλήψεων SOS

void setup()
{
  pinMode(LED, OUTPUT);

  // Έναρξη σειριακής επικοινωνίας στα 9600 bits per second (baud rate)
  // Πρέπει να επιλέξετε την ίδια ταχύτητα στο Serial Monitor του IDE
  Serial.begin(9600);

  Serial.println("[START] SOS Morse Transmitter");
  delay(500);
}

// Βοηθητική συνάρτηση για να αποφύγουμε την επανάληψη κώδικα (DRY - Don't Repeat Yourself)
void flash(int duration)
{
  digitalWrite(LED, HIGH);
  delay(duration);
  digitalWrite(LED, LOW);
  delay(SYMBOL_SPACE);
}

void dot()
{
  Serial.print('.'); // Τύπωσε τελεία στην ίδια γραμμή
  flash(DOT_DURATION);
}

void dash()
{
  Serial.print('-'); // Τύπωσε παύλα στην ίδια γραμμή
  flash(DASH_DURATION);
}

// Εκκίνηση του προγράμματος
void loop()
{
  Serial.print("S:");
  dot();
  dot();
  dot();
  delay(LETTER_SPACE);

  Serial.print(" O:");
  dash();
  dash();
  dash();
  delay(LETTER_SPACE);

  Serial.print(" S:");
  dot();
  dot();
  dot();

  // println = print line (τυπώνει και αλλάζει γραμμή στο τέλος)
  Serial.println("  | Cycle complete");

  delay(WORD_SPACE);
}
delay(WORD_SPACE);
}