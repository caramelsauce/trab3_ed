#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaTelefone.h"

void inicLista(struct listaTelefones *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

int listaVazia(struct listaTelefones *lista)
{
    return (lista->inicio == NULL && lista->fim == NULL);
}

void inserirTelefone(struct listaTelefones *lista, char *telefone)
{
    struct elemento *novo;
    novo = malloc(sizeof(struct elemento));
    strcpy(novo->telefone, telefone);
    if(listaVazia){
        novo->ant = novo->prox = NULL;
        lista->inicio = lista->fim = novo;
    }
    else{
        novo->ant = lista->fim;
        novo->prox = NULL;
        lista->fim = novo;
    }
}