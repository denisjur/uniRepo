/*
 * Titlu: Calcularea lungimii unui șir de caractere și golirea buffer-ului de intrare
 * Descriere:
 * Acest program citește un șir de caractere de la intrarea standard, calculează lungimea sa (fără '\n'-ul final),
 * afișează lungimea și golește buffer-ul de intrare. Utilizează funcțiile `my_strlen` și `clear_buffer`.
 */

#include <stdio.h>
#include <string.h>

void clear_buffer() {
    // Golește buffer-ul de intrare pentru a preveni intrările ulterioare nedorite
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

size_t my_strlen(const char *str) {
    // Calculează lungimea unui șir de caractere fără '\0'-ul final
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

int main(int argc, char const *argv[]) {
    char buffer[100];

    printf("Introduceți un șir: ");

    // Citește un șir de caractere de la intrarea standard
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Eroare la citirea intrării.\n");
        return 1;
    }

    // Elimină '\n'-ul final, dacă este prezent
    size_t len = my_strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--; // Lungimea efectivă fără '\n'
    }

    printf("Șir introdus: %s - Lungime: %zu\n", buffer, len);

    clear_buffer();

    printf("Buffer-ul de intrare a fost golit!\n");

    return 0;
}

