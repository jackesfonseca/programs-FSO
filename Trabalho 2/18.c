#include <stdio.h>
#include <stdlib.h>

int page_fault(int frame_size, int *ref, int len);

int main(void)
{
    int *ref;
    int len, frame_size, i, flag=0, belady=0;
    int first_frame_size, first_page_fault;
    int second_frame_size, second_page_fault;

    scanf("%d", &len);
    ref = malloc(sizeof(int) * len);

    for(i=0; i<len; i++)
    	scanf("%d", &ref[i]);

    while(scanf("%d", &frame_size) != EOF)
    {
    	if(flag == 0)
    	{
    		first_frame_size = frame_size;
    		first_page_fault = page_fault(frame_size, ref, len);

    		printf("%d %d\n", frame_size, first_page_fault);
    	}

    	else
    	{
    		second_frame_size = first_frame_size;
    		second_page_fault = first_page_fault;
    		first_frame_size = frame_size;
    		first_page_fault = page_fault(frame_size, ref, len);

    		printf("%d %d\n", frame_size, first_page_fault);

    		if(first_frame_size > second_frame_size)
    		{
    			if(first_page_fault > second_page_fault)
    				belady = 1;
    		}
    	}

    	flag=1;
    }

    if(belady == 1)
    	printf("Belady detectado\n");

    else
    	printf("Sem anomalia\n");

	return 0;
}

int page_fault(int frame_size, int *ref, int len)
{
	int *arr, i;
	int cont = 0;
    int start = 0;
    int flag;
    int elem;

	arr = malloc(sizeof(int) * frame_size);

	// To initialize the array
    for (i = 0; i < frame_size; i++) 
    {
        arr[i] = -1;
    }

    for (int i = 0; i < len; i++) {
        elem = ref[i];
        
        flag = 0;
        for (int j = 0; j < frame_size; j++) {
            if (elem == arr[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (start < frame_size) {
                arr[start] = elem;
                start++;
            }
            else if (start == frame_size) {
                arr[0] = elem;
                start = 1;
            }
            cont++;
        }
    }

    return cont;
}