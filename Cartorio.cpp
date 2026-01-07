#include <stdio.h>     // Entrada e saída padrão
#include <stdlib.h>    // system(), exit()
#include <locale.h>    // setlocale()
#include <string.h>    // strcpy()

int repetir() {
    int op;
    printf("\n1 - Fazer novamente\n");
    printf("0 - Voltar ao menu\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

void registro() {

    int opcao;

    do {
        char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

        system("cls");

        printf("Digite o CPF: ");
        scanf("%39s", cpf);

        strcpy(arquivo, cpf);

        FILE *file = fopen(arquivo, "w");
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

        fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
        fclose(file);

        printf("\nUsuário cadastrado com sucesso!\n");

        opcao = repetir();

    } while(opcao == 1);
}

void consulta() {

    int opcao;

    do {
        char cpf[40], conteudo[200];

        system("cls");

        printf("Digite o CPF a ser consultado: ");
        scanf("%39s", cpf);

        FILE *file = fopen(cpf, "r");
        if(file == NULL){
            printf("Usuário não encontrado!\n");
            opcao = repetir();
            continue;
        }

        fgets(conteudo, 200, file);
        printf("\nInformações do usuário:\n%s\n", conteudo);
        fclose(file);

        opcao = repetir();

    } while(opcao == 1);
}

void deletar() {

    int opcao;

    do {
        char cpf[40];

        system("cls");

        printf("Digite o CPF a ser deletado: ");
        scanf("%39s", cpf);

        FILE *file = fopen(cpf, "r");
        if(file == NULL){
            printf("Usuário não encontrado!\n");
            opcao = repetir();
            continue;
        }
        fclose(file);

        remove(cpf);
        printf("Usuário deletado com sucesso!\n");

        opcao = repetir();

    } while(opcao == 1);
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
