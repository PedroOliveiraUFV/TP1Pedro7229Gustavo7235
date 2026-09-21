#include "../Headers/CENTRODEPESQUISA.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void inicializaCentroPesquisa(CentroPesquisa* centro){
    FazListaPokemonVazia(&centro->fugitivos);
    FazListaPokemonVazia(&centro->recuperados);
    centro->cord_x = xCentro;
    centro->cord_y = yCentro;
}

void inserirFugitivo(CentroPesquisa* centro, Pokemon poke){
    InsereNaListaPokemon(&centro->fugitivos, poke);
}

void retiraFugitivo(CentroPesquisa* centro, Pokemon* poke){
    RemoverDaListaPokemon(&centro->fugitivos, poke);
}

void imprimePokemonsFugitivos(CentroPesquisa* centro){
    printf("\nPokemons fugitivos a serem resgatados: %d\n", contaPokemonsDaLista(&centro->fugitivos));
}

int fugitivosVazio(CentroPesquisa* centro){
    return ListaPokemonVazia(&centro->fugitivos);
}

void recebePokemonsRecuperados(CentroPesquisa* centro, Treinador* treina){
    Pokemon a;
    while(ListaPokemonVazia(&treina->pokemons)==0){
        retiraPokemonDaListaTreinador(treina, &a);
        InsereNaListaPokemon(&centro->recuperados, a);
    }
}

void recarregarPokebolas(Treinador* treinador){
    srand(time(NULL));
    int pokebolas = rand() % 20 + 1;
    setPokebolas(treinador ,pokebolas);
    printf("Treinador(a) %s recebeu %d Pokebolas.\n", treinador->nome, treinador->quantPokebolas);
}