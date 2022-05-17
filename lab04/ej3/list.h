#include <stdlib.h>
#include <stdbool.h>

#ifndef _LIST_H
#define _LIST_H

typedef struct s_list * list;

typedef int elem;

// -------Constructors-------
//Create empty list.
list empty();

//Adding an element to the list.
list addl(elem e, list l);


// -------Destroy-------
//Destroy a list l.
void destroy(list l);


// -------Operations-------
// Check if the list is empty.
// Returns true if the list is empty.
bool is_empty(list l);

// Return the first element of the list.a
elem head(list l);

// Delete the first element of the list.
list tail(list l);

// Add an element to the end of the list.
list addr(list l, elem e);

// Returns the quantity of elements in the list.
unsigned int length(list l);

// Add to the end of l all the elements of l0 
// in the same order.
void concat(list l, list l0);

// Returns the nth element of list l
elem index(list l, unsigned int n);

// Leave in l only the first n
// elements, removing the rest
list take(list l, unsigned int n);

// Remove the first n elements of l
list drop(list l, unsigned int n);

// Copy all the elements of l1 into the new list l2
list copy_list(list l);

#endif