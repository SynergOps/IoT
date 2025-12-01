/*
  Button Toggle (State Memory)

  Σε αυτό το παράδειγμα εισάγουμε δύο πολύ σημαντικές έννοιες:
  1. **Μνήμη (State):** Το πρόγραμμα "θυμάται" αν το LED είναι αναμμένο ή σβηστό.
  2. **Ανίχνευση Ακμής (Edge Detection):** Μας ενδιαφέρει η στιγμή που το κουμπί *αλλάζει* από ελεύθερο σε πατημένο.
  3. **Αποθορυβοποίηση (Debounce):** Τα μηχανικά κουμπιά κάνουν "θόρυβο" όταν πατιούνται.
     Εδώ θα χρησιμοποιήσουμε μια απλή καθυστέρηση (delay) για να φιλτράρουμε τον θόρυβο.
*/

const int BTN = 2;
const int LED = LED_BUILTIN;

// Μεταβλητές Κατάστασης (State Variables)
int ledState = LOW;         // Κρατάει στη μνήμη την κατάσταση του LED (ON/OFF)
int lastButtonState = HIGH; // Κρατάει την προηγούμενη ανάγνωση του pin (INPUT_PULLUP: HIGH = ελεύθερο)

void setup()
{
    pinMode(BTN, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
}

void loop()
{
    // 1. Διάβασε την τρέχουσα τιμή του pin
    int reading = digitalRead(BTN);

    // 2. Έλεγχος αν άλλαξε η κατάσταση σε σχέση με την προηγούμενη φορά
    if (reading != lastButtonState)
    {
        // Περίμενε λίγο για να σταματήσει ο μηχανικός θόρυβος (Debounce)
        delay(50);

        // Διάβασε ξανά για να βεβαιωθείς
        if (digitalRead(BTN) == reading)
        {
            // Η αλλαγή είναι έγκυρη, ενημέρωσε την τελευταία κατάσταση
            lastButtonState = reading;

            // Αν το κουμπί μόλις πατήθηκε (έγινε LOW)
            if (lastButtonState == LOW)
            {
                // Άλλαξε την κατάσταση του LED (Toggle)
                ledState = !ledState;
                digitalWrite(LED, ledState);
            }
        }
    }
}
