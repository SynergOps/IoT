/*
  SOS Morse Code με Serial Output

  Εκπέμπει ... --- ... και ταυτόχρονα γράφει την ακολουθία στο Serial Monitor.

  Βασικές Έννοιες:
  1. **Serial Communication:** Επικοινωνία του Arduino με τον υπολογιστή μέσω USB.
  2. **Debugging:** Χρήση της `Serial.print()` για να βλέπουμε τι κάνει το πρόγραμμα σε πραγματικό χρόνο.
  3. **Συγχρονισμός:** Πώς να συνδυάσουμε φυσική έξοδο (LED) με ψηφιακή πληροφορία (Κείμενο).
*/

// Ο κώδικας του Firmware σας:
const int ledPin = 13; // Χρησιμοποιούμε const για ασφάλεια, όπως συζητήσαμε
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Εκκίνηση σειριακής επικοινωνίας
  Serial.println("Arduino Starting Up...");
}
void loop() {
  // === ΕΔΩ ΧΡΗΣΙΜΟΠΟΙΕΙΤΑΙ Η STATIC ===
  static int flashCount = 0; 
  // Αυτή η γραμμή εκτελείται σε κάθε πέρασμα του loop, 
  // ΑΛΛΑ η αρχικοποίηση " = 0" συμβαίνει ΜΟΝΟ την πρώτη φορά.
  flashCount++; // Αύξηση του μετρητή σε κάθε επανάληψη του loop
  // Κώδικας αναβοσβήσματος:
  digitalWrite(ledPin, HIGH);   // Άναμμα LED
  delay(500);                   // Παύση 500 ms (μισό δευτερόλεπτο)
  digitalWrite(ledPin, LOW);    // Σβήσιμο LED
  delay(500);                   // Παύση 500 ms (μισό δευτερόλεπτο)
  // Τύπωση του αποτελέσματος:
  Serial.print("The LED flashed: ");
  Serial.print(flashCount);
  Serial.println(" times.");
}
