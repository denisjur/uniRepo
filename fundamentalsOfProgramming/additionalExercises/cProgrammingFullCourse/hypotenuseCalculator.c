#include <stdio.h>
#include <math.h>

int main() {
    double A;
    double B;
    double C;

    printf("Enter side A: ");
    scanf("%lf", &A);

    printf("Enter side B: ");
    scanf("%lf", &B);

    C = sqrt(A*A + B*B);

    printf("Side C: %.2lf\n", C);

    return 0;
}

// Wichtig!!! In C erfordert die Verwendung von Funktionen aus der Math-Bibliothek (z. B. sqrt) die Verknüpfung mit der entsprechenden Bibliothek. Der gcc-Befehl benötigt das Flag -lm, um die Math-Bibliothek einzubinden.
// gcc hypotenuseCalculator.c -o hypotenuse -lm

