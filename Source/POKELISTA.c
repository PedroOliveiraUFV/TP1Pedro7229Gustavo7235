#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Headers/POKELISTA.h"

int ListaPokemonVazia(ListaPokemon* lista){
    return lista->cabecalho == lista->ultimo;
}

void RemoverDaListaPokemon(ListaPokemon* lista, Pokemon* poke){
    if(ListaPokemonVazia(lista)){
        return;
    }
    CelulaPokemon* x = lista->cabecalho->prox;
    *poke = x->pokemon;
    lista->cabecalho->prox = x->prox;

    if (x == lista->ultimo) {
        lista->ultimo = lista->cabecalho;
    }

    free(x);
}

void InsereNaListaPokemon(ListaPokemon* lista, Pokemon poke){
    lista->ultimo->prox = (CelulaPokemon*)malloc(sizeof(CelulaPokemon));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->pokemon = poke;
    lista->ultimo->prox = NULL;
}

void FazListaPokemonVazia(ListaPokemon* lista){
    lista->cabecalho = (CelulaPokemon*)malloc(sizeof(CelulaPokemon));
    lista->ultimo = lista->cabecalho;
    lista->cabecalho->prox = NULL;
}

void ImprimirListaPokemon(ListaPokemon* lista){
    CelulaPokemon* p = lista->cabecalho->prox;
    int cont = 1;
    while (p!=NULL){
        printf("%dº Pokemon\n", cont);
        imprime_poke(&p->pokemon);
        cont++;
        p = p->prox;
    }
}