#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void swap(unsigned int a[], unsigned int i, unsigned int j){
    unsigned int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swapC(char a[], unsigned int i, unsigned int j){
    unsigned int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void copyOn(char a[], char b[], unsigned int length){
    for (unsigned int i = 0; i < length; i++)
    {
        b[i] = a[i];
    }
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n");
}

void dualInsertionSort(unsigned int a[], char b[], unsigned int length) {
    for (unsigned int i = 1; i < length; i++)
    {
        unsigned int j = i;
        while(j>0 && a[j] < a[j-1]){
            swap(a,j-1,j);
            swapC(b,j-1,j);
            j = j-1;
        }
    }
    
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    
    //Abre un archivo .in y lee el largo y modifica el arreglo vacio
    // que nos pasan como parametro
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("ERROR in read file\n");
    }
    unsigned int largo,i;
    largo = 0u;
    i = 0u;
    unsigned int n;
    char c;
    while(i < max_size)
    {   
        fscanf(file,"%u ", &n);
        if (feof(file)){
            break;
        }
        fscanf(file,"'%c'", &c);
        indexes[i] = n;
        letters[i] = c;
        largo = largo + 1u;
        i = i + 1u;
    }
    fclose(file);
    if (largo > max_size){
        return max_size;
    }
    return largo;
}



int main(int argc, char *argv[]) {
    // Necesarios para que funcione
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];

    // Parte A
    unsigned int length = data_from_file(filepath, indexes, letters, MAX_SIZE); 

    // Parte B
    copyOn(letters,sorted,length); //Asumimos que letters y sorted tienen la misma cantidad de elementos.
    dualInsertionSort(indexes,sorted,length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

