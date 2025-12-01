/*
  Serial LED Control

  Ελέγχει το LED στέλνοντας εντολές από το πληκτρολόγιο του υπολογιστή.

  Βασικές Έννοιες:
  1. **Serial.available():** Ελέγχει αν έχουν έρθει δεδομένα από τον υπολογιστή που περιμένουν να διαβαστούν.
  2. **Serial.read():** Διαβάζει τον επόμενο χαρακτήρα (byte) από τη σειρά αναμονής (buffer).
  3. **Χαρακτήρες (Chars):** Οι υπολογιστές στέλνουν γράμματα ως αριθμούς (ASCII). Το '1' είναι διαφορετικό από τον αριθμό 1.

  Οδηγίες:
  - Ανοίξτε το Serial Monitor (Tools > Serial Monitor).
  - Ρυθμίστε ταχύτητα 9600 baud.
  - Πληκτρολογήστε '1' και πατήστε Enter -> Το LED ανάβει.
  - Πληκτρολογήστε '0' και πατήστε Enter -> Το LED σβήνει.
*/

const int LED_PIN = 9; // Χρησιμοποιούμε το Pin 9 (όπως στο προηγούμενο μάθημα PWM)
// Αν δεν έχετε εξωτερικό LED, αλλάξτε το σε LED_BUILTIN (Pin 13)

void setup()
{
	pinMode(LED_PIN, OUTPUT);

	// Έναρξη επικοινωνίας
	Serial.begin(9600);

	// Μήνυμα καλωσορίσματος
	Serial.println("--- Serial LED Control ---");
	Serial.println("Type '1' to turn ON");
	Serial.println("Type '0' to turn OFF");
}

void loop()
{
	// Έλεγχος: Υπάρχουν νέα δεδομένα;
	if (Serial.available() > 0)
	{

		// Διάβασε τον χαρακτήρα
		char command = Serial.read();

		// Έλεγξε τι είναι ο χαρακτήρας
		if (command == '1')
		{
			digitalWrite(LED_PIN, HIGH);
			Serial.println("LED turned ON");
		}
		else if (command == '0')
		{
			digitalWrite(LED_PIN, LOW);
			Serial.println("LED turned OFF");
		}
		// Αγνοούμε άλλους χαρακτήρες (όπως το Enter/Newline)
	}
}
