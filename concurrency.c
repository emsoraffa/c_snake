#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

pthread_mutex_t big_p = PTHREAD_MUTEX_INITIALIZER;

void *someFunc(void *arg);
void *diffFunc(void *arg);
int count = 0;

int main() {
  pthread_t thread_a, thread_b;

  pthread_create(&thread_a, NULL, diffFunc, "");
  pthread_create(&thread_b, NULL, diffFunc, "");
  pthread_join(thread_a, NULL);
  pthread_join(thread_b, NULL);

  printf("%i\n", count);
  return 0;
}

void *someFunc(void *arg) {
  printf("%s\n", (char *)arg);
  return NULL;
}

void *diffFunc(void *arg) {
  for (uint64_t i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&big_p);
    count += 1;
    pthread_mutex_unlock(&big_p);
  }
  return NULL;
}
