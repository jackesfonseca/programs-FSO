#include <stdio.h>
#include <stdilib.h>
#include <sys/types>
#include <sys/wait>
#include <unistd.h>

fazoqueopaifaz() {
	printf("%d: Sou o pai\n", getpid());
	wait(); //é necessário um wai para cada filho
	printf("Filho terminou, tambem vou\n");
	exit(0);
}

fazoqueopaifaz() {
	printf("%d: Sou o filho, e meu pai eh: %d\n", getpid(), getppid());
	sleep(10);
}

int main() {

	pid_t p; 
	p = fork(); //precisa do sys/types e unistd

	if(p > 0)
		fazoqueopaifaz();
	else if(p == 0) 
		fazoqueofilhofaz();
	else
		printf("Fork falhou!\n");

	sleep(50);
}