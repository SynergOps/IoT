/*
  04_Blink_Counter_Serial - Μετρητής Αναβοσβησιών με Serial Output

  Αναβοσβήνει ένα LED και μετρά τις αναβοσβησίες χρησιμοποιώντας static μεταβλητή.
  Ταυτόχρονα εκτυπώνει το πλήθος των αναβοσβησιών στο Serial Monitor.

  Βασικές Έννοιες:
  1. **const μεταβλητή:** Σταθερές ποσότητες (pin αριθμοί) που δεν αλλάζουν.
  2. **static μεταβλητή:** Μετρητής που διατηρεί την τιμή του ανάμεσα στις επαναλήψεις του loop.
  3. **Serial Communication:** Αποστολή δεδομένων στον υπολογιστή για debugging και παρακολούθηση.
*/

// Ορισμός σταθερών με const:
const int ledPin = 13; // Χρησιμοποιούμε const για ασφάλεια, όπως συζητήσαμε
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Εκκίνηση σειριακής επικοινωνίας σε 9600 baud
  Serial.println("Arduino Starting Up...");
}
void loop() {
  // === ΧΡΗΣΙΜΟΠΟΙΟΥΜΕ STATIC ΜΕΤΑΒΛΗΤΗ ΓΙΑ ΜΕΤΡΗΣΗ ===
  static int flashCount = 0; 
  // Η αρχικοποίηση "= 0" συμβαίνει ΜΟΝΟ την πρώτη φορά που εκτελείται το loop().
  // Σε κάθε επόμενη επανάληψη, η τιμή της διατηρείται και δεν ξαναγίνεται 0.
  flashCount++; // Αύξηση του μετρητή σε κάθε επανάληψη του loop
  
  // Κώδικας αναβοσβήσματος LED:
  digitalWrite(ledPin, HIGH);   // Άναμμα LED
  delay(500);                   // Παύση 500 ms (μισό δευτερόλεπτο)
  digitalWrite(ledPin, LOW);    // Σβήσιμο LED
  delay(500);                   // Παύση 500 ms (μισό δευτερόλεπτο)
  
  // Εκτύπωση του μετρητή στο Serial Monitor:
  Serial.print("The LED flashed: ");
  Serial.print(flashCount);
  Serial.println(" times.");
}
