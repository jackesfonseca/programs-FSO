#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *cria_thread(void *a) {
  printf("Sou uma thread\n");
  while(1);
}

int main() {
  pthread tid;
  pthread_create(&pid, NULL, &cria_thread, NULL);
  printf("Thread criada..\n");
  printf("Thread principal dormindo um pouco...\n");
  sleep(10);
  printf("Thread principal consumindo um pouco de CPU....\n");

  for(int i=0; i<100000000; i++)
    getppid();

  printf("Tchau\n");
  return 0;
}
