
# Οδηγός: Διασύνδεση Arduino UNO με Arduino IoT Cloud (μέσω Raspberry Pi Gateway)

## 1. Εισαγωγή και Θεωρία

Στόχος αυτού του έργου είναι η αποστολή δεδομένων από ένα **Arduino UNO** (που δεν διαθέτει WiFi) στο **Arduino IoT Cloud**, χρησιμοποιώντας ένα **Raspberry Pi** ως ενδιάμεση "γέφυρα" (Gateway).

### Πώς λειτουργεί το Arduino IoT Cloud;

Για να κατανοήσουμε τη διαδικασία, πρέπει να γνωρίζουμε τις βασικές έννοιες της πλατφόρμας Arduino IoT Cloud:

* **Device (Συσκευή):** Είναι το φυσικό hardware που συνδέεται στο διαδίκτυο. Στην περίπτωσή μας, η "Συσκευή" για το Cloud είναι το **Raspberry Pi** (Linux Device), καθώς αυτό έχει τη σύνδεση στο Internet. Το Arduino UNO λειτουργεί απλώς ως αισθητήρας.
* **Thing (Αντικείμενο/Ψηφιακό Δίδυμο):** Είναι η λογική οντότητα στο Cloud. Εδώ ορίζουμε ποιες μεταβλητές θα διαχειρίζεται η συσκευή μας. Κάθε "Thing" συνδέεται με μία "Device".
* **Variables (Μεταβλητές):** Τα κανάλια επικοινωνίας. Όταν το Arduino στέλνει μια θερμοκρασία, αυτή αποθηκεύεται σε μια Variable στο Cloud. *Update Policy:* Ορίζουμε πότε θα ανανεώνεται (π.χ. "On Change" = μόνο όταν αλλάξει η τιμή).

* **Dashboard (Πίνακας Ελέγχου):** Η γραφική απεικόνιση (γραφήματα, δείκτες) των δεδομένων που βλέπουμε στην οθόνη ή στο κινητό.

---

## 2. Προαπαιτούμενα

1. **Hardware:**
* Arduino UNO & Καλώδιο USB.
* Raspberry Pi (3 ή 4) με λειτουργικό Raspberry Pi OS.
* Αισθητήρας (π.χ. Θερμοκρασίας).


2. **Software:**
* Λογαριασμός στο Arduino IoT Cloud.
* Εγκατεστημένο Arduino IDE στον υπολογιστή.

---

## 3. Υλοποίηση

### Βήμα 1: Ρύθμιση στο Arduino Cloud

1. Συνδεθείτε στο [Arduino IoT Cloud](https://cloud.arduino.cc).
2. Πηγαίνετε στο μενού **Devices** -> **Add Device** -> **Linux** -> **Raspberry Pi**.
* *ΠΡΟΣΟΧΗ:* Αντιγράψτε το **Device ID** και το **Secret Key** σε ένα αρχείο κειμένου. Δεν θα μπορέσετε να δείτε το κλειδί ξανά!

3. Πηγαίνετε στο μενού **Things** -> **Create Thing**.
4. Συνδέστε τη συσκευή που μόλις φτιάξατε (Link Device).
5. Πατήστε **Add Variable** για να φτιάξετε τη μεταβλητή της θερμοκρασίας:
* **Name:** `temperature` (Προσοχή: όλα μικρά).
* **Type:** `Temperature Sensor (Celsius)` ή `Floating Point Number`.
* **Permission:** Read Only.
* **Update Policy:** On Change.
* Πατήστε **Add Variable**.

### Βήμα 2: Ο Κώδικας του Arduino UNO

Φορτώστε το αρχείο [`arduino_cloud_iot.inο`](arduino_cloud_iot.inο) στο Arduino UNO. Ο ρόλος του είναι να στέλνει απλώς τον αριθμό της μέτρησης μέσω USB.

### Βήμα 3: Προετοιμασία Raspberry Pi

Ανοίξτε το τερματικό στο Raspberry Pi και εκτελέστε τις παρακάτω εντολές:

1. **Έλεγχος Ώρας (Κρίσιμο για τη σύνδεση SSL):**
```bash
date
# Αν η ώρα είναι λάθος, διορθώστε τη πριν προχωρήσετε.

```


2. **Εγκατάσταση Βιβλιοθηκών & Δημιουργία Περιβάλλοντος:**
```bash
sudo apt update
sudo apt install python3-serial python3-venv -y

# Δημιουργία φακέλου για το εικονικό περιβάλλον
python3 -m venv ~/my_arduino_env

# Ενεργοποίηση περιβάλλοντος
source ~/my_arduino_env/bin/activate

# Εγκατάσταση απαραίτητων πακέτων Python
pip install arduino-iot-cloud cbor2 pyserial

```
### Βήμα 4: Το Python Gateway Script

Χρησιμοποιήστε το έτοιμο αρχείο [`raspberry_pi_gateway.py`](raspberry_pi_gateway.py) που περιλαμβάνεται στον φάκελο.

1.  Αντιγράψτε το αρχείο στον φάκελο του project στο Raspberry Pi: `cp raspberry_pi_gateway.py ~/my_arduino_env/`
2.  Επεξεργαστείτε το αρχείο για να βάλετε τα δικά σας `DEVICE_ID` και `SECRET_KEY`:
    `nano ~/my_arduino_env/raspberry_pi_gateway.py`

*Σημείωση: Το αρχείο είναι ήδη ρυθμισμένο με τον βασικό κώδικα σύνδεσης.*

### Βήμα 5: Αυτόματη Εκκίνηση (Service)

Για να ξεκινάει το πρόγραμμα αυτόματα μόλις πάρει ρεύμα το Raspberry Pi, χρησιμοποιήστε το αρχείο [`arduino_gateway.service`](arduino_gateway.service).

1.  Ανοίξτε το αρχείο και βεβαιωθείτε ότι το `User` και τα μονοπάτια (`WorkingDirectory`, `ExecStart`) είναι σωστά για το σύστημά σας (π.χ. αντικαταστήστε το `salih` με το δικό σας username).
2.  Αντιγράψτε το αρχείο στον φάκελο του systemd:
    ```bash
    sudo cp arduino_gateway.service /etc/systemd/system/
    ```
3. Ενεργοποίηση:
```bash
sudo systemctl daemon-reload
sudo systemctl enable arduino_gateway.service
sudo systemctl start arduino_gateway.service
```

### Βήμα 6: Δημιουργία Dashboard

1. Στο Arduino Cloud, πηγαίνετε στο μενού **Dashboards**.
2. Πατήστε **Build Dashboard**.
3. Πατήστε **Add** και επιλέξτε **Gauge** (Δείκτης) ή **Chart** (Γράφημα).
4. Πατήστε **Link Variable** και επιλέξτε την `temperature`.
5. Το σύστημα είναι έτοιμο! Θα βλέπετε τις τιμές να ενημερώνονται ζωντανά.

---

## 4. Αντιμετώπιση Προβλημάτων (Troubleshooting)

* **Σφάλμα `HTTP Error 401/403` ή `Discovery Exception`:**
 Ελέγξτε αν είναι σωστή η ώρα/ημερομηνία στο Raspberry Pi (`date`).
 Ελέγξτε αν βάλατε σωστά το `Device ID` και το `Secret Key` (όχι το Thing ID).


* **Σφάλμα `ModuleNotFoundError`:**
 Βεβαιωθείτε ότι τρέχετε το Python μέσα από το περιβάλλον (`venv`) ή χρησιμοποιείτε το πλήρες μονοπάτι (`/home/user/my_arduino_env/bin/python3`).

* **Δεν έρχονται δεδομένα:**
 Ελέγξτε αν το Arduino αναβοσβήνει (TX LED).
 Βεβαιωθείτε ότι η θύρα USB είναι σωστή (`/dev/ttyACM0` ή `/dev/ttyUSB0`).