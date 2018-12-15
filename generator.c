#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main (int ac, char **av)
{
	int arr[19][4] = {
		{1,6,10,11}, //J
		{0,5,6,7},
		{0,1,5,10},
		{0,1,2,7},
		{0,5,10,11}, //L
		{0,1,2,5},
		{0,1,6,11},
		{2,5,6,7},
		{0,1,5,6}, //O
		{1,2,5,6}, //S
		{0,5,6,11},
		{0,1,6,7}, //Z
		{1,5,6,10},
		{0,5,6,10}, //T
		{0,1,2,6},
		{1,5,6,11},
		{1,5,6,7},
		{0,5,10,15}, //I
		{0,1,2,3}};

	if (ac != 3)
		return 0;
	int i = atoi(av[2]);
	FILE *fd = fopen(av[1], "w+");
	time_t t;
	   
	srand((unsigned) time(&t));
	for (int j = 0; j < i; j++)
	{
		int r = rand() % 19;
		int n = 0;
		for (int k = 0; k < 20; k++)
		{
			char c;
			if (k == 4 || k == 9 || k == 14 || k == 19)
				c = '\n';
			else if (k == arr[r][n])
			{
				n = (n < 3) ? n + 1 : n;
				c = '#';
			}
			else
				c = '.';
			fputc(c, fd);
		}
		if (j + 1 != i)
			fputc('\n', fd);
	}
	fclose(fd);
}
