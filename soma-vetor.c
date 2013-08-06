/*Faça um programa que lê um vetor
de 20 posições de números inteiros
e some todos os elementos com a média
dos valores do vetor. Mostre o vetor
após os cálculos.*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int vet[20];
	int vet_final[20];
	int i, media = 0;

	for(i = 0; i < 20; i++) {
		printf("Digite o %d.o valor: ", i +1);
		scanf("%d",&vet[i]);

		media = media + vet[i];
	}

	media = media / 20;

	for(i = 0; i < 20; i++) {
		vet_final[i] = vet[i] + media; 
	}

	printf("Media: %d", media);

	printf("\n");

	printf("Vetor inicial: ");
	for(i = 0; i < 20; i++) {
		printf("|%d|", vet[i]);
	}

	printf("\n");

	printf("Vetor final: ");
	for(i = 0; i < 20; i++) {
		printf("|%d|", vet_final[i]);
	}

	printf("\n");
}