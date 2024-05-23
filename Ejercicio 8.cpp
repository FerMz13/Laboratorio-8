#include <stdio.h>
#include <stdlib.h>

void memoria(int *mem, int size) {
    for (int i = 0; i < size; i++) {
        mem[i] = -1;
    }
}

int FE(int n, int *mem) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    if (mem[n] != -1) {
        return mem[n];
    }
    mem[n] = FE(n-1, mem) + FE(n-2, mem) + FE(n-3, mem);
    return mem[n];
}

int main() {
    int n = 5;  
    int *mem = (int *)malloc((n + 1) * sizeof(int));

    memoria(mem, n + 1);

    int ways = FE(n, mem);
    printf("Numero de formas de subir la escalera de %d peldanos: %d\n", n, ways);

    free(mem);
    return 0;
}

