// Παράδειγμα: Κουμπί σε D2 (INPUT_PULLUP) ελέγχει το LED_BUILTIN
const int BTN = 2;

void setup() {
	pinMode(BTN, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if (digitalRead(BTN) == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}
