/*
  Button Toggle (State Memory)

  Σε αυτό το παράδειγμα εισάγουμε δύο πολύ σημαντικές έννοιες:
  1. **Μνήμη (State):** Το πρόγραμμα "θυμάται" αν το LED είναι αναμμένο ή σβηστό.
  2. **Ανίχνευση Ακμής (Edge Detection):** Μας ενδιαφέρει η στιγμή που το κουμπί *αλλάζει* από ελεύθερο σε πατημένο, όχι απλά αν είναι πατημένο.
  3. **Αποθορυβοποίηση (Debounce):** Τα μηχανικά κουμπιά κάνουν "θόρυβο" όταν πατιούνται. Χρησιμοποιούμε χρόνο για να φιλτράρουμε αυτόν τον θόρυβο.
*/

const int BTN = 2;
const int LED = LED_BUILTIN;

// Μεταβλητές Κατάστασης (State Variables)
int ledState = LOW;         // Κρατάει στη μνήμη την κατάσταση του LED (ON/OFF)
int lastButtonState = HIGH; // Κρατάει την προηγούμενη ανάγνωση του pin (για σύγκριση)

// Μεταβλητές Χρόνου (για Debounce)
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // 50ms αναμονή για να σταθεροποιηθεί το σήμα

void setup()
{
    pinMode(BTN, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
}

void loop()
{
    // 1. Διάβασε την τρέχουσα τιμή του pin
    int reading = digitalRead(BTN);

    // 2. Έλεγχος για αλλαγή (λόγω θορύβου ή πραγματικού πατήματος)
    if (reading != lastButtonState)
    {
        // Αν η ένδειξη άλλαξε, επανεκκίνησε το χρονόμετρο debounce
        lastDebounceTime = millis();
    }

    // 3. Έλεγχος αν πέρασε ο χρόνος debounce
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        // Αν φτάσαμε εδώ, η ένδειξη είναι σταθερή για τουλάχιστον 50ms.

        // Χρειαζόμαστε μια μεταβλητή για να θυμόμαστε την *σταθεροποιημένη* κατάσταση του κουμπιού
        // Το 'static' σημαίνει ότι η μεταβλητή διατηρεί την τιμή της μεταξύ των εκτελέσεων της loop()
        static int buttonState = HIGH;

        // Αν η σταθερή κατάσταση άλλαξε σε σχέση με αυτό που ξέραμε...
        if (reading != buttonState)
        {
            buttonState = reading; // Ενημέρωσε τη μνήμη μας

            // 4. Δράση μόνο στο ΠΑΤΗΜΑ (Falling Edge: HIGH -> LOW)
            if (buttonState == LOW)
            {
                // Εδώ συμβαίνει η μαγεία του Toggle:
                ledState = !ledState; // Αντιστροφή: Αν ήταν HIGH γίνεται LOW, και αντίστροφα
                digitalWrite(LED, ledState);
            }
        }
    }

    // Αποθήκευση της τρέχουσας ανάγνωσης για τον επόμενο κύκλο loop
    lastButtonState = reading;
}
