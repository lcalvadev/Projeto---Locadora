#include <stdio.h>

#define MAX_VEICULOS 50
#define MAX_CLIENTES 50

struct Cliente {
    char nome[50];
    char cpf[15];
};

struct Veiculo {
    char modelo[30];
    char placa[10];
    int alugado;
    float diaria;
};

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    struct Veiculo veiculos[MAX_VEICULOS];
    int quantidadeClientes = 0;
    int quantidadeVeiculos = 0;
    int opcao;
    int clienteEscolhido;
    int veiculoEscolhido;
    int escolha;
    int dias;

    printf("  +====================================+\n");
    printf("  |      CADASTRO INICIAL DO CLIENTE   |\n");
    printf("  +====================================+\n\n");

    printf("Digite o nome do cliente: ");
    scanf(" %49[^\n]", clientes[quantidadeClientes].nome);

    printf("Digite o CPF do cliente: ");
    scanf(" %14s", clientes[quantidadeClientes].cpf);

    quantidadeClientes++;
    printf("\nCliente cadastrado com sucesso!\n\n");

    do {
        printf("\n========================================\n");
        printf("          LOCADORA DE VEICULOS          \n");
        printf("========================================\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar veiculo\n");
        printf("3 - Listar clientes\n");
        printf("4 - Listar veiculos\n");
        printf("5 - Alugar veiculo\n");
        printf("6 - Devolver veiculo\n");
        printf("7 - Sair\n");
        printf("========================================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quantidadeClientes >= MAX_CLIENTES) {
                    printf("\nLimite maximo de clientes atingido.\n");
                    break;
                }

                printf("\nDigite o nome do cliente: ");
                scanf(" %49[^\n]", clientes[quantidadeClientes].nome);

                printf("Digite o CPF do cliente: ");
                scanf(" %14s", clientes[quantidadeClientes].cpf);

                quantidadeClientes++;
                printf("\nCliente cadastrado com sucesso!\n");
                break;

            case 2:
                if (quantidadeVeiculos >= MAX_VEICULOS) {
                    printf("\nLimite maximo de veiculos atingido.\n");
                    break;
                }

                printf("\nDigite o modelo: ");
                scanf(" %29[^\n]", veiculos[quantidadeVeiculos].modelo);

                printf("Digite a placa: ");
                scanf(" %9s", veiculos[quantidadeVeiculos].placa);

                printf("Digite o valor da diaria: R$ ");
                scanf("%f", &veiculos[quantidadeVeiculos].diaria);

                veiculos[quantidadeVeiculos].alugado = 0;
                quantidadeVeiculos++;
                printf("\nVeiculo cadastrado!\n");
                break;

            case 3:
                printf("\n--- CLIENTES CADASTRADOS ---\n");
                if (quantidadeClientes == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                    break;
                }

                for (int i = 0; i < quantidadeClientes; i++) {
                    printf("\nCliente %d\n", i + 1);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("CPF: %s\n", clientes[i].cpf);
                }
                break;

            case 4:
                printf("\n--- VEICULOS CADASTRADOS ---\n");
                if (quantidadeVeiculos == 0) {
                    printf("Nenhum veiculo cadastrado.\n");
                    break;
                }

                for (int i = 0; i < quantidadeVeiculos; i++) {
                    printf("\nModelo: %s\n", veiculos[i].modelo);
                    printf("Placa: %s\n", veiculos[i].placa);
                    printf("Diaria: R$ %.2f\n", veiculos[i].diaria);
                    if (veiculos[i].alugado == 0) {
                        printf("Status: Disponivel\n");
                    } else {
                        printf("Status: Indisponivel / Alugado\n");
                    }
                }
                break;

            case 5:
                if (quantidadeClientes == 0) {
                    printf("\nCadastre um cliente antes de alugar um veiculo.\n");
                    break;
                }

                if (quantidadeVeiculos == 0) {
                    printf("\nCadastre um veiculo antes de alugar.\n");
                    break;
                }

                printf("\nClientes cadastrados:\n");
                for (int i = 0; i < quantidadeClientes; i++) {
                    printf("%d - %s (%s)\n", i + 1, clientes[i].nome, clientes[i].cpf);
                }

                printf("Escolha o cliente: ");
                scanf("%d", &clienteEscolhido);

                if (clienteEscolhido < 1 || clienteEscolhido > quantidadeClientes) {
                    printf("\nCliente invalido!\n");
                    break;
                }

                printf("\nVeiculos cadastrados:\n");
                for (int i = 0; i < quantidadeVeiculos; i++) {
                    printf("%d - %s (%s)\n", i + 1, veiculos[i].modelo, veiculos[i].placa);
                }

                printf("Escolha o veiculo: ");
                scanf("%d", &veiculoEscolhido);

                if (veiculoEscolhido < 1 || veiculoEscolhido > quantidadeVeiculos) {
                    printf("\nVeiculo invalido!\n");
                    break;
                }

                if (veiculos[veiculoEscolhido - 1].alugado == 1) {
                    printf("\nVeiculo ja esta alugado!\n");
                    break;
                }

                printf("Quantos dias de aluguel? ");
                scanf("%d", &dias);

                if (dias < 1) {
                    printf("\nQuantidade de dias invalida!\n");
                    break;
                }

                veiculos[veiculoEscolhido - 1].alugado = 1;
                printf("\nVeiculo alugado com sucesso para %s!\n", clientes[clienteEscolhido - 1].nome);
                printf("Total do aluguel: R$ %.2f\n", veiculos[veiculoEscolhido - 1].diaria * dias);
                break;

            case 6:
                printf("\nVeiculos cadastrados:\n");
                for (int i = 0; i < quantidadeVeiculos; i++) {
                    printf("%d - %s (%s)\n", i + 1, veiculos[i].modelo, veiculos[i].placa);
                }

                printf("Escolha o veiculo para devolver: ");
                scanf("%d", &escolha);

                if (escolha < 1 || escolha > quantidadeVeiculos) {
                    printf("\nVeiculo invalido!\n");
                    break;
                }

                if (veiculos[escolha - 1].alugado == 0) {
                    printf("\nEste veiculo nao esta alugado!\n");
                    break;
                }

                veiculos[escolha - 1].alugado = 0;
                printf("\nVeiculo devolvido com sucesso!\n");
                break;

            case 7:
                printf("\nFim do programa...\nVolte Sempre!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}
