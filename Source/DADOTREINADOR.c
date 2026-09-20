#include <stdio.h>
#include <string.h>

#include "../Headers/DADOTREINADOR.h"

static int proxId = 1;

//inicializa o treinador//
void inicializaTreinador(Treinador* treinador, char nome[], int pokebolas){
    treinador->id = proxId;
    proxId++;
    strcpy(treinador->nome, nome);
    treinador->cord_x = 0;
    treinador->cord_y = 0;
    FazListaPokemonVazia(&treinador->pokemons);
    treinador->quantPokebolas = pokebolas;
}

//movimenta(teleporta) o treinador//
void movimenta(Treinador* treinador, int x, int y){
    treinador->cord_x = x;
    treinador->cord_y = y;
}

//captura um pokemon pra lista
void capturaPokemon(Treinador* treinador, Pokemon poke){
    InsereNaListaPokemon(&treinador->pokemons, poke);
    treinador->quantPokebolas--;
    printf("%s capturado com sucesso!\n\n", poke.nome);
}

//retira da lista e retorna ele por meio de ponteiro//
void retiraPokemonDaListaTreinador(Treinador* treinador, Pokemon* resul){
    RemoverDaListaPokemon(&treinador->pokemons, resul);
}

//imprime o treinador//
void imprimeTreinador(Treinador* treinador){
    printf("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n",
            treinador->nome, treinador->cord_x, treinador->cord_y, treinador->quantPokebolas);
}

//gets//
void getCord(Treinador* treinador, int* x, int* y){
    *x = treinador->cord_x;
    *y = treinador->cord_y;
}
int getPokebolas(Treinador* treinador){
    return treinador->quantPokebolas;
}

//sets//
void setPokebolas(Treinador* treinador, int quant){
    treinador->quantPokebolas = quant;
}
void setCord(Treinador* treinador, int x, int y){
    treinador->cord_x = x;
    treinador->cord_y = y;
    printf("Treinador(a) %s se movimentou para (%d,%d).\n", treinador->nome, treinador->cord_x, treinador->cord_y);
}
