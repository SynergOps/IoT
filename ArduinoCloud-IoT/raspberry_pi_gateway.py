import time
import serial
import threading
from arduino_iot_cloud import ArduinoCloudClient

# ================= ΡΥΘΜΙΣΕΙΣ ΧΡΗΣΤΗ =================
# Αντικαταστήστε τα παρακάτω με τα στοιχεία από το Cloud (Βήμα 1)
DEVICE_ID  = "TO_DEVICE_ID_SAS_EDO"
SECRET_KEY = "TO_SECRET_KEY_SAS_EDO"

# Ρυθμίσεις USB (Συνήθως /dev/ttyACM0 για UNO ή /dev/ttyUSB0)
SERIAL_PORT = '/dev/ttyACM0' 
BAUD_RATE = 9600 # Ταχύτητα μετάδοσης δεδομένων μεταξύ Arduino και Raspberry Pi
# ====================================================

# Δημιουργία Client
# ΣΗΜΕΙΩΣΗ: Χρησιμοποιούμε την παράμετρο 'password' για το Secret Key
client = ArduinoCloudClient(device_id=DEVICE_ID, username=DEVICE_ID, password=SECRET_KEY)

# Δήλωση μεταβλητής (Πρέπει να έχει ΑΚΡΙΒΩΣ το ίδιο όνομα με Variable στο Cloud)
client.register("temperature") 

# Συνάρτηση για τη σύνδεση στο Cloud (τρέχει στο παρασκήνιο)
def run_arduino_cloud():
    print("Cloud: Εκκίνηση σύνδεσης...")
    client.start() # Σύνδεση στο Arduino Cloud

def main():
    print(f"Gateway: Προσπάθεια σύνδεσης στο {SERIAL_PORT}...")
    
    try:
        # Άνοιγμα Σειριακής Θύρας
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        ser.flush() # Καθαρισμός buffer εισαγωγής δεδομένων
        print("Gateway: Επιτυχής σύνδεση USB!")

        # Εκκίνηση Cloud σε ξεχωριστό Thread (νήμα)
        cloud_thread = threading.Thread(target=run_arduino_cloud, daemon=True) # Daemon thread για αυτόματη διακοπή με το κύριο πρόγραμμα 
        cloud_thread.start() 
        
        time.sleep(2) # Αναμονή για σταθεροποίηση

        print("Gateway: Έτοιμο. Αναμονή δεδομένων...")

        while True:
            if ser.in_waiting > 0:
                try:
                    # Ανάγνωση γραμμής, αποκωδικοποίηση και αφαίρεση κενών
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    
                    if line:
                        # Μετατροπή σε αριθμό και αποστολή
                        temp_val = float(line)
                        print(f"Δεδομένα UNO: {temp_val} C -> Αποστολή στο Cloud")
                        
                        # Ενημέρωση Cloud
                        client["temperature"] = temp_val
                        
                except ValueError:
                    pass # Αγνόηση δεδομένων που δεν είναι αριθμοί
                except Exception as e:
                    print(f"Σφάλμα: {e}")
            
            time.sleep(0.1) # Μικρή παύση για τον επεξεργαστή

    except serial.SerialException:
        print("ΣΦΑΛΜΑ: Δεν βρέθηκε το Arduino. Ελέγξτε το καλώδιο USB.")
    except KeyboardInterrupt:
        print("\nΈξοδος.")

if __name__ == "__main__":
    main()