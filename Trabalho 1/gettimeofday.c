#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(void)
{
	struct timeval start, end;
	int seconds, micros;

	gettimeofday(&start, NULL);

	sleep(1.5);

	gettimeofday(&end, NULL);

	seconds = (end.tv_sec - start.tv_sec);
	//micros  = ((seconds * 1000000)+end.tv_usec) - (start.tv_usec);
	micros  = ((end.tv_usec/1000) - (start.tv_usec)/1000);

	/* search how to convert to exactly time passed on sleep function call */
	printf("The elapsed time is %d seconds and %d micros\n", seconds, micros);

	return 0;
}