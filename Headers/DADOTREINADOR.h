#ifndef DADOTREINADOR_H
#define DADOTREINADOR_H

#include "POKELISTA.h"

typedef struct Treinador{
    int id;
    char nome[100];
    int cord_x;
    int cord_y;
    ListaPokemon pokemons;
    int quantPokebolas;
} Treinador;

void inicializaTreinador(Treinador* treinador, char nome[], int pokebolas);
void movimenta(Treinador* treinador, int x, int y);
void capturaPokemon(Treinador* treinador, Pokemon poke);
void retiraPokemonDaListaTreinador(Treinador* treinador, Pokemon* resul);
void imprimeTreinador(Treinador* treinador);

//gets//
void getCord(Treinador* treinador, int* x, int* y);
int getPokebolas(Treinador* treinador);

//sets//
void setCord(Treinador* treinador, int x, int y);
void setPokebolas(Treinador* treinador, int quant);

#endif
