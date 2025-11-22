/*
  Button LED Control (Momentary)

  Διαβάζει την κατάσταση ενός κουμπιού και ανάβει το LED όσο το κουμπί είναι πατημένο.

  Βασικές Έννοιες:
  1. **INPUT_PULLUP:** Χρησιμοποιούμε την εσωτερική αντίσταση του Arduino.
     - Όταν το κουμπί ΔΕΝ πατιέται, το pin διαβάζει HIGH (5V).
     - Όταν το κουμπί πατιέται, συνδέεται στο GND και διαβάζει LOW (0V).
     Αυτό λέγεται "Active Low" λογική.
  2. **digitalRead():** Διαβάζει την τάση στο pin (HIGH ή LOW).
  3. **if/else:** Δομή ελέγχου για λήψη αποφάσεων.
*/

// Το κουμπί συνδέεται στο Pin 2 και στο GND
const int BTN_PIN = 2;
const int LED_PIN = LED_BUILTIN;

void setup()
{
    // Ορίζουμε το pin του κουμπιού ως είσοδο με ενεργοποιημένη την εσωτερική αντίσταση pull-up
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // Διαβάζουμε την κατάσταση του κουμπιού
    int buttonState = digitalRead(BTN_PIN);

    // Λόγω του INPUT_PULLUP, το LOW σημαίνει ΠΑΤΗΜΕΝΟ
    if (buttonState == LOW)
    {
        digitalWrite(LED_PIN, HIGH); // Άναψε το LED
    }
    else
    {
        digitalWrite(LED_PIN, LOW); // Σβήσε το LED
    }
}
