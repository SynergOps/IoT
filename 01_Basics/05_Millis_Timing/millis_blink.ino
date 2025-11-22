/*
  Blink χωρίς Delay (Non-blocking)

  Αυτό είναι ένα από τα πιο σημαντικά μαθήματα στο Arduino.

  Το πρόβλημα με το `delay()`:
  Όταν χρησιμοποιούμε `delay(1000)`, ο επεξεργαστής "κοιμάται" για 1 δευτερόλεπτο.
  Δεν μπορεί να διαβάσει κουμπιά, αισθητήρες ή να κάνει οτιδήποτε άλλο.

  Η λύση με το `millis()`:
  Το `millis()` είναι σαν ένα ρολόι που μετράει milliseconds από τη στιγμή που ξεκίνησε το Arduino.
  Αντί να κοιμόμαστε, ελέγχουμε συνεχώς το ρολόι: "Πέρασε αρκετός χρόνος;"

  Βασικές Έννοιες:
  1. **millis():** Επιστρέφει τον χρόνο λειτουργίας σε ms.
  2. **unsigned long:** Τύπος μεταβλητής για μεγάλους θετικούς αριθμούς (ο χρόνος δεν είναι ποτέ αρνητικός).
  3. **Multitasking:** Η ικανότητα να κάνουμε πολλά πράγματα "ταυτόχρονα".
*/

const int LED_PIN = LED_BUILTIN;

// Σταθερές δεν αλλάζουν. Χρησιμοποιούμε unsigned long για χρόνους.
const unsigned long BLINK_INTERVAL = 500; // Κάθε πότε θα αλλάζει (500ms)

// Μεταβλητές που αλλάζουν
unsigned long previousMillis = 0; // Πότε έγινε η τελευταία αλλαγή;
int ledState = LOW;				  // Η τρέχουσα κατάσταση του LED

void setup()
{
	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	// 1. Διάβασε την τρέχουσα ώρα
	unsigned long currentMillis = millis();

	// 2. Έλεγξε αν πέρασε το χρονικό διάστημα (Τώρα - Πριν >= Διάστημα)
	if (currentMillis - previousMillis >= BLINK_INTERVAL)
	{
		// 3. Αποθήκευσε την τρέχουσα ώρα ως την "τελευταία φορά"
		previousMillis = currentMillis;

		// 4. Άλλαξε την κατάσταση του LED (Toggle)
		if (ledState == LOW)
		{
			ledState = HIGH;
		}
		else
		{
			ledState = LOW;
		}

		// 5. Ενημέρωσε το φυσικό pin
		digitalWrite(LED_PIN, ledState);
	}

	// Εδώ μπορούμε να προσθέσουμε κώδικα που τρέχει ΣΥΝΕΧΕΙΑ, χωρίς να περιμένει το LED!
	// π.χ. readSensors();
}
