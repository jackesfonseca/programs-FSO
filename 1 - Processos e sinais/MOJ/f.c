#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int m1[2000][2000], m2[2000][2000];
int m3[2000][2000];

int sinalf1 = 0, sinalf2 = 0;

struct t_param {
  int inicio;
  int fim;
  int size;
  int sig;
};

void aguenta(int s) {
  return;
}

void trata_sinalf1(int s) {
  sinalf1++;
}

void trata_sinalf2(int s) {
  sinalf2++;
}

void *multiplica(void *l) {
  signal(SIGUSR1, aguenta);
  for(int i=((struct t_param*)1)->inicio; i<((struct t_param*)1)->fim; i++) {
    for(int j=0; j<((struct t_param*)1)->size; j++) {
      for(int k=0; k<((struct t_param*)1)->size; k++)
        m3[i][j] += m1[i][k]*m2[k][j];
    }
  }
  int r=0;

  kill(getppid(), ((struct t_param*)1)->sig);

  pause();

  for(int i=((struct t_param*)1)->inicio; i<((struct t_param*)1)->fim; i++) {
    printf("%d", m3[i][0]);
    for(int j=1; j<((struct t_param*)1)->size; j++)
      printf(" %d", m3[i][j]);
    printf("\n");
  }

  kill(getppid(), ((struct t_param*)1)->sig);

  exit(0);
}

int main() {
  int size;
  signal(SIGUSR1, trata_sinalf1);
  signal(SIGUSR2, trata_sinalf2);

  scanf("%d", &size);

  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++) {
      scanf("%d", &m1[i][j]);
      m3[i][j] = 0;
    }

  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      scanf("%d", &m2[i][j]);

  struct t_param t;

  t.inicio = 0;
  t.fim = 2;
  t.size = size;
  int threads = 2;
  int divisao = size/threads;
  int resto = size%threads;
  pid_t ids[threads];
  int sigs[2];
  sigs[0] = SIGUSR1;
  sigs[1] = SIGUSR2;

  for(int i=0; i<threads; i++) {
    struct t_param *t;
    t = malloc(sizeof(struct t_param));
    t->inicio = i*divisao;
    t->sig = sigs[i];

    if(i == threads-1)
      t->fim = resto+i*divisao+divisao;
    else
      t->fim = i*divisao+divisao;

    t->size = size;
    ids[i] = fork();

    if(!ids[i])
      multiplica(t);
  }

  pause();

  while(sinalf1 == 0 || sinalf2 == 0) {
    pause();
  }

  kill(ids[0], SIGUSR1);
  pause();
  kill(ids[1], SIGUSR1);

  wait(NULL);
  wait(NULL);

  return 0;
}
