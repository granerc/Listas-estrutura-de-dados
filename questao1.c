//Crie um programa que inicialize uma lista encadeada e realize uma busca para verificar se um item x está nesta lista.
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

int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return 1; // Item encontrado
        }
        current = current->prox;
    }
    return 0; // Item não encontrado
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 

    inserirNoInicio(&head, 10);
    inserirNoInicio(&head, 20);
    inserirNoInicio(&head, 30);
    inserirNoInicio(&head, 40);

    printf("Lista encadeada: ");
    printList(head);

    int x = 20;
    if (search(head, x)) {
        printf("O valor %d esta na lista.\n", x);
    } else {
        printf("O valor %d não esta na lista.\n", x);
    }

    return 0;
}
