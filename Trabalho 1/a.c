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
	struct timeval tv;
	
	gettimeofday(&tv, NULL);

	printf("Seconds: %ld\nMicroseconds: %ld\n", tv.tv_sec, tv.tv_usec);
	
	return 0;
}

