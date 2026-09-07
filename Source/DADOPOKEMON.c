#include <stdio.h>
#include <string.h>

#include "DADOPOKEMON.h"

static int id = 1;

void inicializa_pokemon(Pokemon *poke, int numero, char nome[], char tipo[], int x, int y) {
    poke -> id = id;

    poke -> n_pokedex = numero;

    strcpy(poke -> nome, nome);
    strcpy(poke -> tipo, tipo);

    poke -> cord_x = x;
    poke -> cord_y = y;

    ++id;
}

//get//

int get_n_pokedex(Pokemon *poke) {
    return poke -> n_pokedex;
}

void get_nome(Pokemon *poke, char resposta[]) {
    strcpy((*resposta), (*poke).nome);
}

void get_tipo(Pokemon *poke, char resposta[]) {
    strcpy((*resposta), (*poke).tipo);
}

int get_cordx(Pokemon *poke) {
    return poke -> cord_x;
}

int get_cordy(Pokemon *poke) {
    return poke -> cord_y;
}

//set//

void set_n_pokedex(Pokemon *poke, int numero) {
    poke -> n_pokedex = numero;
}

void set_nome(Pokemon *poke, char nome[]) {
    strcpy((*poke).nome, nome);
}

void set_tipo(Pokemon *poke, char tipo[]){
    strcpy((*poke).tipo, tipo);
}

void set_cord(Pokemon *poke, int x, int y) {
    poke -> cord_x = x;
    poke -> cord_y = y;
}

void imprime_poke(Pokemon *poke) {
    printf("Id: %d\n", poke -> id);
    printf("Numero da pokedex: %d\n", poke -> n_pokedex);
    printf("Nome: %s\n", poke -> nome);
    printf("Tipo: %s\n", poke -> tipo);
    printf("Localizacao (%d, %d):\n", poke -> cord_x, poke -> cord_y);
}
