#include <stdio.h>
#include <stdlib.h>

int** retireProduit(int** Produit, int* taille, int prod, int quant) {
    int j;

    for (j = 0; j < *taille; j++) {
        if (Produit[0][j] == prod) {
            if (Produit[1][j] >= quant) {
                Produit[1][j] -= quant;
                return Produit;
            } else {
                printf("Pas de quantite suffisante pour retirer.\n");
                return Produit;
            }
        }
    }

    printf("Produit non trouve.\n");
    return Produit;
}

int** inserProduit(int** Produit, int* taille, int code, int quantite) {
    int j;

    for (j = 0; j < *taille; j++) {
        if (Produit[0][j] == code) {
            printf("Le produit existe.\n");
            Produit[1][j] += quantite;
            return Produit;
        }
    }

    Produit[0] = (int*)realloc(Produit[0], (*taille + 1) * sizeof(int));
    Produit[1] = (int*)realloc(Produit[1], (*taille + 1) * sizeof(int));

    Produit[0][*taille] = code;
    Produit[1][*taille] = quantite;

    (*taille)++;

    return Produit;
}

int main() {
    int** Produit;
    int taille = 4;
    int i, j;
    int code;
    int quantite;
    int prod;
    int quant;
    int choix;

    Produit = (int**)malloc(2 * sizeof(int*));
    Produit[0] = (int*)malloc(taille * sizeof(int));
    Produit[1] = (int*)malloc(taille * sizeof(int));

    Produit[0][0] = 1;
    Produit[0][1] = 2;
    Produit[0][2] = 3;
    Produit[0][3] = 4;
    Produit[1][0] = 123;
    Produit[1][1] = 453;
    Produit[1][2] = 324;
    Produit[1][3] = 1234;

printf("choix : \n");
printf("---------\n");
printf("####### 1 inserer un produit ##########\n");
printf("------------------------------------------\n");
printf("####### 2  reterer un produit ##########\n");
printf("------------------------------------------\n");
printf("####### 3 afficher les  produit ##########\n");
printf("------------------------------------------\n");
printf("####### 4 exit ###########################\n");
printf("------------------------------------------\n");
do{
printf("prenez un choix dans la menu  : ");
scanf("%d",&choix);

if(choix>0 && choix<=4){

	switch(choix){
		case 1 :
		 printf("Entrez le code du produit a inserer :\n");
        scanf("%d", &code);
        printf("Entrez la quantite du produit a inserer :\n");
    scanf("%d", &quantite);
    Produit = inserProduit(Produit, &taille, code, quantite);
    break;
    case 2 :
    	printf("Entrez le code du produit a retirer :\n");
        scanf("%d", &prod);
        printf("Entrez la quantite du produit a retirer :\n");
        scanf("%d", &quant);
        Produit = retireProduit(Produit, &taille, prod, quant);
        break;
        case 3:
        	    for (i = 0; i < 2; i++) {
                     for (j = 0; j < taille; j++)
                       printf("%d \t", Produit[i][j]);
                printf("\n");
        	    }
                break;
        case 4:
        	exit(0);
    }
	}
}while(choix !=4);

    free(Produit[0]);
    free(Produit[1]);
    free(Produit);

    return 0;
}

