// Μη-αποκλειστικό blink με millis() (χωρίς delay)
const int LED = LED_BUILTIN;
const unsigned long period = 500; // ms
unsigned long last = 0;
bool state = false;

void setup(){
	pinMode(LED, OUTPUT);
}

void loop(){
	unsigned long now = millis(); // Τι ώρα είναι ΤΩΡΑ;
	
	if (now - last >= period) { // Έχει περάσει αρκετός χρόνος;
		last = now; // Θυμήσου την τωρινή ώρα
		state = !state; // Άλλαξε κατάσταση (toggle)
		
		// Άναψε ή σβήσε το LED ανάλογα με την κατάσταση
		if (state) {
			digitalWrite(LED, HIGH);  // Άναψε
		} else {
			digitalWrite(LED, LOW);   // Σβήσε
		}
	}
}
