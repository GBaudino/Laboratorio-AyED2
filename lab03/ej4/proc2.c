#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    // Completar aqui
    *y = (x >= 0) ? x : -x;
}

int main(void) {
    // Completar aqui
    int a = -98;
    int res = 0;
    absolute(a, &res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}