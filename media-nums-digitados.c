/*Escreva um programa que calcula
a media de n números digitados pelo
usuário. Para a média deve ser
considerado apenas os números pares.
Escreva o resultado.*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int n, i, valor;
	float media = 0;

	printf("Quantos numeros serao digitados? ");
	scanf("%d",&n);

	for(i = 0; i < n; i++) {
		printf("Digite o valor %d: ", i + 1);
		scanf("%d",&valor);
		media = media + valor;
	}

	media = media / n;

	printf("A media dos valores informados eh: %.2f\n", media);
}