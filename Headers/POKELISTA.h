#ifndef POKELISTA_H
#define POKELISTA_H

#define maxtam 100

#include "DADOPOKEMON.h"

//Para citar a struct dentro dela mesma//
typedef struct CelulaPokemon CelulaPokemon;

//Celulas da lista, nao sao usadas fora do tad//
typedef struct CelulaPokemon {
    Pokemon pokemon;
    CelulaPokemon* prox;
} CelulaPokemon;

//struct da lista
typedef struct ListaPokemon{
    CelulaPokemon* cabecalho;
    CelulaPokemon* ultimo;
} ListaPokemon;

void FazListaPokemonVazia(ListaPokemon* lista);
void InsereNaListaPokemon(ListaPokemon* lista, Pokemon poke);
void RemoverDaListaPokemon(ListaPokemon* lista, Pokemon* poke);
void ImprimirListaPokemon(ListaPokemon* lista);
int ListaPokemonVazia(ListaPokemon* lista);
int contaPokemonsDaLista(ListaPokemon* lista);

#endif