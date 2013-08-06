/*Escreva um programa que lê números
digitados pelo usuário (a leitura
deve ser finalizada quando o usuário
digitar 0) e encontre e mostre o maior
e o menor valor digitados (desconsidere
o valor 0).*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int valor, maior = 0, menor = 0;

	while(valor != 0) {
		printf("Digite um numero inteiro: ");
		scanf("%d",&valor);

		if(valor > maior) {
			maior = valor;
		} else if(valor < menor){
			menor = valor;
		}
	}

	printf("O maior valor digitado foi: %d\n", maior);
	printf("O menor valor digitado foi: %d\n", menor);
}