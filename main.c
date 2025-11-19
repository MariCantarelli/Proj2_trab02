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
void djikstra(int M, int T[], int mapa[M][M]){
    int visitado[M+1];

    for (int i = 0; i < M; i++) {
        T[i] = MAX; // tempo como infinito
        visitado[i] = 0; // nenhum vertice visitado
    }
    T[0] = 1; //tempo inicial

    for (int i = 0; i < M - 1; i++) {
        int u = rota_mais_rapida(M, T, visitado);
        if(u == -1){
            break;
        }
        visitado[u] = 1;

        for (int v = 0; v < M; v++) {
            if (!visitado[v] && mapa[u][v] < MAX) {
                T[v] = T[u] + mapa[u][v];
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
    int M, N;
    fscanf(arq, "%d", &M);
    fscanf(arq, "%d", &N);

    int mapa[N+1][N+1];

    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++){
            mapa[i][j] = MAX;
        }
    }
    
    int a, b, c;
    while(1){
        if(fscanf(arq, "%d", &a) != 1){
            break;
        }
        if(a == 0){
            break;
        }
        fscanf(arq, "%d %d", &b, &c);
        mapa[a][b] = c;
    }
    fclose(arq);

    int T[N+1];
    djikstra(N, T, mapa);

    printf("Tempo minimo para cada vertice a partir do vertice 0:\n");
    for (int i = 0; i <= N; i++) {
        printf("Vertice %d: %d\n", i, T[i]);
    }
    return 0;


}
