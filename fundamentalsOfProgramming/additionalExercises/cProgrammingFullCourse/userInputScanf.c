#include <stdio.h>
#include <string.h> // Am inclus aceasta librarie pentru strcspn = "String Complement Span"

int main() {
    int age;
    char name[25];      // Max 24 characters + null terminator (\0). Aici e mx 24 bytes, ca 1 byte = 1 char.
    char fullName[45];  // Max 44 characters + null terminator 

    printf("What's your first name?\n");
    scanf("%s", &name); 
    
    // ##############################################################
    // Clear the input buffer to avoid issues when switching to fgets
    // Cand scrii ceva in command line si apesi enter atunci sunt luate char care leai scri, dar si Entertaste ca [\n].
    // Characterele sunt gespeichert in die Variable care ai vruto, dar [\n] de la Enter ramane in Buffer si poate sa
    // te incurce la urmatorul Befeht, de asta trebuie sa leeren Bufferul cu comanda asta!
    while (getchar() != '\n');
    // ##############################################################

    printf("\nHi %s!\n", name);

    printf("But what is your full name?\n");
    fgets(fullName, sizeof(fullName), stdin);  // Read full name with spaces. Aici syntaxa de la 
    
    // Prüfe, ob das letzte Zeichen ein '\n' ist
    if (fullName[strlen(fullName) - 1] == '\n') {
        fullName[strlen(fullName) - 1] = '\0'; // Entferne den Zeilenumbruch
    }

    printf("Hi %s!\n", fullName);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("You are %d years old.\n", age);

    return 0;
}
