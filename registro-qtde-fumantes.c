/*Faça um programa que utilize o seguinte
registro:

typedef struct {
	int passagem, num_poltrona;
	float dist;
	char fumante;
	char origem[20], destino[20];
} REGPASSAGEM;

REGPASSAGEM onibus[40];

O programa deve ler os dados de
5 passageiros, contar quantos são
fumantes e escrever esta informação
na tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int passagem, num_poltrona;
	float dist;
	char fumante;
	char origem[20], destino[20];
} REGPASSAGEM;

main() {
	REGPASSAGEM onibus[40];
	int i, num_fumantes;

	printf("***CADASTRO DE PASSAGEIROS***\n");
	for(i = 0; i < 5; i++) {
		printf("***PASSAGEIRO %d***\n", i + 1);
		printf("Passagem: ");
		scanf("%d",&onibus[i].passagem);
		printf("Numero Poltrona: ");
		scanf("%d",&onibus[i].num_poltrona);
		printf("Distancia: ");
		scanf("%f",&onibus[i].dist);
		printf("Fumante (S/N): ");		
		scanf("%c",&onibus[i].fumante);
		printf("Origem: ");
		fflush(stdin);
		gets(onibus[i].origem);
		printf("Destino: ");
		fflush(stdin);
		gets(onibus[i].destino);
	}

	for(i = 0; i < 5; i++) {
		if(onibus[i].fumante == 'S') {
			num_fumantes++;
		}
	}

	printf("O numero de passageiros fumantes eh: %d\n", num_fumantes);
}