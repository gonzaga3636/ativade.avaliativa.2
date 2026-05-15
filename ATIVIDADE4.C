
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    //Estrutura do nó da pilha.


typedef struct No {
    char letra;
    struct No *prox;
} No;


    //Estrutura da pilha.


typedef struct {
    No *topo;
    int tamanho;
} Pilha;

    //Inicializa pilha.


void inicializarPilha(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

    //Push -> empilha caractere.


void push(Pilha *p, char letra) {

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    novo->letra = letra;

    novo->prox = p->topo;

    p->topo = novo;

    p->tamanho++;
}


    //Retorna topo da pilha.

char topo(Pilha *p) {

    if(p->topo == NULL) {
        return '\0';
    }

    return p->topo->letra;
}


   // Remove elemento da pilha.


void pop(Pilha *p) {

    if(p->topo == NULL) {
        return;
    }

    No *temp = p->topo;

    p->topo = p->topo->prox;

    free(temp);

    p->tamanho--;
}


    //Inverte string.


void inverterString(char str[]) {

    int inicio = 0;
    int fim = strlen(str) - 1;

    while(inicio < fim) {

        char temp = str[inicio];

        str[inicio] = str[fim];

        str[fim] = temp;

        inicio++;
        fim--;
    }
}


   //Remove duplicatas consecutivas.


void removerDuplicatas(char texto[]) {

    Pilha pilha;

    inicializarPilha(&pilha);

    int i;

    for(i = 0; texto[i] != '\0'; i++) {

      
           //Só empilha se for diferente
           // do topo da pilha.
      

        if(texto[i] != topo(&pilha)) {
            push(&pilha, texto[i]);
        }
    }

 
       // Como a pilha inverte a ordem,
       // precisamos montar a string
       // e depois inverter novamente.


    char resultado[100];

    int j = 0;

    while(pilha.topo != NULL) {

        resultado[j] = topo(&pilha);

        pop(&pilha);

        j++;
    }

    resultado[j] = '\0';

    inverterString(resultado);

    printf("Resultado: %s\n", resultado);
}


    //Programa principal.


int main() {

    char texto[100];
    int opcao;

    do {

        printf("\n{{REMOCAO DE DUPLICATAS}}\n");
        printf("1: Digitar string\n");
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

                printf("Digite a string: ");

                scanf("%s", texto);

                removerDuplicatas(texto);

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
