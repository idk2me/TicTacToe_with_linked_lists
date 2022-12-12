#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked lists are from David Georg Reichelt's course of 
// Fundamentals Of Computer Science at Lancaster University Leipzig
// Week 8 & Week 9

// Define a node struct to hold the data and a pointer to the next node
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Define a linked list struct to hold a pointer to the first node
typedef struct LinkedList {
    Node *head;
} LinkedList;

// Function to create a new node and return a pointer to it
Node *create_node(char data);

// Function to create a new linked list and return a pointer to it
LinkedList *create_linked_list();

// Function to insert a new node at the beginning of the linked list
void insert_node(LinkedList *list, char data);

// Function to print the data in the linked list
void print_grid(LinkedList *list);

int main() 
{
    int MIN = 2;
    int MAX = 50;

    // Create a new linked list
    LinkedList *list = create_linked_list();
    Node *node = create_node('_');

    int n; 
    printf("Enter board width: ");
    scanf("%d", &n);
    if((n^2) > (MAX^2) || (n^2) < (MIN^2))
    {
        printf("Invalid input, minimum is 2, max is 50\n");
        scanf("%d", &n);
        return 0;
    }

    // Insert nodes
    for(int i = 0; i < (n^2); i++)
    {
        Node *node = create_node('_');
        insert_node(list, node);
    }

    // Print the linked list
    print_grid(list);

    return 0;
}
//functions

Node *create_node(char data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

LinkedList *create_linked_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void insert_node(LinkedList *list, char data) {
    Node *new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

void print_grid(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node != NULL) 
    {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}