#include <stdio.h>
#include <stdlib.h>

int file_compare(FILE *file1, FILE *file2);

int main(int argc, char **argv)
{
	FILE *file1, *file2;
	int i,j;

	for(i=1; i<argc; i++)
	{
		file1 = fopen(argv[i], "r");

		for(j=1; j<argc; j++)
		{
			if(i<j) /* compare elements just once */
			{
				file2 = fopen(argv[j], "r");

				if(file_compare(file1, file2))
					printf("%s %s iguais\n", argv[i], argv[j]);

				else
					printf("%s %s diferentes\n", argv[i], argv[j]);

				fclose(file2);
			}
		}
		fclose(file1);
	}

	return 0;
}

int file_compare(FILE *file1, FILE *file2)
{
	char text1, text2;
	long filebyte1, filebyte2;
	int i;

	fseek(file1, 0, SEEK_END);
	fseek(file2, 0, SEEK_END);

	filebyte1 = ftell(file1);
	filebyte2 = ftell(file2);

	if(filebyte1 != filebyte2)
		return 0; /* false */

	for(i=0; i<filebyte1; i++)
	{
		fread(&text1, filebyte1, 1, file1);
		fread(&text2, filebyte2, 1, file2);
		printf("%d: tmp1 %x != tmp2 %x\n", i, text1, text2);
		if(text1 != text2)
			return 0; /* false */
	}

	return 1; /* true */
}