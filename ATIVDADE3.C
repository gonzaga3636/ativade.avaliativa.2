

#include <stdio.h>
#include <stdlib.h>


    //Estrutura do nó da pilha.

  //  Cada nó guarda:
   // - valor -> valor inserido
   // - minimo -> menor valor até aquele ponto


typedef struct No {
    int valor;
    int minimo;
    struct No *prox;
} No;


   // Estrutura da pilha.


typedef struct {
    No *topo;
    int tamanho;
} Pilha;


    //Inicializa pilha.


void inicializarPilha(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}


   // Push -> empilha elemento.


void push(Pilha *p, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    novo->valor = valor;

   
       //Define o menor valor da pilha.


    if(p->topo == NULL || valor < p->topo->minimo) {
        novo->minimo = valor;
    }
    else {
        novo->minimo = p->topo->minimo;
    }

    novo->prox = p->topo;

    p->topo = novo;

    p->tamanho++;

    printf("Valor %d empilhado!\n", valor);
}


   // Pop -> remove elemento do topo.



void pop(Pilha *p) {

    if(p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    No *temp = p->topo;

    printf("Valor removido: %d\n", temp->valor);

    p->topo = p->topo->prox;

    free(temp);

    p->tamanho--;
}

/*
    Mostra topo da pilha.
*/

void mostrarTopo(Pilha *p) {

    if(p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Topo da pilha: %d\n", p->topo->valor);
}

/*
    getMin() -> mostra menor elemento.
*/

void getMin(Pilha *p) {

    if(p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Menor elemento: %d\n", p->topo->minimo);
}

/*
    Mostra pilha.
*/

void mostrarPilha(Pilha *p) {

    if(p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    No *aux = p->topo;

    printf("Pilha: ");

    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

/*
    Programa principal.
*/

int main() {

    Pilha pilha;

    inicializarPilha(&pilha);

    int opcao;
    int valor;

    do {

        printf("\n{{PILHA COM MINIMO}}\n");
        printf("1: Push (Empilhar)\n");
        printf("2: Pop (Desempilhar)\n");
        printf("3: Mostrar topo\n");
        printf("4: getMin()\n");
        printf("5: Mostrar pilha\n");
        printf("0: Sair\n");
        printf("Escolha: ");

        // Validação de entrada
        if(scanf("%d", &opcao) != 1) {

            printf("Entrada invalida!\n");

            while(getchar() != '\n');

            opcao = -1;

            continue;
        }

        switch(opcao) {

            case 1:

                printf("Digite um valor: ");

                if(scanf("%d", &valor) != 1) {

                    printf("Valor invalido!\n");

                    while(getchar() != '\n');

                    break;
                }

                push(&pilha, valor);

                break;

            case 2:

                pop(&pilha);

                break;

            case 3:

                mostrarTopo(&pilha);

                break;

            case 4:

                getMin(&pilha);

                break;

            case 5:

                mostrarPilha(&pilha);

                break;

            case 0:

                printf("Encerrando...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
