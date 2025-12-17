/*
  Multitasking με Millis (Blink & Button)

  Σε αυτό το μάθημα συνδυάζουμε όσα μάθαμε:
  1. **Digital I/O:** Διαβάζουμε το κουμπί (από το κεφάλαιο 04).
  2. **Millis Timing:** Αναβοσβήνουμε το LED χωρίς `delay()`

  Το Πρόβλημα:
  Αν χρησιμοποιούσαμε `delay(1000)` για το LED, το Arduino θα "κοιμόταν" για 1 δευτερόλεπτο.
  Αν πατούσαμε το κουμπί εκείνη τη στιγμή, το Arduino δεν θα το καταλάβαινε!

  Η Λύση:
  Χρησιμοποιούμε το `millis()` για να μετράμε τον χρόνο για το LED, ενώ ταυτόχρονα
  ελέγχουμε το κουμπί σε κάθε κύκλο του `loop()`.

  Σενάριο:
  - Το LED αναβοσβήνει αργά (κάθε 1 δευτερόλεπτο).
  - Όσο ΚΡΑΤΑΜΕ ΠΑΤΗΜΕΝΟ το κουμπί, το LED αναβοσβήνει γρήγορα (κάθε 100ms).
  - Μόλις το αφήσουμε, επιστρέφει στον αργό ρυθμό.
*/

const int LED_PIN = LED_BUILTIN;
const int BTN_PIN = 2; // Το κουμπί που έχουμε ήδη στο breadboard

// Μεταβλητές Χρόνου
unsigned long previousMillis = 0;
unsigned long interval = 1000; // Αρχική ταχύτητα: 1 δευτερόλεπτο

// Κατάσταση LED
int ledState = LOW;

void setup()
{
	pinMode(LED_PIN, OUTPUT);
	pinMode(BTN_PIN, INPUT_PULLUP); // Χρήση εσωτερικής αντίστασης
}

void loop()
{
	// --- ΕΡΓΑΣΙΑ 1: Έλεγχος Κουμπιού (Άμεση Αντίδραση) ---
	// Διαβάζουμε το κουμπί σε ΚΑΘΕ κύκλο, χωρίς καθυστερήσεις
	if (digitalRead(BTN_PIN) == LOW)
	{
		// Όσο το κουμπί είναι πατημένο, τρέχουμε γρήγορα!
		interval = 100;
	}
	else
	{
		// Όταν αφήνουμε το κουμπί, επιστρέφουμε στον αργό ρυθμό
		interval = 1000;
	}

	// --- ΕΡΓΑΣΙΑ 2: Διαχείριση Χρόνου LED (Blink) ---
	unsigned long currentMillis = millis();

	// Ελέγχουμε αν πέρασε ο χρόνος που ορίσαμε (είτε 1000ms είτε 100ms)
	if (currentMillis - previousMillis >= interval)
	{
		// Ήρθε η ώρα να αλλάξουμε κατάσταση
		previousMillis = currentMillis; // Αποθήκευση της τρέχουσας ώρας

		// Toggle LED
		if (ledState == LOW)
			ledState = HIGH;
		else
			ledState = LOW;

		digitalWrite(LED_PIN, ledState);
	}
}
