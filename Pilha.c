#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char string[40];
	struct lista* prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;

Pilha* cria_pilha(){
	Pilha* p= (Pilha*) malloc(sizeof(Pilha));
	p->topo= NULL;
	return p;
}

int pilha_vazia(Pilha* p){
	return (p->topo==NULL);
}

void push(Pilha* p, char info[40]){
	Lista* no= (Lista*) malloc(sizeof(Lista));
	strcpy(no->string,info);
	no->prox= p->topo;
	p->topo= no;
}

void pop(Pilha* p){
	if(pilha_vazia(p)){
		printf("\nPilha Vazia!\n");
		return;
	}
	Lista* aux= p->topo;
	p->topo= p->topo->prox;
	free(aux);
}

void imprime(Pilha* p){
    if((p==NULL)||(p->topo==NULL)){
        printf("\nPilha vazia!\n");
    }
    for(Lista* aux=p->topo; aux!=NULL; aux=aux->prox){
        printf("\n[%s]",aux->string);
    }
    printf("\n");
}

void libera(Pilha** p){
    Lista* L= (*p)->topo;
    while(L!=NULL){
        Lista* aux= L->prox;
        free(L);
        L= aux;
    }
    free(p);
    *p= NULL;
}