#include <stdio.h>
#include <string.h>

int main()
{
    // while loop = repeats a section of code possibly unlimited times.
    // WHILE some condition remains true
    // a while loop might not execute at all

    char name[25];

    printf("\nWhat's your name?: ");
    fgets(name, 25, stdin);  
    name[strlen(name) - 1] = '\0';  // Die Zeile name[strlen(name) - 1] = '\0'; 
                                    // wird verwendet, um das Zeilenumbruch-Zeichen (\n) zu entfernen, 
                                    // das von der Funktion fgets automatisch am Ende des Eingabewerts eingefügt wird.
                                    // Gen asa e gespeichert: (John \n  \0)

                                
    while (strlen(name) == 0) {
        printf("\nYou did not enter your name");
        printf("\nWhat's your name?: ");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
    };

    printf("Hello %s\n", name);

    return 0;
};

