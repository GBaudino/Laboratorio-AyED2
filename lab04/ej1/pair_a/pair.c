#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t new_pair;
    new_pair.fst = x;
    new_pair.snd = y;
    return new_pair;
}

int pair_first(pair_t p){
    return p.fst;
}


int pair_second(pair_t p){
    return p.snd;
}

pair_t pair_swapped(pair_t p){
    pair_t swapped_pair;
    swapped_pair.fst = p.snd;
    swapped_pair.snd = p.fst;
    return swapped_pair;
}

pair_t pair_destroy(pair_t p){
    return p;
}

/* 
 *¿La implementación logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
 * No, no logra encapsulamiento porque puedo usar p.fst y p.snd para acceder al primer o segundo elemento del par
*/