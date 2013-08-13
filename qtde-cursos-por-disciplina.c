/*Declare uma estrutura que represente
os cursos de uma instituição, da seguinte
forma:
- Criar uma tabela para 20 cursos.
- Cada curso contém os seguintes
dados:
	-> Código do curso.
	-> Disciplinas.
- Podem existir 3 disciplinas para cada
curso.
- Cada disciplina possui um código e
quantidade de aulas.
Faça um programa que conte em quantos
cursos aparece uma determinada disciplina.

Obs.: Faça a leitura de 3 cursos para
testar o programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	int qtde_aulas;
	char nome[50];
} DISCIPLINA;

typedef struct {
	int codigo;
	char nome[50];
	DISCIPLINA disciplina[3];
} CURSO;

main() {
	CURSO curso[20];
	int i, j, codigo, qtde_disciplinas;

	printf("***CADASTRO CURSOS***\n");
	for(i = 0; i < 3; i++) {
		printf("***CURSO %d***\n", i + 1);
		printf("Codigo do curso: ");
		scanf("%d",&curso[i].codigo);
		getchar();
		printf("Nome do curso: ");
		gets(curso[i].nome);
		printf("***DISCIPLINAS***\n");
		for(j = 0; j < 3; j++){
			printf("***DISCIPLINA %d***\n", j + 1);
			printf("Codigo da disciplina: ");
			scanf("%d",&curso[i].disciplina[j].codigo);
			getchar();
			printf("Nome da disciplina: ");
			gets(curso[i].disciplina[j].nome);
		}
	}

	printf("\n");

	printf("***QUANTIDADE DISCIPLINAS POR CURSO***\n");
	printf("Informe o codigo da disciplina: ");
	scanf("%d",&codigo);
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(curso[i].disciplina[j].codigo == codigo) {
				qtde_disciplinas++;
			}
		}
	}

	printf("\n");

	printf("A disciplina %s aparece em %d cursos\n", curso[i].disciplina[j].nome, qtde_disciplinas);
}