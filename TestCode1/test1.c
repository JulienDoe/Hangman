#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//Draft NOOK
	int testV[20] = {1,2,3,4,5};
	char testW[20] = { 0 };
	int v = 0, w = 0, longueur = 4;
	do
	{
		printf("\nBoucle =%d\n", v);
		printf("Tape un chiffre = ");
		scanf("%d", &testW[v]);
		if (testV[v] == testW[v])
		{
			w++;
			printf("\nw =%d", w);
		}
		else
		{
			printf("\nv=%d",v);
		}
		v++;
	} while (w < 4 || v < 10);
	
	return 0;
}