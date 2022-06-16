#include "Gestion_jeu.h"

int taille_echiquier()
{
	int taille = 0;
	printf("Veuillez inserer un chiffre pair de 2 a 10 pour la taille de l'echiquier");
	scanf("%d", &taille);

	int isnan(taille);
	//std::cout << isnan(taille) << std::endl;
	while ((!isnan) || (taille > 10) || (taille < 2) || (taille % 2 )==1)
	{
		printf("Veuillez inserer un chiffre pair de 2 a 10 pour la taille de l'echiquier");
		scanf("%d", &taille);
	}

	/*while ((taille > 10) || (taille < 2))
	{
		if (isnan(taille))
		{
			printf("Taille non valide, veuillez inserer un chiffre pair entre 2 et 10 ");
			
		}
		printf("Taille non valide, veuillez inserer un chiffre pair entre 2 et 10 ");
		scanf("%d", &taille);
	}*/
	printf("la taille selectionne est %d\n", taille);
	return taille;
}
