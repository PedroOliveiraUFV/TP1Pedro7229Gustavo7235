#include <stdio.h>
#include <stdlib.h>

#include "DADOPOKEMON.h"
#include "POKELISTA.h"
#include "DADOTREINADOR.h"
#include "CENTRODEPESQUISA.h"

#define MAX_TREINADOR = 2

int ler_treinadores(FILE *arq, Treinador **treinadores) {
    char nome[50];
    int pokebolas;

    for (int i = 0; i < MAX_TREINADOR; ++i) {
        if (fscanf(arq, "%49s %d", nome, &pokebolas) != 2) {
            return 0;
        }
        treinadores[i] = inicializaTreinador(i + 1, nome, pokebolas);

        if (treinadores[i] == NULL ) {
            return 0;
        }
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
        if (fscanf(arq, "%d %49s %49s %d %d") != 5) {
            return 0;
        }

        Pokemon poke;
        
        inicializa_pokemon(&poke, num_pokedex, nome, tipo, x, y);

        inserirFugitivo(centro, poke);
    }
    return 1;
}


int main() {

    FILE *arq;

}
