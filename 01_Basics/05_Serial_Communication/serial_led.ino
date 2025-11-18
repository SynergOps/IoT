// Serial Echo και έλεγχος LED με χαρακτήρες '1'/'0'
void setup(){
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
	Serial.println("Ready. Send 1/0 to toggle LED.");
}

void loop(){
	if (Serial.available()) {
		char c = Serial.read();
		if (c == '1') { digitalWrite(LED_BUILTIN, HIGH); Serial.println("LED ON"); }
		if (c == '0') { digitalWrite(LED_BUILTIN, LOW);  Serial.println("LED OFF"); }
	}
}
