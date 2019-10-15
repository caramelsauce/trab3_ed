#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaTelefone.h"

void inicListaTelefone(struct listaTelefones *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

int listaVaziaTelefone(struct listaTelefones *lista)
{
    return (!lista->inicio && !lista->fim);
}

void inserirTelefone(struct listaTelefones *lista, char *telefone)
{
    struct elementoTelefone *novo;
    novo = malloc(sizeof(struct elementoTelefone));
    strcpy(novo->telefone, telefone);
    if(listaVaziaTelefone(lista)){
        novo->ant = novo->prox = NULL;
        lista->inicio = lista->fim = novo;
    }
    else{
        novo->ant = lista->fim;
		lista->fim->prox = novo;
        novo->prox = NULL;
        lista->fim = novo;
    }
}

int excluirTelefone(struct listaTelefones *lista, char *telefone)
{
	struct elementoTelefone *aux = lista->inicio;
	int status = 0;
	
	while(aux != NULL){
		if(strcmp(aux->telefone, telefone) == 0){
			status = 1;
			if(!aux->ant)
				lista->inicio = aux->prox;
			else{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			if(aux == lista->fim)
				lista->fim = NULL;
			free(aux);
			aux = NULL;
		}
		else
			aux = aux->prox;
	}
	return status;
}

void printTelefones(struct listaTelefones *lista)
{
	struct elementoTelefone *aux = lista->inicio;
	printf("\tTelefones do Contato:\n");
	while(aux != NULL){
		printf("\t\t%s\n", aux->telefone);
		aux = aux->prox;
	}
	printf("\n\n");
}
