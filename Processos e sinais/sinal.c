#include <stdio.h>
#include <signal.h>

/**
	Processo não irá finalizar
*/

void tratasinal(int s) {
	if(s == SIGINT)
		printf("CTRL + c comigo naaao!\n");
	else
		printf("Sinal recebido\n");
}

int main() {
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);
	signal(SIGTERM, tratasinal);
	signal(SIGINT, tratasinal);
	while(1)
		pause();
}