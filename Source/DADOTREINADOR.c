#include <stdio.h>
#include <string.h>

#include "../Headers/DADOTREINADOR.h"

static int proxId = 1;

void inicializaTreinador(Treinador* treinador, char nome[]){
    treinador->id = proxId;
    proxId++;
    strcpy(treinador->nome, nome);
    treinador->cord_x = 0;
    treinador->cord_y = 0;
    FazListaPokemonVazia(&treinador->pokemons);
    treinador->quantPokebolas = 2;
}

void movimenta(Treinador* treinador, int x, int y){
    treinador->cord_x = x;
    treinador->cord_y = y;
}
void capturaPokemon(Treinador* treinador, Pokemon poke){
    InsereNaListaPokemon(&treinador->pokemons, poke);
    treinador->quantPokebolas--;
}
void retiraPokemonDaListaTreinador(Treinador* treinador, Pokemon* resul){
    RemoverDaListaPokemon(&treinador->pokemons, resul);
}
void imprimeTreinador(Treinador* treinador){
    printf("Id: %d\n", treinador->id);
    printf("Nome: %s\n", treinador->nome);
    printf("Cordenadas: (%d, %d)\n",treinador->cord_x,treinador->cord_y);
    printf("Pokebolas restantes: %d\n",treinador->quantPokebolas);
    printf("Pokemons do Treinador:\n");
    ImprimirListaPokemon(&treinador->pokemons);
}

void getCord(Treinador* treinador, int* x, int* y){
    *x = treinador->cord_x;
    *y = treinador->cord_y;
}
void setCord(Treinador* treinador, int x, int y){
    treinador->cord_x = x;
    treinador->cord_y = y;
}

int getPokebolas(Treinador* treinador){
    return treinador->quantPokebolas;
}
void setPokebolas(Treinador* treinador, int quant){
    treinador->quantPokebolas = quant;
}