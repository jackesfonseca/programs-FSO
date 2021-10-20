#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int exit_son = 0;

void tratasinal(int s) {
	exit_son = s;
}

int main(void) {
	signal(SIGUSR1, tratasinal);
	signal(SIGUSR2, tratasinal);

	pause(); //recebe sinal
	if(fork() == 0) //cria processo zumbi
		exit(0);
	pause(); //recebe sinal
	wait(NULL); //matando o processo zumbi
	pause(); //recebe sinal
	exit(0); //encerra o programa
}