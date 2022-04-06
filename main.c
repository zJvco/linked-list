#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
} List;

Node* create_node(int v) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = v;
    node->next = NULL;
    return node;
}

void insert(List *l, int v) {
    Node *tmp = (Node*) malloc(sizeof(Node));

    tmp = create_node(v);
    tmp->next = l->head;
    l->head = tmp;
}

void print(List *l)
{
    Node *aux = l->head;

    if (l->head == NULL) {
        printf("Empty list");
        return;
    }

    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
}

void delete(List *l, int v) {
    Node *aux = l->head;
    Node *prev = aux;

    if (l->head == NULL) {
        printf("Empty list");
        return;
    }

    while (aux != NULL) {
        if (aux->value == v) {
            prev->next = aux->next;

            if (aux == l->head) {
                l->head = aux->next;
            }

            free(aux);
            break;
        }

        prev = aux;
        aux = aux->next;
    }
}

void free_list(List *l) {
    free(l);
}

int main(int argc, char const *argv[]) {
    List *l = (List*) malloc(sizeof(List));

    // Inserting numbers 0 - 9
    for (int i = 0; i < 10; i++) {
        insert(l, i);
    }

    // Deleting a specify number
    delete(l, 9);

    // Printing linked list values
    print(l);

    // Freeing list from memory
    free_list(l);

    return 0;
}
