#include "listaContato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicListaContato(struct listaContatos *lista)
{
    lista->inicio = lista->fim = NULL;
}

int listaVaziaContato(struct listaContatos *lista)
{
    return (!lista->inicio && !lista->fim);
}

void inserirContato(struct listaContatos *lista, struct contato temp)
{
    struct elementoContato *novo;
    struct elementoContato *aux;
    novo = malloc(sizeof(struct elementoContato));
    novo->contato = temp;
    if(listaVaziaContato(lista)){
        novo->ant = novo->prox = NULL;
        lista->inicio = lista->fim = novo;
        return;
    }
    else{
        aux = lista->inicio;
        while (aux != NULL){
            if(strcmp(aux->contato.nome, temp.nome) > 0){
                novo->prox = aux;
                if(!aux->ant)
                    lista->inicio = novo;
                else
                    aux->ant->prox = novo;
                return;
            }
            aux = aux->prox;
        }
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        novo->prox = NULL;
        lista->fim = novo;
    }
}

void excluirContato(struct listaContatos *lista, char *nome)
{
    struct elementoContato *aux = lista->inicio;

    while(aux != NULL){
        if(strcmp(aux->contato.nome, nome) == 0){
			if(aux->ant == NULL)
				lista->inicio = aux->prox;
            else if(aux == lista->fim){
				lista->fim = lista->fim->ant;
                lista->fim->prox = NULL;
            }
			else{
                aux->prox->ant = aux->ant;
				aux->ant->prox = aux->prox;
			}
            excluirListaTelefone(&aux->contato.telefones);
			free(aux);
			aux = NULL;
		}
		else
            aux = aux->prox;
    }
}

//retorna um ponteiro para um elemento se achar o nome na lista ou NULL se nao achar
struct elementoContato *checkContato(struct listaContatos *lista, char *nome)
{
    struct elementoContato *aux = lista->inicio;
    while(aux != NULL){
        if(strcmp(aux->contato.nome, nome) == 0)
            return aux;
        else
            aux = aux->prox;
    }
    return NULL;
}

void printListaContatos(struct listaContatos *lista)
{
    struct elementoContato *aux = lista->inicio;
	printf("\n\n");
	printf("Contatos:\n");
	while(aux != NULL){
		printf("\t%s\n\n", aux->contato.nome);
        printTelefones(&aux->contato.telefones);
		aux = aux->prox;
	}
	printf("\n\n");
}