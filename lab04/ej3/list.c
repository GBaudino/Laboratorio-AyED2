#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "list.h"

struct s_list {
    elem e;
    struct s_list *next;
};


// -------Constructors-------
//Create empty list.
list empty(){
    list l = NULL;
    return l;
}

//Adding an element to the list.
list addl(elem e, list l){
    list newelem = NULL;
    newelem = malloc(sizeof(list));
    newelem->e = e;
    newelem->next = l;
    l = newelem;
    return l;
}

// -------Destroy-------
//Destroy a list l.
void destroy(list l){
    list p = NULL;
    while(l != NULL){
        p = l;
        l = l->next;
        free(p);
    }
}


// -------Operations-------
// Check if the list is empty.
// Returns true if the list is empty.
bool is_empty(list l){
    return (l == NULL);
}

// Return the first element of the list.a
elem head(list l){
    assert(!is_empty(l));
    return l->e;
}

// Delete the first element of the list.
list tail(list l){
    assert(!is_empty(l));
    l = l->next;
    return l;
}

// Add an element to the end of the list.
list addr(list l, elem e){
    list q = NULL;
    list p = NULL;
    p = malloc(sizeof(list));
    p->e = e;
    p->next = NULL;
    if (!is_empty(l)){
        q = l;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    } else {
        l = p;
    }
    return l;
}

// Returns the quantity of elements in the list.
unsigned int length(list l){
    unsigned int largo = 0u;
    if(!is_empty(l)){
        list p = l;
        while(p != NULL){
            largo = largo + 1;
            p = p->next;
        }
    }
    return largo;
}

// Add to the end of l all the elements of l0 
// in the same order.
void concat(list l, list l0){
    if (!is_empty(l0)){
        // Guardo el principio de l0
        list initl0 = l0;
        // Hago que p apunte al principio de l
        list p = l;
        if (!is_empty(l)){
            // Llego hasta el ultimo elemento de l con p
            while(p->next != NULL){
                p = p->next;
            }
        }
        
        while (l0 != NULL){
            p->next = malloc(sizeof(list));
            p = p->next;
            p->e = l0->e;
            l0 = l0->next;
        }
        l0 = initl0;
    }
}


// Returns the nth element of list l
elem index(list l, unsigned int n){
    assert(n<length(l));
    if (n>=1){
        list p = l;
        unsigned int indice = 0u;
        while(indice < n-1){
            p = p->next;
            indice += 1;
        }
        return p->e;
    } else if (n == 0){
        return head(l);
    } else {
        return 0;
    }
    
}

// Leave in l only the first n
// elements, removing the rest
list take(list l, unsigned int n){
    if (n<length(l)){
        list p = l;
        n--;
        while(n--){
            p = p->next;
        }
        list q = p->next;
        p->next = NULL;
        destroy(q);
    }
    return l;
}

// Remove the first n elements of l
list drop(list l, unsigned int n){
    if(n<length(l)){
        list p = l;
        n -= 2;
        while(n--){
            l = l->next;
        }
        list q = l;
        l = l->next;
        q->next = NULL;
        destroy(p);
    }else{
        destroy(l);
    }
    return l;
}

// Copy all the elements of l1 into the new list l2
list copy_list(list l){
    list p, q, l2;
    l2 = NULL;
    p = NULL;
    q = NULL;
    l2 = empty();
    p = l;
    if(p != NULL){
        l2 = malloc(sizeof(list));
        l2 -> e = l->e;
        q = l2;
        while(p->next != NULL){
            q->next = malloc(sizeof(list));
            q = q->next;
            p = p->next;
            q->e = p->e;
        }
        q->next = NULL;
    }else{
        l2 = NULL;
    }
    return l2;
}