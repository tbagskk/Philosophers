#include "../includes/Philosophers.h"
#include <pthread.h>


int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
  int i;
  for (i = 0; i < 100000; i++) {
    pthread_mutex_lock(&mutex);
    counter++;
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void jsp() {
  pthread_t thread_id1, thread_id2;
  printf("Creating threads...\n");
  int result1 = pthread_create(&thread_id1, NULL, thread_function, NULL);
  int result2 = pthread_create(&thread_id2, NULL, thread_function, NULL);
  if (result1 != 0 || result2 != 0) {
    printf("Error creating threads.\n");

  }
  printf("Waiting for threads to finish...\n");
  pthread_join(thread_id1, NULL);
  pthread_join(thread_id2, NULL);
  printf("Counter value: %d\n", counter);

}