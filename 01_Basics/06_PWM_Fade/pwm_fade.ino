/*
  PWM Fade (Pulse Width Modulation)

  Αυξομειώνει ομαλά τη φωτεινότητα ενός LED (εφέ "αναπνοής").

  Βασικές Έννοιες:
  1. **PWM (Pulse Width Modulation):** Τεχνική για να προσομοιώσουμε αναλογική έξοδο χρησιμοποιώντας ψηφιακά pins.
	 Ανοιγοκλείνουμε το pin πολύ γρήγορα. Όσο περισσότερο μένει ανοιχτό (Duty Cycle), τόσο πιο φωτεινό φαίνεται το LED.
  2. **analogWrite(pin, value):** Δέχεται τιμές από 0 (0% - σβηστό) έως 255 (100% - πλήρως αναμμένο).
	 Λειτουργεί μόνο στα pins που έχουν το σύμβολο '~' (π.χ. 3, 5, 6, 9, 10, 11 στο Uno).
  3. **for loop:** Δομή επανάληψης για να μετρήσουμε από το 0 στο 255 και ανάποδα.
*/

const int PWM_PIN = 9;	  // Πρέπει να είναι PWM pin (έχει ~)
const int FADE_DELAY = 5; // Πόσο γρήγορα γίνεται το fade (μικρότερο = πιο γρήγορο)

void setup()
{
	pinMode(PWM_PIN, OUTPUT);
}

void loop()
{
	// Σταδιακή αύξηση φωτεινότητας (Fade In)
	// Από 0 (σβηστό) έως 255 (μέγιστο)
	for (int brightness = 0; brightness <= 255; brightness++)
	{
		analogWrite(PWM_PIN, brightness);
		delay(FADE_DELAY); // Μικρή καθυστέρηση για να προλαβαίνει το μάτι να δει την αλλαγή
	}

	// Σταδιακή μείωση φωτεινότητας (Fade Out)
	// Από 255 (μέγιστο) έως 0 (σβηστό)
	for (int brightness = 255; brightness >= 0; brightness--)
	{
		analogWrite(PWM_PIN, brightness);
		delay(FADE_DELAY);
	}
}
