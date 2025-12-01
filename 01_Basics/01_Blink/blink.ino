/*
  Blink: Το "Hello World" του Hardware

  Αυτό είναι το πιο απλό πρόγραμμα για να ελέγξετε αν όλα λειτουργούν σωστά.
  Αναβοσβήνει το ενσωματωμένο LED του Arduino.

  Βασικές Έννοιες:
  1. **setup():** Τρέχει ΜΙΑ φορά όταν ξεκινάει το Arduino. Εδώ ρυθμίζουμε τα pins.
  2. **loop():** Τρέχει ΣΥΝΕΧΕΙΑ, ξανά και ξανά. Εδώ μπαίνει η κύρια λογική.
  3. **pinMode():** Ορίζει αν ένα pin είναι ΕΙΣΟΔΟΣ (Input) ή ΕΞΟΔΟΣ (Output).
  4. **digitalWrite():** Στέλνει ρεύμα (HIGH) ή κόβει το ρεύμα (LOW) σε ένα pin.
  5. **delay():** Παγώνει την εκτέλεση του προγράμματος για συγκεκριμένα milliseconds.
*/

// Το LED_BUILTIN είναι μια σταθερά που αντιστοιχεί στο pin 13 στα περισσότερα Arduino
const int LED_PIN = LED_BUILTIN;

void setup()
{
	// Ρυθμίζουμε το pin του LED ως έξοδο (OUTPUT) για να μπορούμε να στείλουμε τάση
	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_PIN, HIGH); // Άναψε το LED (HIGH = 5V)
	delay(500);					 // Περίμενε 500ms (μισό δευτερόλεπτο)

	digitalWrite(LED_PIN, LOW); // Σβήσε το LED (LOW = 0V)
	delay(500);					// Περίμενε 500ms
}
