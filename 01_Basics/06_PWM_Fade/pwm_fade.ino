// Fade σε ακίδα PWM (π.χ. D9 σε Uno)
const int PWM_LED = 9;

void setup(){
	pinMode(PWM_LED, OUTPUT);
}

void loop(){
	for (int v = 0; v <= 255; v++) {
		analogWrite(PWM_LED, v);
		delay(5);
	}
	for (int v = 255; v >= 0; v--) {
		analogWrite(PWM_LED, v);
		delay(5);
	}
}
