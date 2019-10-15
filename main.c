#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaContato.h"

void menu();

void menu_excluir();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct listaContatos lista;
    struct contato temp;
    char telefone_temp[10] = "1";
    struct elementoContato *aux, *i_procurado = NULL, *f_procurado = NULL;
    int op, quit = 0, encontrado;
    inicListaContato(&lista);
    while(!quit){
        encontrado = 0;
        menu();
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                printf("\nDigite o nome do contato que deseja inserir: ");
                gets(temp.nome);
                aux = buscarContato(&lista, temp.nome);
                if(!aux){
                    inicListaTelefone(&temp.telefones);
                    while(1){
                        printf("\nDigite os telefones deste contato ou 0 para concluir a inserção:");
                        gets(telefone_temp);
                        if(strcmp(telefone_temp, "0") == 0)
                            break;
                        inserirTelefone(&temp.telefones, telefone_temp);
                    }
                    inserirContato(&lista, temp);
                }
                else{
                    printf("\nO contato já existe\n");
                    printTelefones(&aux->contato.telefones);
                }
                break;
            case 2:
                printf("\nDigite o nome do contato a ser procurado: ");
                gets(temp.nome);
                aux = lista.inicio;
                while(aux != NULL){
                    if(strncmp(aux->contato.nome, temp.nome, strlen(temp.nome) ) == 0){                      
                        printf("\t%s\n\n", aux->contato.nome);
                        printTelefones(&aux->contato.telefones);
                        encontrado = 1; 
                    }
                    aux = aux->prox;
                }
                if(!encontrado)
                    printf("\nO contato não está na agenda\n");
                break;
            case 3:
                printf("\nDigite o nome do contato que deseja excluir: ");
                gets(temp.nome);
                aux = lista.inicio;
                while(aux != NULL){
                    if(strncmp(aux->contato.nome, temp.nome, strlen(temp.nome) ) == 0){
                        if(!i_procurado)
                            i_procurado = aux;
                        printf("\t%s\n\n", aux->contato.nome);
                        printTelefones(&aux->contato.telefones);
                        encontrado = 1;
                        f_procurado = aux;
                    }
                    aux = aux->prox;
                }
                if(!encontrado){
                    printf("\nO contato não está na agenda\n");
                    break;
                }
                while(op > 0 && op <=3){
                    menu_excluir();
                    scanf("%d", &op);
                    getchar();
                    switch(op){
                        case 1:
                            op = -1;
                            break;
                        case 2:
                            printf("\nDigite o nome do contato que deseja excluir: ");
                            gets(temp.nome);
                            aux = buscarContato(&lista, temp.nome);
                            if(!aux)
                                printf("\n\nContato não encontrado \n\n");
                            else{
                                excluirContato(&lista, temp.nome);
                                op = -1;
                            }
                            break;
                        case 3:
                            while(f_procurado != i_procurado){
                                f_procurado = f_procurado->ant;
                                excluirContato(&lista, f_procurado->prox->contato.nome);
                            }
                            op = -1;
                            break;
                    }
                }
                break;
            case 0:
                quit = 1;
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