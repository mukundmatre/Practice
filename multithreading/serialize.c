#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_th1, sem_th2, sem_th3, sem_th4;

void* t1_handler(void* arg) {
  sem_wait(&sem_th1);
  printf("I am first thread with thread id: %lu\n", pthread_self());
  sem_post(&sem_th2);
  pthread_exit(NULL);
}

void* t2_handler(void* arg) {
  sem_wait(&sem_th2);
  printf("I am second thread with thread id:%lu\n", pthread_self());
  sem_post(&sem_th3);
  pthread_exit(NULL);
}

void* t3_handler(void* arg) {
  sem_wait(&sem_th3);
  printf("I am third thread with thread id: %lu\n", pthread_self());
  sem_post(&sem_th4);
  pthread_exit(NULL);
}

void* t4_handler(void* arg) {
  sem_wait(&sem_th4);
  printf("I am fourth thread with thread id:%lu\n", pthread_self());
  sem_post(&sem_th1);
  pthread_exit(NULL);
}


int main(void) {
  pthread_t thread1, thread2, thread3, thread4;
  sem_init(&sem_th1, 0, 0);
  sem_init(&sem_th2, 0, 0);
  sem_init(&sem_th3, 0, 0);
  sem_init(&sem_th4, 0, 0);
  pthread_create(&thread1, NULL, &t1_handler, NULL);
  pthread_create(&thread2, NULL, &t2_handler, NULL);
  pthread_create(&thread3, NULL, &t3_handler, NULL);
  pthread_create(&thread4, NULL, &t4_handler, NULL);
  sem_post(&sem_th1);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  return 0;
}
