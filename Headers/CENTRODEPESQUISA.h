#ifndef CENTRODEPESQUISA_H
#define CENTRODEPESQUISA_H

#include "DADOTREINADOR.h"

#define xCentro 0
#define yCentro 0

typedef struct {
    ListaPokemon fugitivos;
    ListaPokemon recuperados;
    int cord_x;
    int cord_y;
} CentroPesquisa;

void inicializaCentroPesquisa(CentroPesquisa* centro);
void inserirFugitivo(CentroPesquisa* centro, Pokemon poke);
void retiraFugitivo(CentroPesquisa* centro, Pokemon* poke);
int fugitivosVazio(CentroPesquisa* centro);
void imprimePokemonsFugitivos(CentroPesquisa* centro);
void recebePokemonsRecuperados(CentroPesquisa* centro, Treinador* treina);
void recarregarPokebolas(Treinador* treinador);

#endif