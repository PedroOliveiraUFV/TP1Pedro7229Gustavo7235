#include "../Headers/CENTRODEPESQUISA.h"

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
    printf("\nPokémons fugitivos a serem resgatados: %d\n", contaPokemonsDaLista(&centro->fugitivos));
}

int fugitivosVazio(CentroPesquisa* centro){
    return ListaPokemonVazia(&centro->fugitivos);
}

void recebePokemonsRecuperados(CentroPesquisa* centro, ListaPokemon* lista);

//tem que fazer essa funão escrever "Treinador(a) %s recebeu %d Pokébolas.\n""
void recarregarPokebolas(Treinador* treinador);