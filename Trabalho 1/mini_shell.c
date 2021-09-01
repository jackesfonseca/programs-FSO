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
	int seconds, micros, seconds_final, micros_final, ret;
	struct timeval start, end, start_final, end_final;
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

			/* calculate command execution time in seconds and micros */
			seconds = (end.tv_sec - start.tv_sec);
			micros  = ((end.tv_usec/1000) - (start.tv_usec)/1000);
		}

		/* get child process status */
		child_process = wait(&ret);

		/* print result*/
		printf("> Demorou %d.%d segundos retornou %d\n", seconds, micros, ret);
	}

	/* get final end time*/
	gettimeofday(&end_final, NULL);

	/* calculate final execution time in seconds and micros */
	seconds = (end_final.tv_sec - start_final.tv_sec);
	micros  = ((end_final.tv_usec/1000) - (start_final.tv_usec)/1000);

	/* print result */
	printf(">> O tempo total foi de %d.%d segundos\n", seconds_final, micros_final);

	return 0;
}

