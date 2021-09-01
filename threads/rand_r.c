#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int seed;
	printf("Put yours seed: ");
	scanf("%d", &seed);

	for(int i=0; i<3; i++)
		printf("%d\n", rand_r(&seed)%256);

	return 0;
}