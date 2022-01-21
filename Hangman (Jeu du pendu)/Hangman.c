#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SIZE_MAX 20	// taille maxi du mot

void checkfile(char check) //Fonction vérif de fichier
{
	if (check == NULL)
	{
		perror("ATTENTION, Erreur dans le fichier contenant les mots =>  ");
	}
}


char reading() //Fonction lire caractere
{
	char carac = 0;
	carac = getchar(); //On lit le caractère
	while(getchar() != '\n'); //Lecture du caractère jusqu'au saut de ligne
	return carac; // on retourne le caractere lu 
}

void initTab(int* letter, int length)
{
	for (int i = 0; i < length; i++)
	{
		letter[i] = 0;
	}
}

int research(char carac, char choice[], int* letter)
{
	int i = 0;
	int good= 1;
	//On parcour le mot pour checker
	for (i = 0; choice[i] != '\0'; i++)
	{
		if (carac == choice[i])
		{
			good = 1;
			letter[i] = 1;
		}
	}
}

int gameover(int* letter, int length)
{
	int win = 1;
	for (int i = 0; i < length; i++)
	{
		if (letter[i] == 0)
			win = 0;
	}
	return win;
}

int main(int argc, char* argv[])
{
	FILE* file = NULL;
	char choice[SIZE_MAX] = "rouge", carac = 0;
	int lines = 1, read = 0, min = 0, index = 0, length = 0, remain = 10;
	int *letter = NULL; // Tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée

	//Code pour aller chercher dans un fichier texte => lecture de la chaine ne marche pas
	/*//Compte le nombre de lignes dans le fichier biblio.txt
	file = fopen("biblio.txt", "r");
	checkfile(file);
	while (read = getc(file), read != EOF)
	{
		if (read == '\n')
			lines++;

	}
	fclose(file);
	
	//Genere un nombre aleatoire
	srand(time(NULL));
	index = (rand() % (lines - min + 1) + min);
	
	//Choisit un mot dans la biblio.txt en fonction du nombre aleatoire genere
	lines = 0;
	file = fopen("biblio.txt", "r");
	while (index != lines)
	{
		lines++;
		fgets(choice, SIZE_MAX, file);
	}
	fclose(file);
	length = strlen(choice)-1; // Nb de caracteres dans le mot
	
	//Affiche le mot choisi
	printf("Mot choisi = %s\n", choice);
	printf("Index du mot choisi = %d\n", lines);
	printf("Longueur du mot = %d\n", length);
	*/
	//Affichage des regles
	/*printf("===== JEU DU PENDU =====\n\n"
	"Le jeu du Pendu est un jeu tres connu dans lequel vous devez devener le mot choisi par la machine\n"
	"Vous avez 9 essais pour essayer de deviner le mot.\n"
	"Vous devez choisir une lettre dans l'alphabet.\n"
	"Si cette lettre est presente dans le mot à devenir, alors les blancs (tirets) se rempliront.\n"
	"Petit a petit, vous verrez apparaitre le mot.\n"
	"Le but est de deviner le mot complet.\n\n"
	"Attention les accents ne sont pas permis, ni les majuscules.\n\n"
	"=== A vous de jouer !===\n");
	*/

	length = strlen(choice);

	//Initialisation tableau
	letter = malloc(length * sizeof(int));
	initTab(letter, length);
	while (remain > 0 && !gameover(letter, length))
	{


		printf("\nIl vous reste encore %d pour trouver le mot", remain);
		printf("\nLe mot a trouver est le suivant :\n==> ");

		//On affiche le mot secret en masquant les lettres non trouvées
		for (int i = 0; i < length; i++)
		{
			if (letter[i])
				printf("%c ", choice[i]);
			else
				printf("_ ");
		}

		printf("\n\nQuelle lettre proposes-tu ? ");
		carac = reading();

		if (!research(carac, choice, letter))
			remain--;
		else
			printf("\nCette lettre n'est pas le mot a deviner.");
	}
	if (gameover(letter, length))
		printf("\n\n --- C'EST GAGNE --- Le mot etait bien : %s\n", choice);
	else
		printf("\n\n Dommage, le mot a devine etait : %s\n", choice);
	
	free(letter);
	return 0;
}

