/*
 * Content: Example solution to a programming exercise, with a non-zero number
 *          of bugs.
 *
 * Goal: Evolve the example into a correctly functioning, well-constructed,
 *       application.
 *
 * To build in a Linux environment:
 *  gcc exercise.c -l pthread -o exercise
 * To run in a Linux environment:
 *  ./exercise
 *
 * Problem statement:
 * 1. A producer thread passes a pre-defined sequence of unsigned shorts to
 *    a main function, one value at a time.
 * 2. The main function accumulates values received from a producer thread
 * 3. The main function displays the sequence of values, in ascending order.
 *
 * Required implementation constraints:
 * 1. As noted above, the producer thread must provide one value, and no
 *    more than one value, at a time to the main function.
 * 2. The main function must be able to handle a sequence of arbitrary length.
 * 3. The application must remain coded in the C language.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
pthread_mutex_t m;
pthread_cond_t c;
/* state shared between the producer and main */
struct shared_state {
  int value_available;  /* set by producer to indicate a value is available */
  unsigned short value; /* the current value */
  int done;     /* set by the producer when done */
};


/*
 * provide a sequence of pre-defined unsigned shorts,
 * one value at a time, to main
 */
void *producer(void *arg) {
  /* access the shared state provided by main */
  struct shared_state *state = (struct shared_state *)arg;
  /* this is the array of values that we'll provide to main, one at a time */
  unsigned short values[] = {5,7,234,0,9,18,27,54,238,848,996,3,2,57,8,12};
  int i = 0;
  int val = sizeof(values)/sizeof(values[0]);  
  /* loop through the array of values */
  // lock the state values using mutex
  pthread_mutex_lock(&m);
  while (i < val) {
    /* make next value available to main */
    state->value = values[i++];
    /* signal availability */
    state->value_available = 1;
    pthread_cond_signal(&c);
    /* and wait for main to acknowledge receipt */
    while (state->value_available){
    	pthread_cond_wait(&c,&m);
    }
    
  }
  /* signal that producer is done */
  state->done = 1;
  pthread_cond_signal(&c);
  // unlock mutex
  pthread_mutex_unlock(&m);
  return NULL;
}


/*
 * we'll allocate a dynamically-sized array to hold received values, and
 * double the size each time that we run out of room.
 */
#define INITIAL_ALLOC 512

/*
 * comparison function passed to qsort() by main to sort an array of
 * unsigned shorts
 */
int cmpshort(const void *one, const void *two) {
  return *(unsigned short *)one - *(unsigned short *)two;
}

/*
 * launch the producer thread, receive a set of values one at a time
 * from that thread, and finally, display the set in ascending order.
 */
int main(int argc, char **argv) {
  pthread_t pro;
  pthread_mutex_init(&m, NULL);
  pthread_cond_init(&c, NULL);
  struct shared_state state = { 0, 0, 0}; /* state we share with the producer thread. */
  unsigned short *array;     /* pointer to our dynamically allocated array. */
  int array_size;            /* the current size of the array */
  int i = 0;                 /* our current index into the array */
  int j;

  /* we'll allocate an initial array, then double its size as needed */
  array_size = INITIAL_ALLOC * sizeof(unsigned short);
  array = malloc(array_size);

  /* create the producer thread */
  if(pthread_create (&pro, NULL, producer, (void *)&state) != 0){
    printf("Thread creation failed.");
  }

  /* loop until producer is done */
  while (!state.done) {
    /* wait for the next value to become available */
    if (!state.value_available){
       pthread_cond_wait(&c, &m);
    }
    /* acknowledge receipt of value */
    state.value_available=0;
    pthread_cond_signal(&c);
    /* record the value */
    array[i++] = state.value;
    /* if we've reached the current size of our array, then double its size */
    if (i * sizeof(unsigned short) >= array_size) {
      array_size *= 2;
      array = realloc(array, array_size);
    }
    pthread_cond_wait(&c,&m);
  }

  /* wait for the producer thread to finish */
  pthread_join(pro, NULL);
  // destroy mutex and condition variable
  pthread_mutex_destroy(&m);
  pthread_cond_destroy(&c);
  /* sort the array */
  qsort(array, i, sizeof(unsigned short), cmpshort);

  /* and print it out */
  printf ("The %d values, in ascending order, are: ", i);
  for (j = 0; j < i; j++)
    printf("%u ", array[j]);
  printf("\n");
  free(array);

  
}
