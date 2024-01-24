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

    printf("Entrez le code du produit a inserer :\n");
    scanf("%d", &code);
    printf("Entrez la quantite du produit a inserer :\n");
    scanf("%d", &quantite);
    printf("Entrez le code du produit a retirer :\n");
    scanf("%d", &prod);
    printf("Entrez la quantite du produit a retirer :\n");
    scanf("%d", &quant);

    Produit = inserProduit(Produit, &taille, code, quantite);
    Produit = retireProduit(Produit, &taille, prod, quant);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < taille; j++)
            printf("%d \t", Produit[i][j]);
        printf("\n");
    }

    free(Produit[0]);
    free(Produit[1]);
    free(Produit);

    return 0;
}
