#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura de uma lista
typedef struct{
    int info;
    struct ListaE* prox;
}ListaE;

//Criar uma lista
ListaE* criaLista(){
    return NULL;
}

//Insere na lista
ListaE* insereNo(int valor, ListaE* ref){
    ListaE* novoNo= (ListaE*) malloc(sizeof(ListaE));
    novoNo->info= valor;
    novoNo->prox= ref;
    return ref;
}

//Imprime a lista
void imprime(ListaE* ref){
    printf("Imprimindo lista:\n");
    if(ref==NULL){
        printf("Lista vazia!\n");
        return;
    }
    for(p=ref;p!=NULL;p=p->prox){
        printf("%d",p->info);
    }
}

//Remove da lista
ListaE* removeNo(ListaE* ref, int valor){
    Lista* p= ref;
    Lista* ant= NULL;
    while((p!= NULL)&&(p->info!= valor)){
        ant=p;
        p=p->prox;
    }
    //Nao encontrou o valor
    if(p==NULL){
        return ref;
    }
    //Se o valor estiver logo no inicio da lista
    if(p==ref){
        ref= p->prox;
    }else{
        ant->prox=p->prox;
    }
    free(p)
    return ref;
}

//Libera toda memoria utilizada pela lista
void libera(ListaE** lista){
    Lista* p= *lista;
    while(p!=NULL){
        Lista* aux= p->prox;
        free(p);
        p= aux;
    }
    *lista= NULL;
}








