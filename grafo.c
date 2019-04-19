#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia{
  int vertice;
  TIPOPESO peso;
  struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
  /*Dados costumizados*/
  ADJACENCIA *cab;
}VERTICE;

typedef struct grafo{
  int vertices;
  int arestas;
  VERTICE *adj;
}GRAFO;

/* OPERAÇÕES BASICAS */

GRAFO *criarGrafo(int v){
  GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));

  g -> vertices = v;
  g -> arestas = 0;
  g -> adj = (VERTICE *)malloc(v * sizeof(VERTICE));

  int i;
  for(i = 0; i < v; i++){
    g -> adj[i].cab = NULL;
  }
  return(g);
}

ADJACENCIA *criarAdj(int v, int p){
  ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));

  temp -> vertice = v;
  temp -> peso = p;
  temp -> prox = NULL;

  return temp;
}

bool criarAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
  ADJACENCIA *novo = criarAdj(vf, p);
  novo -> prox = gr->adj[vi].cab;
  gr->adj[vi].cab = novo;
  gr->arestas++;

  return(true);
}

void imprimeGrafo(GRAFO *gr){
  printf("Vértices: %d. Arestas: %d. \n", gr->vertices, gr->arestas);

  int i;
  for(i =0; i < gr->vertices; i++){
    printf("v%d:", i);
    ADJACENCIA *ad = gr->adj[i].cab;

    while(ad){
        printf("v%d(%d) ", ad->vertice, ad->peso);
        ad = ad->prox;
    }
    printf("\n");
  }
}

int main(void){

	GRAFO * gr = criarGrafo(5);
	criarAresta(gr, 0, 1, 2);
	criarAresta(gr, 1, 2, 4);
	criarAresta(gr, 2, 0, 12);
	criarAresta(gr, 2, 4, 40);
	criarAresta(gr, 3, 1, 3);
	criarAresta(gr, 4, 3, 8);

	imprimeGrafo(gr);
}
