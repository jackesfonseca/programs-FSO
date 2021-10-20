#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void trata(int s) {
	int r;
	char string[11];

	//o espaço em branco antes do % faz com que a função scanf processe todos os caracteres de espaço
	if(scanf(" %s", string) != 1) // r != EOF
		exit(0);

	if(s == SIGUSR1 && string[3] == 'r') {
		printf("Certo\n");
	}
	else if(s == SIGUSR2 && string[3] == 'a') {
		printf("Certo\n");
	}
	else if(s == SIGINT && string[3] == '1') {
		printf("Certo\n");
	}
	else if(s == SIGTERM && string[3] == '2') {
		printf("Certo\n");
	}
	else if(s == SIGALRM && string[3] == 'e') {
		printf("Certo\n");
	}
	else {
		printf("Erro\n");
	}

}


int main(void) {
	signal(SIGTERM, trata);
	signal(SIGUSR1, trata);
	signal(SIGUSR2, trata);
	signal(SIGINT, trata);
	signal(SIGALRM, trata);

	while(1)
		pause();
}