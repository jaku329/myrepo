#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1;
sem_t sem2;

void* func1(void* arg) {
  printf("1 ");
  sem_post(&sem1);
  sem_wait(&sem2);
  printf("3 ");
  sem_post(&sem1);
  return NULL;
}

void* func2(void* arg) {
  sem_wait(&sem1);
  printf("2 ");
  sem_post(&sem2);
  sem_wait(&sem1);
  printf("4 ");
  return NULL;
}

int main() {
  sem_init(&sem1, 0, 0);
  sem_init(&sem2, 0, 1);
  
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, func1, NULL);
  pthread_create(&t2, NULL, func2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  int v1, v2;
  sem_getvalue(&sem1, &v1);
  sem_getvalue(&sem2, &v2);
  printf("sem1 = %d, sem2 = %d\n", v1, v2);
  return 0;
}
