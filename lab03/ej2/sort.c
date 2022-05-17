/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"


void swap(player_t a[], unsigned int i, unsigned int j){
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

bool goes_before(player_t x, player_t y){
    return (x.rank <= y.rank);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    // completar aquí
    for (unsigned int i = 1u; i < length; i++)
    {
        for (unsigned int j = i; j >= 1; j--)
        {
            if (goes_before(a[j], a[j - 1]))
            {
                swap(a,j,j-1);
            }
            else{
                break;
            }
        }
    }
}

