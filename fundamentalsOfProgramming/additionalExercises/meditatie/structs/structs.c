#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Structura simplă pentru o persoană
struct Persoana {
    char name[50];   // Numele persoanei
    int varsta;      // Vârsta persoanei
    float inaltime;  // Înălțimea persoanei
};

// 2. Structura pentru un student
struct Student {
    char numecomplete[100]; // Numele complet al studentului
    int varsta;             // Vârsta studentului
    float medie;            // Media generală a studentului
    char facultate[50];     // Facultatea unde studiază
    int anStudiu;           // Anul de studiu
};

// 3. Structura pentru un angajat
struct Angajat {
    char *nume;          // Numele angajatului (alocat dinamic)
    int varsta;          // Vârsta angajatului
    float salariu;       // Salariul angajatului
    char *departament;   // Departamentul (alocat dinamic)
};

// 4. Structura pentru un punct în spațiu 2D
struct Point {
    float x, y; // Coordonatele punctului (x, y)
};

// 5. Structura pentru o mașină
struct Masina {
    char marca[40];       // Marca mașinii
    char model[40];       // Modelul mașinii
    struct Point pozitie; // Poziția mașinii (utilizând structura `Point`)
    int anFabricatie;     // Anul de fabricație
};

// Funcție pentru afișarea detaliilor unei persoane
void afiseazaPersoana(struct Persoana p) {
    printf("Nume: %s\n", p.name);
    printf("Vârsta: %d\n", p.varsta);
    printf("Înălțimea: %.2f\n", p.inaltime);
}

int main(int argc, char const *argv[]) {

    // Creăm o instanță a structurii `Persoana`
    struct Persoana p1;

    // Inițializăm câmpurile structurii `Persoana`
    strcpy(p1.name, "John");  // Copiem numele în câmpul `name`
    p1.varsta = 20;           // Setăm vârsta
    p1.inaltime = 1.75;       // Setăm înălțimea

    // Afișăm detaliile persoanei
    afiseazaPersoana(p1);

    // Creăm un pointer către o structură `Angajat` și alocăm memorie în HEAP
    struct Angajat *ang = malloc(sizeof(struct Angajat)); // Alocare memorie

    if (ang == NULL) { // Verificăm dacă alocarea a eșuat
        printf("Eroare la alocarea memoriei pentru angajat!\n");
        return 1;
    }

    // Inițializăm câmpurile structurii `Angajat`
    ang->nume = strdup("Resig"); // Copiem numele alocat dinamic
    if (ang->nume == NULL) {     // Verificăm dacă alocarea a eșuat
        printf("Eroare la alocarea memoriei pentru numele angajatului!\n");
        free(ang);               // Eliberăm memoria alocată pentru `ang`
        return 1;
    }

    ang->varsta = 30;       // Setăm vârsta
    ang->salariu = 2500.50; // Setăm salariul

    // Afișăm detaliile angajatului
    printf("Angajat: %s\n", ang->nume);
    printf("Salariu: %.2f\n", ang->salariu);

    // Eliberăm memoria alocată dinamic
    free(ang->nume); // Eliberăm memoria alocată pentru numele angajatului
    free(ang);       // Eliberăm structura `Angajat`

    return 0;
}

