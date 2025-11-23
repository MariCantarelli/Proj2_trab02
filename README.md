# Projeto e Análise de algoritmos 2 - Bombeiros

Alunos: 
  - Luiza Marinho de Mesquita - 10438045
  - Marina Cantarelli Barroca - 10740412
  - Vinicius Barbosa Pereira Allegretti - 10437502

Turma: 04G

Link do nosso vídeo no Youtube: https://www.youtube.com/watch?v=1o0d5y_wpFw

O objetivo é auxiliar o departamento de bombeiros da cidade de Nlogônia a encontrar a **rota mais rápida** entre o quartel (localizado na esquina \#1) e o local de um incêndio, considerando um mapa de ruas de mão única com diferentes tempos de deslocamento.

## Funcionalidades

O software implementa o algoritmo **Dijkstra** adaptado para:

  * **Calcular o tempo mínimo ($T$)**: Determina o menor tempo possível para chegar ao foco do incêndio.
  * **Reconstruir a rota ($R$)**: Diferente do algoritmo padrão que apenas calcula custos, esta implementação armazena os predecessores para exibir a sequência exata de esquinas a serem percorridas.
  * **Leitura de Arquivo**: Processa automaticamente as informações do mapa a partir de um arquivo de texto.

## Tecnologias Utilizadas

  * **Linguagem**: C
  * **Estrutura de Dados**: Matriz de Adjacência (para o grafo) e Vetores Auxiliares (para distâncias e predecessores).

## Como Compilar e Rodar

Para executar este projeto, você precisará de um compilador C (como o GCC).

1.  **Clone ou baixe** os arquivos do projeto.
2.  Certifique-se de que o arquivo de entrada `bombeiro.txt` esteja na mesma pasta do código fonte.
3.  Abra o terminal na pasta do projeto e compile:

<!-- end list -->

```bash
gcc bombeiros.c -o bombeiros
```

4.  Execute o programa:

**No Windows:**

```bash
bombeiros.exe
```

**No Linux/Mac:**

```bash
./bombeiros
```

## 📄 Formato do Arquivo de Entrada (`bombeiro.txt`)

O programa espera um arquivo de texto formatado conforme o exemplo do enunciado:

1.  **Linha 1**: Número da esquina onde ocorre o incêndio.
2.  **Linha 2**: Número total de esquinas no mapa.
3.  **Linhas seguintes**: Triplas de inteiros contendo `Origem Destino Tempo`.
4.  **Última linha**: Um único `0` indicando o fim da leitura.

**Exemplo (`bombeiro.txt`):**

```text
3       <-- Incêndio na esquina 3
6       <-- Total de 6 esquinas
4 6 3   <-- Rua da esq. 4 para 6 gasta 3 min
5 2 4
2 3 1
1 4 2
3 5 1
1 5 4
4 5 1
5 6 1
1 3 8
6 2 2
0       <-- Fim da leitura
```

## Exemplo de Saída

Ao executar com o arquivo acima, o programa exibirá na tela:

```text
Rota da esquina #1 ate 3 = 1 4 5 6 2 3 
Tempo calculado para rota = 8
```

> **Nota sobre o exemplo:** O caminho encontrado (1-\>4-\>5-\>6-\>2-\>3) possui custo matemático de 8 minutos. A implementação prioriza a precisão matemática baseada nos pesos fornecidos no arquivo de entrada.

## Estrutura do Código

  * `rota_mais_rapida`: Função auxiliar "gulosa" que seleciona o vértice não visitado com menor custo acumulado.
  * `dijkstra`: Implementação do algoritmo principal. Atualiza os custos ($T$) e preenche o vetor de predecessores (`prev`) para rastreamento do caminho.
  * `rota`: Função recursiva que utiliza *backtracking* no vetor `prev` para imprimir o caminho da origem até o destino na ordem correta.
