/*
  Capstone Project: Smart Light

  Συνδυασμός όλων των βασικών εννοιών:
  1. Ψηφιακή Είσοδος (Κουμπί) - Έλεγχος
  2. Χρονισμός (Millis) - Multitasking (Blink χωρίς delay)
  3. Σειριακή Επικοινωνία - Έλεγχος από PC
  4. Κατάσταση (State Machine) - Διαχείριση λειτουργίας

  Λειτουργία:
  - Το σύστημα έχει 3 καταστάσεις: OFF, SLOW_BLINK, FAST_BLINK.
  - Το κουμπί αλλάζει την κατάσταση κυκλικά.
  - Μπορούμε επίσης να στείλουμε '0', '1', '2' από το Serial Monitor για αλλαγή κατάστασης.
*/

const int BTN = 2;
const int LED = LED_BUILTIN;

// Καταστάσεις λειτουργίας
enum Mode
{
    OFF,
    SLOW_BLINK,
    FAST_BLINK
};

Mode currentMode = OFF;

// Μεταβλητές για το κουμπί (Edge Detection & Debounce)
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// Μεταβλητές για το Blink (Millis)
unsigned long previousMillis = 0;
int ledState = LOW;

void setup()
{
    pinMode(BTN, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);

    Serial.println("Smart Light System Ready");
    Serial.println("Press Button or type: 0 (OFF), 1 (SLOW), 2 (FAST)");
}

void loop()
{
    // Η loop τρέχει χιλιάδες φορές το δευτερόλεπτο.
    // Κάθε συνάρτηση εδώ πρέπει να είναι γρήγορη και να μην μπλοκάρει (χωρίς delay).

    // 1. Διαχείριση Εισόδου από Κουμπί (Βλέπε μάθημα 04_Digital_IO)
    handleButton();

    // 2. Διαχείριση Εισόδου από Serial (Βλέπε μάθημα 07_Serial_Communication)
    handleSerial();

    // 3. Εκτέλεση Λογικής (Βλέπε μάθημα 05_Millis_Timing)
    runLightLogic();
}

// --- Λειτουργίες Εισόδου ---

void handleButton()
{
    int reading = digitalRead(BTN);

    // Debounce Logic (όπως στο button_toggle.ino)
    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        static int buttonState = HIGH;
        if (reading != buttonState)
        {
            buttonState = reading;

            // Δράση μόνο στο πάτημα (Falling Edge)
            if (buttonState == LOW)
            {
                changeMode(); // Αλλαγή κατάστασης συστήματος
            }
        }
    }
    lastButtonState = reading;
}

void handleSerial()
{
    // Έλεγχος αν υπάρχουν δεδομένα από τον υπολογιστή
    if (Serial.available() > 0)
    {
        char cmd = Serial.read(); // Διάβασε τον χαρακτήρα

        // Επεξεργασία εντολής
        if (cmd == '0')
        {
            currentMode = OFF;
            Serial.println("Command: OFF");
        }
        else if (cmd == '1')
        {
            currentMode = SLOW_BLINK;
            Serial.println("Command: SLOW_BLINK");
        }
        else if (cmd == '2')
        {
            currentMode = FAST_BLINK;
            Serial.println("Command: FAST_BLINK");
        }
        // Αγνοούμε άλλους χαρακτήρες (π.χ. newline)
    }
}

// --- Λογική Συστήματος ---

void changeMode()
{
    // Κυκλική αλλαγή κατάστασης: OFF -> SLOW -> FAST -> OFF
    if (currentMode == OFF)
        currentMode = SLOW_BLINK;
    else if (currentMode == SLOW_BLINK)
        currentMode = FAST_BLINK;
    else
        currentMode = OFF;

    Serial.print("Button Pressed. New Mode: ");
    // Εκτύπωση ονόματος κατάστασης για debugging
    switch (currentMode)
    {
    case OFF:
        Serial.println("OFF");
        break;
    case SLOW_BLINK:
        Serial.println("SLOW");
        break;
    case FAST_BLINK:
        Serial.println("FAST");
        break;
    }
}

void runLightLogic()
{
    // Χρησιμοποιούμε millis() αντί για delay() ώστε να μην μπλοκάρουμε τα κουμπιά
    unsigned long currentMillis = millis();
    long interval = 0;

    // Ρύθμιση συμπεριφοράς ανάλογα με την κατάσταση (State Machine)
    switch (currentMode)
    {
    case OFF:
        digitalWrite(LED, LOW);
        ledState = LOW;
        return; // Έξοδος από τη συνάρτηση, δεν χρειάζεται blink

    case SLOW_BLINK:
        interval = 1000; // 1 δευτερόλεπτο
        break;

    case FAST_BLINK:
        interval = 200; // 200 χιλιοστά
        break;
    }

    // Blink Logic (από το μάθημα 05_Millis_Timing)
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis; // Αποθήκευση χρόνου τελευταίας αλλαγής

        // Toggle LED
        if (ledState == LOW)
        {
            ledState = HIGH;
        }
        else
        {
            ledState = LOW;
        }
        digitalWrite(LED, ledState);
    }
}
