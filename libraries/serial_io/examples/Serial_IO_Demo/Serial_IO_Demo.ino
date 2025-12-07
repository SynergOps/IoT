// Προαιρετικά: Ορισμός δεκαδικών ψηφίων (προεπιλογή = 2)
#define DECIMAL_PLACES 4
#include "serial_io.h"

void setup()
{
    Serial.begin(9600);

    // 1. Παραδείγματα Εξόδου (print/println)
    println("--- Επίδειξη Εξόδου ---");
    print("Απλή εκτύπωση χωρίς αλλαγή γραμμής. ");
    println("Τώρα αλλάζουμε γραμμή.");

    // Εκτύπωση πολλαπλών ορισμάτων (έως 5)
    println("Μέτρηση:", 1, "Τιμή:", 12.3456789, "Μονάδες"); // Θα δείξει 4 δεκαδικά λόγω του define
    println();                                              // Κενή γραμμή
    delay(2000);

    // 2. Παραδείγματα Εισόδου
    println("--- Επίδειξη Εισόδου ---");

    // inputString (με και χωρίς echo)
    String name = inputString("Πώς σε λένε; ");                       // echo = true (default)
    String secret = inputString("Δώσε έναν κωδικό (κρυφό): ", false); // echo = false
    println("\nΟ κωδικός καταχωρήθηκε.");                             // Χρειάζεται \n γιατί το echo=false δεν αλλάζει γραμμή

    // inputCharacter
    char answer = inputCharacter("Σου αρέσει ο προγραμματισμός; (y/n): ");

    // inputInteger & inputFloat
    int age = inputInteger("Πόσο χρονών είσαι; ");
    float height = inputFloat("Τι ύψος έχεις (σε μέτρα); ");

    // 3. Εμφάνιση αποτελεσμάτων
    println("\n--- Αποτελέσματα ---");
    println("Όνομα:", name);
    println("Απάντηση:", answer);
    println("Ηλικία:", age);
    println("Ύψος:", height);

    // 4. Τερματισμός
    stop();
}

void loop()
{
    // Ο κώδικας εδώ δεν θα εκτελεστεί ποτέ λόγω της stop() στο setup
}
