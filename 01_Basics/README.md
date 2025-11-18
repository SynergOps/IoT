# 01_Basics

## Εισαγωγή στο Arduino

Αυτός ο φάκελος περιέχει βασικά έργα για να ξεκινήσετε με έννοιες που αφορούν το Arduino και γενικά τα IoT.

### Θέματα που Καλύπτονται
- Εγκατάσταση του Arduino IDE
- Κατανόηση ψηφιακού I/O
- Βασικές έννοιες προγραμματισμού
- Παραλλαγές αναβοσβήματος LED
- Βασικά σειριακής επικοινωνίας
- Τεχνικές αποσφαλμάτωσης

---

## Γενικές Οδηγίες Υλικών και Καλωδίωσης

### Πολικότητα LED
```
     LED (Light Emitting Diode)
     
  Μακρύ πόδι (+)  │  Κοντό πόδι (-)
    Anode         │    Cathode
       │          │       │
       └──────┬───┴───────┘
              │
       Επίπεδη πλευρά (-)
```
- **Anode (+)**: Μακρύ πόδι → συνδέεται στο pin (μέσω αντίστασης)
- **Cathode (-)**: Κοντό πόδι ή επίπεδη πλευρά → συνδέεται στο GND

### Τιμές Αντιστάσεων (Χρωματικός Κώδικας)
| Τιμή | Χρώματα | Χρήση |
|------|---------|-------|
| 220Ω | Κόκκινο-Κόκκινο-Καφέ | LED (κόκκινο/πράσινο/κίτρινο) |
| 330Ω | Πορτοκαλί-Πορτοκαλί-Καφέ | LED (μπλε/λευκό) |
| 10kΩ | Καφέ-Μαύρο-Πορτοκαλί | Pull-down για κουμπιά |

### Συνήθη Λάθη
- ❌ LED αντίστροφα (δεν ανάβει ή καίγεται)
- ❌ Ξεχασμένη αντίσταση σε σειρά με LED (καίγεται το LED)
- ❌ Όχι κοινή γείωση (GND) μεταξύ συσκευών
- ❌ PWM pins: μόνο pins με ~ (D3, D5, D6, D9, D10, D11 στο Uno)
- ❌ Analog pins: A0-A5 για `analogRead()`, όχι για `analogWrite()`

### Breadboard Tips
```
Power Rails:          Internal Connections:
  +  +  +  +  +          a b c d e   f g h i j
  -  -  -  -  -         ┌─────────┬─────────┐
    (vertical)          │ 1 ●●●●● │ ●●●●● 1 │
                        │ 2 ●●●●● │ ●●●●● 2 │
                        └─────────┴─────────┘
```
- Κάθε σειρά a έως e και f έως j συνδέονται εσωτρικά, οριζόντια
- Οι κάθετες ράγες (+/-) συνδέονται εσωτρικά εσωτρικά κάθετα

---

## Έργα (Projects)

Κάθε έργο βρίσκεται σε δικό του υποφάκελο με αναλυτικό README, σχεδιάγραμμα κυκλώματος και sketch.

### 📁 [01_Blink](./01_Blink/) - Hello World
**Το πρώτο σας πρόγραμμα!** Αναβοσβήνει το ενσωματωμένο LED κάθε 500ms.
- ⚡ Δυσκολία: Αρχάριοι
- 🔧 Υλικά: Μόνο Arduino + USB
- 📚 Μαθαίνετε: `setup()`, `loop()`, `digitalWrite()`, `delay()`

### 📁 [02_Blink_SOS](./02_Blink_SOS/) - Σήμα Κινδύνου SOS
**Morse code στην πράξη!** Εκπέμπει το διεθνές σήμα κινδύνου SOS (··· ─── ···).
- ⚡ Δυσκολία: Αρχάριοι
- 🔧 Υλικά: Μόνο Arduino + USB
- 📚 Μαθαίνετε: Συναρτήσεις, patterns, sequences, επικοινωνία με φως

### 📁 [03_Blink_SOS_Serial](./03_Blink_SOS_Serial/) - SOS με Serial Debug
**Morse code + Serial Monitor!** Το ίδιο σήμα SOS αλλά με εκτύπωση στο Serial Monitor για debugging.
- ⚡ Δυσκολία: Αρχάριοι
- 🔧 Υλικά: Μόνο Arduino + USB
- 📚 Μαθαίνετε: `Serial.print()`, debugging, ταυτόχρονη έξοδος LED & Serial

### 📁 [04_Digital_IO](./04_Digital_IO/) - Κουμπί & LED
Διαβάζει κουμπί και ελέγχει LED. Εισαγωγή στο digital input/output.
- ⚡ Δυσκολία: Αρχάριοι
- 🔧 Υλικά: Arduino, κουμπί, 2× jumpers
- 📚 Μαθαίνετε: `digitalRead()`, `INPUT_PULLUP`, button logic

### 📁 [05_Millis_Timing](./05_Millis_Timing/) - Μη-αποκλειστικός Χρονισμός (Non-blocking)
Blink χωρίς `delay()` χρησιμοποιώντας `millis()`. Κλειδί για πολύπλοκα προγράμματα!
- ⚡ Δυσκολία: Μεσαίοι
- 🔧 Υλικά: Μόνο Arduino + USB
- 📚 Μαθαίνετε: `millis()`, non-blocking code, multiple timers

### 📁 [06_PWM_Fade](./06_PWM_Fade/) - Ομαλή Μεταβολή Φωτεινότητας
Fade effect με PWM. Έλεγχος φωτεινότητας LED.
- ⚡ Δυσκολία: Μεσαίοι
- 🔧 Υλικά: Arduino, LED, αντίσταση 220Ω, jumpers
- 📚 Μαθαίνετε: `analogWrite()`, PWM, for loops

### 📁 [07_Serial_Communication](./07_Serial_Communication/) - Σειριακή Επικοινωνία
Έλεγχος LED από τον υπολογιστή μέσω Serial Monitor. Debugging & διαδραστικότητα.
- ⚡ Δυσκολία: Μεσαίοι
- 🔧 Υλικά: Arduino + USB
- 📚 Μαθαίνετε: `Serial.begin()`, `Serial.read()`, debugging

---

## Σύνοψη Θεμάτων

Κάθε υποφάκελος καλύπτει ένα βασικό θέμα:

| Έργο | Βασική Έννοια | Εντολές Κλειδιά |
|------|---------------|-----------------|
| **01_Blink** | Δομή προγράμματος | `pinMode()`, `digitalWrite()`, `delay()` |
| **02_Blink_SOS** | Συναρτήσεις & Patterns | `dot()`, `dash()`, sequences |
| **03_Blink_SOS_Serial** | Serial Debug + Morse | `Serial.print()`, `dot()`, `dash()` |
| **04_Digital_IO** | Input/Output | `digitalRead()`, `INPUT_PULLUP` |
| **05_Millis_Timing** | Χρονισμός | `millis()`, non-blocking |
| **06_PWM_Fade** | Αναλογικό output | `analogWrite()`, PWM |
| **07_Serial_Communication** | Επικοινωνία | `Serial.begin()`, `Serial.read()` |

---

## Πως να ξεκινήσετε (Quick Start)

### 1. Εγκατάσταση Arduino IDE
1. Κατεβάστε από [arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Εγκαταστήστε για το λειτουργικό σας σύστημα
3. Συνδέστε το Arduino με USB
4. **Tools → Board** → επιλέξτε το board σας (π.χ. Arduino Uno)
5. **Tools → Port** → επιλέξτε τη σειριακή θύρα (π.χ. COM3)

### 2. Δοκιμαστικό Upload
- Kάντε `git clone` ή κατεβάστε το repository `Ιοt`
- Ανοίξτε το **01_Blink**
- Στο Arduino IDE κάντε επικόλληση τον κώδικα του `blink.ino`
- Πατήστε το κουμπί **Upload** (→)
- Το LED του arduino 13 θα αρχίσει να αναβοσβήνει! ✅

### 3. Συνήθη Προβλήματα

| Πρόβλημα | Λύση |
|----------|------|
| "Port not found" | Εγκαταστήστε drivers (CH340/CP2102 για κλώνους) |
| Upload error | Πατήστε Reset πριν το upload, κλείστε Serial Monitor |
| LED δεν ανάβει | Ελέγξτε board/port selection |

---

## Τεχνικές Αποσφαλμάτωσης

### IDE & Σύνδεση
- ✅ Ελέγξτε: Board selection, Port, USB καλώδιο δεδομένων
- ⚠️ Κλώνοι: Μπορεί να χρειάζονται [CH340 drivers](http://www.wch.cn/downloads/CH341SER_ZIP.html)
- 🔧 Reset button: Πατήστε πριν upload σε ορισμένους κλώνους

### Καλωδίωση
- 🔴 LED πολικότητα: Μακρύ πόδι (+) → pin, Κοντό (-) → GND
- ⚡ Πάντα αντίσταση 220Ω-330Ω σε σειρά με LED
- 🔌 Κοινή γείωση (GND) μεταξύ όλων των συσκευών

### Serial Debug
```cpp
Serial.begin(9600);
Serial.print("Sensor value: ");
Serial.println(analogRead(A0));
```
- Χρησιμοποιείστε Serial Monitor για debugging
- Ξεκινήστε απλά, προσθέστε σταδιακά

### Κουμπιά
- Χρησιμοποιήστε `INPUT_PULLUP` (όχι εξωτερική αντίσταση)
- Λογική: Πατημένο = LOW, Αφημένο = HIGH
- Debouncing: `delay(50)` ή capacitor 0.1µF

---

## Σημαντικές Σημειώσεις

### Analog vs Digital
```cpp
analogRead(A0);      // Input: A0-A5 → 0-1023
analogWrite(9, 128); // Output (PWM): D3,5,6,9,10,11 → 0-255
```
⚠️ Το `analogWrite()` είναι **PWM**, όχι πραγματικό αναλογικό!

### PWM Pins (Uno)
Μόνο τα pins με **~** υποστηρίζουν PWM:
- ✅ D3, D5, D6, D9, D10, D11
- ❌ Όχι στα A0-A5 ή άλλα digital pins

### Μνήμη
- Arduino Uno: **2KB RAM**, **32KB Flash**
- Προσοχή με `String` objects (καταναλώνουν RAM)
- Προτίμηση: `char[]` arrays για production code

---

## Μαθησιακοί Στόχοι

Μετά την ολοκλήρωση αυτού του module, θα μπορείτε να:

✅ **Εγκατάσταση & Ρύθμιση**
- Εγκαταστήσετε και ρυθμίσετε το Arduino IDE
- Συνδέσετε και διαμορφώσετε πλακέτες Arduino
- Ανεβάσετε sketches και αντιμετωπίσετε βασικά προβλήματα

✅ **Προγραμματισμός**
- Κατανοήσετε τη δομή ενός Arduino sketch (`setup()`, `loop()`)
- Χρησιμοποιήσετε μεταβλητές, βρόχους και συνθήκες
- Γράψετε μη-αποκλειστικό κώδικα με `millis()`

✅ **Hardware I/O**
- Ελέγξετε digital pins (HIGH/LOW)
- Διαβάσετε είσοδο από κουμπιά και sensors
- Χρησιμοποιήσετε PWM για έλεγχο φωτεινότητας
- Συνδέσετε σωστά LEDs με αντιστάσεις

✅ **Debugging & Επικοινωνία**
- Χρησιμοποιήσετε Serial Monitor για debugging
- Στείλετε και λάβετε δεδομένα μέσω σειριακής
- Αποσφαλματώσετε προγράμματα αποτελεσματικά

---

## Προαπαιτούμενα

- 💻 Βασικές γνώσεις υπολογιστών
- 🔌 Καμία εμπειρία με ηλεκτρονικά απαιτείται!
- 🧠 Διάθεση για μάθηση και πειραματισμό

---

## Υλικά που Χρειάζονται

### Βασικό Kit (για όλα τα έργα):
- 1× Arduino Uno (ή συμβατό clone)
- 1× Καλώδιο USB (τύπου A-B για Uno)
- 1× Breadboard (400 ή 830 σημείων)
- Jumper wires (αρσενικό-αρσενικό, ~20 τεμάχια)

### Εξαρτήματα:
- 3× LEDs (κόκκινο, πράσινο, κίτρινο)
- 5× Αντιστάσεις 220Ω (για LEDs)
- 2× Αντιστάσεις 10kΩ (για κουμπιά - προαιρετικά με INPUT_PULLUP)
- 2× Push buttons (tactile switches)

**Προτεινόμενα starter kits:**
- Elegoo UNO Project Super Starter Kit
- Arduino Starter Kit (επίσημο)
- Οποιοδήποτε Arduino-compatible kit με τα παραπάνω

---

## Πώς να Χρησιμοποιήσετε αυτό το Module

### 📖 Μέθοδος Μάθησης
1. **Διαβάστε** το README κάθε έργου
2. **Κατασκευάστε** το κύκλωμα σύμφωνα με το σχεδιάγραμμα
3. **Ανεβάστε** το sketch στο Arduino
4. **Πειραματιστείτε** αλλάζοντας παραμέτρους
5. **Επεκτείνετε** με τις προτάσεις "Πειραματισμός"

### 🔢 Προτεινόμενη Σειρά
Ακολουθήστε τα έργα με τη σειρά:
```
01_Blink → 02_Blink_SOS → 03_Blink_SOS_Serial → 04_Digital_IO → 05_Millis_Timing → 06_PWM_Fade → 07_Serial_Communication
```

Κάθε έργο χτίζει πάνω στις έννοιες του προηγούμενου.

### ⏱️ Εκτιμώμενος Χρόνος
- Κάθε έργο: 30-60 λεπτά
- Συνολικό module: 4-6 ώρες
- Με πειραματισμό: 7-12 ώρες

---

## Επόμενα Βήματα

Αφού ολοκληρώσετε το **01_Basics**, προχωρήστε σε:

📂 **[02_Input](../02_Input/)** - Αισθητήρες & Είσοδος
- Potentiometers, photoresistors, temperature sensors
- Analog input, calibration, smoothing

📂 **[03_Output](../03_Output/)** - Ενεργοποιητές & Έξοδος
- Servos, motors, buzzers, relays
- Motor control, sound generation

📂 **[04_Sensors](../04_Sensors/)** - Προχωρημένοι Αισθητήρες
- Ultrasonic, PIR, DHT22, accelerometers
- Sensor fusion, data logging

---

## Πόροι & Βοήθεια

### 📚 Επίσημη Τεκμηρίωση
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Arduino Tutorials](https://www.arduino.cc/en/Tutorial/HomePage)
- [Arduino Forum](https://forum.arduino.cc/)

### 🎓 Εκπαιδευτικό Υλικό
- [Arduino Getting Started Guide](https://www.arduino.cc/en/Guide)
- [Adafruit Learn Arduino](https://learn.adafruit.com/series/learn-arduino)
- [SparkFun Arduino Tutorials](https://learn.sparkfun.com/tutorials)

### 🛠️ Tools & Simulators
- [Tinkercad Circuits](https://www.tinkercad.com/circuits) - Online simulator
- [Fritzing](https://fritzing.org/) - Σχεδίαση κυκλωμάτων
- [Wokwi](https://wokwi.com/) - Arduino simulator

---

## Συμβολή

Βρήκατε λάθος; Έχετε πρόταση; Ανοίξτε ένα issue ή pull request!

**Καλή επιτυχία με το Arduino! 🚀**
