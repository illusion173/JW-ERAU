
/*
 * Submitted by: Jeremiah Webb
 * In class assignment
 * Submitted on 10/18/2022
 * By submitting this program with my name, I affirm that the creation and
 * modification of this program is primarily my work
 *
 *
 *
 *
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int average = 0;
int minimum = 0;
int maximum = 0;
int *values;
int size_of_array = 0;
// Find average of values, iterate and add all of them, divide by size of the
// array
void *findaverage(void *param) {
  int sum = 0;
  int *values;
  int i = 0;
  values = param;
  for (i = 0; i < size_of_array; i++) {
    sum += values[i];
  }
  average = sum / (int)size_of_array;
  return (void *)0;
}

// Cycle through array, basic if statement
void *findmin(void *param) {
  int *values;

  values = param;
  minimum = values[0];
  for (int i = 0; i < size_of_array; i++) {
    if (values[i] < minimum) {
      minimum = values[i];
    }
  }

  return (void *)0;
}
// find max function, cycle through array
void *findmax(void *param) {
  int *values;
  values = param;
  maximum = values[0];

  for (int i = 0; i < size_of_array; i++) {
    if (values[i] > maximum) {
      maximum = values[i];
    }
  }

  return (void *)0;
}

int main(int argc, char **argv) {

  // if not enough args
  if (argc < 2) {
    fprintf(stderr, "Use: %s <integer value> \n", argv[0]);
    exit(1);
  }
  --argc;
  ++argv;

  values = calloc(argc, sizeof(int));
  for (int i = 0; i < argc; i++) {
    values[i] = atoi(argv[i]);
    size_of_array++;
  }

#if 0
  pthread_attr_t attr;
#endif

  // generate threads
  pthread_t averagePT;
  pthread_t minimumPT;
  pthread_t maximumPT;
#if 0 
// Physical creation of threads & run them
  pthread_create(&averagePT, &attr, findaverage, values);
  pthread_create(&minimumPT, &attr, findmin, values);
  pthread_create(&maximumPT, &attr, findmax, values);

#else
  // Physical creation of threads & run them
  pthread_create(&averagePT, NULL, findaverage, values);
  pthread_create(&minimumPT, NULL, findmin, values);
  pthread_create(&maximumPT, NULL, findmax, values);

#endif
  // Finally, join the threads
  pthread_join(averagePT, NULL);
  pthread_join(minimumPT, NULL);
  pthread_join(maximumPT, NULL);
  // Now we need to print the values
  printf("The average value is %d\n", average);
  printf("The minimum value is %d\n", minimum);
  printf("The maximum value is %d\n", maximum);
  return 0;
}
