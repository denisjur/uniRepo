#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char *vorname, *nachname;
} person;

void split(char** namen, person** personen) {
    int i = 0, len;
    char* lz;
    for (i = 0; namen[i] != NULL; i++) {
        personen[i] = malloc(sizeof(person));
        lz = strstr(namen[i], " ");
        len = lz - namen[i];
        personen[i]->vorname = malloc(sizeof(char) * (len + 1));
        personen[i]->nachname = malloc(sizeof(char) * (strlen(namen[i]) - len - 1 + 1));
        strncpy(personen[i]->vorname, namen[i], len);
        strcpy(personen[i]->nachname, lz + 1);
    }
    personen[i] = NULL;
}

void print(person** personen) {
    int i;
    for (i = 0; personen[i] != NULL; i++) {
        printf("Vorname: %s\tNachname: %s\n", personen[i]->vorname, personen[i]->nachname);
    }
}

int main(void) {
    char* namen[MAX] = {"Max Mueller", "Maria Meier", "Sven Kunze", NULL};
    person* personen[MAX];
    split(namen, personen);
    print(personen);
    return 0;
}

