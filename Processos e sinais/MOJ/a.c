#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int password=0;

void tratasinal(int s) {
	printf("Recebi %d\n", s);

	if((password == 0 && s == SIGINT) || (password == 1 && s == SIGUSR2))
		password++;

	else if(password == 2 && SIGTERM) {
		password++;
		printf("Senha acionada\n");
	}
	else if(password == 3 && s == SIGUSR1) {
		printf("Tchau\n");
		exit(0);
	}
	else
		password = 0;
}

int main() {
	signal(SIGTERM, tratasinal);
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);
	signal(SIGINT, tratasinal);

	while(1)
		pause();
}