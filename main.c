#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

int rota_mais_rapida(int M, int T[], int visitado[]){
    int menor = MAX;
    int indice = -1;

    for (int i = 0; i <= M; i++) {
        if (!visitado[i] && T[i] < menor) {
            menor = T[i];
            indice = i;
        }
    }
    return indice;
}


//pro tempo minimo tem que usar o dijkstra
void djikstra(int M, int origem, int T[], int mapa[M+1][M+1]){
    int visitado[M+1];

    for (int i = 0; i < M; i++) {
        T[i] = MAX; // tempo como infinito
        visitado[i] = 0; // nenhum vertice visitado
    }
    T[origem] = 0; //lugar inicial, a estacao de bombeiros

    for (int i = 0; i < M - 1; i++) {
        int u = rota_mais_rapida(M, T, visitado);
        if(u == -1){
            break;
        }
        visitado[u] = 1;

        for (int v = 1; v < M; v++) {
            if (!visitado[v] && mapa[u][v] < MAX) {
                if (T[u] + mapa[u][v] < T[v]) {
                    T[v] = T[u] + mapa[u][v];
                }
            }
        }
    }
}

int main(){
    FILE *arq = fopen("bombeiro.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!!\n");
        return 1;   
    }
    int incendio, M;
    fscanf(arq, "%d", &incendio);
    fscanf(arq, "%d", &M);

    int mapa[M+1][M+1];

    for (int i = 1; i <= M; i++) {
        for(int j = 1; j <= M; j++){
            mapa[i][j] = MAX;
        }
    }
    
    int a, b, c;
    while(1){
        fscanf(arq, "%d", &a);

        if(a == 0){
            break;
        }

        fscanf(arq, "%d %d", &b, &c);
        mapa[a][b] = c; // chama uma vez pq a rua e mao unica
    }
    fclose(arq);

    int T[M+1];
    djikstra(M, 1, T, mapa);

    printf("Rota da esquina #1 ate %d = :\n", incendio);
    printf("Tempo calculado para rota = %d\n", T[incendio]);
    
    return 0;
}

