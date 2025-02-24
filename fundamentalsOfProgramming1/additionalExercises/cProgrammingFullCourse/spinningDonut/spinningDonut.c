#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h> // for usleep

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define PI 3.14159

int main() {
    float A = 0, B = 0; // Rotation angles
    float i, j; // Loop variables

    char screen[SCREEN_WIDTH * SCREEN_HEIGHT]; // Screen buffer
    printf("\x1b[2J"); // Clear the screen

    while (1) {
        memset(screen, ' ', SCREEN_WIDTH * SCREEN_HEIGHT); // Clear buffer
        float zbuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
        memset(zbuffer, 0, sizeof(zbuffer));

        for (i = 0; i < 2 * PI; i += 0.07) {
            for (j = 0; j < 2 * PI; j += 0.02) {
                float sinA = sin(A), cosA = cos(A);
                float sinB = sin(B), cosB = cos(B);
                float sini = sin(i), cosi = cos(i);
                float sinj = sin(j), cosj = cos(j);

                float circlex = cosi + 2; // Torus major radius
                float circley = sini;

                float x = circlex * (cosB * cosj + sinA * sinB * sinj) - circley * cosA * sinB;
                float y = circlex * (cosj * sinB - sinA * cosB * sinj) + circley * cosA * cosB;
                float z = 1 / (circlex * sinj * cosA + circley * sinA + 5); // Depth
                int screenx = (int)(SCREEN_WIDTH / 2 + SCREEN_WIDTH / 4 * x * z);
                int screeny = (int)(SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 4 * y * z);

                int idx = screenx + screeny * SCREEN_WIDTH;
                if (idx >= 0 && idx < SCREEN_WIDTH * SCREEN_HEIGHT) {
                    if (z > zbuffer[idx]) {
                        zbuffer[idx] = z;
                        screen[idx] = ".,-~:;=!*#$@"[(int)(z * 12)];
                    }
                }
            }
        }

        printf("\x1b[H"); // Move cursor to home
        for (int k = 0; k < SCREEN_WIDTH * SCREEN_HEIGHT; k++) {
            putchar(k % SCREEN_WIDTH ? screen[k] : '\n');
        }

        A += 0.04;
        B += 0.02;
        usleep(30000); // Pause
    }

    return 0;
}

