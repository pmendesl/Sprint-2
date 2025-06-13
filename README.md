# Sprint-2
# ENTREGA 2 – Simulação de Decisão e Consumo com Algoritmos Básicos

## Integrantes
- Pedro Mendes RM: 562242
- Leonardo RM: 565564
- Alexandre RM: 563346
- Guilherme Peres RM: 563981
- Gabriel de Matos RM: 565218

## Descrição do Projeto
Este programa implementa um sistema de simulação de consumo inteligente que, com base no nível de energia disponível (em kWh), decide quais dispositivos devem permanecer ligados com base na prioridade. O sistema utiliza o algoritmo Bubble Sort para ordenar os dispositivos por prioridade e implementa uma lógica de decisão para maximizar o uso dos dispositivos mais importantes dentro do limite de energia disponível.

## Funcionalidades Implementadas

1. **Cadastro de Dispositivos**: Permite registrar dispositivos com nome, consumo em kWh e nível de prioridade.
2. **Listagem de Dispositivos**: Exibe todos os dispositivos cadastrados com suas informações e status atual.
3. **Simulação de Consumo Inteligente**: 
   - Recebe a quantidade de energia disponível
   - Ordena dispositivos por prioridade (usando Bubble Sort)
   - Liga dispositivos de maior prioridade primeiro
   - Verifica se o consumo acumulado ultrapassa a energia disponível
   - Exibe quais dispositivos foram ativados e quais foram desligados
   - Mostra o consumo total após a simulação e a energia restante
4. **Persistência de Dados**: Salva e carrega os dispositivos cadastrados em um arquivo binário.

## Como Compilar e Executar

1. **Compilação**: Abra um terminal, navegue até o diretório onde o arquivo `simulacao_consumo.c` está salvo e execute:
   ```bash
   gcc simulacao_consumo.c -o simulacao_consumo -lm
   ```

2. **Execução**: Após compilar com sucesso, execute o programa:
   ```bash
   ./simulacao_consumo
   ```

## Exemplo de Uso

Ao executar o programa, um menu será exibido:

```
===== SISTEMA DE SIMULAÇÃO DE CONSUMO INTELIGENTE =====
1. Cadastrar Dispositivo
2. Listar Dispositivos
3. Simular Consumo Inteligente
4. Salvar Dispositivos
0. Sair
====================================================
```

### Fluxo de uso típico:

1. **Cadastrar dispositivos** (opção 1):
   - Informe o nome do dispositivo
   - Informe o consumo em kWh
   - Defina a prioridade (números menores indicam maior prioridade)

2. **Listar dispositivos** (opção 2):
   - Visualize todos os dispositivos cadastrados
   - Veja o consumo total dos dispositivos atualmente ligados

3. **Simular consumo inteligente** (opção 3):
   - Informe a quantidade de energia disponível em kWh
   - O sistema ordenará os dispositivos por prioridade
   - Ligará os dispositivos mais prioritários até atingir o limite de energia
   - Exibirá os dispositivos ativados e desativados
   - Mostrará o consumo total e a energia restante

4. **Salvar dispositivos** (opção 4):
   - Salva os dispositivos cadastrados para uso futuro

5. **Sair** (opção 0):
   - Encerra o programa

## Estrutura de Dados e Algoritmos Utilizados

- **Struct Dispositivo**: Armazena informações de cada dispositivo (nome, consumo, prioridade, status)
- **Array de Dispositivos**: Armazena a coleção de dispositivos cadastrados
- **Bubble Sort**: Algoritmo de ordenação utilizado para ordenar os dispositivos por prioridade
- **Algoritmo Guloso**: Utilizado na simulação para maximizar o uso de dispositivos prioritários dentro do limite de energia

## Formato do Arquivo de Persistência

O programa utiliza um arquivo binário (`dispositivos.dat`) para armazenar os dispositivos cadastrados. A estrutura do arquivo é:
- 4 bytes iniciais: número de dispositivos
- Sequência de registros de dispositivos, cada um contendo:
  - Nome (string)
  - Consumo (float)
  - Prioridade (int)
  - Status (int)
