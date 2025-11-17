// Μη-αποκλειστικό blink με millis() (χωρίς delay)
const int LED = LED_BUILTIN;
const unsigned long period = 500; // ms
unsigned long last = 0;
bool state = false;

void setup(){
	pinMode(LED, OUTPUT);
}

void loop(){
	unsigned long now = millis();
	if (now - last >= period) {
		last = now;
		state = !state;
		digitalWrite(LED, state ? HIGH : LOW);
	}
}
