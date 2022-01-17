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
	FILE* file = NULL;
	char choice[SIZE_MAX] = { NULL };
	
	int lines = 1, read = 0, min = 0, index = 0, length = 0;

	//Compte le nombre de lignes dans le fichier biblio.txt
	file = fopen("biblio.txt", "r");
	checkfile(file);
	while (read = getc(file), read != EOF)
	{
		if (read == '\n')
			lines++;

	}
	/*printf("Nb lignes du fichier texte = %d\n", lines);*/
	fclose(file);
	
	//Genere un nombre aleatoire
	srand(time(NULL));
	index = (rand() % (lines - min + 1) + min);

	//Choisit un mot dans la biblio.txt en fonction du nombre aleatoir genere
	lines = 0;
	file = fopen("biblio.txt", "r");
	while (index != lines)
	{
		lines++;
		fgets(choice, SIZE_MAX, file);
		length = strlen(choice) - 1;
		
	}
	fclose(file);

	/*printf("Nombre genere de maniere aleatoire = %d\n", index);*/
	printf("Mot a deviner = %s\n", choice);
	printf("Index du mot a deviner = %d\n", lines);
	printf("Longueur du mot = %d\n", length);
	printf("Size of = %d\n", sizeof(choice));
	
	return 0;
}