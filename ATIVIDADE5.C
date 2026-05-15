
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


   // Estrutura do nó da pilha.


typedef struct No {
    char pagina[50];
    struct No *prox;
} No;


   // Estrutura da pilha.


typedef struct {
    No *topo;
} Pilha;


   // Inicializa pilha.


void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}


    //Push -> empilha página.


void push(Pilha *p, char pagina[]) {

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    strcpy(novo->pagina, pagina);

    novo->prox = p->topo;

    p->topo = novo;
}


    //Pop -> remove topo da pilha.


void pop(Pilha *p, char destino[]) {

    if(p->topo == NULL) {
        strcpy(destino, "");
        return;
    }

    No *temp = p->topo;

    strcpy(destino, temp->pagina);

    p->topo = p->topo->prox;

    free(temp);
}


    //Limpa pilha.


void limparPilha(Pilha *p) {

    char lixo[50];

    while(p->topo != NULL) {
        pop(p, lixo);
    }
}


   // Mostra conteúdo da pilha.

void mostrarPilha(Pilha *p) {

    if(p->topo == NULL) {
        printf("Vazia\n");
        return;
    }

    No *aux = p->topo;

    while(aux != NULL) {

        printf("%s ", aux->pagina);

        aux = aux->prox;
    }

    printf("\n");
}

   //Programa principal.


int main() {

    Pilha voltar;
    Pilha avancar;

    inicializarPilha(&voltar);
    inicializarPilha(&avancar);

    char paginaAtual[50] = "HOME";

    int opcao;

    char novaPagina[50];

    do {

        printf("\n{{NAVEGADOR}}\n");
        printf("Pagina atual: %s\n", paginaAtual);

        printf("\n1: Visitar pagina\n");
        printf("2: Voltar\n");
        printf("3: Avancar\n");
        printf("4: Mostrar pilha voltar\n");
        printf("5: Mostrar pilha avancar\n");
        printf("0: Sair\n");

        printf("Escolha: ");

        // Validação
        if(scanf("%d", &opcao) != 1) {

            printf("Entrada invalida!\n");

            while(getchar() != '\n');

            opcao = -1;

            continue;
        }

        switch(opcao) {

            case 1:

                printf("Digite o nome da pagina: ");

                scanf("%s", novaPagina);

                
                   // Página atual vai
                   // para pilha voltar.
              

                push(&voltar, paginaAtual);

              
                   // Nova navegação limpa
                  //  pilha avançar.
             

                limparPilha(&avancar);

                strcpy(paginaAtual, novaPagina);

                printf("Pagina acessada: %s\n", paginaAtual);

                break;

            case 2:

                if(voltar.topo == NULL) {

                    printf("Nao ha pagina para voltar!\n");

                }
                else {

                  
                       // Página atual vai
                       // para pilha avançar.
                   

                    push(&avancar, paginaAtual);

                   
                       // Recupera página anterior.
                   

                    pop(&voltar, paginaAtual);

                    printf("Voltando para: %s\n", paginaAtual);
                }

                break;

            case 3:

                if(avancar.topo == NULL) {

                    printf("Nao ha pagina para avancar!\n");

                }
                else {

                   
                      //  Página atual vai
                      //  para pilha voltar.
                   

                    push(&voltar, paginaAtual);

                   
                       // Recupera página futura.
                    

                    pop(&avancar, paginaAtual);

                    printf("Avancando para: %s\n", paginaAtual);
                }

                break;

            case 4:

                printf("Pilha VOLTAR: ");

                mostrarPilha(&voltar);

                break;

            case 5:

                printf("Pilha AVANCAR: ");

                mostrarPilha(&avancar);

                break;

            case 0:

                printf("Encerrando navegador...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

