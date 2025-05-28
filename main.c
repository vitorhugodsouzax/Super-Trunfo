#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h> // Essencial para SetConsoleOutputCP

// Define o número máximo de cartas que podemos cadastrar
#define MAX_CARTAS 100

// Define a estrutura para uma carta do Super Trunfo
typedef struct {
    char estado[50];
    int codigo;
    char nomeCidade[100];
    long int populacao;
    double pib;
    double area;
    int numPontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
    int ativa;
} Carta;

// Array global de cartas e contador
Carta baralho[MAX_CARTAS];
int numeroDeCartasCadastradas = 0;

// --- Protótipos das Funções ---
void configurarConsole();
void exibirMenu();
void cadastrarNovaCarta();
void exibirCartasCadastradas();
void limparBufferEntrada();

// --- Função Principal (main) ---
int main() {
    // Configura o console para UTF-8
    configurarConsole();

    int opcao;

    // Inicializa as cartas
    for (int i = 0; i < MAX_CARTAS; i++) {
        baralho[i].ativa = 0;
    }

    // Loop do menu
    do {
        exibirMenu();
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpção inválida! Por favor, digite um número.\n");
            limparBufferEntrada();
            opcao = -1; // Usa -1 para evitar sair se digitar 0
            system("pause");
            continue;
        }

        limparBufferEntrada();

        switch (opcao) {
            case 1:
                cadastrarNovaCarta();
                break;
            case 2:
                exibirCartasCadastradas();
                break;
            case 0:
                printf("\nSaindo do programa. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        if (opcao != 0) {
           system("pause");
        }

    } while (opcao != 0);

    return 0;
}

// --- Implementação das Funções ---

/**
 * @brief Configura o console para exibir acentos corretamente (UTF-8).
 */
void configurarConsole() {
    SetConsoleOutputCP(65001); // Define a página de código de SAÍDA para UTF-8
    SetConsoleCP(65001);       // Define a página de código de ENTRADA para UTF-8
    // A linha setlocale é comentada para focar na solução via Windows API + UTF-8
    // setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"); // Poderia ser testado se necessário
}

/**
 * @brief Limpa o buffer de entrada do teclado.
 */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Exibe o menu principal do programa.
 */
void exibirMenu() {
    system("cls");
    printf("=========================================\n");
    printf("    Super Trunfo - Cadastro de Cidades   \n");
    printf("=========================================\n");
    printf("1. Cadastrar Nova Carta (Cidade)\n");
    printf("2. Exibir Cartas Cadastradas\n");
    printf("0. Sair\n");
    printf("=========================================\n");
    printf("Cartas cadastradas: %d / %d\n", numeroDeCartasCadastradas, MAX_CARTAS);
    printf("=========================================\n");
}

/**
 * @brief Cadastra uma nova carta no baralho.
 */
void cadastrarNovaCarta() {
    system("cls");
    printf("--- Cadastro de Nova Carta ---\n");

    if (numeroDeCartasCadastradas >= MAX_CARTAS) {
        printf("Não é possível cadastrar mais cartas. O baralho está cheio!\n");
        return;
    }

    int indice = numeroDeCartasCadastradas;

    printf("Digite o Código da Carta: ");
    while (scanf("%d", &baralho[indice].codigo) != 1) {
        printf("Entrada inválida. Digite um número para o Código: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();

    printf("Digite o Nome do Estado: ");
    fgets(baralho[indice].estado, 50, stdin);
    baralho[indice].estado[strcspn(baralho[indice].estado, "\n")] = 0;

    printf("Digite o Nome da Cidade: ");
    fgets(baralho[indice].nomeCidade, 100, stdin);
    baralho[indice].nomeCidade[strcspn(baralho[indice].nomeCidade, "\n")] = 0;

    printf("Digite a População: ");
     while (scanf("%ld", &baralho[indice].populacao) != 1 || baralho[indice].populacao <= 0) {
        printf("Entrada inválida. Digite um número positivo para a População: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();

    printf("Digite o PIB (Produto Interno Bruto): ");
     while (scanf("%lf", &baralho[indice].pib) != 1 || baralho[indice].pib < 0) {
        printf("Entrada inválida. Digite um número não negativo para o PIB: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();

    printf("Digite a Área (em km²): "); // Mantido o ² para teste
    while (scanf("%lf", &baralho[indice].area) != 1 || baralho[indice].area <= 0) {
        printf("Entrada inválida. Digite um número positivo para a Área: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();

    printf("Digite o Número de Pontos Turísticos: ");
     while (scanf("%d", &baralho[indice].numPontosTuristicos) != 1 || baralho[indice].numPontosTuristicos < 0) {
        printf("Entrada inválida. Digite um número não negativo para Pontos Turísticos: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();

    // Cálculos
    baralho[indice].densidadePopulacional = (baralho[indice].area > 0) ? baralho[indice].populacao / baralho[indice].area : 0;
    baralho[indice].pibPerCapita = (baralho[indice].populacao > 0) ? baralho[indice].pib / baralho[indice].populacao : 0;

    baralho[indice].ativa = 1;
    numeroDeCartasCadastradas++;

    printf("\nCarta cadastrada com sucesso!\n");
}

/**
 * @brief Exibe todas as cartas que já foram cadastradas.
 */
void exibirCartasCadastradas() {
    system("cls");
    printf("--- Cartas Cadastradas ---\n");

    if (numeroDeCartasCadastradas == 0) {
        printf("Nenhuma carta cadastrada ainda.\n");
        return;
    }

    for (int i = 0; i < MAX_CARTAS; i++) {
        if (baralho[i].ativa == 1) {
            printf("-----------------------------------------\n");
            printf("Carta Código: %d\n", baralho[i].codigo);
            printf("Cidade: %s\n", baralho[i].nomeCidade);
            printf("Estado: %s\n", baralho[i].estado);
            printf("População: %ld habitantes\n", baralho[i].populacao);
            printf("PIB: R$ %.2f\n", baralho[i].pib);
            printf("Área: %.2f km²\n", baralho[i].area); // Mantido o ²
            printf("Pontos Turísticos: %d\n", baralho[i].numPontosTuristicos);
            printf("Densidade Populacional: %.2f hab/km²\n", baralho[i].densidadePopulacional);
            printf("PIB per Capita: R$ %.2f\n", baralho[i].pibPerCapita);
            printf("-----------------------------------------\n\n");
        }
    }
}