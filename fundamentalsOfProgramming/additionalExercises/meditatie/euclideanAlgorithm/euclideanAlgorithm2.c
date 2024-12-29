/*
 * Algoritmul lui Euclid pentru găsirea celui mai mare divizor comun (GCD) între
 * două numere, folosind restul împărțirii (modulo). Este o metodă eficientă 
 * care se oprește atunci când restul devine zero.
 */

#include <stdio.h>

int euclid(int a, int b) {
    int rest;

    // Continuăm până când b devine zero
    // Structura while repetă un set de instrucțiuni atâta timp cât condiția este evaluată ca fiind TRUE 
    while (b != 0) {
        rest = a % b;  // Calculăm restul împărțirii lui a la b
        a = b;          // Atribuim valoarea lui b în a
        b = rest;       // Atribuim restul în b
    }

    // La final, a va conține cel mai mare divizor comun
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
 * Exemplu:
 * a = 10, b = 3
 * 
 * Implementarea algoritmului lui Euclid:
 * 
 * 1. La început:
 *    a = 10, b = 3
 *    Calculăm restul: rest = a % b = 10 % 3 = 1
 *    Actualizăm valorile: a = b și b = rest → a = 3, b = 1
 * 
 * 2. Următoarea iterație:
 *    a = 3, b = 1
 *    Calculăm restul: rest = a % b = 3 % 1 = 0
 *    Actualizăm valorile: a = b și b = rest → a = 1, b = 0
 * 
 * Algoritmul se oprește când b devine 0, iar a conține cel mai mare divizor comun (GCD).
 * Așadar, cel mai mare divizor comun între 10 și 3 este 1.
 * 
 * Un alt exemplu:
 * a = 48, b = 10
 * 
 * Pași:
 * 1. 48 % 10 = 8 → a = 10, b = 8
 * 2. 10 % 8 = 2 → a = 8, b = 2
 * 3. 8 % 2 = 0 → a = 2, b = 0
 * 
 * Cel mai mare divizor comun între 48 și 10 este 2.
 * 
 * Pseudocodul algoritmului:
 * Algoritmul în pseudocod este următorul:
 * 
 * - Se declară două variabile a și b.
 * - Se execută următoarele operații atâta timp cât b este diferit de zero:
 *     - Se calculează restul împărțirii lui a la b (rest = a % b).
 *     - Variabila a va primi valoarea lui b.
 *     - Variabila b va primi valoarea restului calculat.
 * - La final, se tipărește pe ecran valoarea lui a, care va fi cel mai mare divizor comun (GCD).
 * 
 * Pseudocod:
 * 
 * a = valoare inițială
 * b = valoare inițială
 * 
 * while (b != 0) {
 *     rest = a % b
 *     a = b
 *     b = rest
 * }
 * 
 * tipărește a
 */

