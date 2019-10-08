#ifndef LISTA_TELEFONE_H
#define LISTA_TELEFONE_H

struct elemento{
    char telefone[10];
    struct elemento *prox, *ant;
};

struct listaTelefones{
    struct elemento *inicio, *fim;
};

void inicLista(struct listaTelefones *lista);

int listaVazia(struct listaTelefones *lista);

void inserirTelefone(struct listaTelefones *lista, char *telefone);

int excluirTelefone(struct listaTelefones *lista, char *telefone);

#endif