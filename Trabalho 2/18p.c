#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, *pages, frames, faults=0, *visited_pages, visited_cont=0;
	int i, j, k;

	scanf("%d", &N); /* leio quantas páginas vai ter */

	pages = (int *)malloc(sizeof(int) * N); 
	visited_pages = (int *)malloc(sizeof(int) * N);

	for(i=0; i<N; i++)
		scanf("%d" pages[i]); /* leio as páginas */

	while(scanf("%d", &frames) != EOF) /* leio quantos quadros */
	{
		for(i=0; i<N; i++) /* percorrer todo o vetor de páginas verificando se houve falta */
		{
			for(j=0; j<frames; j++) /*  */
			{
				for(k=0; k<visited_cont; k++)
				visited_pages = pages[i];
			}
		}
	}

	return 0;
}