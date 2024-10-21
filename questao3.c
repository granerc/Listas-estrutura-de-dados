//Crie um programa que inicialize uma lista encadeada e realize a destruição desta lista em tempo de execução.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prox;
};

struct Node* criarNode(int data) {
    struct Node* novaNode = (struct Node*)malloc(sizeof(struct Node));
    novaNode->data = data;
    novaNode->prox = NULL;
    return novaNode;
}

void inserirNoInicio(struct Node** head, int data) {
    struct Node* novaNode = criarNode(data);
    novaNode->prox = *head;
    *head = novaNode;
}

void imprimirLista(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void destruirLista(struct Node** head) {
    struct Node* temp = *head;
    struct Node* proxNode;

    while (temp != NULL) {
        proxNode = temp->prox; 
        printf("Liberando o no com valor: %d\n", temp->data);
        free(temp); 
        temp = proxNode; 
    }

    *head = NULL; 
}

int main() {
    struct Node* lista = NULL;

    inserirNoInicio(&lista, 10);
    inserirNoInicio(&lista, 20);
    inserirNoInicio(&lista, 30);
    inserirNoInicio(&lista, 40);

    printf("Lista encadeada: ");
    imprimirLista(lista);

    destruirLista(&lista);

    if (lista == NULL) {
        printf("Lista destruida com sucesso.\n");
    } else {
        printf("Erro ao destruir a lista.\n");
    }

    return 0;
}
