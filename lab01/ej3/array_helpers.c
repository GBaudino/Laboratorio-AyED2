#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    
    //Abre un archivo .in y lee el largo y modifica el arreglo vacio
    // que nos pasan como parametro
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("ERROR in read file\n");
    }
    unsigned int largo;
    fscanf(file, "%u", &largo);
    printf("%d\n",largo);
    for (unsigned int i = 0; i < largo && i < max_size; i++)
    {
        fscanf(file,"%d", &array[i]);
    }
    fclose(file);
    if (largo > max_size){
        return max_size;
    }
    return largo;
}

void array_dump(int a[], unsigned int length) {
    if (length < 1) {
        printf("El arreglo esta vacio\n");
    } else {
        for (unsigned int i = 0; i < length - 1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[length-1]);
    }
}
    