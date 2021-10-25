#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int vet1[] = {1, 2, 3, 4, 5};
	int i, j, tam=5;

	/* compara matriz triangular inferior */
	for(i=0; i<tam; i++)
		for(j=0; j<tam; j++)
			if(i<j)
				printf("[COMPARA] %d, %d\n", vet1[i], vet1[j]);

	return 0;
}