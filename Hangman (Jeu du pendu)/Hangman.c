#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SIZE_MAX 20	// taille maxi du mot

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
	char choice[SIZE_MAX] = { NULL }, word[SIZE_MAX] = { NULL }, letter[SIZE_MAX] = { NULL };
	int lines = 1, read = 0, min = 0, index = 0, length = 0, i = 0;

	//Compte le nombre de lignes dans le fichier biblio.txt
	/*
	file = fopen("biblio.txt", "r");
	checkfile(file);
	while (read = getc(file), read != EOF)
	{
		if (read == '\n')
			lines++;

	}
	fclose(file);
	*/
	//Genere un nombre aleatoire
	/*srand(time(NULL));
	index = (rand() % (lines - min + 1) + min);
	*/
	//Choisit un mot dans la biblio.txt en fonction du nombre aleatoire genere
	/*
	lines = 0;
	file = fopen("biblio.txt", "r");
	while (index != lines)
	{
		lines++;
		fgets(choice, SIZE_MAX, file);
	}
	fclose(file);
	length = strlen(choice)-1; // Nb de caracteres dans le mot
	
	printf("Mot choisi = %s\n", choice);
	printf("Index du mot choisi = %d\n", lines);
	printf("Longueur du mot = %d\n", length);
	*/
	//Affichage des regles
	/*printf("===== JEU DU PENDU =====\n\n");
	printf("Le jeu du Pendu est un jeu tres connu dans lequel vous devez devener le mot choisi par la machine\n");
	printf("Vous avez 9 essais pour essayer de deviner le mot.\n");
	printf("Vous devez choisir une lettre dans l'alphabet.\n");
	printf("Si cette lettre est presente dans le mot à devenir, alors les blancs (tirets) se rempliront.\n");
	printf("Petit a petit, vous verrez apparaitre le mot.\n");
	printf("Le but est de deviner le mot complet.\n\n");
	printf("Attention les accents ne sont pas permis, ni les majuscules.\n\n");
	printf("=== A vous de jouer !===\n\n");*/
	//Affichage du mot de départ
	/*printf("Le mot a deviner est le suivant.\nIl contient %d lettres :\n-> ", length);
	for (int i = 0; i < length; i++)
	{
		word[i] = '_';
		printf(" %c", word[i]);
	}
	*/

	//Draft NOOK
	char testV[20] = {'f','i','l','m','\n'};
	char testW[20] = {NULL};
	int v = 0, w = 0, longueur = 4;
	do
	{
		printf("Tentative = %d\n", v);
		printf("Tape une lettre = ");
		scanf("%c", &testW[v]);
		if (testV[v] == testW[v])
		{
			w++;
			printf("\nNb de lettre trouvee=%d\n", w);
		}
		v++;
		printf("---NOOK---");
	} while (v < 10 && w != 4);
	
	return 0;
}