#ifndef LISTA_TELEFONE_H
#define LISTA_TELEFONE_H

struct elementoTelefone{
    char telefone[10];
    struct elementoTelefone *prox, *ant;
};

struct listaTelefones{
    struct elementoTelefone *inicio, *fim;
};

void inicListaTelefone(struct listaTelefones *lista);

int listaVaziaTelefone(struct listaTelefones *lista);

void inserirTelefone(struct listaTelefones *lista, char *telefone);

int excluirTelefone(struct listaTelefones *lista, char *telefone);

void excluirListaTelefone(struct listaTelefones *lista);

void printTelefones(struct listaTelefones *lista);

#endif