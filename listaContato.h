#ifndef LISTA_CONTATO_H
#define LISTA_CONTATO_H

#include "listaTelefone.h"

struct contato{
	char nome[50];
	struct listaTelefones telefones;
};

struct elementoContato{
	struct contato;
	struct elementoContato *ant;
	struct elementoContato *prov;
};

struct listaContatos{
	struct elementoContato *inicio;
	struct elementoContato *fim;
};

#endif
