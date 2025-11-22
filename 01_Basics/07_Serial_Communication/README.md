# 07_Serial_Communication - Σειριακή Επικοινωνία

## Περιγραφή
Χρησιμοποιεί το Serial Monitor για να στέλνει και να λαμβάνει δεδομένα μεταξύ Arduino και υπολογιστή. Ελέγχει το LED στέλνοντας '1' (ON) ή '0' (OFF).

## Πού χρησιμοποιείται σε υλοποίηση IoT;
*   **GPS Tracking:** Οι trackers οχημάτων λαμβάνουν συντεταγμένες από το GPS module μέσω σειριακής θύρας (NMEA protocol).
*   **Βιομηχανικό IoT (IIoT):** Πολλά βιομηχανικά αισθητήρια χρησιμοποιούν πρωτόκολλα όπως το Modbus RTU πάνω από σειριακή σύνδεση (RS-485).
*   **GSM/LTE Modems:** Η σύνδεση στο ίντερνετ μέσω δικτύου κινητής τηλεφωνίας γίνεται στέλνοντας εντολές στο modem μέσω Serial.

## Μαθησιακοί Στόχοι
- Κατανόηση σειριακής επικοινωνίας (UART)
- Χρήση `Serial.begin()`, `Serial.print()`, `Serial.read()`
- Debugging με Serial Monitor
- Διαδραστικός έλεγχος του Arduino από τον υπολογιστή

## Σχεδιάγραμμα Κυκλώματος

```
┌─────────────────┐         ╔═══════════════╗
│   Arduino Uno   │  USB    ║   Computer    ║
│                 ├─────────║               ║
│  D13 (Built-in) ├──► LED  ║  Serial       ║
│                 │         ║  Monitor      ║
│      GND        │         ║  (9600 baud)  ║
└─────────────────┘         ╚═══════════════╝
```

## Υλικά που Χρειάζονται
- 1× Arduino Uno
- 1× Καλώδιο USB (για σειριακή επικοινωνία και τροφοδοσία)

**Το USB καλώδιο χρησιμεύει για δύο σκοπούς:**
1. Τροφοδοσία (5V)
2. Σειριακή επικοινωνία (RX/TX)

## Τι είναι η Σειριακή Επικοινωνία;

**Serial (UART)** = Universal Asynchronous Receiver-Transmitter

```
Arduino        USB         Computer
  TX  ─────────────────►   RX  (Transmit)
  RX  ◄─────────────────   TX  (Receive)
 GND  ◄────────────────►  GND  (Κοινή γείωση)
```

**Baud Rate:** Ταχύτητα μετάδοσης (bits/second)
- Συνηθισμένες τιμές: 9600, 19200, 57600, 115200
- Πρέπει να ταιριάζει και στα δύο άκρα!

## Οδηγίες Χρήσης

### Βήμα προς Βήμα:
1. Συνδέστε το Arduino με USB
2. Ανεβάστε το `serial_led.ino`
3. Ανοίξτε το Serial Monitor:
   - **Tools → Serial Monitor** ή
   - **Ctrl+Shift+M** (Windows/Linux) / **Cmd+Shift+M** (Mac)
4. Ρυθμίστε baud rate στα **9600** (κάτω δεξιά)
5. Στείλτε `1` για να ανάψει το LED
6. Στείλτε `0` για να σβήσει το LED

## Επεξήγηση Κώδικα

Το σημαντικό κομμάτι είναι πώς διαβάζουμε και αντιδρούμε στις εντολές:

```cpp
if (Serial.available()) {        // 1. Υπάρχουν δεδομένα στη σειρά;
  char c = Serial.read();        // 2. Διάβασε τον επόμενο χαρακτήρα
  
  if (c == '1') {                // 3. Αν είναι '1', άναψε το LED
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED ON");
  }
  
  if (c == '0') {                // 4. Αν είναι '0', σβήσε το LED
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED OFF");
  }
}
```

### Βασικές Εντολές:

| Εντολή | Λειτουργία |
|--------|------------|
| `Serial.begin(baud)` | Εκκίνηση σειριακής με baud rate |
| `Serial.available()` | Επιστρέφει αριθμό διαθέσιμων bytes |
| `Serial.read()` | Διαβάζει 1 byte (χαρακτήρας) |
| `Serial.print(data)` | Στέλνει δεδομένα χωρίς newline |
| `Serial.println(data)` | Στέλνει δεδομένα με newline |

## Debugging με Serial Monitor

### Εκτύπωση Μεταβλητών:
```cpp
int sensorValue = analogRead(A0);
Serial.print("Sensor: ");
Serial.println(sensorValue);
// Output: "Sensor: 512"
```

### Formatted Output:
```cpp
Serial.print("Temperature: ");
Serial.print(temp, 2);  // 2 δεκαδικά ψηφία
Serial.println(" °C");
// Output: "Temperature: 23.45 °C"
```

### Πολλαπλές Τιμές (CSV):
```cpp
Serial.print(time);
Serial.print(",");
Serial.print(value1);
Serial.print(",");
Serial.println(value2);
// Output: "1234,512,768" (εύκολο για Excel/plotter)
```

## Πειραματισμός

### 1. Πολλαπλές Εντολές:
```cpp
if (c == '1') digitalWrite(LED_BUILTIN, HIGH);
if (c == '0') digitalWrite(LED_BUILTIN, LOW);
if (c == 't') digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle
if (c == '?') Serial.println("Commands: 1=ON, 0=OFF, t=Toggle");
```

### 2. Διάβασμα Αριθμών:
```cpp
if (Serial.available()) {
  int number = Serial.parseInt();  // Διαβάζει ακέραιο
  Serial.print("You sent: ");
  Serial.println(number);
}
```

### 3. Διάβασμα Strings:
```cpp
if (Serial.available()) {
  String command = Serial.readStringUntil('\n');
  
  if (command == "ON") {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (command == "OFF") {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
```

### 4. Serial Plotter:
```cpp
// Tools → Serial Plotter για γραφικές
void loop() {
  int value = analogRead(A0);
  Serial.println(value);  // Εμφανίζεται ως γράφημα
  delay(10);
}
```

## Troubleshooting

| Πρόβλημα | Λύση |
|----------|------|
| Gibberish characters | Λάθος baud rate - ρυθμίστε 9600 |
| "Port already in use" | Κλείστε Serial Monitor πριν upload |
| Δεν βλέπω output | Ελέγξτε: σωστό port, baud rate, `Serial.begin()` |
| LED δεν αλλάζει | Στείλτε '1' ή '0' (με apostrophes στον κώδικα) |

## Προχωρημένες Τεχνικές

### Parsing Εντολών με Παραμέτρους:
```cpp
// Στείλτε: "PWM:128" για να ρυθμίσετε φωτεινότητα
if (Serial.available()) {
  String cmd = Serial.readStringUntil(':');
  int value = Serial.parseInt();
  
  if (cmd == "PWM") {
    analogWrite(9, value);
    Serial.print("PWM set to ");
    Serial.println(value);
  }
}
```

### Timeout Protection:
```cpp
// Προστασία από κολλημένο Serial.read()
Serial.setTimeout(100);  // 100ms timeout
String input = Serial.readStringUntil('\n');
```

### Non-blocking Serial Read:
```cpp
// Διάβασε μόνο αν υπάρχουν δεδομένα (δεν περιμένει)
void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    // Process command
  }
  
  // Άλλες εργασίες τρέχουν παράλληλα
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(500);
}
```

## Σημαντικές Σημειώσεις

### Μνήμη & Strings:
- Το Arduino Uno έχει **2KB RAM**
- Οι `String` καταναλώνουν πολλή μνήμη
- Για production code, προτιμήστε `char[]` arrays

### Buffer Overflow:
```cpp
// Προστασία από υπερχείλιση buffer
const int MAX_CMD_LEN = 32;
char buffer[MAX_CMD_LEN];
int idx = 0;

if (Serial.available() && idx < MAX_CMD_LEN - 1) {
  buffer[idx++] = Serial.read();
}
```

### Πολύ Output = Αργό Πρόγραμμα:
```cpp
// ❌ Αποφύγετε excessive prints στο loop()
void loop() {
  Serial.println(analogRead(A0));  // 9600 baud = αργό!
  // Προσθέστε delay ή throttle
}
```

## Επόμενα Βήματα

Τώρα που γνωρίζετε τα βασικά, μπορείτε να προχωρήσετε σε:
- **02_Input:** Αισθητήρες (potentiometer, photoresistor, κτλ)
- **03_Output:** Servos, motors, buzzers
- **06_Communication:** I2C, SPI, Bluetooth, WiFi

**Συγχαρητήρια!** Ολοκληρώσατε τα 01_Basics! 🎉
