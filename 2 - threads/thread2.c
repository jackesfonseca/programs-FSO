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
  int a = 10;
  printf("a = %d\n", a);
  pthread_create(&pid, NULL, &cria_thread, (void *)&a);
  printf("Thread criada..\n");
  printf("Thread principal dormindo um pouco...\n");
  sleep(10);
  printf("a = %d\n", a);

  printf("Tchau\n");
  return 0;
}
