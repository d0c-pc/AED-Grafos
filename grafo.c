#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

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

void visitaP(GRAFO *g, int u, int *cor){
  cor[u] = AMARELO;

  ADJACENCIA *v = g->adj[u].cab;

  while(v){
    if(cor[v->vertice] == BRANCO) visitaP(g, v->vertice, cor);
    v = v->prox;
  }
  cor[u] = VERMELHO;

}

void buscaProfundidade(GRAFO *g){
  int cor[g->vertices];

  int u;
  for(u=0; u < g->vertices; u++){
    cor[u] = BRANCO;
  }
  for (u=0; u < g->vertices; u++){
    if(cor[u] == BRANCO) visitaP(g, u, cor);
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
