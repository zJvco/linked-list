typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
} List;

Node* create_node(int v);
void insert(List *l, int v);
void print(List *l);
void delete(List *l, int v);
void free_list(List *l);