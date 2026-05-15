#include <stdio.h>
#include <stdlib.h>


    //Estrutura do nó da fila.


typedef struct No {
    int id;
    struct No *prox;
} No;

/*
    Estrutura da fila.
*/

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;


    //Inicializa a fila.


void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}


    //Função para verificar se um ID já existe na fila.


int idExiste(Fila *f, int id) {

    No *aux = f->inicio;

    while(aux != NULL) {

        if(aux->id == id) {
            return 1; // ID já existe
        }

        aux = aux->prox;
    }

    return 0; // ID não existe
}


   // Insere cliente na fila.


void inserirCliente(Fila *f, int id) {


        //Verifica se já existe cliente com esse ID.
    

    if(idExiste(f, id)) {
        printf("Erro! Ja existe um cliente com ID %d na fila.\n", id);
        return;
    }

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
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tamanho++;

    printf("Cliente %d inserido na fila!\n", id);
}


   // Atende cliente.


void atenderCliente(Fila *f) {

    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    No *temp = f->inicio;

    printf("Cliente %d atendido!\n", temp->id);

    f->inicio = f->inicio->prox;

    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);

    f->tamanho--;
}


  //  Mostra próximo cliente.


void mostrarProximo(Fila *f) {

    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo cliente: %d\n", f->inicio->id);
}


    //Mostra tamanho da fila.


void mostrarTamanho(Fila *f) {
    printf("Tamanho da fila: %d\n", f->tamanho);
}


   // Programa principal.


int main() {

    Fila fila;

    inicializarFila(&fila);

    int opcao;
    int id;

    do {

        printf("\n {{FILA DE ATENDIMENTO}}\n");
        printf("1: Inserir cliente\n");
        printf("2: Atender cliente\n");
        printf("3: Mostrar proximo cliente\n");
        printf("4: Mostrar tamanho da fila\n");
        printf("0: Sair\n");
        printf("Escolha: ");

        // Verifica entrada inválida
        if(scanf("%d", &opcao) != 1) {

            printf("Entrada invalida! Digite apenas numeros.\n");

            while(getchar() != '\n');

            opcao = -1;

            continue;
        }

        switch(opcao) {

            case 1:

                printf("Digite o ID do cliente: ");

                if(scanf("%d", &id) != 1) {

                    printf("ID invalido! Digite apenas numeros.\n");

                    while(getchar() != '\n');

                    break;
                }

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


