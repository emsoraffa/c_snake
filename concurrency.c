#include <pthread.h>
#include <stdio.h>

pthread_cond_t c = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *someFunc(void *arg);

int main() {
  pthread_t t1, t2;

  pthread_create(&t1, NULL, someFunc, "Jåss");
  pthread_create(&t2, NULL, someFunc, "kukkene bruse");
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}

void *someFunc(void *arg) {
  printf("%s\n", (char *)arg);
  return NULL;
}
