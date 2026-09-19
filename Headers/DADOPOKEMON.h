#ifndef DADOPOKEMON_H
#define DADOPOKEMON_H

typedef struct {
    int id;
    int n_pokedex;
    char nome[50];
    char tipo[30];
    int cord_x;
    int cord_y;
} Pokemon;

void inicializa_pokemon(Pokemon *poke, int numero, char nome[], char tipo[], int x, int y); 

//get//

int get_n_pokedex(Pokemon *poke);
char *get_nome(Pokemon *poke);
char *get_tipo(Pokemon *poke);
int get_cordx(Pokemon *poke);
int get_cordy(Pokemon *poke);

//set//

void set_n_pokedex(Pokemon *poke, int numero);
void set_nome(Pokemon *poke, char nome[]);
void set_tipo(Pokemon *poke, char tipo[]);
void set_cord(Pokemon *poke, int x, int y);

//impressao//

void imprime_poke(Pokemon *poke);

#endif
