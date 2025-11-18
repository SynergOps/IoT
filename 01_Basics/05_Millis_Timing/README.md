# 05_Millis_Timing - Μη-αποκλειστικός Χρονισμός

## Περιγραφή
Αναβοσβήνει το LED χωρίς `delay()`, χρησιμοποιώντας `millis()`. Αυτό επιτρέπει στο Arduino να εκτελεί άλλες εργασίες ταυτόχρονα.

## Μαθησιακοί Στόχοι
- Κατανόηση της `millis()` για χρονισμό
- Μη-αποκλειστικός προγραμματισμός (non-blocking code)
- Διαχείριση πολλαπλών χρονιστών ταυτόχρονα
- Αποφυγή προβλημάτων του `delay()`

## Σχεδιάγραμμα Κυκλώματος

```
┌─────────────────┐
│   Arduino Uno   │
│                 │
│  D13 (Built-in) ├──► LED εσωτερικό (χρήση millis)
│                 │
│      GND        │
└─────────────────┘
```

## Υλικά που Χρειάζονται
- 1× Arduino Uno
- 1× Καλώδιο USB

**Ίδια καλωδίωση με το Blink, αλλά διαφορετική λογική!**

## Γιατί Millis(); Τα Προβλήματα του delay()

### ❌ Με delay():
```cpp
digitalWrite(LED, HIGH);
delay(500);  // ⚠️ Μπλοκάρει όλο το πρόγραμμα για 500ms
digitalWrite(LED, LOW);
delay(500);  // ⚠️ Δεν μπορεί να κάνει τίποτα άλλο
```

### ✅ Με millis():
```cpp
if (millis() - lastTime >= 500) {
  // Εκτέλεση μόνο όταν περάσουν 500ms
  // Στο ενδιάμεσο, ο κώδικας τρέχει ελεύθερα!
}
```

## Πώς να το Τρέξετε

1. Ανοίξτε το `millis_blink.ino`
2. Ανεβάστε στο Arduino
3. Το LED αναβοσβήνει όπως το Blink, αλλά το πρόγραμμα δεν "παγώνει"

## Επεξήγηση Κώδικα

```cpp
const unsigned long period = 500;  // Περίοδος σε ms
unsigned long last = 0;            // Τελευταία αλλαγή
bool state = false;                // Κατάσταση LED

void loop(){
  unsigned long now = millis();    // Τρέχων χρόνος
  
  if (now - last >= period) {      // Πέρασαν 500ms;
    last = now;                    // Ενημέρωση χρόνου
    state = !state;                // Αντιστροφή κατάστασης
    digitalWrite(LED, state ? HIGH : LOW);
  }
  
  // ✅ Εδώ μπορείτε να κάνετε άλλες εργασίες!
}
```

### Βασικές Έννοιες:
- **millis()**: Επιστρέφει χρόνο σε ms από την εκκίνηση
- **unsigned long**: Τύπος για μεγάλους αριθμούς (μέχρι ~49 ημέρες)
- **Έλεγχος διαφοράς**: `now - last >= period` αποφεύγει rollover issues

## Σύγκριση delay() vs millis()

| Χαρακτηριστικό | delay() | millis() |
|----------------|---------|----------|
| Μπλοκάρει πρόγραμμα | ✅ Ναι | ❌ Όχι |
| Πολλαπλά timers | ❌ Δύσκολο | ✅ Εύκολο |
| Responsive input | ❌ Όχι | ✅ Ναι |
| Απλότητα κώδικα | ✅ Πολύ | ⚠️ Μέτρια |

## Πειραματισμός

### 1. Πολλαπλά LEDs με διαφορετικούς ρυθμούς:
```cpp
unsigned long last1 = 0, last2 = 0;
const int LED1 = 13, LED2 = 12;

void loop() {
  if (millis() - last1 >= 500) {
    last1 = millis();
    digitalWrite(LED1, !digitalRead(LED1));
  }
  
  if (millis() - last2 >= 300) {
    last2 = millis();
    digitalWrite(LED2, !digitalRead(LED2));
  }
}
```

### 2. Συνδυασμός με κουμπί (από 04_Digital_IO):
```cpp
// Blink με millis() + άμεση ανταπόκριση σε κουμπί
```

### 3. Fade effect με millis():
Χρήση `analogWrite()` σε συνδυασμό με millis-based timing

## Προσοχή: Rollover του millis()

Το `millis()` επιστρέφει στο 0 μετά από ~49 ημέρες. Η μέθοδος `now - last` λειτουργεί σωστά ακόμα και στο rollover:

```cpp
// ✅ Σωστό (λειτουργεί με rollover)
if (millis() - lastTime >= interval)

// ❌ Λάθος (πρόβλημα στο rollover)
if (millis() >= lastTime + interval)
```

## Επόμενο Βήμα
Δείτε **06_PWM_Fade** για αναλογικό έλεγχο φωτεινότητας με PWM.
