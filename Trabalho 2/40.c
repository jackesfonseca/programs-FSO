#include <stdio.h>
#include <stdlib.h>

int file_compare(FILE *file1, FILE *file2);

int main(int argc, char **argv)
{
	FILE *file1, *file2;
	int i=0;

	for(i=0; i<argc; i+=2) /* 0, 2, 4, 6, 8, ... */
	{
		file1 = fopen(argv[i], "r");
		file2 = fopen(argv[i+1], "r");

		if(file_compare(file1, file2))
			printf("%s %s iguais\n", argv[i], argv[i+1]);

		else
			printf("%s %s diferentes\n", argv[i], argv[i+1]);

		fclose(file1);
		fclose(file2);
	}

	return 0;
}

int file_compare(FILE *file1, FILE *file2)
{
	/* 
		0 - false
		1 - true
	*/
	int file1byte, file2byte;

	do
	{
		file1byte = file1->ReadByte();
		file2byte = file2->ReadByte();
	}while((file1byte == file2byte) && (file1byte != -1));

	return ((file1byte - file2byte) == 0);
}