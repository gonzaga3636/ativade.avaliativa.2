#include <stdio.h>
#include <stdlib.h>


   //Estrutura do nó da fila.

   // Cada nó representa um cliente.
  //  O cliente possui:
   // id = número do cliente
   //  prox = ponteiro para o próximo cliente


typedef struct No {
    int id;
    struct No *prox;
} No;


    //Estrutura da fila.

  //  A fila possui:
   // - inicio = primeiro elemento
    //- fim = último elemento
   // - tamanho = quantidade de elementos


typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;


    //Função para inicializar a fila.


void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}


    //Função para inserir cliente na fila.

    //Na fila:
    // novos elementos entram no FINAL


void inserirCliente(Fila *f, int id) {

    // Aloca memória para novo nó
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    novo->id = id;
    novo->prox = NULL;

    // Se a fila estiver vazia
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        // Liga o último elemento ao novo
        f->fim->prox = novo;

        // Atualiza o fim da fila
        f->fim = novo;
    }

    f->tamanho++;

    printf("Cliente %d inserido na fila!\n", id);
}


    //Função para atender cliente.

    //Na fila:
    // elementos saem do INICIO


void atenderCliente(Fila *f) {

    // Verifica se a fila está vazia
    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    // Guarda o primeiro elemento
    No *temp = f->inicio;

    printf("Cliente %d atendido!\n", temp->id);

    // Move o início para o próximo nó
    f->inicio = f->inicio->prox;

    // Se a fila ficou vazia
    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);

    f->tamanho--;
}


    //Função para mostrar o próximo cliente.


void mostrarProximo(Fila *f) {

    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo cliente: %d\n", f->inicio->id);
}


    //Função para mostrar tamanho da fila.


void mostrarTamanho(Fila *f) {
    printf("Tamanho da fila: %d\n", f->tamanho);
}


    //Função principal com menu.


int main() {

    Fila fila;

    inicializarFila(&fila);

    int opcao;
    int id;

    do {

        printf("\n===== FILA DE ATENDIMENTO =====\n");
        printf("1 - Inserir cliente\n");
        printf("2 - Atender cliente\n");
        printf("3 - Mostrar proximo cliente\n");
        printf("4 - Mostrar tamanho da fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("Digite o ID do cliente: ");
                scanf("%d", &id);

                inserirCliente(&fila, id);

                break;

            case 2:

                atenderCliente(&fila);

                break;

            case 3:

                mostrarProximo(&fila);

                break;

            case 4:

                mostrarTamanho(&fila);

                break;

            case 0:

                printf("Encerrando sistema...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
