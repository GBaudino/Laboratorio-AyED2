#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = array[0];
    result.min_value = array[0];


    // IMPLEMENTAR
    for (size_t i = 1; i < length; i++)
    {
        int value = array[i];
        if (result.max_value < value){
            result.max_value = value;
            result.max_position = i;
        }
        if (result.min_value > value) {
            result.min_value = value;
            result.min_position = i;
        }
    }
    
    return result;
}

int main(void)
{
    int array[ARRAY_SIZE];
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        int aux;
        printf("Ingrese un numero para el array: ");
        scanf("%d", &aux);
        array[i] = aux;
    }
    
    // PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO.

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}

