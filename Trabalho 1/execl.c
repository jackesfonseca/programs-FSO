#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("I'm a test about to turn a LS command\n");
	if(fork() == 0)
		execl("/bin/ls", "ls", NULL);
	sleep(15);

	pid_t child_process;
	int ret;
	child_process = wait(&ret);
	printf("The LS command ended, had PID %d and returned %d\n", child_process, ret);

	return 0;
}