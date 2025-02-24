#include <stdio.h>

/*
 * Funcția euclid calculează cel mai mare divizor comun (GCD)
 * între două numere a și b folosind algoritmul lui Euclid prin scăderi succesive.
 */
int euclid(int a, int b) {
    // Continuăm să scădem cel mai mic număr din cel mai mare până când a și b devin egale
    while (a != b) {
        if (a > b) {
            a = a - b;  // Dacă a este mai mare, scădem b din a
        } else {
            b = b - a;  // Dacă b este mai mare, scădem a din b
        }
    }
    // La final, a și b vor fi egale, iar valoarea lor reprezintă GCD
    return a;
}

int main() {
    int a, b;

    // Solicităm utilizatorului să introducă cele două numere
    printf("Introduceti valoarea pentru a: ");
    scanf("%d", &a);

    printf("Introduceti valoarea pentru b: ");
    scanf("%d", &b);

    // Apelăm funcția euclid și afișăm rezultatul
    printf("Cel mai mare divizor comun dintre %d si %d este: %d\n", a, b, euclid(a, b));

    return 0;
}

/*
 * Algoritmul lui Euclid pentru găsirea celui mai mare divizor comun (GCD) 
 * prin scăderi succesive.
 *
 * Exemplu:
 * a = 10
 * b = 3
 *
 * 1. Cel mai mare divizor comun între 10 și 3 este 1.
 * 
 * Descrierea algoritmului:
 * La început avem a = 10 și b = 3. Algoritmul lui Euclid funcționează astfel:
 *   - Continuăm să scădem valoarea celui mai mic număr din cel mai mare,
 *     până când cele două numere devin egale.
 *   
 * Pași detaliați:
 *  - Iterăm atâta timp cât a și b nu sunt egale.
 *  - Dacă a este mai mare decât b, scădem b din a: a = a - b.
 *  - Dacă b este mai mare decât a, scădem a din b: b = b - a.
 *
 * Algoritmul se termină când a și b devin egale, iar acestă valoare este
 * cel mai mare divizor comun (GCD).
 *
 * Exemplu concret:
 *   - Pasul 1: (a = 10, b = 3) → a este mai mare, a = a - b → a = 7, b = 3
 *   - Pasul 2: (a = 7, b = 3) → a este mai mare, a = a - b → a = 4, b = 3
 *   - Pasul 3: (a = 4, b = 3) → a este mai mare, a = a - b → a = 1, b = 3
 *   - Pasul 4: (a = 1, b = 3) → b este mai mare, b = b - a → a = 1, b = 2
 *   - Pasul 5: (a = 1, b = 2) → b este mai mare, b = b - a → a = 1, b = 1
 *
 * După aceste pași, a și b devin egale (a = b = 1). Așadar, cel mai mare divizor comun
 * între 10 și 3 este 1. Cel mai mare divizor comun (a,b) = (10,3) = 1
 *
 * La final, returnăm valoarea lui a sau b (care sunt egale), care reprezintă GCD.
 *
 * Afișăm rezultatul: 1
 */

