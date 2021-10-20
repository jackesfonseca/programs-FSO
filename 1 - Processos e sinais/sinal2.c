#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
	Processo não irá finalizar
*/

void tratasinal(int s) {
	if(s == SIGINT)
		printf("CTRL + c comigo naaao!\n");
	else if (s == SIGALRM){
		printf("ALARME\n");
		alarm(1);
	}
	else
		printf("Sinal recebido\n");
}

int main() {
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);
	signal(SIGTERM, tratasinal);
	signal(SIGINT, tratasinal);
	signal(SIGALRM, tratasinal);
	alarm(1);
	while(1)
		pause();
}