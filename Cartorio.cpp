#include <stdio.h>   // Biblioteca para entrada e saída (printf, scanf)
#include <stdlib.h>  // Biblioteca para system(), remove(), exit()
#include <locale.h>  // Biblioteca para setlocale()
#include <string.h>  // Biblioteca para strcpy(), strcmp(), sscanf()

// Função que pergunta se o usuário quer repetir a operação
int repetir() {
    int op;
    printf("\n1 - Fazer novamente\n");
    printf("0 - Voltar ao menu\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op; // Retorna a opção escolhida
}

// Função para registrar um novo usuário
void registro() {
    int opcao;

    do {
        char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

        system("cls"); // Limpa a tela

        printf("Digite o CPF: ");
        scanf("%39s", cpf);

        strcpy(arquivo, cpf); // Usa o CPF como nome do arquivo

        FILE *file = fopen(arquivo, "w"); // Cria o arquivo
        if(file == NULL){
            printf("Erro ao criar o arquivo!\n");
            system("pause");
            return;
        }

        // Coleta os dados
        printf("Digite o nome: ");
        scanf("%39s", nome);
        printf("Digite o sobrenome: ");
        scanf("%39s", sobrenome);
        printf("Digite o cargo: ");
        scanf("%39s", cargo);

        // Grava os dados no arquivo separados por vírgula
        fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
        fclose(file);

        printf("\nUsuário cadastrado com sucesso!\n");

        opcao = repetir(); // Pergunta se quer cadastrar outro

    } while(opcao == 1);
}

// Função para consultar um usuário
void consulta() {
    int opcao;

    do {
        char cpf[40], linha[200];
        char cpfLido[40], nome[40], sobrenome[40], cargo[40];

        system("cls");

        printf("Digite o CPF a ser consultado: ");
        scanf("%39s", cpf);

        FILE *file = fopen(cpf, "r"); // Abre o arquivo para leitura
        if(file == NULL){
            printf("Usuário não encontrado!\n");
            opcao = repetir();
            continue;
        }

        fgets(linha, 200, file); // Lê a linha do arquivo
        fclose(file);

        // Separa os dados usando a vírgula como delimitador
        sscanf(linha, "%[^,],%[^,],%[^,],%s", cpfLido, nome, sobrenome, cargo);

        // Exibe os dados formatados
        printf("\n===== DADOS DO USUÁRIO =====\n");
        printf("CPF: %s\n", cpfLido);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
        printf("Cargo: %s\n", cargo);

        opcao = repetir();

    } while(opcao == 1);
}

// Função para deletar um usuário
void deletar() {
    int opcao;

    do {
        char cpf[40];

        system("cls");

        printf("Digite o CPF a ser deletado: ");
        scanf("%39s", cpf);

        FILE *file = fopen(cpf, "r"); // Verifica se o arquivo existe
        if(file == NULL){
            printf("Usuário não encontrado!\n");
            opcao = repetir();
            continue;
        }
        fclose(file);

        remove(cpf); // Remove o arquivo
        printf("Usuário deletado com sucesso!\n");

        opcao = repetir();

    } while(opcao == 1);
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese"); // Define idioma português

    char senha[20];

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador\n");
    printf("Digite a senha: ");
    scanf("%19s", senha);

    // Verifica se a senha está correta
    if(strcmp(senha, "admin") == 0) {

        int opcao = 0;
        int laco = 1;

        while(laco == 1) {
            system("cls");

            printf("### Cartório da EBAC ###\n\n");
            printf("1 - Registrar\n");
            printf("2 - Consultar\n");
            printf("3 - Deletar\n");
            printf("4 - Sair\n\n");
            printf("Opcao: ");
            scanf("%d", &opcao);

            // Decide o que fazer com base na opção
            switch(opcao){
                case 1: registro(); break;
                case 2: consulta(); break;
                case 3: deletar(); break;
                case 4: laco = 0; break;
                default:
                    printf("Opção inválida!\n");
                    system("pause");
            }
        }

    } else {
        printf("\nSenha incorreta!\n");
        system("pause");
    }

    return 0; // Encerra o programa
}
