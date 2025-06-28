//Implementazione di una Pila di interi in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int data;
    struct Nodo* next;
}Nodo;

typedef struct Pila{
    Nodo* head;
    int size;
}Pila;

Pila* getStack()
{
    Pila* Stack = (Pila*)malloc(sizeof(Pila));
    if(Stack == NULL){
        fprintf(stderr, "Errore: Impossibile allocare la Pila.\n");
        exit(EXIT_FAILURE);
    }

    Stack->head = NULL;
    Stack->size = 0;
    return Stack;
}

bool isEmpty(Pila* Stack)
{
    if(Stack->size == 0){
        return true;
    } else {
        return false;
    }
}

void Push(Pila* Stack, int n)
{
    Nodo* newnode = (Nodo*)malloc(sizeof(Nodo));
    if(newnode == NULL){
        fprintf(stderr, "Errore: Nodo non allocabile.\n");
        exit(EXIT_FAILURE);
    }

    newnode->data = n;
    newnode->next = NULL;
    
    if(Stack->head == NULL){
        Stack->head = newnode;
    } else {
        newnode->next = Stack->head;
        Stack->head = newnode;
    }
    Stack->size++;
}

void Pop(Pila* Stack)
{
    if(isEmpty(Stack)){
        fprintf(stderr, "La Pila è vuota.");
        exit(EXIT_FAILURE);
    }

    Nodo* tmp = Stack->head;
    Stack->head = Stack->head->next;
    free(tmp);
    Stack->size--;
}

void printStack(Pila* Stack)
{
    if(isEmpty(Stack)){
        fprintf(stderr, "La Pila è vuota.");
        exit(EXIT_FAILURE);
    }
    
    Nodo* tmp = Stack->head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void clearStack(Pila* Stack)
{
    while(Stack->head != NULL){
        Nodo* tmp = Stack->head;
        Stack->head = Stack->head->next;
        free(tmp);
        Stack->size--;
    }
    printf("Pila eliminata al termine del programma.\n");
    free(Stack);
}

int main(int argc, char* argv[])
{
    Pila* Stack = getStack();
    
    Push(Stack, 1);
    Push(Stack, 2);
    Push(Stack, 3);
    Push(Stack, 4);
    Push(Stack, 5);
    Push(Stack, 6);
    Push(Stack, 7);
    Push(Stack, 8);
    Push(Stack, 9);

    printf("Contenuto della Pila:\n");
    printStack(Stack);
    printf("Size Pila: %d\n", Stack->size);

    Pop(Stack);
    Pop(Stack);

    printf("\n");
    printf("Contenuto della Pila dopo due Pop:\n");
    printStack(Stack);
    printf("Size Pila: %d\n", Stack->size);

    clearStack(Stack);
}
