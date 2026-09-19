#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "CENTRODEPESQUISA.h"

#define MAX_TREINADOR 2

void inicioMissao(){
    printf("========================================\n");
    printf("          INÍCIO DA MISSÃO              \n");
    printf("========================================\n\n");
}

void linha(){
    printf("\n----------------------------------------\n");
}

int ler_treinadores(FILE *arq, Treinador **treinadores) {
    char nome[50];
    int pokebolas;

    for (int i = 0; i < MAX_TREINADOR; ++i) {
        if (fscanf(arq, "%49s %d", nome, &pokebolas) != 2) {
            return 0;
        }
        inicializaTreinador(&treinadores[i], nome, pokebolas);
    }
    return 1;
}

int ler_pokemons(FILE *arq, CentroPesquisa *centro) {
    int quant, num_pokedex;
    char nome[50], tipo[30];
    int x, y;

    if (fscanf(arq, "%d", &quant) != 1) {
        return 0;
    }

    for (int i = 0; i < quant; ++i) {
        if (fscanf(arq, "%d %49s %29s %d %d", &num_pokedex, nome, tipo, &x, &y) != 5) {
            return 0;
        }

        Pokemon poke;
        
        inicializa_pokemon(&poke, num_pokedex, nome, tipo, x, y);

        inserirFugitivo(centro, poke);
    }
    return 1;
}

double calcula_distancia (Treinador *treinadores, int x, int y) {
    double dx, dy;

    dx = x - treinadores -> cord_x;
    dy = y - treinadores -> cord_y;

    return sqrt(dx * dx + dy * dy);
}

Treinador *escolhe_treinador(Treinador *treina1, Treinador *treina2, Pokemon *poke) {
    double distancia1, distancia2;

    distancia1 = calcula_distancia(treina1, get_cordx(poke), get_cordy(poke));
    distancia2 = calcula_distancia(treina2, get_cordx(poke), get_cordy(poke));

    if (distancia1 < distancia2) {
        return treina1;
    }
    if (distancia2 < distancia1) {
        return treina2;
    }
}


int main() {

    //lendo o arquivo de entrada
    FILE *arq = fopen("exemplo.txt", "r");

    CentroPesquisa centro;
    inicializaCentroPesquisa(&centro);

    Treinador treinador[MAX_TREINADOR];

    if (!ler_treinadores(arq, treinador)) {
        printf("Erro ao ler treinadores!\n");
        fclose(arq);
        return 1;
    }

    if (!ler_pokemons(arq, &centro)) {
        printf("Erro ao ler pokemons!\n");
        fclose(arq);
        return 1;
    }

    fclose(arq);

    //iniciando a missão
    inicioMissao();
    for(int i = 0; i<MAX_TREINADOR;i++){
        imprimeTreinador(&treinador[i]);
    }
    linha();

    //Pokemons alvos
    while(fugitivosVazio(&centro)!=1){
        Pokemon fugitivo;
        retiraFugitivo(&centro, &fugitivo);
        printf("Pokemon alvo: %s\n", fugitivo.nome);
        printf("Localização: (%d,%d)\n\n", fugitivo.cord_x, fugitivo.cord_y);
    }
}
