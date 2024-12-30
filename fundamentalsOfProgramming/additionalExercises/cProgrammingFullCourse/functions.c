// Anstatt das zu schreiben:
//#include <stdio.h>
//
//int main() {
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday dear... YOU!");
//    printf("\nHappy birthday to you!\n");
//
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday dear... YOU!");
//    printf("\nHappy birthday to you!\n");
//
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday to you!");
//    printf("\nHappy birthday dear... YOU!");
//    printf("\nHappy birthday to you!\n");
//
//    return 0;
//}
//
// Können wir eine Funktion verwenden, bzw aufrufen, wenn wir sie brauchen.

#include <stdio.h>

void birthday() {
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday dear... YOU!");
    printf("\nHappy birthday to you!\n");
}

int main() {
    birthday();
    birthday();
    birthday();

    return 0;
};


