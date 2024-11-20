#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generate_map(char map[SIZE][SIZE]) {
    // Encadre la carte par des murs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1)
                map[i][j] = '1';  // Bordure de murs
            else
                map[i][j] = '0';  // Espace vide par défaut
        }
    }
    
    // Place la position de départ 'P'
    int px = 1 + rand() % (SIZE - 2);
    int py = 1 + rand() % (SIZE - 2);
    map[px][py] = 'P';

    // Place la sortie 'E' dans une position différente
    int ex, ey;
    do {
        ex = 1 + rand() % (SIZE - 2);
        ey = 1 + rand() % (SIZE - 2);
    } while (ex == px && ey == py);
    map[ex][ey] = 'E';

    // Place au moins un item 'C'
    int num_items = 1 + rand() % 10; // Nombre aléatoire d'items entre 1 et 10
    for (int i = 0; i < num_items; i++) {
        int cx, cy;
        do {
            cx = 1 + rand() % (SIZE - 2);
            cy = 1 + rand() % (SIZE - 2);
        } while (map[cx][cy] != '0'); // Trouve un emplacement vide
        map[cx][cy] = 'C';
    }

    // Place des murs aléatoires à l'intérieur de la carte
    int num_walls = (SIZE * SIZE) / 10; // Par exemple, 10% de la carte
    for (int i = 0; i < num_walls; i++) {
        int wx, wy;
        do {
            wx = 1 + rand() % (SIZE - 2);
            wy = 1 + rand() % (SIZE - 2);
        } while (map[wx][wy] != '0'); // Place un mur dans un espace vide
        map[wx][wy] = '1';
    }
}

void print_map(char map[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL)); // Initialise le générateur aléatoire

    char map[SIZE][SIZE];
    generate_map(map);
    print_map(map);

    // TODO: Ajoutez une vérification pour vérifier le chemin entre 'P', tous les 'C', et 'E'

    return 0;
}
