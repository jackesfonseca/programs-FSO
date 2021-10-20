#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
	Processo não irá finalizar
*/

void tratasinal(int s) {
	if(s == SIGINT)
		printf("Filho %d: CTRL + c comigo naaao!\n", getpid());
	else if (s == SIGALRM){
		printf("Filho %d: ALARME\n", getpid());
		alarm(1);
	}
	else
		printf("Filho %d: Sinal recebido\n");
}

fazcoisadefilho() {
	while(1) {
		printf("Filho %d: Chamando o pai %d\n", getpid(), getppid());
		kill(getppid, SIGUSR1);
		sleep(1);
	}
}

int main() {
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);
	signal(SIGTERM, tratasinal);
	signal(SIGINT, tratasinal);
	signal(SIGALRM, tratasinal);
	alarm(1);

	pid_t p = fork();

	if(p == 0)
		fazcoisadefilho();

	while(1)
		pause();
}