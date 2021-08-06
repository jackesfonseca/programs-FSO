#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int senha=0;

void tratasinal(int s) {
	printf("Recebi %d\n", s);

	if(senha == 0 && s == SIGINT){
		senha++;
	}
	else if(senha == 1 && s == SIGUSR2){
		senha++;
	}
	else if(senha == 2 && SIGTERM) {
		senha++;
		printf("Senha acionada\n");
	}
	else if(s == SIGINT) {
		senha=1;
	}
	else if(senha == 3 && s == SIGUSR1) {
		printf("Tchau\n");
		exit(0);
	}
	else{
		senha = 0;
	}
}

int main() {	
	signal(SIGINT, tratasinal);
	signal(SIGTERM, tratasinal);
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);

	while(1)
		pause();
}