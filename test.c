#include <stdio.h>
#include <stdlib.h>

// Funzione per controllare se una permutazione collida con due permutazioni date
int collidesWith(int *perm, int *perm1, int *perm2, int n) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == perm1[i] || perm[i] == perm2[i]) {
            return 1;  // Collisione
        }
    }
    return 0;  // Nessuna collisione
}

// Funzione per stampare una permutazione
void printPermutation(int *perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Funzione ricorsiva per generare e stampare permutazioni
void generatePermutations(int *perm, int *collisionPerm1, int *collisionPerm2, int *used, int currentIndex, int n) {
    if (currentIndex == n) {
        if (!collidesWith(perm, collisionPerm1, collisionPerm2, n)) {
            printPermutation(perm, n);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (used[i] == 0) {
                perm[currentIndex] = i;
                used[i] = 1;
                generatePermutations(perm, collisionPerm1, collisionPerm2, used, currentIndex + 1, n);
                used[i] = 0;
            }
        }
    }
}

int main() {
    int n;
    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    int *collisionPerm1 = (int *)malloc(n * sizeof(int));
    int *collisionPerm2 = (int *)malloc(n * sizeof(int));
    int *currentPerm = (int *)malloc(n * sizeof(int));
    int *used = (int *)calloc(n + 1, sizeof(int));

    printf("Inserisci la prima permutazione di collisione:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &collisionPerm1[i]);
        used[collisionPerm1[i]] = 1;
    }

    printf("Inserisci la seconda permutazione di collisione:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &collisionPerm2[i]);
        used[collisionPerm2[i]] = 1;
    }

    generatePermutations(currentPerm, collisionPerm1, collisionPerm2, used, 0, n);

    free(collisionPerm1);
    free(collisionPerm2);
    free(currentPerm);
    free(used);

    return 0;
}