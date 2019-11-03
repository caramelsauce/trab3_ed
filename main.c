#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaContato.h"

void menu();

void menu_excluir();

void incluir_contato(struct listaContatos *lista);

void buscar_contato_agenda(struct listaContatos *lista);

void excluir(struct listaContatos *lista);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //declaração

    struct listaContatos lista;
    int op, quit = 0;

    //setar a lista
    inicListaContato(&lista);

    //loop principal

    while(!quit){

        //printar as opções e pegar a escolha do usuário

        menu();
        scanf("%d", &op);
        getchar();//tirar o \n do buffer

        switch(op){
            case 1:
                incluir_contato(&lista);
                break;
            case 2:
                buscar_contato_agenda(&lista);
                break;
            case 3:
                excluir(&lista);
                break;
            case 0:
                quit = 1;//condição de saída
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("\n\n");
    printf("1 - Incluir Contato\n");
    printf("2 - Buscar Contato\n");
    printf("3 - Excluir Contato\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}

void menu_excluir()
{
    printf("\n\n");
    printf("1 - Cancelar\n");
    printf("2 - Escolher um Contato a ser excluído\n");
    printf("3 - Excluir Todos os Contatos Selecionados\n");
    printf("Opção: ");
}

void incluir_contato(struct listaContatos *lista)
{
    int quit = 0;
    char telefone_temp[10] = "1";
    struct contato temp;
    struct elementoContato *aux;

    //verificar se o nome já existe na lista
    printf("\nDigite o nome do contato que deseja inserir: ");
    gets(temp.nome);
    aux = checkContato(lista, temp.nome);

    /*se não existir o nome na lista de contatos
    -seta a lista de telefone do contato
    -preenche a lista com telefones até que seja digitado "0"
    -insere o contato na lista de contatos
    */
    if(!aux){
        inicListaTelefone(&temp.telefones);
        while(!quit){
            printf("\nDigite os telefones deste contato ou 0 para concluir a inserção:");
            gets(telefone_temp);
            if(strcmp(telefone_temp, "0") == 0)
                    quit = 1;
            else
                inserirTelefone(&temp.telefones, telefone_temp);
        }
        inserirContato(lista, temp);
    }
    /*se o nome já existir na lista de contatos
    -printa uma mensagem dizendo que já existe
    -printa o nome e os telefones do contato
    */
    else{
        printf("\nO contato já existe\n");
        printf("\t%s\n", aux->contato.nome);
        printTelefones(&aux->contato.telefones);
   }
}

void buscar_contato_agenda(struct listaContatos *lista)
{
    int encontrado = 0;
    struct contato temp;
    struct elementoContato *aux;
    printf("\nDigite o nome do contato a ser procurado: ");
    gets(temp.nome);
    aux = lista->inicio;

    //percorre a lista 
    while(aux != NULL){
        //se o nome digitado for igual a algum contato printa as informações do contato
        if(strncmp(aux->contato.nome, temp.nome, strlen(temp.nome) ) == 0){                      
            printf("\t%s\n", aux->contato.nome);
            printTelefones(&aux->contato.telefones);
            encontrado = 1; 
        }
        aux = aux->prox;
    }
    //se não for encontrado 
    if(!encontrado)
        printf("\nNenhum Contato foi encontrado com esse nome\n");
}

void excluir(struct listaContatos *lista)
{
    int op;
    char nome[50];
    struct elementoContato *aux, *prox;
    printf("\nDigite o nome do contato a ser procurado: ");
    gets(nome);
    aux = lista->inicio;

    //percorre a lista printando os nomes dos contatos que contenham a string digitada
    while (aux != NULL)
    {
        if(strncmp(aux->contato.nome, nome, strlen(nome) ) == 0){                      
            printf("\t%s\n", aux->contato.nome);
            printTelefones(&aux->contato.telefones); 
        }
        aux = aux->prox;
    }

    //menu para excluir 
    menu_excluir();
    scanf("%d",&op);
    getchar();

    switch(op){
        //cancela 
        case 1:
            return;
            break;
        
        //exclui um contato pelo nome
        case 2:
            printf("\nDigite o nome do contato a ser excluído: ");
            gets(nome);
            excluirContato(lista, nome);
            break;
        case 3:
            aux = lista->inicio;
            while (aux != NULL)
            {
                prox = aux->prox;
                if(strncmp(aux->contato.nome, nome, strlen(nome) ) == 0){                      
                    excluirContato(lista, aux->contato.nome);
                }
                aux = prox;
            }
            break;
    }
}