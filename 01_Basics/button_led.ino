// Παράδειγμα: Κουμπί σε D2 (INPUT_PULLUP) ελέγχει το LED_BUILTIN
const int BTN = 2;

void setup() {
	pinMode(BTN, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	bool pressed = (digitalRead(BTN) == LOW);
	digitalWrite(LED_BUILTIN, pressed ? HIGH : LOW);
}
