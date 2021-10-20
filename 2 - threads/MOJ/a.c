#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int v1[10000000];
int v2[10000000];

struct thread_st 
{
	int *v; 
	int size;
	pthread_t tid;
};

struct thread_compar
{
	int ini;
	int fim;
	pthread_t tid;
	int result;
};

int compar(const void *a, const void *b) 
{
	if(*(int*)a > *(int*)b)
		return 1;
	if(*(int*)a < *(int*)b)
		return -1;
	return 0;
}

void *threadfunc(void *p) 
{
	struct thread_st *a = (struct thread_st*)p;
	qsort(a->v, a->size, sizeof(int), compar);
}

void *threadcompar(void *p)
{
	struct thread_compar *a=(struct thread_compar*)p;
	for(int i=a->ini; i<a->fim; i++)
	{
		if(v1[i] != v2[i])
		{
			a->result = 0;
			return NULL;
		}
	}
	a->result = 1;
}

int main()
{
	int tv1, tv2;
	scanf("%d", &tv1);
	tv2 = tv1;

	//v1 = malloc(sizeof(int)*tv1);
	//v2 = malloc(sizeof(int)*tv2);

	for(int i=0; i<tv1; i++)
		scanf("%d", &v1[i]);

	for(int i=0; i<tv2; i++)
		scanf("%d", &v2[i]);

	struct thread_st t1, t2;

	t1.v = v1;
	t1.size = tv1;
	t2.v = v2;
	t2.size = tv2;

	pthread_create(&t1.tid, NULL, threadfunc, (void*)&t1);
	pthread_create(&t2.tid, NULL, threadfunc, (void*)&t2);
	pthread_join(t1.tid, NULL);
	pthread_join(t2.tid, NULL);

	struct thread_compar ct1, ct2;
	ct1.ini = 0;
	ct1.fim = tv1/2;
	ct2.ini = tv1/2;
	ct2.fim = tv1;

	pthread_create(&ct1.tid, NULL, threadcompar, (void*)&ct1);
	pthread_create(&ct2.tid, NULL, threadcompar, (void*)&ct2);
	pthread_join(ct1.tid, NULL);
	pthread_join(ct2.tid, NULL);

	if(ct1.result == 1 &&ct2.result == 1)
		printf("Mesmos elementos\n");
	else
		printf("Diferentes\n");

	return 0;
}
