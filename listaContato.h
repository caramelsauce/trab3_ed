#ifndef LISTA_CONTATO_H
#define LISTA_CONTATO_H

#include "listaTelefone.h"

struct contato{
	char nome[50];
	struct listaTelefones telefones;
};

struct elementoContato{
	struct contato contato;
	struct elementoContato *ant;
	struct elementoContato *prox;
};

struct listaContatos{
	struct elementoContato *inicio;
	struct elementoContato *fim;
};

void inicListaContato(struct listaContatos *lista);

int listaVaziaContato(struct listaContatos *lista);

void inserirContato(struct listaContatos *lista, struct contato temp);

void excluirContato(struct listaContatos *lista,char *nome);

struct elementoContato * checkContato(struct listaContatos *lista, char *nome);

void printListaContatos(struct listaContatos *lista);

#endif
