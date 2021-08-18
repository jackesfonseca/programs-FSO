#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int compare_data(const void *a, const void *b) {
	printf("Compara...\n");
	return *((int *)a) - *((int *)b);
}

void *sort_data(void *vet) {
	printf("Thread...\n");
	qsort((int *)vet, sizeof((int *)vet)/sizeof(int), sizeof(int), compare_data);
}

int main(void) {

	pthread_t threads[2];
	int len, i;
	int *vet1, *vet2;

	scanf("%d", &len);

	vet1 = malloc(sizeof(int)*len);
	vet2 = malloc(sizeof(int)*len);

	//get first vector data 
	for(i=0; i<len; i++)
		scanf("%d", &vet1[i]);

	pthread_create(&threads[0], NULL, &sort_data, (void *)vet1);

	pthread_join(threads[0], NULL);

	//get second vector data
	for(i=0; i<len; i++)
		scanf("%d", &vet2[i]);

	pthread_create(&threads[1], NULL, &sort_data, (void *)vet2);

	pthread_join(threads[1], NULL);

	for(i=0; i<len; i++)
		printf("%d", vet2[i]);
	if(i != len-1)
		printf(" ");

	printf("\n");
}