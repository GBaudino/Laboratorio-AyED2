#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t new_pair = NULL;
    new_pair = malloc(sizeof(pair_t));
    new_pair->fst = x;
    new_pair->snd = y;
    return new_pair;
}

elem pair_first(pair_t p){
    return p->fst;
}


elem pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    pair_t swapped_pair = malloc(sizeof(pair_t));
    swapped_pair->fst = p->snd;
    swapped_pair->snd = p->fst;
    return swapped_pair;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}



/*
 *¿La implementación logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
 * Si, logra el encapsulamiento ya que para poder, luego, hacer uso del tipo pair_t tan
 * solo vamos a poder utilizar los metodos definidos, y no su implementacion interna
*/