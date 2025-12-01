# 04_Blink_Counter_Serial - Μετρητής Αναβοσβησιών με Serial

## Περιγραφή
Επέκταση του απλού blink: το LED αναβοσβήνει και ταυτόχρονα το πρόγραμμα **μετράει** πόσες φορές έχει αναβοσβήσει, εμφανίζοντας τον αριθμό στο Serial Monitor.

## Πού χρησιμοποιείται σε υλοποίηση IoT;
*   **Διάγνωση Σφαλμάτων:** Μέτρηση κύκλων και γεγονότων για να ανιχνεύσουμε προβλήματα (π.χ., "το LED έχει αναβοσβήσει 1000 φορές χωρίς να έχει κάνει τίποτα άλλο").
*   **Uptime Tracking:** Καταγραφή του πόσο καιρό τρέχει η συσκευή μέσω μέτρησης κύκλων.
*   **Event Logging:** Καταγραφή συμβάντων ή σφαλμάτων σε αριθμητική μορφή για ανάλυση.

## Στόχοι Μάθησης
- Κατανόηση `static` μεταβλητών
- Δημιουργία απλών μετρητών
- Συνδυασμός Serial output με φυσικές ενέργειες
- Δομημένη καταγραφή δεδομένων στο Serial Monitor

## Νέες Έννοιες

### `const` μεταβλητή
Μια μεταβλητή που **δεν μπορεί να αλλάξει** αφού οριστεί. Χρήσιμη για τιμές που είναι σταθερές (όπως ο αριθμός pin, ο baud rate κ.λπ.).

```cpp
const int ledPin = 13;  // ✅ Σωστό - το ledPin δεν θα αλλάξει ποτέ
ledPin = 12;            // ❌ ΣΦΑΛΜΑ - δεν μπορείς να αλλάξεις const!
```

**Γιατί χρησιμοποιούμε `const`:**
- ✅ **Ασφάλεια**: Προστατεύει από τυχαία αλλαγή της τιμής
- ✅ **Αναγνωσιμότητα**: Καθιστά σαφές ότι αυτή η τιμή δεν αλλάζει
- ✅ **Μνήμη**: Ο compiler μπορεί να βελτιστοποιήσει καλύτερα
- ✅ **Σφάλματα**: Θα πάρεις σφάλμα compilation αν προσπαθήσεις να αλλάξεις

### `static` μεταβλητή
Μια μεταβλητή που αρχικοποιείται **μόνο την πρώτη φορά** που εκτελείται ο κώδικας, αλλά **διατηρεί την τιμή της** μεταξύ των επαναλήψεων του `loop()`. Χρήσιμη για μετρητές και καταστάσεις.

```cpp
static int counter = 0;  // Ο counter ξεκινά από 0 μόνο την πρώτη φορά
counter++;               // Αυξάνεται σε κάθε loop (διατηρεί τη τιμή)
```

**Γιατί χρησιμοποιούμε `static`:**
- ✅ **Μετρητές**: Μετράμε events που συμβαίνουν επαναλαμβανόμενα
- ✅ **Διατήρηση Κατάστασης**: Θυμάται την τιμή μεταξύ κύκλων
- ✅ **Τοπικό Scope**: Δεν είναι global (ασφαλέστερο)
- ✅ **Αποτελεσματικότητα**: Δεν επανακατανέμεται μνήμη κάθε κύκλο

### Σύγκριση: `const` vs `static`

| Ιδιότητα | `const` | `static` |
|----------|---------|----------|
| **Αλλαγή τιμής** | ❌ Δεν αλλάζει ποτέ | ✅ Αλλάζει αλλά διατηρείται |
| **Αρχικοποίηση** | Κάθε φορά | Μόνο την πρώτη |
| **Scope** | Κανονικό | Τοπικό ή global |
| **Χρήση** | Σταθερές | Μετρητές, καταστάσεις |
| **Παράδειγμα** | Αριθμός pin, baud rate | Μετρητής flashes |

- **`Μετρητές`**: Χρησιμοποιούμε `static` μεταβλητές για να μετρήσουμε συμβάντα
- **`Serial Output`**: Στέλνουμε τα αποτελέσματα του μετρητή στο Serial Monitor

## Κύριες Έννοιες
| Έννοια | Περιγραφή |
|--------|-----------|
| Static Μεταβλητή | Τιμή που διατηρείται μεταξύ κύκλων loop |
| Μετρητής | Ακέραιος που αυξάνεται σε κάθε συμβάν |
| Serial Logging | Καταγραφή τιμών στο Serial Monitor |
| Event Tracking | Παρακολούθηση συμβάντων με αριθμούς |

## Υλικά
- Arduino Uno (ή συμβατό)
- Καλώδιο USB
- (Δεν απαιτούνται εξωτερικά εξαρτήματα)

## Σχεδιάγραμμα
```
┌─────────────────┐      Serial Output:
│   Arduino Uno   │      The LED flashed: 1 times.
│                 │      The LED flashed: 2 times.
│  D13 (Built-in) ├──► LED αναβοσβήνει     The LED flashed: 3 times.
│      GND        │      ...
└─────────────────┘
```

## Πώς να το Τρέξετε

1. Ανοίξτε το `blink_counter_serial.ino`
2. Ανεβάστε στο Arduino
3. Ανοίξτε το Serial Monitor (Tools → Serial Monitor)
4. Ρυθμίστε baud rate στα **9600**
5. Παρακολουθήστε τον μετρητή να αυξάνεται!

## Επεξήγηση Κώδικα

```cpp
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Arduino Starting Up...");
}

void loop() {
  // === STATIC ΜΕΤΑΒΛΗΤΗ ===
  static int flashCount = 0;
  // Η πρώτη φορά: flashCount = 0
  // Κάθε άλλη φορά: διατηρεί την προηγούμενη τιμή
  
  flashCount++;  // Αύξηση του μετρητή
  
  // Blink κώδικας
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  
  // Serial output με τον μετρητή
  Serial.print("The LED flashed: ");
  Serial.print(flashCount);
  Serial.println(" times.");
}
```

### Πώς λειτουργεί το `static`:

```
Κύκλος 1:
├─ static int flashCount = 0;  (αρχικοποίηση - συμβαίνει ΜΟΝΟ εδώ)
├─ flashCount++ → flashCount = 1
└─ Serial output: "The LED flashed: 1 times."

Κύκλος 2:
├─ static int flashCount = 0;  (παραλείπεται - ήδη αρχικοποιήθηκε)
├─ flashCount++ → flashCount = 2  (διατήρησε την τιμή από τον προηγούμενο κύκλο!)
└─ Serial output: "The LED flashed: 2 times."

Κύκλος 3:
├─ flashCount++ → flashCount = 3
└─ Serial output: "The LED flashed: 3 times."

... συνεχίζεται άπειρα
```

## Παρατηρούμε στο Serial Monitor

```
Arduino Starting Up...
The LED flashed: 1 times.
The LED flashed: 2 times.
The LED flashed: 3 times.
The LED flashed: 4 times.
The LED flashed: 5 times.
...
```

## Σύγκριση: Τοπική vs Static Μεταβλητή

| Τύπος | Κώδικας | Συμπεριφορά |
|-------|--------|------------|
| **Τοπική** | `int counter = 0;` στο loop | ❌ Ξαναγίνεται 0 σε κάθε κύκλο |
| **Static** | `static int counter = 0;` στο loop | ✅ Διατηρεί την τιμή |

### Με τοπική (ΛΑΘΟΣ):
```cpp
void loop() {
  int counter = 0;  // ❌ Ξαναγίνεται 0 κάθε φορά!
  counter++;
  Serial.println(counter);  // Πάντα εκτυπώνει: 1
}
```

### Με static (ΣΩΣΤΟ):
```cpp
void loop() {
  static int counter = 0;  // ✅ Διατηρείται
  counter++;
  Serial.println(counter);  // Εκτυπώνει: 1, 2, 3, 4, ...
}
```

## Troubleshooting

| Πρόβλημα | Λύση |
|----------|------|
| Δεν εμφανίζεται τίποτα | Ελέγξτε baud rate (9600), port |
| Μετρητής ξαναρχίζει από 1 | Πιθανώς έχετε βάλει τη μεταβλητή χωρίς `static` |
| Μετρητής δεν αυξάνεται | Ελέγξτε `flashCount++` και `Serial.println()` |

## Πειραματισμός

### 1. Διαφορετικό μήνυμα ανά κύκλο:
```cpp
Serial.print("Flash #");
Serial.print(flashCount);
Serial.print(" - LED: ");
Serial.println(digitalRead(ledPin) ? "ON" : "OFF");
```

### 2. Reset του μετρητή:
```cpp
if (flashCount >= 100) {
  flashCount = 0;  // Ξαναρχίζει από 0 μετά τα 100 αναβοσβήματα
  Serial.println("Counter reset!");
}
```

### 3. Δεδομένα σε μορφή CSV (για Excel):
```cpp
Serial.print(flashCount);
Serial.print(",");
Serial.println(millis());  // Χρόνος σε ms
```

## Σημαντικές Σημειώσεις

### Static vs Global
```cpp
// ❌ Global - ορατή παντού (κακή πρακτική)
int globalCounter = 0;

// ✅ Static local - ορατή μόνο στο loop (καλή πρακτική)
void loop() {
  static int localCounter = 0;
  // ...
}
```

### Υπερχείλιση Μετρητή
```cpp
// Ο int πηγαίνει ως το 2,147,483,647
// Μετά γίνεται αρνητικός! Χρησιμοποιήστε unsigned long αν χρειάζεστε μεγαλύτερες τιμές
static unsigned long largeCounter = 0;
```

## Επόμενο Βήμα
Προχωρήστε στο **05_Digital_IO** για να μάθετε πώς να διαβάζετε είσοδο (κουμπιά) και να συνδυάζετε input με output.
