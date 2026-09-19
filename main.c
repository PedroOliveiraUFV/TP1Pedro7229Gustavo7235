#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        if (fscanf(arq, "%d %49s %29s %d %d", &num_pokedex, nome, tipo, &x, &y) != 5) {
            return 0;
        }

        Pokemon poke;
        
        inicializa_pokemon(&poke, num_pokedex, nome, tipo, x, y);

        inserirFugitivo(centro, poke);
    }
    return 1;
}

double calcula_distacia (Treinador *treinadores, int x, int y) {
    double dx, dy;

    dx = x - treinadores -> cord_x;
    dy = y - treinadores -> cord_y;

    return sqrt(dx * dx + dy * dy);
}

Treinador escolhe_treinador(Treinador *treina1, Treinador *treina2, Pokemon *poke) {
    double distancia1, distancia2;

    distancia1 = calcula_distacia(treina1, get_cordx(poke), get_cordy(poke));
    distancia2 = calcula_distacia(treina2, get_cordx(poke), get_cordy(poke));

    if (distancia1 < distancia2) {
        return treina1;
    }
    if (distancia2 < distancia1) {
        return treina2;
    }
}


int main() {

    FILE *arq;

    CentroPesquisa centro;

}
