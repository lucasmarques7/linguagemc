#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*estrutura para o tipo 'pessoa'*/
typedef struct{
    /*Dados pessoais*/
    char nome[200];
    char email[100];
    /*Endereço*/
    char rua[200];
    int numero;
    char complemento[100];
    char bairro[100];
    char cep[20];
    char cidade[100];
    char estado[4];
    char pais[50];
    /*Telefone*/
    char telefone[20];
    /*Data de Nascimento*/
    char dia[4];
    char mes[4];
    char ano[6];
    /*Observacao*/
    char observacao[200];
} AGENDA;

AGENDA agenda[100];
int indice = 0;

/*metodo para o programa pular quantas linhas
forem informadas no parametro do metodo*/
void pulaLinha(int qtdeLinhas){
    int i;

    for(i = 0; i < qtdeLinhas; i++) {
        printf("\n");
    }
}

/*metodo para limpar a tela*/
void limpaTela(){
    system("cls");
}

/*este metodo ordena o array em ordem alfabetica
na medida em que os dados sao inseridos. Obs.: E
utilizado o algorítimo de ordenacao Bubblesort*/
void ordemAlfabetica() {
    int i;
    int j;
    AGENDA aux[100];
    int k = indice - 1 ;

    for(i = 0; i < indice; i++) {
        for(j = 0; j < k; j++) {
            if(strcmp(agenda[j].nome, agenda[j+1].nome) > 0) {
                aux[j] = agenda[j];
                agenda[j] = agenda[j+1];
                agenda[j+1] = aux[j];
            }
        }
        k--;
    }
}

/*metodo utilizado para deixar a data
no formato dd/MM/yyyy*/
void geraData(char dia[], char mes[], char ano[]) {
    strcat(dia, "/");
    strcat(dia, mes);
    strcat(dia, "/");
    strcat(dia, ano);

    puts(dia);

    dia[0] = '\0';
    mes[0] = '\0';
    ano[0] = '\0';
}

/*metodo para salvar pessoa em um vetor de 100 posicoes*/
void salvaPessoa(){
    printf("Insira o nome: ");
    fflush(stdin); //limpa o buffer do teclado
    gets(agenda[indice].nome);

    printf("Insira o email: ");
    fflush(stdin);
    gets(agenda[indice].email);

    printf("Insira a rua: ");
    fflush(stdin);
    gets(agenda[indice].rua);

    printf("Insira o numero da residencia: ");
    fflush(stdin);
    scanf("%d",&agenda[indice].numero);

    printf("Insira o complemento (se nao existir digite 'N'): ");
    fflush(stdin);
    gets(agenda[indice].complemento);

    printf("Insira o bairro: ");
    fflush(stdin);
    gets(agenda[indice].bairro);

    printf("Insira o cep: ");
    fflush(stdin);
    gets(agenda[indice].cep);

    printf("Insira a cidade: ");
    fflush(stdin);
    gets(agenda[indice].cidade);

    printf("Insira o estado: ");
    fflush(stdin);
    gets(agenda[indice].estado);

    printf("Insira o pais: ");
    fflush(stdin);
    gets(agenda[indice].pais);

    printf("Insira o telefone: ");
    fflush(stdin);
    gets(agenda[indice].telefone);

    printf("***INSIRA A DATA DE NASCIMENTO***\n");
    fflush(stdin);
    printf("Insira o dia: ");
    fflush(stdin);
    gets(agenda[indice].dia);
    printf("Insira o mes: ");
    fflush(stdin);
    gets(agenda[indice].mes);
    printf("Insira o ano: ");
    fflush(stdin);
    gets(agenda[indice].ano);

    printf("Observacoes (se nao houver digite 'N'): ");
    fflush(stdin);
    gets(agenda[indice].observacao);

    fflush(stdin);

    indice++;

    ordemAlfabetica();
}

/*metodo realizado para remover uma pessoa
da agenda baseando-se em seu nome completo*/
void removePessoa(char nome[]) {
    int i;
    int j;

    for(i = 0; i < indice; i++) {
        if(stricmp(agenda[i].nome, nome) == 0) {
            for(j = i + 1; j < indice; j++) {
                agenda[j-1] = agenda[j];
            }
        indice--;
        } else {
            printf("Contato nao encontrado!");
        }
    }
}

/*retorna todos os contatos cadastrados*/
void imprimirTodos(char todos[]){
    int i;

    for(i = 0; i < indice; i++){
        if(stricmp(todos, "S") == 0) {
            printf("---------------------------------------------\n");
            printf("Nome: ");
            puts(agenda[i].nome);

            printf("Email: ");
            puts(agenda[i].email);

            printf("Rua: ");
            puts(agenda[i].rua);

            printf("Numero: ");
            printf("%d\n", agenda[i].numero);

            printf("Complemento: ");
            puts(agenda[i].complemento);

            printf("Bairro: ");
            puts(agenda[i].bairro);

            printf("CEP: ");
            puts(agenda[i].cep);

            printf("Cidade: ");
            puts(agenda[i].cidade);

            printf("Estado: ");
            puts(agenda[i].estado);

            printf("Pais: ");
            puts(agenda[i].pais);

            printf("Telefone: ");
            puts(agenda[i].telefone);

            printf("Data de  Nascimento: ");
            geraData(agenda[i].dia, agenda[i].mes, agenda[i].ano);

            printf("Observacao: ");
            puts(agenda[i].observacao);

            pulaLinha(1);
        } else {
            printf("---------------------------------------------\n");
            printf("Nome: ");
            puts(agenda[i].nome);

            printf("Telefone: ");
            puts(agenda[i].telefone);

            printf("Email: ");
            puts(agenda[i].email);

            pulaLinha(1);
        }
    }
}

/*este metodo retorna todos os registros
existentes utilizando o primeiro nome do
contato para realizar a busca*/
void buscaPorNome(char nome[], char todos[]){
    int i;

    for(i = 0; i < indice; i++) {
        /*se a primeira string for igual a segunda String
        a função stricmp retorna 0. Obs.: Diferente da
        função strcmp a função stricmp NAO e case-sensitive*/
        if(stricmp(agenda[i].nome, nome) == 0) {
            if(stricmp(todos, "S") == 0) {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Email: ");
                puts(agenda[i].email);

                printf("Rua: ");
                puts(agenda[i].rua);

                printf("Numero: ");
                printf("%d\n", agenda[i].numero);

                printf("Complemento: ");
                puts(agenda[i].complemento);

                printf("Bairro: ");
                puts(agenda[i].bairro);

                printf("CEP: ");
                puts(agenda[i].cep);

                printf("Cidade: ");
                puts(agenda[i].cidade);

                printf("Estado: ");
                puts(agenda[i].estado);

                printf("Pais: ");
                puts(agenda[i].pais);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Data de  Nascimento: ");
                geraData(agenda[i].dia, agenda[i].mes, agenda[i].ano);

                printf("Observacao: ");
                puts(agenda[i].observacao);

                pulaLinha(1);
            } else {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Email: ");
                puts(agenda[i].email);

                pulaLinha(1);
            }
        } else {
            printf("Contato nao encontrado!\n");
        }
    }
}

/*este metodo retorna todos os registros
existentes utilizando o mes de aniversario
do contato para realizar a busca*/
void buscaPorMes(char mes[], char todos[]){
    int i;

    for(i = 0; i < indice; i++) {
        /*se a primeira string for igual a segunda String
        a função strcmp retorna 0.*/
        if(strcmp(agenda[i].mes, mes) == 0) {
            if(stricmp(todos, "S") == 0) {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Email: ");
                puts(agenda[i].email);

                printf("Rua: ");
                puts(agenda[i].rua);

                printf("Numero: ");
                printf("%d\n", agenda[i].numero);

                printf("Complemento: ");
                puts(agenda[i].complemento);

                printf("Bairro: ");
                puts(agenda[i].bairro);

                printf("CEP: ");
                puts(agenda[i].cep);

                printf("Cidade: ");
                puts(agenda[i].cidade);

                printf("Estado: ");
                puts(agenda[i].estado);

                printf("Pais: ");
                puts(agenda[i].pais);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Data de  Nascimento: ");
                geraData(agenda[i].dia, agenda[i].mes, agenda[i].ano);

                printf("Observacao: ");
                puts(agenda[i].observacao);

                pulaLinha(1);
            } else {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Email: ");
                puts(agenda[i].email);

                pulaLinha(1);
            }
        } else {
            printf("Contato nao encontrado!\n");
        }
    }
}

/*este metodo retorna todos os registros
existentes utilizando o dia e mes de aniversario
do contato para realizar a busca*/
void buscaPorDiaEMes(char dia[], char mes[], char todos[]){
    int i;

    for(i = 0; i < indice; i++) {
        /*se a primeira string for igual a segunda String
        a função strcmp retorna 0.*/
        if(strcmp(agenda[i].dia, dia) == 0 && strcmp(agenda[i].mes, mes) == 0) {
            if(stricmp(todos, "S") == 0) {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Email: ");
                puts(agenda[i].email);

                printf("Rua: ");
                puts(agenda[i].rua);

                printf("Numero: ");
                printf("%d\n", agenda[i].numero);

                printf("Complemento: ");
                puts(agenda[i].complemento);

                printf("Bairro: ");
                puts(agenda[i].bairro);

                printf("CEP: ");
                puts(agenda[i].cep);

                printf("Cidade: ");
                puts(agenda[i].cidade);

                printf("Estado: ");
                puts(agenda[i].estado);

                printf("Pais: ");
                puts(agenda[i].pais);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Data de  Nascimento: ");
                geraData(agenda[i].dia, agenda[i].mes, agenda[i].ano);

                printf("Observacao: ");
                puts(agenda[i].observacao);

                pulaLinha(1);
            } else {
                printf("---------------------------------------------\n");
                printf("Nome: ");
                puts(agenda[i].nome);

                printf("Telefone: ");
                puts(agenda[i].telefone);

                printf("Email: ");
                puts(agenda[i].email);

                pulaLinha(1);
            }
        } else {
            printf("Contato nao encontrado!\n");
        }
    }
}

/*metodo que oferece um menu de opcoes
para a insercao, exclusao e busca de contatos
na agenda*/
void menu(){
    int opcao = 0;
    int opcaoBusca = 0;
    char nome[200];
    char dia[4];
    char mes[4];
    char todos[1];

    do{
        limpaTela();
        printf("********AGENDA********");
        pulaLinha(2);
        printf("[1] SALVAR CONTATO");
        pulaLinha(1);
        printf("[2] BUSCAR CONTATO");
        pulaLinha(1);
        printf("[3] APAGAR CONTATO");
        pulaLinha(1);
        printf("[0] SAIR");
        pulaLinha(2);
        printf("Digite uma opcao: ");
        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            limpaTela();
            printf("********SALVAR********");
            pulaLinha(2);
            salvaPessoa();
            break;
        case 2:
            do{
                limpaTela();
                printf("********BUSCAR********");
                pulaLinha(2);
                printf("[1] BUSCAR TODOS");
                pulaLinha(1);
                printf("[2] BUSCA POR NOME");
                pulaLinha(1);
                printf("[3] BUSCAR POR MES");
                pulaLinha(1);
                printf("[4] BUSCAR POR DIA E MES");
                pulaLinha(1);
                printf("[0] RETORNAR AO MENU");
                pulaLinha(2);fflush(stdin);
                printf("Digite uma opcao: ");
                scanf("%d",&opcaoBusca);

                switch(opcaoBusca){
                case 1:
                    limpaTela();
                    printf("Imprimir todos os dados? 'S' ou 'N': ");
                    fflush(stdin);
                    gets(todos);
                    limpaTela();
                    imprimirTodos(todos);
                    system("pause");
                    break;
                case 2:
                    limpaTela();
                    printf("Digite o nome da pessoa que deseja buscar: ");
                    fflush(stdin);
                    gets(nome);
                    limpaTela();
                    printf("Imprimir todos os dados? 'S' ou 'N': ");
                    fflush(stdin);
                    gets(todos);
                    limpaTela();
                    buscaPorNome(nome, todos);
                    system("pause");
                    break;
                case 3:
                    limpaTela();
                    printf("Digite o mes de aniversario da pessoa que deseja buscar: ");
                    fflush(stdin);
                    gets(mes);
                    limpaTela();
                    printf("Imprimir todos os dados? 'S' ou 'N': ");
                    fflush(stdin);
                    gets(todos);
                    limpaTela();
                    buscaPorMes(mes, todos);
                    system("pause");
                    break;
                case 4:
                    limpaTela();
                    printf("Digite o dia de aniversario da pessoa que deseja buscar: ");
                    fflush(stdin);
                    gets(dia);
                    printf("Digite o mes de aniverfflush(stdin);sario da pessoa que deseja buscar: ");
                    fflush(stdin);
                    gets(mes);
                    limpaTela();
                    printf("Imprimir todos os dados? 'S' ou 'N': ");
                    fflush(stdin);
                    gets(todos);
                    limpaTela();
                    buscaPorDiaEMes(dia, mes, todos);
                    system("pause");
                    break;
                }
            }while(opcaoBusca != 0);
            break;
        case 3:
            limpaTela();
            printf("********REMOVER********");
            pulaLinha(2);
            printf("Digite o nome completo da pessoa que deseja remover: ");
            fflush(stdin);
            gets(nome);
            removePessoa(nome);
            break;
        }
    }while(opcao != 0);
}

/*metodo de inicializacao*/
int main(){
    menu();

    return 0;
}
