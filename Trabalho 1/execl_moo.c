#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid; 
	int ret;
	
	pid = fork();

	/* child */
	if(pid == 0)
	{
		execl("/bin/apt-get", "apt-get", "moo", NULL);
		perror("execl");
		return EXIT_FAILURE;
	}

	pid_t child_process = wait(&ret);
	printf("The LS command ended, had PID %d and returned %d\n", child_process, ret);

	return 0;
}