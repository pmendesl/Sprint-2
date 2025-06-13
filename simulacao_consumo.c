/*******************************************************************************
 * ENTREGA 2 – Simulação de Decisão e Consumo com Algoritmos Básicos
 * 
 * Integrantes:
 * Pedro Mendes RM: 562242
 * Leonardo RM: 565564
 * Alexandre RM: 563346
 * Guilherme Peres RM: 563981
 * Gabriel de Matos RM: 565218
 * 
 * Descrição:
 * Este programa simula um sistema de decisão de consumo inteligente que,
 * com base no nível de energia disponível (em kWh), decide quais dispositivos
 * devem permanecer ligados com base na prioridade.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_DISPOSITIVOS 100

// Estrutura para representar um dispositivo
typedef struct {
    char nome[MAX_NOME];
    float consumo;     // Consumo em kWh
    int prioridade;    // Quanto menor o número, maior a prioridade (1 = máxima prioridade)
    int status;        // 1 = ligado, 0 = desligado
} Dispositivo;

// Protótipos das funções
void cadastrarDispositivo(Dispositivo dispositivos[], int *numDispositivos);
void listarDispositivos(Dispositivo dispositivos[], int numDispositivos);
void ordenarDispositivosPorPrioridade(Dispositivo dispositivos[], int numDispositivos);
void simularConsumoInteligente(Dispositivo dispositivos[], int numDispositivos, float energiaDisponivel);
void bubbleSort(Dispositivo dispositivos[], int numDispositivos);
float calcularConsumoTotal(Dispositivo dispositivos[], int numDispositivos);
void salvarDispositivos(Dispositivo dispositivos[], int numDispositivos);
int carregarDispositivos(Dispositivo dispositivos[]);
void exibirMenu();

int main() {
    Dispositivo dispositivos[MAX_DISPOSITIVOS];
    int numDispositivos = 0;
    int opcao;
    float energiaDisponivel;
    
    // Tenta carregar dispositivos salvos anteriormente
    numDispositivos = carregarDispositivos(dispositivos);
    
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarDispositivo(dispositivos, &numDispositivos);
                break;
            case 2:
                listarDispositivos(dispositivos, numDispositivos);
                break;
            case 3:
                printf("\nInforme a quantidade de energia disponível (kWh): ");
                scanf("%f", &energiaDisponivel);
                simularConsumoInteligente(dispositivos, numDispositivos, energiaDisponivel);
                break;
            case 4:
                salvarDispositivos(dispositivos, numDispositivos);
                printf("\nDispositivos salvos com sucesso!\n");
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        printf("\nPressione Enter para continuar...");
        getchar(); // Consome o '\n' deixado pelo scanf
        getchar(); // Aguarda o Enter
        
    } while(opcao != 0);
    
    return 0;
}

// Exibe o menu principal
void exibirMenu() {
    printf("\n===== SISTEMA DE SIMULAÇÃO DE CONSUMO INTELIGENTE =====\n");
    printf("1. Cadastrar Dispositivo\n");
    printf("2. Listar Dispositivos\n");
    printf("3. Simular Consumo Inteligente\n");
    printf("4. Salvar Dispositivos\n");
    printf("0. Sair\n");
    printf("====================================================\n");
}

// Cadastra um novo dispositivo
void cadastrarDispositivo(Dispositivo dispositivos[], int *numDispositivos) {
    if (*numDispositivos >= MAX_DISPOSITIVOS) {
        printf("\nLimite máximo de dispositivos atingido!\n");
        return;
    }
    
    Dispositivo novoDispositivo;
    
    printf("\n--- Cadastro de Dispositivo ---\n");
    
    printf("Nome do dispositivo: ");
    scanf(" %[^\n]", novoDispositivo.nome);
    
    printf("Consumo em kWh: ");
    scanf("%f", &novoDispositivo.consumo);
    
    printf("Prioridade (1 = máxima prioridade, números maiores = menor prioridade): ");
    scanf("%d", &novoDispositivo.prioridade);
    
    // Por padrão, o dispositivo começa desligado
    novoDispositivo.status = 0;
    
    dispositivos[*numDispositivos] = novoDispositivo;
    (*numDispositivos)++;
    
    printf("\nDispositivo cadastrado com sucesso!\n");
}

// Lista todos os dispositivos cadastrados
void listarDispositivos(Dispositivo dispositivos[], int numDispositivos) {
    if (numDispositivos == 0) {
        printf("\nNenhum dispositivo cadastrado!\n");
        return;
    }
    
    printf("\n--- Lista de Dispositivos ---\n");
    printf("%-30s %-15s %-15s %-10s\n", "Nome", "Consumo (kWh)", "Prioridade", "Status");
    printf("-------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numDispositivos; i++) {
        printf("%-30s %-15.2f %-15d %-10s\n", 
               dispositivos[i].nome, 
               dispositivos[i].consumo, 
               dispositivos[i].prioridade, 
               dispositivos[i].status ? "Ligado" : "Desligado");
    }
    
    // Exibe o consumo total dos dispositivos ligados
    float consumoTotal = calcularConsumoTotal(dispositivos, numDispositivos);
    printf("-------------------------------------------------------------------------\n");
    printf("Consumo total dos dispositivos ligados: %.2f kWh\n", consumoTotal);
}

// Calcula o consumo total dos dispositivos ligados
float calcularConsumoTotal(Dispositivo dispositivos[], int numDispositivos) {
    float total = 0.0;
    
    for (int i = 0; i < numDispositivos; i++) {
        if (dispositivos[i].status == 1) {
            total += dispositivos[i].consumo;
        }
    }
    
    return total;
}

// Implementação do algoritmo Bubble Sort para ordenar dispositivos por prioridade
void bubbleSort(Dispositivo dispositivos[], int numDispositivos) {
    int i, j;
    Dispositivo temp;
    
    for (i = 0; i < numDispositivos - 1; i++) {
        for (j = 0; j < numDispositivos - i - 1; j++) {
            // Ordena por prioridade (menor número = maior prioridade)
            if (dispositivos[j].prioridade > dispositivos[j + 1].prioridade) {
                // Troca os dispositivos
                temp = dispositivos[j];
                dispositivos[j] = dispositivos[j + 1];
                dispositivos[j + 1] = temp;
            }
        }
    }
}

// Ordena os dispositivos por prioridade
void ordenarDispositivosPorPrioridade(Dispositivo dispositivos[], int numDispositivos) {
    bubbleSort(dispositivos, numDispositivos);
}

// Simula o consumo inteligente com base na energia disponível
void simularConsumoInteligente(Dispositivo dispositivos[], int numDispositivos, float energiaDisponivel) {
    if (numDispositivos == 0) {
        printf("\nNenhum dispositivo cadastrado para simular!\n");
        return;
    }
    
    // Primeiro, desliga todos os dispositivos
    for (int i = 0; i < numDispositivos; i++) {
        dispositivos[i].status = 0;
    }
    
    // Ordena os dispositivos por prioridade
    ordenarDispositivosPorPrioridade(dispositivos, numDispositivos);
    
    float consumoAcumulado = 0.0;
    int dispositivosLigados = 0;
    
    printf("\n--- Simulação de Consumo Inteligente ---\n");
    printf("Energia disponível: %.2f kWh\n\n", energiaDisponivel);
    
    // Liga os dispositivos por ordem de prioridade até atingir o limite de energia
    for (int i = 0; i < numDispositivos; i++) {
        if (consumoAcumulado + dispositivos[i].consumo <= energiaDisponivel) {
            dispositivos[i].status = 1; // Liga o dispositivo
            consumoAcumulado += dispositivos[i].consumo;
            dispositivosLigados++;
        }
    }
    
    // Exibe o resultado da simulação
    printf("Dispositivos ativados (%d):\n", dispositivosLigados);
    printf("%-30s %-15s %-15s\n", "Nome", "Consumo (kWh)", "Prioridade");
    printf("----------------------------------------------------------\n");
    
    for (int i = 0; i < numDispositivos; i++) {
        if (dispositivos[i].status == 1) {
            printf("%-30s %-15.2f %-15d\n", 
                   dispositivos[i].nome, 
                   dispositivos[i].consumo, 
                   dispositivos[i].prioridade);
        }
    }
    
    printf("\nDispositivos desativados (%d):\n", numDispositivos - dispositivosLigados);
    printf("%-30s %-15s %-15s\n", "Nome", "Consumo (kWh)", "Prioridade");
    printf("----------------------------------------------------------\n");
    
    for (int i = 0; i < numDispositivos; i++) {
        if (dispositivos[i].status == 0) {
            printf("%-30s %-15.2f %-15d\n", 
                   dispositivos[i].nome, 
                   dispositivos[i].consumo, 
                   dispositivos[i].prioridade);
        }
    }
    
    printf("\nConsumo total após simulação: %.2f kWh (%.2f%% da energia disponível)\n", 
           consumoAcumulado, (consumoAcumulado / energiaDisponivel) * 100);
    printf("Energia restante: %.2f kWh\n", energiaDisponivel - consumoAcumulado);
}

// Salva os dispositivos em um arquivo
void salvarDispositivos(Dispositivo dispositivos[], int numDispositivos) {
    FILE *arquivo = fopen("dispositivos.dat", "wb");
    
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar os dispositivos!\n");
        return;
    }
    
    // Salva o número de dispositivos
    fwrite(&numDispositivos, sizeof(int), 1, arquivo);
    
    // Salva cada dispositivo
    for (int i = 0; i < numDispositivos; i++) {
        fwrite(&dispositivos[i], sizeof(Dispositivo), 1, arquivo);
    }
    
    fclose(arquivo);
}

// Carrega os dispositivos de um arquivo
int carregarDispositivos(Dispositivo dispositivos[]) {
    FILE *arquivo = fopen("dispositivos.dat", "rb");
    int numDispositivos = 0;
    
    if (arquivo == NULL) {
        // Arquivo não existe ou não pode ser aberto
        return 0;
    }
    
    // Lê o número de dispositivos
    fread(&numDispositivos, sizeof(int), 1, arquivo);
    
    // Lê cada dispositivo
    for (int i = 0; i < numDispositivos; i++) {
        fread(&dispositivos[i], sizeof(Dispositivo), 1, arquivo);
    }
    
    fclose(arquivo);
    
    printf("Carregados %d dispositivos do arquivo.\n", numDispositivos);
    return numDispositivos;
}
