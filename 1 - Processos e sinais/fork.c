#include <stdio.h>
#include <stdlib.h>
#include <sys/types>
#include <unistd.h>

/**
 * Criando um processo zumbi!!!!!
 */


fazoqueopaifaz() {
	/*enquanto o processo pai não pega o retorno do processo filho ele fica no estado
	 *de zumbi (não pode matar) aguardando pegar o resultado do processo filho
	*/
	printf("%d: Sou o pai\n", getpid());
	sleep(10);
	exit(0);
}

fazoqueofilhofaz() {
	printf("%d: Sou o filho, e meu pai eh: %d\n", getpid(), getppid());
	sleep(20);
	/**Para verificar o estado do processo filho quando o pai morre, basta fazer
	 * com que o processo filho não morra (exit(0)). Assim o novo pai do processo
	 * filho será o processo init/systemd
	 */
	exit(0); //encerra o programa sem retornar
	printf("Ainda vivo?\n"); //nunca será impresso e o processo pai ficará sem retorno

	/**
	 * pstree: ainda irá exibir o processo pai e processo filho
	 * ps x: o processo filho terá um comportamento diferente (<defunct>)
	*/	
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