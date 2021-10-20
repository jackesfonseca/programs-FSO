#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int password=0;

void tratasinal(int s) {
	printf("Recebi %d\n", s);

	if(s == SIGINT)
		password = 1;
	else if(password == 1 && s == SIGUSR2)
		password++;
	else if(password == 2 && s == SIGTERM) {
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
	signal(SIGINT, tratasinal);
	signal(SIGTERM, tratasinal);
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);

	while(1)
		pause();
}