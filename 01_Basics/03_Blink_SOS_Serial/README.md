# 03_Blink_SOS_Serial - SOS με Serial Debug

## Περιγραφή
Αυτή η παραλλαγή του SOS Morse (··· --- ···) επεκτείνει το προηγούμενο έργο προσθέτοντας **σειριακή έξοδο** ώστε να παρακολουθούμε τι στέλνεται σε πραγματικό χρόνο στο Serial Monitor.

## Πού χρησιμοποιείται σε υλοποίηση IoT;
*   **Debugging & Logs:** Κατά την ανάπτυξη IoT συσκευών, η σειριακή θύρα είναι ο βασικός τρόπος για να βλέπουμε τι συμβαίνει "μέσα στο μυαλό" του επεξεργαστή.
*   **Επικοινωνία Gateway:** Πολλά IoT nodes στέλνουν δεδομένα σε ένα Gateway (π.χ. Raspberry Pi) μέσω USB/Serial για να προωθηθούν στο Cloud.
*   **Ρύθμιση Modules:** Η ρύθμιση παραμέτρων σε modules επικοινωνίας (π.χ. Wi-Fi, LoRaWAN, GSM) γίνεται συχνά με εντολές AT μέσω σειριακής θύρας.

## Στόχοι Μάθησης
- Χρήση `Serial.begin()`, `Serial.print()/println()` για debugging
- Δημιουργία επαναχρησιμοποιήσιμων συναρτήσεων (`dot()`, `dash()`, `flash()`)
- Σύνθεση σύνθετου μοτίβου εξόδου (LED + Text)
- Ανάγνωση χρονισμών Morse & δομημένη καταγραφή

## Κύριες Έννοιες
| Έννοια | Περιγραφή |
|--------|-----------|
| Morse Pattern | Οπτική + κειμενική αναπαράσταση SOS |
| Serial Monitor | Παρακολούθηση κύκλων και στοιχείων μοτίβου |
| Δομημένες Συναρτήσεις | `dot()`, `dash()`, κοινή `flash()` |
| Χρονισμός | DOT, DASH, SPACES για ακρίβεια μοτίβου |

## Υλικά
- Arduino Uno (ή συμβατό)
- Καλώδιο USB
- (Δεν απαιτούνται εξωτερικά εξαρτήματα)

## Σχεδιάγραμμα
```
┌─────────────────┐      Serial Output:
│   Arduino Uno   │      S:... O:--- S:... | Cycle complete
│                 │      Επαναλαμβάνεται ανά WORD_SPACE
│  D13 (Built-in) ├──► LED MORSE SOS
│      GND        │
└─────────────────┘
```

## Κώδικας (βασική δομή)
```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("S:"); dot(); dot(); dot();  // S
  delay(LETTER_SPACE);
  Serial.print(" O:"); dash(); dash(); dash(); // O
  delay(LETTER_SPACE);
  Serial.print(" S:"); dot(); dot(); dot();   // S
  Serial.println(" | Cycle complete");
  delay(WORD_SPACE);
}
```

## Παρατηρούμε στο Serial Monitor
Παράδειγμα εξόδου:
```
[START] SOS Morse Transmitter
S:... O:--- S:...  | Cycle complete
S:... O:--- S:...  | Cycle complete
...
```

## Βελτιώσεις έναντι 02_Blink_SOS
| Χαρακτηριστικό | 02_Blink_SOS | 03_Blink_SOS_Serial |
|----------------|--------------|---------------------|
| Ορατότητα μοτίβου | Μόνο LED | LED + Text |
| Debugging | Περιορισμένο | Αναλυτικό Serial log |
| Εντοπισμός σφαλμάτων | Δύσκολος | Εμφανής στο Monitor |
| Επεκτασιμότητα | Μέτρια | Υψηλή (εύκολη προσθήκη parsing) |

## Πειραματισμοί
1. Αλλάξτε το `DOT_DURATION` (π.χ. 150ms ή 300ms) και δείτε την επίδραση.
2. Προσθέστε μετρητή κύκλων:
```cpp
static unsigned long cycles = 0;
cycles++;
Serial.print(" | Cycle: "); Serial.println(cycles);
```
3. Στείλτε διαφορετικό μήνυμα μετά από 5 κύκλους (π.χ. "HELP")
4. Προσθέστε time-stamp:
```cpp
Serial.print("[ms="); Serial.print(millis()); Serial.print("] ");
```
5. Καταγράψτε σε CSV format για ανάλυση:
```cpp
Serial.print(cycle); Serial.print(','); Serial.println(millis());
```

## Προχωρημένο: Δυναμικό Μήνυμα
Μπορείτε να δημιουργήσετε συνάρτηση `sendMessage("SOS TEST")` (δείτε bonus στο προηγούμενο README) και να εμφανίζετε κάθε γράμμα με header:
```cpp
Serial.print("Letter S: "); dot(); dot(); dot();
```

## Troubleshooting
| Πρόβλημα | Λύση |
|----------|------|
| Χαοτική έξοδος | Ελέγξτε σωστό baud (9600) |
| Δεν εμφανίζεται τίποτα | `Serial.begin(9600)` ξεχάστηκε ή λάθος port |
| Μη ευδιάκριτες παύλες | Αυξήστε `DASH_DURATION` ή μειώστε `SYMBOL_SPACE` |
| Πολύ γρήγορο | Αυξήστε DOT/DASH τιμές αναλογικά |

## Επόμενο Βήμα
Προχωρήστε στο **04_Digital_IO** (κουμπί & LED) για εισαγωγή σε input.

---
**Καλή συνέχεια! ··· --- ··· με Serial ορατότητα.**
