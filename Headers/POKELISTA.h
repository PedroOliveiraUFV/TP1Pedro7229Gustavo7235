#ifndef POKELISTA_H
#define POKELISTA_H

#define maxtam 100

#include "DADOPOKEMON.h"

typedef struct CelulaPokemon CelulaPokemon;

typedef struct CelulaPokemon {
    Pokemon pokemon;
    CelulaPokemon* prox;
} CelulaPokemon;

typedef struct ListaPokemon{
    CelulaPokemon* cabecalho;
    CelulaPokemon* ultimo;
} ListaPokemon;

void FazListaPokemonVazia(ListaPokemon* lista);
void InsereNaListaPokemon(ListaPokemon* lista, Pokemon poke);
void RemoverDaListaPokemon(ListaPokemon* lista, Pokemon* poke);
void ImprimirListaPokemon(ListaPokemon* lista);
int ListaPokemonVazia(ListaPokemon* lista);

#endif