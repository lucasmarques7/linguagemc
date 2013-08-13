/*Faça um programa que leia uma tabela
com N códigos e nomes de profissões.
Dado o código de uma determinada
profissão, ele escreve a profissão
correspondente na tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[20];
} PROFISSAO;

main() {
	PROFISSAO profissao[50];
	int qtde_profissoes, i, codigo;

	printf("Digite a quantidade de profissoes a serem cadastradas: ");
	scanf("%d",&qtde_profissoes);

	for(i = 0; i < qtde_profissoes; i++) {
		printf("***CADASTRO PROFISSAO***\n");
		printf("***PROFISSAO %d***\n", i + 1);
		printf("Codigo: ");
		scanf("%d",&profissao[i].codigo);
		/*utilizei o getchar() com intuito de 
		substituir o fflush(stdin), ja que este
		nao funciona corretamente em ambientes
		unix.*/
		getchar();
		printf("Nome: ");
		gets(profissao[i].nome);
	}

	printf("\n");

	printf("***BUSCAR PROFISSAO***\n");
	printf("Digite o codigo da profissao que voce deseja encontrar: ");
	scanf("%d",&codigo);
	for (i = 0; i < qtde_profissoes; i++) {
		if(profissao[i].codigo == codigo) {
			puts(profissao[i].nome);
		}
	}
}