#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "CENTRODEPESQUISA.h"

#define MAX_TREINADOR 2

void inicioMissao(){
    printf("========================================\n");
    printf("          INÍCIO DA MISSÃO              \n");
    printf("========================================\n\n");
}

void linha(){
    printf("\n----------------------------------------\n");
}

void treinadorSemPokebolas(Treinador* trei){
    printf("\n========================================\n");
    printf("       Treinador(a) %s SEM POKÉBOLAS  \n", trei->nome);
    printf("========================================\n\n");
}

void todosPokemonsResuperados(){
    printf("========================================\n");
    printf("     Todos Pokemons foram resgatados    \n");
    printf("========================================\n\n");
}

void missaoConcluida(){
    printf("========================================\n");
    printf("          MISSÃO CONCLUÍDA              \n");
    printf("========================================\n\n");
}

int ler_treinadores(FILE *arq, Treinador **treinadores) {
    char nome[50];
    int pokebolas;

    for (int i = 0; i < MAX_TREINADOR; ++i) {
        if (fscanf(arq, "%49s %d", nome, &pokebolas) != 2) {
            return 0;
        }
        inicializaTreinador(&treinadores[i], nome, pokebolas);
    }
    return 1;
}

int ler_pokemons(FILE *arq, CentroPesquisa *centro) {
    int quant, num_pokedex;
    char nome[50], tipo[30];
    int x, y;

    if (fscanf(arq, "%d", &quant) != 1) {
        return 0;
    }

    for (int i = 0; i < quant; ++i) {
        if (fscanf(arq, "%d %49s %29s %d %d", &num_pokedex, nome, tipo, &x, &y) != 5) {
            return 0;
        }

        Pokemon poke;
        
        inicializa_pokemon(&poke, num_pokedex, nome, tipo, x, y);

        inserirFugitivo(centro, poke);
    }
    return 1;
}

double calcula_distancia (int x1, int y1, int x2, int y2) {
    double dx, dy;

    dx = x1 - x2;
    dy = y1 - y2;

    return sqrt(dx * dx + dy * dy);
}

Treinador *escolhe_treinador(Treinador *treina, Pokemon *poke) {
    Treinador* treinadorMaisProx = &treina[0];
    double distanciaMaisProx = 0;
    for(int i = 0; i<MAX_TREINADOR; i++){
        double distancia = calcula_distancia(treina[i].cord_x, &treina[i].cord_y, poke->cord_x, poke->cord_y);
        printf("Distância Treinador(a) %s: %.2f\n",treina[i].nome, distancia);
        if(distancia>distanciaMaisProx){
            treinadorMaisProx = &treina[i];
            distanciaMaisProx = distancia;
        }
    }
    printf("\n");
    return treinadorMaisProx;
}


int main() {

    //lendo o arquivo de entrada
    FILE *arq = fopen("exemplo.txt", "r");

    CentroPesquisa centro;
    inicializaCentroPesquisa(&centro);

    Treinador treinador[MAX_TREINADOR];

    if (!ler_treinadores(arq, treinador)) {
        printf("Erro ao ler treinadores!\n");
        fclose(arq);
        return 1;
    }

    if (!ler_pokemons(arq, &centro)) {
        printf("Erro ao ler pokemons!\n");
        fclose(arq);
        return 1;
    }

    fclose(arq);

    //iniciando a missão
    inicioMissao();
    for(int i = 0; i<MAX_TREINADOR;i++){
        imprimeTreinador(&treinador[i]);
    }
    linha();

    //Pokemons alvos
    while(fugitivosVazio(&centro)!=1){
        Pokemon fugitivo;
        retiraFugitivo(&centro, &fugitivo);
        printf("Pokemon alvo: %s\n", fugitivo.nome);
        printf("Localização: (%d,%d)\n\n", fugitivo.cord_x, fugitivo.cord_y);
        Treinador *missionario = escolhe_treinador(treinador, &fugitivo);
        printf("Missão atribuída ao Treinador(a) %s.\n\n",missionario->nome);
        set_cord(missionario, fugitivo.cord_x, fugitivo.cord_y);
        capturaPokemon(missionario, fugitivo);
        printf("Pokébolas restantes para o Treinador(a) %s: %d\n", missionario->nome, getPokebolas(missionario));
        if(getPokebolas(missionario) == 0){
            treinadorSemPokebolas(missionario);
            set_cord(missionario, xCentro, yCentro);
            printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n\n", missionario->nome);
            recebePokemonsRecuperados(&centro, &missionario->pokemons);
            printf("Entregando Pokémons ao Centro de Pesquisa.\n\n");
        }
        linha();
    }

    //fim da missão
    todosPokemonsResuperados();
    for(int i = 0; i<MAX_TREINADOR; i++){
        setCord(&treinador[i], xCentro, yCentro);
    }
    printf("Todos treinadores retornam ao Centro de Pesquisa.\n\n");
    for(int i = 0; i<MAX_TREINADOR; i++){
        recebePokemonsRecuperados(&centro, &treinador[i].pokemons);
        printf("Treinador(a) %s devolve os Pokémon.\n\n",treinador[i].nome);
    }
    missaoConcluida();

    //escrever relatorio de pokemons repurados no relatorio.txt 
}
