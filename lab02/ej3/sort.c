#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    unsigned int piv, i, j;
    piv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i],a[piv])){
            i++;
        }
        else if (goes_before(a[piv],a[j])){
            j--;
        }
        else if (goes_before(a[piv], a[i]) && goes_before(a[j], a[piv])){
            swap(a, i, j);
        }
    }
    swap(a, piv, j);
    piv = j;
    return piv;
    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    
    if(izq < der){
        unsigned int pivot = partition(a,izq,der);

        // Ahorramos una entrada a la func
        if (pivot > 0 && izq < pivot - 1){
            quick_sort_rec(a,izq,pivot - 1);    
        }
        if (pivot + 1 < der){
            quick_sort_rec(a,pivot + 1, der);
        }
    }
}


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

