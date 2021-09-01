#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h> // probably not used
#include <unistd.h>
#include <errno.h>

int main()
{
	struct timeval start, end, start_final, end_final;
	double program_time, command_time;
	int ret;
	pid_t child_process;
	char *arg0, *arg1, *path, *path_copy;

	/* dynamic memory allocation */
	arg0 = (char *)malloc(sizeof(char) * 255);
	arg1 = (char *)malloc(sizeof(char) * 255);
	path = (char *)malloc(sizeof(char) * 255);
	path_copy = (char *)malloc(sizeof(char) * 255);

	/* get final start time */
	gettimeofday(&start_final, NULL);
	
	/* execute 'til the end of file' */
	while(scanf("%s %s", path, arg1) != EOF)
	{
		/* create a copy of path string */
		strcpy(path_copy, path);

		/* split string path and get command to arg0 */
		arg0 = strtok(path_copy, "/");
		arg0 = strtok(NULL, "/");

		

		/* if it's a child process */
		if(fork() == 0)
		{
			/* get command start time */
			gettimeofday(&start, NULL);

			/* execute command */
			execl(path, arg0, arg1, NULL);

			/* command end time */
			gettimeofday(&end, NULL);

		}

		/* calculate command execution time in seconds and micros */
		command_time = end.tv_sec + end.tv_usec/1000000 - start.tv_sec + start.tv_usec/1000000;

		/* get child process status */
		child_process = wait(&ret);

		/* print result*/
		printf("> Demorou %.1lf segundos retornou %d\n", command_time, WEXITSTATUS(ret));
	}

	/* calculate final execution time in seconds and micros */
	program_time = end_final.tv_sec + end_final.tv_usec/1000000 
							- start_final.tv_sec + start_final.tv_usec/1000000;

	/* print result */
	printf(">> O tempo total foi de %.1lf segundos\n", program_time);

	return 0;
}

