#include <stdio.h>
#include <stdlib.h>	//exit
#include <signal.h>	//signal
#include <unistd.h> //alarm

int control = 0;

void tratasinal(int s);

int main(void) {
	signal(SIGUSR1, tratasinal);
	signal(SIGALRM, tratasinal);

	while(1)
		pause();
}

void tratasinal(int s) {
	if(s == SIGUSR1){
		printf("SIGUSR1 eh para aproveitar mais um pouco\n");
	}
	else if(control < 2) {
		printf("Ai que sono, quero dormir mais um pouco\n");
		control += 1;
	}
	else {
		printf("Os incomodados que se mudem, tchau\n");
		exit(0);
	}
}