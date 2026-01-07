#include <stdio.h>     // Entrada e saída padrão
#include <stdlib.h>    // system(), exit()
#include <locale.h>    // setlocale()
#include <string.h>    // strcpy()

void registro() {

    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("Digite o CPF: ");
    scanf("%39s", cpf); // Limita tamanho para evitar estouro de memória

    strcpy(arquivo, cpf); // Copia CPF para o nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Cria o arquivo com o CPF
    if(file == NULL){
        printf("Erro ao criar o arquivo!\n");
        system("pause");
        return;
    }

    printf("Digite o nome: ");
    scanf("%39s", nome);
    printf("Digite o sobrenome: ");
    scanf("%39s", sobrenome);
    printf("Digite o cargo: ");
    scanf("%39s", cargo);

    // Salva todos os dados em formato CSV
    fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("\nUsuário cadastrado com sucesso!\n");
    system("pause");
}

void consulta() {

    char cpf[40], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);

    FILE *file = fopen(cpf, "r"); // Abre o arquivo
    if(file == NULL){
        printf("Usuário não encontrado!\n");
        system("pause");
        return;
    }

    fgets(conteudo, 200, file); // Lê a linha do arquivo
    printf("\nInformações do usuário:\n%s\n", conteudo);

    fclose(file);
    system("pause");
}

void deletar() {

    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%39s", cpf);

    FILE *file = fopen(cpf, "r"); // Testa se existe
    if(file == NULL){
        printf("Usuário não encontrado!\n");
        system("pause");
        return;
    }
    fclose(file);

    remove(cpf); // Apaga o arquivo
    printf("Usuário deletado com sucesso!\n");
    system("pause");
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    int laco = 1;

    while(laco == 1) {

        system("cls");

        printf("### Cartório da EBAC ###\n\n");
        printf("1 - Registrar\n");
        printf("2 - Consultar\n");
        printf("3 - Deletar\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        switch(opcao){
            case 1: registro(); break;
            case 2: consulta(); break;
            case 3: deletar(); break;
            case 0: laco = 0; break;
            default:
                printf("Opção inválida!\n");
                system("pause");
        }
    }

    return 0;
}
