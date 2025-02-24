#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM 10

void drucke(char** helden) {
    int i;
    for (i = 0; helden[i] != NULL; i++) {
        printf("%s", helden[i]);
        if (helden[i+1] != NULL) printf(", ");
    }
    printf("\n");
}

void freigabe(char** helden) {
    int i;
    for (i = 0; helden[i] != NULL; i++) {
        free(helden[i]);
        helden[i] = NULL;
    }
}

void add(char** helden, char* hero, int max) {
    int i;
    for (i = 0; helden[i] != NULL; i++) {}
    if (i >= max - 1) {
        printf("Array voll");
        return;
    }
    helden[i] = malloc(sizeof(char) * (strlen(hero) + 1));
    if (helden[i] == NULL) {
        printf("Heap voll");
        return;
    }
    strcpy(helden[i], hero);
    helden[i + 1] = NULL;
}



int main(void) {
    char* helden[MAX_NUM + 1];

    helden[0] = NULL;
    add(helden, "Frodo Beutlin", MAX_NUM + 1);
    add(helden, "Luke Skywalker", MAX_NUM + 1);
    add(helden, "Hans Gruber", MAX_NUM + 1);
    add(helden, "Deadpool", MAX_NUM + 1);
    drucke(helden);
    freigabe(helden);
    return 0;
}

