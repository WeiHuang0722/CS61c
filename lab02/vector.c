/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = malloc(sizeof(vector_t));/* YOUR CODE HERE */

    /* Check our return value to make sure we got memory */
    if (retval == NULL  /* YOUR CODE HERE */) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = 1 /* YOUR CODE HERE */;
    retval->data = malloc(sizeof(int))/* YOUR CODE HERE */;

    /* Check the data attribute of our vector to make sure we got memory */
    if (retval->data == NULL /* YOUR CODE HERE */) {
      free(retval); 	//???			//Why is this line necessary?
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */

   *(retval->data)   /* YOUR CODE HERE */ = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }


    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc < v->size /* YOUR CODE HERE */) {
        return v->data[loc]/* YOUR CODE HERE */;
    } else {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
	free(v->data);
	free(v);
    	/* YOUR SOLUTION HERE */
}
/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

if(loc < v->size)
{	

v->data[loc] = value; 
/* int  i = 0; */

/*while(v->data[loc + i]!=NULL)
{
	v->data[loc+i] = 0;
	i++;
}

*/
}
else
{

       	v->data = realloc(v->data, (loc + 1)*sizeof(int)); 
	for (int i = v->size; i < loc; i++)
	{
	v->data[i] = 0;
	}
 /*   int *temp = malloc((loc + 1)*sizeof(int));
    for(int i = 0; i < v->size; i++)
    {

    temp[i] = v->data[i];

    }*/
 /*  for (int i = v->size; i < loc; i++)
    {
    
    temp[i] = 0;
    
    }
*/
   /* v->data = temp;*/
	v->size = loc + 1; 
    
    
    v->data[loc] = value;
}
 /*   for(int j = 0; j < (loc + 1); j++ )
{
if(j != loc)
{
temp[j] = 0;
}
}
*/
}


