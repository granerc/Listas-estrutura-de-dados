// Crie um programa que inicialize duas listas encadeadas e realize a concatenação destas listas
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

void concatenarListas(struct Node** lista1, struct Node* lista2) {
    if (*lista1 == NULL) {
        *lista1 = lista2;
        return;
    }

    struct Node* temp = *lista1;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = lista2;
}

int main() {

    struct Node* lista1 = NULL;
    struct Node* lista2 = NULL;

    inserirNoInicio(&lista1, 10);
    inserirNoInicio(&lista1, 20);
    inserirNoInicio(&lista1, 30);

    inserirNoInicio(&lista2, 40);
    inserirNoInicio(&lista2, 50);
    inserirNoInicio(&lista2, 60);

    printf("Lista 1 antes da concatenacao: ");
    imprimirLista(lista1);

    printf("Lista 2 antes da concatenacao: ");
    imprimirLista(lista2);

    concatenarListas(&lista1, lista2);

    printf("Lista 1 apos a concatenacaoo: ");
    imprimirLista(lista1);

    return 0;
}
