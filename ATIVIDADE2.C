
#include <stdio.h>
#include <stdlib.h>


    //Estrutura do nó da fila.


typedef struct No {
    int valor;
    struct No *prox;
} No;


   // Estrutura da fila.


typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;


    //Inicializa fila.


void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}


   // Insere elemento na fila.


void inserir(Fila *f, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tamanho++;
}


    //Mostra fila.


void mostrarFila(Fila *f) {

    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    No *aux = f->inicio;

    printf("Fila: ");

    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}


    //Verifica se a fila é palíndroma.

  //  Estratégia:
  //  - Copiamos os valores da fila para um vetor
  //  - Comparamos início e fim do vetor


int verificarPalindromo(Fila *f) {

    if(f->inicio == NULL) {
        return 0;
    }

    int vetor[f->tamanho];

    No *aux = f->inicio;

    int i = 0;

    // Copia fila para vetor
    while(aux != NULL) {
        vetor[i] = aux->valor;
        aux = aux->prox;
        i++;
    }

    int inicio = 0;
    int fim = f->tamanho - 1;

    // Compara extremos
    while(inicio < fim) {

        if(vetor[inicio] != vetor[fim]) {
            return 0;
        }

        inicio++;
        fim--;
    }

    return 1;
}


   // Programa principal.


int main() {

    Fila fila;

    inicializarFila(&fila);

    int opcao;
    int valor;

    do {

        printf("\n{{FILA PALINDROMA}}\n");
        printf("1: Inserir numero\n");
        printf("2: Mostrar fila\n");
        printf("3: Verificar palindromo\n");
        printf("0:Sair\n");
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

                printf("Digite um numero: ");

                if(scanf("%d", &valor) != 1) {

                    printf("Valor invalido!\n");

                    while(getchar() != '\n');

                    break;
                }

                inserir(&fila, valor);

                printf("Numero inserido!\n");

                break;

            case 2:

                mostrarFila(&fila);

                break;

            case 3:

                if(verificarPalindromo(&fila)) {
                    printf("A fila e um palindromo!\n");
                }
                else {
                    printf("A fila NAO e um palindromo!\n");
                }

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
