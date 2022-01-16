#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SIZE_MAX 30	// taille maxi du mot


void checkfile(char check)
{
	if (check == NULL)
	{
		perror("ATTENTION, l'experience de jeu risque d'etre alteree => ");
	}
}

int main(int argc, char* argv[])
{
	
	char word2guess[SIZE_MAX]="caca";

	FILE* file = NULL;
	int lines = 1, read = 0, min = 0, index = 0;

	file = fopen("biblio.txt", "r");
	checkfile(file);

	//Compte le nombe de lignes dans le fichier et définir la taille du tableau à remplir
	while (read = getc(file), read != EOF)
	{
		if (read == '\n')
			lines++;

	}
	//printf("Nm lignes = %d\n", lines);
	fclose(file);
	
	//Generer nombre aleatoire
	srand(time(NULL));
	index = (rand() % (lines - min + 1) + min);
	//printf("index = %d\n", index);

	return 0;
}